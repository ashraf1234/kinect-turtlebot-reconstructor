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

typedef pcl::PointXYZRGB CloudPointType;
typedef pcl::PointCloud<CloudPointType> RGBCloud;
typedef RGBCloud::Ptr RGBCloudPtr;
typedef pcl::PointCloud<pcl::Normal> NormalsCloud;
typedef NormalsCloud::Ptr NormalsCloudPtr;

float NORMALS_SEARCH_RADIUS = 0.03;
float EPS_ANGLE = 0.2;
float EPS_HEIGHT = 0.05;
int SEG_METHOD_TYPE = pcl::SAC_RANSAC;
float DISTANCE_THRESHOLD = 0.03;
int groundColor[] = {255,0,0};

ros::Publisher pub;

pcl::visualization::PCLVisualizer *p;
//its left and right viewports
int vp_1, vp_2;
int counter=0;
float error=0.1,dt=0.03,height=1;
char name[30];

bool isGroundPlane(pcl::ModelCoefficients::Ptr coefficients)
{
  return (abs(coefficients->values[1]-1)<error) || (abs(coefficients->values[1]+1)<error) && coefficients->values[3]>height;
}
void populateIndices(pcl::IndicesPtr indices, int size)
{
  for(int i=0;i<size;i++)
  {
    indices->push_back(i);
  }
}
void updateIndices(pcl::IndicesPtr indices, pcl::PointIndices::Ptr inliers)
{
  int toRemove = inliers->indices.size();
  for(int i=0;i<toRemove;i++)
  {
    int origSize = indices->size();
    for(int j=0;j<origSize;j++)
    {
      if((*indices)[j]==inliers->indices[i])
      {
	indices->erase(indices->begin()+j);
	break;
      }
    }
  }
}
void markPointsOnCloud(RGBCloudPtr outputCloud, pcl::PointIndices::Ptr inliers)
{
  int size = inliers->indices.size();
  for(int i=0;i<size;i++)
  {
    outputCloud->points[inliers->indices[i]].r = groundColor[0]%256;
    outputCloud->points[inliers->indices[i]].g = groundColor[1]%256;
    outputCloud->points[inliers->indices[i]].b = groundColor[2]%256;
  }
}
void cloud_cb (const sensor_msgs::PointCloud2& input)
{
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr inpCloud(new pcl::PointCloud<pcl::PointXYZRGB>);
  sensor_msgs::PointCloud2 output;
  fromROSMsg(input,*cloud);
  fromROSMsg(input,*inpCloud);

  std::cerr << "Point cloud data: " << cloud->points.size () << " points" << std::endl;

  pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  pcl::IndicesPtr indices(new vector<int>());
  populateIndices(indices,cloud->points.size());
  
  // Create the segmentation object
  pcl::SACSegmentation<pcl::PointXYZRGB> seg;
  // Optional
  seg.setOptimizeCoefficients (true);
  // Mandatory
//   seg.setModelType (pcl::SACMODEL_PERPENDICULAR_PLANE);
  seg.setModelType (pcl::SACMODEL_PLANE);
  const Eigen::Vector3f z(-0.000992613,-0.992319,-0.123705);
//   seg.setAxis(z);
//   seg.setEpsAngle(0.3);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setDistanceThreshold (dt);
  do{
    seg.setInputCloud ((*cloud).makeShared ());
    seg.setIndices(indices);
    seg.segment (*inliers, *coefficients);

    if (inliers->indices.size () == 0)
    {
      PCL_ERROR ("Could not estimate a planar model for the given dataset.");
      exit(-1);
    }

    int coeffCount = coefficients->values.size();
    cerr<< "Coefficients: "<< coeffCount<<endl;
    for(int i=0;i<coeffCount;i++)
    {
      cerr << coefficients->values[i] << std::endl;
    }
    cerr << "Model inliers: " << inliers->indices.size () << endl;

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr newCloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr ground(new pcl::PointCloud<pcl::PointXYZRGB>);
    
    // Extract the planar inliers from the input cloud
//     pcl::ExtractIndices<pcl::PointXYZRGB> extract;
//     extract.setInputCloud (cloud);
//     extract.setIndices (inliers);
    
    if(isGroundPlane(coefficients))
    {      
//       extract.setNegative (false);
//       extract.filter(*ground);
      markPointsOnCloud(inpCloud, inliers);
      sprintf(name,"./output/%dground.pcd",counter);
      pcl::toROSMsg(*inpCloud,output);
      pcl::io::savePCDFile(name,output);
    }
//     extract.setNegative (false);
//     extract.filter(*ground);

    // Remove the planar inliers, extract the rest
//     extract.setNegative (true);
//     extract.filter (*newCloud);
//     cloud = newCloud;
//     toROSMsg(*ground,output);
    
//     char name[20];
//     sprintf(name,"./output/%d.pcd",counter++);
//     pcl::io::savePCDFile(name,output);
    
//     pub.publish (output);
    updateIndices(indices,inliers);
  }while(!isGroundPlane(coefficients));
  printf("Ground Plane found :)\n");
  
  sprintf(name,"./output/%dorig.pcd",counter);
  pcl::io::savePCDFile(name,input);
  counter++;
  pub.publish (output);
}

void printHelp()
{
  printf("Usage: <executable> <error> <distance-threshold> <ground-height>\n");
}
int
main (int argc, char** argv)
{
  if(argc!=4)
  {
    printHelp();
    exit(0);
  }
  sscanf(argv[1],"%f",&error);
  sscanf(argv[2],"%f",&dt);
  sscanf(argv[3],"%f",&height);
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