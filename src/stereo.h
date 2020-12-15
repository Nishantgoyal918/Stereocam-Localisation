#ifndef STEREO_H
#define STEREO_H

#include <ros/ros.h>

class Stereo{
    public:
        /**
         * Default Constructor
         **/
        Stereo(ros::NodeHandle& node);

        ~Stereo();

        /**
         * Function to run the stereo localisation pipeline
         **/ 
        void localise();
    
    private:
        ros::NodeHandle& nh;

        /**
         * Function to implement the tracking algo to 
         * get non optimised localisation values
         **/ 
        void tracking();

        /**
         * Function to optimise the output from tracking algo
         * using ceres solver
         **/ 
        void optimise();

        /**
         * Function to update the surrounding map of the car 
         * from the world map while is is moving
         **/
        void updateLocalMap();
};

#endif