#include "stereo.h"

Stereo::Stereo(ros::NodeHandle& node): nh(node){

    baseLinkTracking = "camera";
    worldTracking = "world";

    _main_thread = std::thread(&Stereo::localise, this);

}

Stereo::~Stereo(){

    _main_thread.join();

}

void Stereo::tracking() {

    tf::StampedTransform calculatedTransform;

    try {

        listener.lookupTransform(baseLinkTracking, worldTracking, ros::Time(0), calculatedTransform);
        optimise(calculatedTransform);

    }
    catch (tf::TransformException err) {
 	    
        ROS_ERROR("%s",err.what());
 	    ros::Duration(1.0).sleep();
 	
     }

}

void Stereo::optimise(tf::StampedTransform calculatedTransform){

    tf::Vector3 translationCalculated;
    translationCalculated = calculatedTransform.getOrigin();

    std::cout << translationCalculated.x() << " " << translationCalculated.y() << " " << translationCalculated.z() << std::endl;

    updateLocalMap();
}

void Stereo::updateLocalMap(){

}

void Stereo::localise() {

    ros::Rate rate(10.0);

    while(nh.ok()) {

        tracking();
        rate.sleep();
    }

}