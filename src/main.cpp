#include "localiser.h"

int main(int argc, char** argv) {

    ros::init(argc, argv, "stereocam_localisation");
    
    ros::NodeHandle nh("~");

    Localiser LO(nh);

    ROS_INFO("\033[1;32m---->\033[0m STEREOCAM-LOCALISATION Started.");

    ros::shutdown();

    return 0;
}