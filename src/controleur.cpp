// LES FICHIERS EN-TETES
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <ros/ros.h>
#include <std_msgs/String.h>

// LES NAMESPACES
using namespace ros;
using namespace std_msgs;
using namespace geometry_msgs;

// LES CONSTANTES
#define MODE_CIRCULAIRE 1
#define MODE_RECTANGULAIRE 2
#define LINEAR_SPEED 0.8
#define ANGULAR_SPEED 0.8
#define FREQ_CONTROL 10 // hz

// LES VARIABLES GLOBALES
Twist cmd;
Publisher cmd_pub;
int mode;

// LES FONTIONS ET LES CALLBACKS
void avancer(float lin_vel) {}

void reculer(float lin_vel) {}

void pivoter(float ang_vel) {}

void stop() {}

void drive(float lin_vel, float ang_vel) {}

void mouvement_circulaire() {}

void mouvement_rectangulaire() {}

// MAIN DE L'APPLICATION
int main(int argc, char **argv) {

  init(argc, argv, "controleur");
  NodeHandle nh;

  cmd_pub = nh.advertise<Twist>("/cmd_vel", 100);

  Rate loop_rate(FREQ_CONTROL);

  while (ok()) {

    mouvement_rectangulaire();

    //
    spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
