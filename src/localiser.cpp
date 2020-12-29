#include "localiser.h"

Localiser::Localiser(ros::NodeHandle& node) : nh(node), stereocam(node) {

    //stereocam(nh);
}

Localiser::~Localiser() {

}