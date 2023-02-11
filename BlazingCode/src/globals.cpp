#include "main.h"
pros::Motor intake(14, pros::E_MOTOR_GEARSET_06, pros::E_MOTOR_ENCODER_COUNTS);
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Motor flywheel(10, pros::E_MOTOR_GEARSET_06, pros::E_MOTOR_ENCODER_COUNTS);
pros::ADIDigitalOut piston('H');
pros::ADIDigitalOut piston2('G');
pros::ADIDigitalOut piston3('F');
