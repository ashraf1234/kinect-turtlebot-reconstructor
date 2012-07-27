/*
 * PrimitivesExtract.cpp
 *
 *  Created on: Jun 4, 2012
 *      Author: Karol Hausman
 */

#include "PrimitivesExtract.h"

inline bool comparison_intens(const pcl::PointXYZI& i,
		const pcl::PointXYZI& j) {
	return (i.intensity > j.intensity);
}

inline bool comparison_curvature(pcl::Normal i, pcl::Normal j) {
	return (i.curvature > j.curvature);
}

template<typename PointType> void PrimitivesExtract<PointType>::findBoundaries(
		const CloudConstPtr cloud, Cloud &result) {

	pcl::PointCloud<pcl::Normal>::Ptr temp_normals(
			new pcl::PointCloud<pcl::Normal>);
	pcl::PointCloud<pcl::Normal>::Ptr normals_cloud(
			new pcl::PointCloud<pcl::Normal>);
	pcl::NormalEstimation<PointType, pcl::Normal> norm_est;
	norm_est.setSearchMethod(KdTreePtr(new KdTree));
	norm_est.setInputCloud(cloud);
	norm_est.setRadiusSearch(find_boundaries_radius_search_);
	norm_est.compute(*normals_cloud);

	pcl::copyPointCloud(*normals_cloud, *temp_normals);

	std::sort(temp_normals->points.begin(), temp_normals->points.end(),
			comparison_curvature);
	int place = (int) (temp_normals->points.size() * best_curv_percent_);
	pcl::Normal tresh_point = *(temp_normals->points.begin() + place);
	float treshold = tresh_point.curvature;
//	std::cerr << "tresh: " << treshold << std::endl;

	for (size_t i = 0; i < normals_cloud->size(); ++i) {
		if (normals_cloud->points[i].curvature > treshold)
			result.push_back(cloud->points.at(i));
	}

	result.width = result.points.size();
	result.height = 1;
	result.is_dense = false;

}

template<typename PointType> bool PrimitivesExtract<PointType>::extractCornerVector(
		CloudConstPtr cloud_input, std::vector<CloudPtr>& result, int number) {

	CloudPtr corners(new Cloud);
	CloudPtr corners_debug(new Cloud);
	int size;

	extractCorners(cloud_input, *corners, *corners_debug, number);

	for (size_t j = 0; j < corners->points.size(); j++) {
		CloudPtr augmented_corner(new Cloud);
		pcl::PointIndices::Ptr inliers(new pcl::PointIndices);

		extractNeighbor(cloud_, corners->points[j], inliers, size);

		augmented_corner->points.push_back(corners->points[j]);

		for (size_t i = 0; i < inliers->indices.size(); i++) {
			PointType point = cloud_->points[inliers->indices[i]];
			augmented_corner->points.push_back(point);

		}
			int planes_number=countPlanes(augmented_corner);
		if ((planes_number == 4)
				|| (planes_number == 3))
			result.push_back(augmented_corner);
	}
	if (result.size() == 0)
		return false;
	else
		return true;

}

template<typename PointType> void PrimitivesExtract<PointType>::removePrimitive(
		const CloudConstPtr &cloud, pcl::PointIndices::Ptr &indices_to_remove,
		Cloud &result) {

	pcl::ExtractIndices<PointType> extract;
	extract.setInputCloud(cloud);
	extract.setIndices(indices_to_remove);
	extract.setNegative(true);

	extract.filter(result);

}

template<typename PointType> bool PrimitivesExtract<PointType>::extractLines(
		const CloudConstPtr &cloud, std::vector<CloudPtr> &result_vector,
		std::vector <pcl::ModelCoefficients::Ptr> &coefficients_vector, int lines_number) {

	pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
	pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
	pcl::PointIndices::Ptr extended_inliers(new pcl::PointIndices);

	CloudPtr nonline_cloud(new Cloud);

	if (cloud->size() == 0)
		return false;
	pcl::copyPointCloud(*cloud, *nonline_cloud);

	for (int number = 0;; number++) {

		if (lines_number > 0)
			if (number == lines_number)
				break;
		pcl::SACSegmentation<PointType> seg;
		seg.setOptimizeCoefficients(true);

		seg.setModelType(pcl::SACMODEL_LINE);
		seg.setMethodType(pcl::SAC_RANSAC);
		seg.setDistanceThreshold(line_distance_tresh_);

		seg.setInputCloud(nonline_cloud);
		seg.segment(*inliers, *coefficients);
		if (coefficients!=NULL)
			coefficients_vector.push_back(coefficients);
		if (inliers->indices.size() < min_line_inliers_) {
			PCL_ERROR(
					"Could not estimate a line model for the given dataset.");
			break;
		}
		CloudPtr one_line(new Cloud);
		for (size_t i = 0; i < inliers->indices.size(); i++) {
			PointType point = nonline_cloud->points[inliers->indices[i]];

			one_line->points.push_back(point);

			float radius = eliminate_line_neigh_radius_;
			int size;
			extractNeighbor(nonline_cloud, point, extended_inliers, size,
					radius);
			extended_inliers->indices.push_back(i);

		}
		std::sort(extended_inliers->indices.begin(),
				extended_inliers->indices.end());
		extended_inliers->indices.erase(
				std::unique(extended_inliers->indices.begin(),
						extended_inliers->indices.end()),
				extended_inliers->indices.end());
		result_vector.push_back(one_line);
		removePrimitive(nonline_cloud, extended_inliers, *nonline_cloud);
	}
	coefficients_vector.resize(result_vector.size());
	if (result_vector.size() == 0)
		return false;
	else
		return true;

}

