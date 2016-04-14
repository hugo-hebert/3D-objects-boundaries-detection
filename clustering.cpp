/* Author : Kévin Naudin
 * Version : 1.0
 * Made for the I3 Mainz laboratory under GPL license
 */

#include "clustering.h"

clustering::clustering()
{

}

//This algorithm classifies points according to their colors and coordinates
//then create one point cloud per grouping
void clustering::cloudColorSegmentation(pcl::PointCloud<pcl::PointXYZRGB> ::Ptr my_cloud)
{
    pcl::PointXYZRGB my_crt_point;

    //While we still have points to sort
    while(point_cloud_vct.size() != 0)
    {
        //Get a random point in the cloud and its color
        my_crt_point = getRNDPoint(my_cloud);
        Eigen::Vector3i point_color = my_crt_point.getRGBVector3i();

        //If our map already contains a key for this color, then there's a chance the point has already been sorted
        if(color_map.find(point_color) != color_map.end())
        {
            //We see if the point is contained in the cloud obtained by the map
            if(checkIfPointAlreadySorted(my_crt_point, my_cloud))
            {
                //The point has already been sorted, there's no need to sort it again
                cloudColorSegmentation(my_cloud);
            }
            else
            {
                createNewCloud(my_crt_point, point_color);
            }
        }
        else
        {
            createNewCloud(my_crt_point, point_color);
        }
    }
}

void clustering::createNewCloud(pcl::PointXYZRGB my_crt_point, Eigen::Vector3i point_color)
{
    //The point hasn't been sorted so it must be in another segment of the main cloud
    //We will create a new cloud for this point and its neighbours
    pcl::PointCloud<pcl::PointXYZRGB> ::Ptr new_cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
    color_map[point_color] = new_cloud;
    //We then add all its neighbours and itself in this new cloud
    addingOfNeighbours(my_crt_point, new_cloud);
    //We add the newly filled cloud to a vector containing every other cloud
    point_clouds.push_back(new_cloud);
}

//Using a new cloud, we insert the neighbours of our current point and of the same color in it
void clustering::addingOfNeighbours(pcl::PointXYZRGB my_crt_point, pcl::PointCloud<pcl::PointXYZRGB> ::Ptr new_cloud)
{
    //TO-DO
}

void clustering::sortPointsByColor()
{
    //TO-DO
}

void clustering::sortPointsByCoordinates()
{
    //TO-DO
}

void clustering::addPointXYZRGBoVector(pcl::PointXYZRGB my_crt_point)
{
    point_cloud_vct.push_back(my_crt_point);
}

bool clustering::checkIfPointAlreadySorted(pcl::PointXYZRGB my_crt_point, pcl::PointCloud<pcl::PointXYZRGB> ::Ptr my_cloud)
{
    bool pointAlreadySorted = false;
    //TO-DO
    return pointAlreadySorted;
}

pcl::PointXYZRGB clustering::getRNDPoint(pcl::PointCloud<pcl::PointXYZRGB> ::Ptr my_cloud)
{
    //TO-DO
}
