
// LES FICHIERS EN-TETE
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <tf/tf.h>
#include <tf2/LinearMath/Quaternion.h>

// LES NAMESPACES
using namespace ros;
using namespace std_msgs;
using namespace geometry_msgs;

// LE PROTOTYPE DES FONCTIONS
geometry_msgs::Vector3 quaternionToRPY(geometry_msgs::Quaternion q_angle);

// LES FONCTIONS CALLBACK ICI

// MAIN
int main(int argc, char **argv) {
  init(argc, argv, "localisation");
  NodeHandle nh;

  // subscribers ICI

  //
  spin();
  return 0;
}

// FONCTION DE CONVERSION QUATERNION => ANGLE D'EULER RPY [ RAW (ROTATION X),
//                                     PITCH (ROTATION Y), YAW (ROTATION Z) ]
geometry_msgs::Vector3 quaternionToRPY(geometry_msgs::Quaternion q_angle) {
  // the incoming geometry_msgs::Quaternion is transformed to a tf::Quaterion
  tf::Quaternion quat;
  tf::quaternionMsgToTF(q_angle, quat);

  // the tf::Quaternion has a method to acess roll pitch and yaw
  double roll, pitch, yaw;
  tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);

  // the found angles are written in a geometry_msgs::Vector3
  geometry_msgs::Vector3 rpy;
  rpy.x = roll;
  rpy.y = pitch;
  rpy.z = yaw;

  return rpy;
}
