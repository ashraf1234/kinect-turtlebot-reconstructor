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

#include <pcl/features/normal_3d.h>

#include <pcl/io/pcd_io.h>

#include <math.h>
#include <stdio.h>

using namespace std;

#define GROUND_PLANE_COEFF_TOPIC "/ground_plane"

float NORMALS_SEARCH_RADIUS = 0.03;
float EPS_ANGLE = 0.2;
int SEG_METHOD_TYPE = pcl::SAC_RANSAC;
float DISTANCE_THRESHOLD = 0.03;
int groundColor[] = {255,0,0};
int MAX_ITER = 100;

typedef pcl::PointXYZRGB CloudPointType;
typedef pcl::PointCloud<CloudPointType> RGBCloud;
typedef RGBCloud::Ptr RGBCloudPtr;
typedef pcl::PointCloud<pcl::Normal> NormalsCloud;
typedef NormalsCloud::Ptr NormalsCloudPtr;

ros::Publisher pub;
ros::Publisher groundPlaneCoeffPublisher;

char name[30];
bool groundPlaneFound = false;
float groundPlaneCoeff[4],EPS[4];

bool isAtRequiredDepth(pcl::ModelCoefficients::Ptr coefficients)
{
  return abs(coefficients->values[3]-groundPlaneCoeff[3])<EPS[3];
}

bool isValidGroundPlane(pcl::ModelCoefficients::Ptr coefficients)
{
  return (abs(coefficients->values[0]-groundPlaneCoeff[0])<EPS[0]) && (abs(coefficients->values[1]-groundPlaneCoeff[1])<EPS[1]) && (abs(coefficients->values[2]-groundPlaneCoeff[2])<EPS[2]) && isAtRequiredDepth(coefficients);
}

void genNormalsCloud(RGBCloudPtr cloud, NormalsCloudPtr cloudNormals)
{
  pcl::NormalEstimation<CloudPointType, pcl::Normal> ne;
  ne.setInputCloud(cloud);
  pcl::search::KdTree<CloudPointType>::Ptr tree (new pcl::search::KdTree<CloudPointType> ());
  ne.setSearchMethod (tree);

  ne.setRadiusSearch (NORMALS_SEARCH_RADIUS);
  ne.compute (*cloudNormals);
}

