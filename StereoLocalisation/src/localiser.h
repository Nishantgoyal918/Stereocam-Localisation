#ifndef LOCALISER_H
#define LOCALISER_H

#include <ros/ros.h>
#include "stereo.h"

/**
 * Localiser Class  
 */
class Localiser {
public:

    /**
     * Default Constructor 
     */
    Localiser(ros::NodeHandle& node);

    ~Localiser();

    Stereo stereocam;

private:

    ros::NodeHandle& nh;

};

#endif