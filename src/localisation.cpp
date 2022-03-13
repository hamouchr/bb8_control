
// LES FICHIERS EN-TETE
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <tf/tf.h>
#include <tf2/LinearMath/Quaternion.h>

using namespace geometry_msgs;

// LES NAMESPACES
using namespace ros;
using namespace std_msgs;
using namespace geometry_msgs;

// LE PROTOTYPE DES FONCTIONS
float quaternionToAngleEuler(Quaternion q_angle);

// VARIABLES GLOBALES


// LES FONCTIONS CALLBACK ICI


// MAIN
int main(int argc, char **argv) {
  init(argc, argv, "localisation");
  NodeHandle nh;

  // subscribers ICI




  spin();
  return 0;
}

// FONCTION DE CONVERSION QUATERNION => ANGLE D'EULER RPY [ RAW (ROTATION X),
//                                     PITCH (ROTATION Y), YAW (ROTATION Z) ]

float quaternionToAngleEuler(Quaternion angle_quaternion) {

float angle_Euler = tf::getYaw(angle_quaternion);
  
return angle_Euler;

}