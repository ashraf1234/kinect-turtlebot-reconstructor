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

#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_plane.h>

#include <pcl/io/pcd_io.h>
ros::Publisher pub;

pcl::visualization::PCLVisualizer *p;
//its left and right viewports
int vp_1, vp_2;
int counter=0;
void 
cloud_cb (const sensor_msgs::PointCloud2& input)
{
  pcl::PointCloud<pcl::PointXYZRGB> cloud;
  sensor_msgs::PointCloud2 output;
  fromROSMsg(input,cloud);

  std::cerr << "Point cloud data: " << cloud.points.size () << " points" << std::endl;
//   for (size_t i = 0; i < cloud.points.size (); ++i)
//     std::cerr << "    " << cloud.points[i].x << " " 
//                         << cloud.points[i].y << " " 
//                         << cloud.points[i].z << std::endl;

  SampleConsensusModelPlane<PointXYZRGB>::Ptr model(new SampleConsensusModelPlane<PointXYZRGB> (cloud));

  // Create the RANSAC object
  RandomSampleConsensus<PointXYZRGB> sac (model, 0.03);

  // perform the segmenation step
  bool result = sac.computeModel ();
  
  pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  // Create the segmentation object
  pcl::SACSegmentation<pcl::PointXYZRGB> seg;
  // Optional
  seg.setOptimizeCoefficients (true);
  // Mandatory
  seg.setModelType (pcl::SACMODEL_PERPENDICULAR_PLANE);
  const Eigen::Vector3f z(0,0,1);
  seg.setAxis(z);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setDistanceThreshold (0.01);

  seg.setInputCloud (cloud.makeShared ());
  seg.segment (*inliers, *coefficients);

  if (inliers->indices.size () == 0)
  {
    PCL_ERROR ("Could not estimate a planar model for the given dataset.");
//     return (-1);
  }

  std::cerr << "Model coefficients: " << coefficients->values[0] << " " 
                                      << coefficients->values[1] << " "
                                      << coefficients->values[2] << " " 
                                      << coefficients->values[3] << std::endl;

  std::cerr << "Model inliers: " << inliers->indices.size () << std::endl;
//   for (size_t i = 0; i < inliers->indices.size (); ++i)
//     std::cerr << inliers->indices[i] << "    " << cloud.points[inliers->indices[i]].x << " "
//                                                << cloud.points[inliers->indices[i]].y << " "
//                                                << cloud.points[inliers->indices[i]].z << std::endl;
  pcl::PointCloud<pcl::PointXYZRGB> newCloud(cloud);
//   newCloud.width = cloud.width;
//   newCloud.height = cloud.height;
//   newCloud.points.resize(cloud.width*cloud.height);
  for (size_t i = 0; i < inliers->indices.size (); ++i)
  {
    newCloud.points[i].r = 255;
    newCloud.points[i].g = 0;
    newCloud.points[i].b = 0;
//     newCloud.points[i].x = cloud.points[inliers->indices[i]].x;
//     newCloud.points[i].y = cloud.points[inliers->indices[i]].y;
//     newCloud.points[i].z = cloud.points[inliers->indices[i]].z;
//     newCloud.points[i].r = cloud.points[inliers->indices[i]].r;
//     newCloud.points[i].g = cloud.points[inliers->indices[i]].g;
//     newCloud.points[i].b = cloud.points[inliers->indices[i]].b;
  }
  toROSMsg(newCloud,output);
  char name[20];
  sprintf(name,"./output/%d.pcd",counter);
  pcl::io::savePCDFile(name,output);
  sprintf(name,"./output/%d%d.pcd",counter,counter);
  pcl::io::savePCDFile(name,input);
  counter++;
  pub.publish (output);
}

int
main (int argc, char** argv)
{
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