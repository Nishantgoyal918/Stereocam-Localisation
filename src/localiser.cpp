#include "localiser.h"

Localiser::Localiser(ros::NodeHandle& node) : nh(node) {

    stereocam(nh);
}

Localiser::~Localiser() {

}