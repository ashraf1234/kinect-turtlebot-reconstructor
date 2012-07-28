#include <stdio.h>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
// PCL specific includes
#include <pcl/ros/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

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
unsigned int MIN_CLOUD_SIZE = 2000;
float HEIGHT_MIN = 0.1f;
float HEIGHT_MAX = 1.0f;
float HEIGHT_STEP = 0.1f;

typedef pcl::PointXYZRGB CloudPointType;
typedef pcl::PointCloud<CloudPointType> RGBCloud;
typedef RGBCloud::Ptr RGBCloudPtr;
typedef pcl::PointCloud<pcl::Normal> NormalsCloud;
typedef NormalsCloud::Ptr NormalsCloudPtr;

ros::Publisher pub;
ros::Publisher groundPlaneCoeffPublisher;

char name[30];
bool groundPlaneFound = false;
bool groundPlaneInitialized = false;
float groundPlaneCoeff[] = {0.0,-1.0,0.0,0.5};
float EPS[] = {0.02,0.02,0.02,0.2};
int MAX_ITER = 100;

void printGroundPlaneCoefficients();

bool isAtRequiredDepth(pcl::ModelCoefficients::Ptr coefficients)
{
  return abs(coefficients->values[3]-groundPlaneCoeff[3])<EPS[3];
}

