#ifndef POINTCLOUDOPERATIONS_H
#define POINTCLOUDOPERATIONS_H

#include <ros/ros.h>

/**
 * Point Cloud Operations Class  
 */
class PointCloudOperations {
public:

    /**
     * Default Constructor 
     */
    PointCloudOperations(ros::NodeHandle& node);

    ~PointCloudOperations();


private:

    ros::NodeHandle& nh;


public:

    /**
     * 
     */
    void transform();

    /**
     * Function to find the local map corresponding to current position
     */
    void outTreeSearch();
};

#endif