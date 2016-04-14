#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#ifndef CLUSTERING_H
#define CLUSTERING_H


class clustering
{
public:
    clustering();
    static void cloudColorSegmentation(pcl::PointCloud<pcl::PointXYZRGB> ::Ptr my_cloud);
    static void sortPointsByColor();
    static void addPointXYZRGBoVector(pcl::PointXYZRGB my_crt_point);

private:
    static std::map<Eigen::Vector3i, pcl::PointCloud<pcl::PointXYZRGB> ::Ptr> color_map;
    static std::vector<pcl::PointXYZRGB> point_cloud_vct;
    static std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr> point_clouds;

    static void addingOfNeighbours(pcl::PointXYZRGB my_crt_point, pcl::PointCloud<pcl::PointXYZRGB> ::Ptr new_cloud);
    static void sortPointsByCoordinates();
    static bool checkIfPointAlreadySorted(pcl::PointXYZRGB my_crt_point, pcl::PointCloud<pcl::PointXYZRGB> ::Ptr my_cloud);
    static void createNewCloud(pcl::PointXYZRGB my_crt_point, Eigen::Vector3i point_color);
    static pcl::PointXYZRGB getRNDPoint(pcl::PointCloud<pcl::PointXYZRGB> ::Ptr my_cloud);
};

#endif // CLUSTERING_H
