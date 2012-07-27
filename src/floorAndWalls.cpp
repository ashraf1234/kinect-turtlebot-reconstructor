#include <stdio.h>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
// PCL specific includes
#include <pcl/ros/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/visualization/pcl_visualizer.h>

#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>

#include <pcl/segmentation/extract_clusters.h>
#include <pcl/filters/extract_indices.h>

#include <pcl/io/pcd_io.h>

#include <math.h>
#include <stdio.h>

using namespace std;

ros::Publisher pub;

pcl::visualization::PCLVisualizer *p;
//its left and right viewports
int vp_1, vp_2;
int counter=0,minPoints = 500;
float error=0.1,dt=0.03;
char name[40];

void cloud_cb (const sensor_msgs::PointCloud2& input)
{
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
  sensor_msgs::PointCloud2 output;
  fromROSMsg(input,*cloud);
      
  sprintf(name,"./output/scene%d.pcd",counter);
  pcl::io::savePCDFile(name,input);

  
  std::cerr << "Point cloud data: " << cloud->points.size () << " points" << std::endl;

  pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  // Create the segmentation object
  pcl::SACSegmentation<pcl::PointXYZRGB> seg;
  // Optional
  seg.setOptimizeCoefficients (true);
  // Mandatory
//   seg.setModelType (pcl::SACMODEL_PERPENDICULAR_PLANE);
  seg.setModelType (pcl::SACMODEL_PLANE);
//   const Eigen::Vector3f z(-0.000992613,-0.992319,-0.123705);
//   seg.setAxis(z);
//   seg.setEpsAngle(0.3);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setDistanceThreshold (dt);
  int planeCount = 0;
  do{
    seg.setInputCloud ((*cloud).makeShared ());
    seg.segment (*inliers, *coefficients);

    if (inliers->indices.size () == 0)
    {
      PCL_ERROR ("Could not estimate a planar model for the given dataset.");
      break;
    }

    int coeffCount = coefficients->values.size();
    cerr<< "Coefficients: "<< coeffCount<<endl;
    for(int i=0;i<coeffCount;i++)
    {
      cerr << coefficients->values[i] << std::endl;
    }
    cerr << "Model inliers: " << inliers->indices.size () << endl;

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr newCloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr plane(new pcl::PointCloud<pcl::PointXYZRGB>);
    
    // Extract the planar inliers from the input cloud
    pcl::ExtractIndices<pcl::PointXYZRGB> extract;
    extract.setInputCloud (cloud);
    extract.setIndices (inliers);

    // Remove the planar inliers, extract the rest
    extract.setNegative (true);
    extract.filter (*newCloud);
    cloud = newCloud;
    
    if(inliers->indices.size()>minPoints)
    {
      extract.setNegative (false);
      extract.filter(*plane);
      toROSMsg(*plane,output);
      
      sprintf(name,"./output/scene%d_plane%d.pcd",counter,planeCount);
      printf("Scene%d_Plane%d\n",counter,planeCount);
      planeCount++;
      pcl::io::savePCDFile(name,output);
    }
    
//     pub.publish (output);
//     printf("Cloud Size:%d\n",cloud->points.size());
//     printf("MinPoints:%d\n",minPoints);
  }while(cloud->points.size()>minPoints);
  counter++;
}

void printHelp()
{
  printf("Usage: <executable> <distance-threshold> <min-points-in-plane>\n");
}
int
main (int argc, char** argv)
{
  if(argc!=3)
  {
    printHelp();
    exit(0);
  }
  sscanf(argv[1],"%f",&dt);
  sscanf(argv[2],"%d",&minPoints);
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/camera/depth_registered/points", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);

  // Spin
  ros::spin ();
}