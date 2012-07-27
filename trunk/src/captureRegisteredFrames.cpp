#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
// PCL specific includes
#include <pcl/ros/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>

#include <iostream>
using namespace std;

#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/keyboard_event.h>
using namespace pcl;

ros::Publisher pub;

pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");
PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
//its left and right viewports

int count=0;

void keyboard_cb(const pcl::visualization::KeyboardEvent &event, void *ptr)
{
  if(event.getKeyCode()=='c')
  {
    stringstream ss;
    ss<<"pcd";
    ss<<::count;
    ss<<".pcd";
    ::count++;
    string s;
    ss>>s;
    pcl::io::savePCDFile(s,*cloud);
  }
}

void cloud_cb (const sensor_msgs::PointCloud2& input)
{
  // ... do data processing

//   sensor_msgs::PointCloud2 *output;
  // Publish the data
  fromROSMsg (input, *cloud);
  
  viewer.showCloud(cloud);
//   while (!viewer.wasStopped())
//   {
//   }
//   pub.publish (input);
}

int
main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh;

  boost::signals2::connection conn = viewer.registerKeyboardCallback(keyboard_cb);
  
  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/camera/depth_registered/points", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud
//   pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);

  // Spin
  ros::spin ();
}