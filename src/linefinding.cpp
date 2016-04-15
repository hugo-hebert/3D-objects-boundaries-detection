#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <vector>
#include <pcl/common/io.h>
#include <iostream>
#include <pcl/filters/extract_indices.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/sample_consensus/sac_model_sphere.h>

void lineFindingAlgo(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud){
    std::vector<int> inliers;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloudTemp (new pcl::PointCloud<pcl::PointXYZ>);

    pcl::SampleConsensusModelPlane<pcl::PointXYZ>::Ptr model_p (new pcl::SampleConsensusModelPlane<pcl::PointXYZ> (cloud));

    pcl::RandomSampleConsensus<pcl::PointXYZ> ransac (model_p);
    ransac.setDistanceThreshold (.01);
    ransac.computeModel();
    ransac.getInliers(inliers);


    // copies all inliers of the model computed to another PointCloud
    pcl::copyPointCloud<pcl::PointXYZ>(*cloud, inliers, *cloudTemp);
    cloud->clear();
    pcl::copyPointCloud<pcl::PointXYZ>(*cloudTemp, inliers, *cloud);

}
