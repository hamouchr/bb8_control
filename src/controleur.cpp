//-- LES FICHIERS EN-TETES
#include <csignal>
#include <math.h>
#include <ros/ros.h>
#include <std_msgs/String.h>

// LES NAMESPACES
using namespace ros;
using namespace std_msgs;

// LES CONSTANTES
#define MAX_UINT 65535
#define MODE_CIRCULAIRE 1
#define MODE_RECTANGULAIRE 2
#define LINEAR_SPEED 0.6
#define ANGULAR_SPEED 0.6
#define FREQ_CONTROL 10 // hz

// LES VARIABLES GLOBALES
int mode;


// LES PROTOTYPES DE FONCTIONS
void sigintHandler(int sig);


// LES FONCTIONS ET LES CALLBACKS
void avancer(float lin_vel) {

}

void stop() {

}

void pivoter(float ang_vel) {

}

void reculer(float lin_vel) { 

}

void drive(float lin_vel, float ang_vel) {

}

void mouvement_rectangulaire(unsigned int iteration) {

}

void mouvement_circulaire(unsigned int iteration) {
	
}

void mouvement_avancer_reculer(unsigned int iteration) {
	
}

// MAIN DE L'APPLICATION
int main(int argc, char **argv) {
  signal(SIGINT, sigintHandler);
  init(argc, argv, "controleur", ros::init_options::NoSigintHandler);

  NodeHandle nh;




  Rate loop_rate(FREQ_CONTROL);
  unsigned int iteration = 1;

  while (ok()) {




    iteration = (iteration + 1) % MAX_UINT;
    ROS_INFO("iteration %d", iteration);
    spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

void sigintHandler(int sig) {
  // Log quit
  ROS_INFO("Exiting program gracefully ...");
  stop();
  // Kill all open subscriptions, publications, service calls, and service
  // servers
  shutdown();
}