template<typename PointType> void PrimitivesExtract<PointType>::extractNeighbor(
		const CloudConstPtr cloud, PointType &searchPoint,
		pcl::PointIndices::Ptr &inliers, int& size, float radius) {

	pcl::KdTreeFLANN<PointType> kdtree;

	kdtree.setInputCloud(cloud);

	std::vector<int> pointIdxRadiusSearch;
	std::vector<float> pointRadiusSquaredDistance;

	if (radius == 0)
		radius = extract_neigh_radius_;
	if (kdtree.radiusSearch(searchPoint, radius, pointIdxRadiusSearch,
			pointRadiusSquaredDistance) > 0) {
		for (size_t i = 0; i < pointIdxRadiusSearch.size(); ++i)

			inliers->indices.push_back(pointIdxRadiusSearch[i]);

	}

	size = (int) pointIdxRadiusSearch.size();

}

template<typename PointType> bool PrimitivesExtract<PointType>::extractPlane(
		const CloudConstPtr cloud, pcl::PointIndices::Ptr &inliers) {

	pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);

	if (cloud->size() == 0)
		return false;

	pcl::SACSegmentation<PointType> seg;
	// Optional
	seg.setOptimizeCoefficients(true);

	seg.setModelType(pcl::SACMODEL_PLANE);
	seg.setMethodType(pcl::SAC_RANSAC);
	seg.setDistanceThreshold(plane_distance_treshold_);

	seg.setInputCloud(cloud);
	seg.segment(*inliers, *coefficients);
	if (inliers->indices.size() < min_plane_inliers_) {
		PCL_ERROR( "Could not estimate a plane model for the given dataset.");
		return false;
	}

	return true;

}

template<typename PointType> int PrimitivesExtract<PointType>::countPlanes(
		const CloudConstPtr cloud) {
	pcl::PointIndices::Ptr inliers(new pcl::PointIndices);

	int number = 0;

	CloudPtr nonplane_cloud(new Cloud);
	pcl::copyPointCloud(*cloud, *nonplane_cloud);
	for (u_int i = 0; i < 6; i++) {

		inliers.reset(new pcl::PointIndices);

		if (extractPlane(nonplane_cloud, inliers)) {

			removePrimitive(nonplane_cloud, inliers, *nonplane_cloud);
			number++;
		} else
			return number;
	}

	return number;

}

template<typename PointType> bool PrimitivesExtract<PointType>::extractCorners(
		const CloudConstPtr cloud, Cloud &result, Cloud &result_debug,
		int number) {

	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_intensity(
			new pcl::PointCloud<pcl::PointXYZI>);
	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_intensity_after_treshhold(
			new pcl::PointCloud<pcl::PointXYZI>);

	pcl::HarrisKeypoint3D<PointType, pcl::PointXYZI>* harris3D =
			new pcl::HarrisKeypoint3D<PointType, pcl::PointXYZI>(
					pcl::HarrisKeypoint3D<PointType, pcl::PointXYZI>::HARRIS);
	harris3D->setNonMaxSupression(true);
//		 harris3D->setThreshold(0.0009);
//		 harris3D->setThreshold(0.00011);

	harris3D->setRadius(radius_harris_);
	harris3D->setRadiusSearch(radius_search_harris_);
	harris3D->setInputCloud(cloud);
	harris3D->setRefine(false);
	harris3D->setMethod(
			pcl::HarrisKeypoint3D<PointType, pcl::PointXYZI>::HARRIS);
	harris3D->compute(*cloud_intensity);

	if (cloud_intensity->size() > 0) {
		std::sort(cloud_intensity->points.begin(),
				cloud_intensity->points.end(), comparison_intens);
		if (number == 0) {
			int place = (int) (cloud_intensity->points.size()
					* best_intens_percent_);
			pcl::PointXYZI tresh_point = *(cloud_intensity->points.begin()
					+ place);
			float treshold = tresh_point.intensity;

			for (size_t i = 0; i < cloud_intensity->size(); ++i) {
				if (cloud_intensity->points[i].intensity > treshold)
					cloud_intensity_after_treshhold->points.push_back(
							cloud_intensity->points.at(i));
			}
		} else {
			if (number > cloud_intensity->size()) {
				PCL_ERROR("Number of corners is bigger than found corners.");
				return false;
			} else {

				for (size_t i = 0; i < number; ++i) {
					cloud_intensity_after_treshhold->points.push_back(
							cloud_intensity->points[i]);
				}
			}
		}

		pcl::copyPointCloud(*cloud_intensity_after_treshhold, result);
		pcl::copyPointCloud(result, result_debug);

		if (convex_corners_only_) {

			std::vector<int> neighbor_num;

			for (size_t j = 0; j < result.points.size(); j++) {

				pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
				int size;
				extractNeighbor(cloud, result.points[j], inliers, size);

				if (size > 0)
					neighbor_num.push_back(size);

			}
			double avg = 0;
			std::vector<int>::iterator it;
			for (it = neighbor_num.begin(); it != neighbor_num.end(); it++)
				avg += *it;
			avg /= neighbor_num.size();

			if (neighbor_num.size() == result.points.size()) {
				for (int n = 0; n < neighbor_num.size(); n++) {
					if (neighbor_num[n] > avg) {
						neighbor_num.erase(neighbor_num.begin() + n);
						result.points.erase(result.points.begin() + n);
					}
				}
			} else
				return false;

		} else {
			return false;
		}
	}
	result.width = result.points.size();
	result.height = 1;
	result.is_dense = false;

	return true;

}