bool isValidGroundPlane(pcl::ModelCoefficients::Ptr coefficients)
{
  return (abs(coefficients->values[0]-groundPlaneCoeff[0])<EPS[0]) && (abs(coefficients->values[1]-groundPlaneCoeff[1])<EPS[1]) && (abs(coefficients->values[2]-groundPlaneCoeff[2])<EPS[2])/* && isAtRequiredDepth(coefficients)*/;
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
bool searchGroundPlane(RGBCloudPtr cloud)
{
  RGBCloudPtr cloudCopy(new RGBCloud(*cloud));
//   genNormalsCloud(cloudCopy, cloudNormals);
//   RGBCloudPtr ground(new RGBCloud);
  
  pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  
  // Create the segmentation object
  pcl::SACSegmentation<CloudPointType> seg;
  seg.setOptimizeCoefficients (true);
  seg.setMaxIterations (MAX_ITER);
  seg.setModelType (pcl::SACMODEL_PLANE);
  seg.setMethodType (SEG_METHOD_TYPE);
  seg.setDistanceThreshold(DISTANCE_THRESHOLD);
  
  // Iterating over height values
  float height = HEIGHT_MIN;
  unsigned int maxInliers = 0;
  float newCoefficients[4];
  
  while(height<=HEIGHT_MAX)
  {
    RGBCloudPtr cloudCopy(new RGBCloud(*cloud));
    groundPlaneCoeff[3] = height;
    printf("##Height:%f ::",height);
    do{
      seg.setInputCloud ((*cloudCopy).makeShared ());
      seg.segment (*inliers, *coefficients);

      if (inliers->indices.size () == 0)
      {
	height+=HEIGHT_STEP;
	printf("FAILED##\n");
	break;
      }
      
      pcl::ExtractIndices<pcl::PointXYZRGB> extract;
      extract.setInputCloud (cloudCopy);
      extract.setIndices (inliers);
      
      if(isValidGroundPlane(coefficients))
      {
	printf("SUCCESS::%d inliers##\n",inliers->indices.size());
	if(inliers->indices.size()>maxInliers)
	{
	  groundPlaneInitialized = true;
	  newCoefficients[0] = coefficients->values[0];
	  newCoefficients[1] = coefficients->values[1];
	  newCoefficients[2] = coefficients->values[2];
	  newCoefficients[3] = coefficients->values[3];
	}
	height+=HEIGHT_STEP;
	break;
      }
      RGBCloudPtr newCloud(new RGBCloud());
      extract.setNegative (true);
      extract.filter (*newCloud);
      cloudCopy = newCloud;
    }while(1);
  }
  if(groundPlaneInitialized)
  {
    updateGroundPlaneCoeff(newCoefficients[0],newCoefficients[1],newCoefficients[2],newCoefficients[3]);
  }
  return groundPlaneInitialized;
}
float getDistFromPlane(CloudPointType p, float coeff[])
{
  float res = 0.0;
  res = coeff[0]*p.x + coeff[1]*p.y + coeff[2]*p.z + coeff[3];
  res/=sqrt(coeff[0]*coeff[0] + coeff[1]*coeff[1] + coeff[2]*coeff[2]);
  return abs(res);
}
pcl::PointIndices::Ptr searchGroundPlaneWithoutRANSAC(RGBCloudPtr cloud)
{
  int cloudPointSize = cloud->points.size();
  pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
  for(int i=0;i<cloudPointSize;i++)
  {
    float dist = getDistFromPlane(cloud->points[i],groundPlaneCoeff);
    if(dist<DISTANCE_THRESHOLD)
    {
      inliers->indices.push_back(i);
    }
  }
//   printf("Inliers:%d\n",inliers->indices.size());
  if(inliers->indices.size()>=MIN_CLOUD_SIZE)
    groundPlaneFound = true;
  else
    groundPlaneFound = false;
  return inliers;
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
  
//   printf("Cloud Size:%d\n",cloud->points.size());
//   fflush(stdout);
  
  pcl::PointIndices::Ptr inliers;
  
  if(!groundPlaneInitialized)
  {
    if(searchGroundPlane(cloud))
    {
      printf("##Ground Plane Successfully Initialized##\n");
//       printf("Inliers:%d\n",inliers->indices.size());
      printGroundPlaneCoefficients();
      return;
    }
    else
    {
      PCL_ERROR("##Ground Plane Not Found::Re-orient Camera parallel to ground##\n");
      return;
    }
  }
  else
  {
    inliers = searchGroundPlaneWithoutRANSAC(cloud);
    if(!groundPlaneFound)
    {
      PCL_ERROR("##Ground Plane Lost##\n");
      return;
    }
  }
  markPointsOnCloud(outputCloud, inliers);
  toROSMsg(*outputCloud,output);
  pub.publish (output);
}

void printHelp()
{
  printf("Usage: <executable> <a> <b> <c> <EPS_a> <EPS_b> <EPS_c> <EPS_d> <HEIGHT_MIN> <HEIGHT_MAX> <HEIGHT_STEP> <DISTANCE_THRESHOLD> <MIN_CLOUD_SIZE> <MAX_ITER>\n");
}
void input(int argc, char** argv)
{
  if(argc!=14)
  {
    printHelp();
    exit(0);
  }
  int next = 0;
  sscanf(argv[++next],"%f",&groundPlaneCoeff[0]);
  sscanf(argv[++next],"%f",&groundPlaneCoeff[1]);
  sscanf(argv[++next],"%f",&groundPlaneCoeff[2]);
  sscanf(argv[++next],"%f",&EPS[0]);
  sscanf(argv[++next],"%f",&EPS[1]);
  sscanf(argv[++next],"%f",&EPS[2]);
  sscanf(argv[++next],"%f",&EPS[3]);
  sscanf(argv[++next],"%f",&HEIGHT_MIN);
  sscanf(argv[++next],"%f",&HEIGHT_MAX);
  sscanf(argv[++next],"%f",&HEIGHT_STEP);
  sscanf(argv[++next],"%f",&DISTANCE_THRESHOLD);
  sscanf(argv[++next],"%d",&MIN_CLOUD_SIZE);
  sscanf(argv[++next],"%d",&MAX_ITER);
}
int
main (int argc, char** argv)
{
  input(argc,argv);
  // Initialize ROS
  ros::init (argc, argv, "trackGroundPlaneWithoutRANSAC");
  ros::NodeHandle nh;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/camera/depth_registered/points", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);
//   groundPlaneCoeffPublisher = nh.advertise<GroundPlaneCoeff> (GROUND_PLANE_COEFF_TOPIC, 1, getGroundPlaneCoeff);

  // Spin
  ros::spin ();
}