void updateGroundPlaneCoeff(float a, float b, float c, float d)
{
  groundPlaneCoeff[0] = a;
  groundPlaneCoeff[1] = b;
  groundPlaneCoeff[2] = c;
  groundPlaneCoeff[3] = d;
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
void populateIndices(pcl::IndicesPtr indices, int size)
{
  for(int i=0;i<size;i++)
  {
    indices->push_back(i);
  }
}
RGBCloudPtr searchGroundPlane(RGBCloudPtr cloud)
{
  // Additional accuracy can be achieved using SACSegmentationFromNormals
//   NormalsCloudPtr cloudNormals(new NormalsCloud);
//   printf("##Normals Gen\n");
  
  RGBCloudPtr cloudCopy(new RGBCloud(*cloud));
//   genNormalsCloud(cloudCopy, cloudNormals);
  RGBCloudPtr ground(new RGBCloud);
  
  pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  
  // Create the segmentation object
  pcl::SACSegmentation<CloudPointType> seg;
//   pcl::SACSegmentationFromNormals<CloudPointType,pcl::Normal> seg;
//   pcl::IndicesPtr indices(new vector<int>());
//   populateIndices(indices,cloud->points.size());
  
//   printf("IndicesSize:%d CloudSize:%d",indices->size(),cloud->points.size());
  
  seg.setOptimizeCoefficients (true);
  seg.setModelType (pcl::SACMODEL_PLANE);
  seg.setMaxIterations (MAX_ITER);
//   seg.setModelType (pcl::SACMODEL_PLANE);
  // Using the previous estimate of ground plane
//   const Eigen::Vector3f y(groundPlaneCoeff[0],groundPlaneCoeff[1],groundPlaneCoeff[2]);
//   seg.setAxis(y);
//   seg.setEpsAngle(EPS_ANGLE);
  seg.setMethodType (SEG_METHOD_TYPE);
  seg.setDistanceThreshold(DISTANCE_THRESHOLD);
  do{
    seg.setInputCloud ((*cloudCopy).makeShared ());
//     seg.setInputNormals(cloudNormals);
//     seg.setIndices(indices);
    seg.segment (*inliers, *coefficients);

    if (inliers->indices.size () == 0)
    {
      PCL_ERROR ("##GROUND PLANE NOT FOUND##");
      groundPlaneFound = false;
      return ground;
    }

//     int coeffCount = coefficients->values.size();
//     cerr<< "Coefficients: "<< coeffCount<<endl;
//     for(int i=0;i<coeffCount;i++)
//     {
//       cerr << coefficients->values[i] << std::endl;
//     }
//     cerr << "Model inliers: " << inliers->indices.size () << endl;
    
    pcl::ExtractIndices<pcl::PointXYZRGB> extract;
    extract.setInputCloud (cloudCopy);
    extract.setIndices (inliers);
    
    if(isValidGroundPlane(coefficients))
    {
      updateGroundPlaneCoeff(coefficients->values[0],coefficients->values[1],coefficients->values[2],coefficients->values[3]);
      groundPlaneFound = true;
      extract.setNegative (false);
      extract.filter(*ground);
      return ground;
    }
    RGBCloudPtr newCloud(new RGBCloud());
    extract.setNegative (true);
    extract.filter (*newCloud);
    cloudCopy = newCloud;
//     genNormalsCloud(cloudCopy, cloudNormals);
//     updateIndices(indices,inliers);
  }while(1);
}
void printGroundPlaneCoefficients()
{
  printf("Coefficients:\n");
  for(int i=0;i<4;i++)
  {
    printf("%f\n",groundPlaneCoeff[i]);
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
  RGBCloudPtr cloud(new RGBCloud);
  RGBCloudPtr outputCloud(new RGBCloud);
  sensor_msgs::PointCloud2 output;
  fromROSMsg(input,*cloud);
  fromROSMsg(input,*outputCloud);
  
//   pcl::PointIndices::Ptr inliers;
  
  if(!groundPlaneFound)
  {
    outputCloud = searchGroundPlane(cloud);
    if(groundPlaneFound)
    {
      printf("##Ground Plane Found##\n");
      printGroundPlaneCoefficients();
    }
    else
      return;
  }
  else
  {
    outputCloud = searchGroundPlane(cloud);
    if(!groundPlaneFound)
    {
      return;
    }
  }
//   markPointsOnCloud(outputCloud, inliers);
  toROSMsg(*outputCloud,output);
  pub.publish (output);
}

void printHelp()
{
  printf("Usage: <executable> <a> <b> <c> <d> <DISTANCE_THRESHOLD> <EPS_a> <EPS_b> <EPS_c> <EPS_d>\n");
}
void input(int argc, char** argv)
{
  if(argc!=11)
  {
    printHelp();
    exit(0);
  }
  int next = 0;
  sscanf(argv[++next],"%f",&groundPlaneCoeff[0]);
  sscanf(argv[++next],"%f",&groundPlaneCoeff[1]);
  sscanf(argv[++next],"%f",&groundPlaneCoeff[2]);
  sscanf(argv[++next],"%f",&groundPlaneCoeff[3]);
  sscanf(argv[++next],"%f",&EPS[0]);
  sscanf(argv[++next],"%f",&EPS[1]);
  sscanf(argv[++next],"%f",&EPS[2]);
  sscanf(argv[++next],"%f",&EPS[3]);
  sscanf(argv[++next],"%f",&DISTANCE_THRESHOLD);
  sscanf(argv[++next],"%d",&MAX_ITER);
}
int
main (int argc, char** argv)
{
  input(argc,argv);
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/camera/depth_registered/points", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);
//   groundPlaneCoeffPublisher = nh.advertise<GroundPlaneCoeff> (GROUND_PLANE_COEFF_TOPIC, 1, getGroundPlaneCoeff);

  // Spin
  ros::spin ();
}