#include "main.h"
/*
#include "Vex.h"
#include <iostream>
using namespace vex;
competition Competetion;
/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////*/


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int SLOW_SPEED = 50;
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

PID intakePID{1, 0.003, 4, 100, "Intake"};

///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.
/*
void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}
*/
void TunedPIDConstants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);

  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);

  chassis.set_pid_constants(&chassis.forward_drivePID, 5, 1, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 5, 1, 5, 0);

  chassis.set_pid_constants(&chassis.turnPID, 5, 0.1, 35, 15);

  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
  intakePID.set_exit_condition(100, 3, 500, 7, 500, 500);
}
void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 1, 1, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
  intakePID.set_exit_condition(100, 3, 500, 7, 500, 500);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}
// BASIC BUILDING BLOCK FUNCTIONS
  



void launchDisk(){
  bool pistonExtended;
  piston.set_value(true);
  pistonExtended = true;
  pros::delay(500);
  piston.set_value(false);
  pistonExtended = false;
}

void expand(){
  bool piston2Extended;
  bool piston3Extended;
  piston2.set_value(true);
  piston2Extended = true;
  piston3.set_value(true);
  piston3Extended = (true);
}

void timedShot(int goalRPM){
  flywheel.move_voltage(12000);
  while (flywheel.get_actual_velocity() < goalRPM){
    std::cout << "waiting for flywheel, current velocity = " << flywheel.get_actual_velocity() << "\n";
  }
  launchDisk();
  pros::delay(100);
}

// Autonomous Routines
void flywheelTest(){
  timedShot(470);
  timedShot(470);
  timedShot(470);
  flywheel.move_velocity(0);
}
void skillsAuton(){
  /*
  //Auton Was generated by Dheeshik's Cool Generator
  flywheel.set_brake_mode(MOTOR_BRAKE_BRAKE); // brakes the flywheel if velocity set to 0

  chassis.set_drive_pid(4, DRIVE_SPEED, true);
  chassis.wait_drive();

  // First Roller
  intake.move_relative(200, 300);
  pros::delay(1000);

  chassis.set_drive_pid(-4, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(131.7713521303644, TURN_SPEED);
  chassis.wait_drive();

  intake.move_velocity(600);
  chassis.set_drive_pid(28, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  intake.move_velocity(0);

  chassis.set_drive_pid(6, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Second Roller
  intake.move_relative(200, 300);
  pros::delay(500);

  flywheel.move_voltage(12000);

  chassis.set_drive_pid(-4, DRIVE_SPEED, true);
  chassis.wait_drive();


  chassis.set_turn_pid(1, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-5, DRIVE_SPEED);

  timedShot(470);
  timedShot(470);
  timedShot(470);
  flywheel.move_velocity (0);



  chassis.set_turn_pid(-135, TURN_SPEED);
  chassis.wait_drive();
  intake.move_velocity(600);
  chassis.set_drive_pid(67, SLOW_SPEED, true);
  chassis.wait_drive();
  intake.move_velocity(0);


  // SHOOTING SECOND TIME
  flywheel.move_velocity(12000);
  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid( 8, SLOW_SPEED, true);
  chassis.wait_drive();

  timedShot(400);
  timedShot(400);
  timedShot(400);
  flywheel.move_velocity (0);

  chassis.set_drive_pid(-5, SLOW_SPEED, true);
  chassis.wait_drive();

  // Expansion
  // chassis.set_turn_pid(45, TURN_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(-51, DRIVE_SPEED, true);
  // chassis.wait_drive();

  // chassis.set_turn_pid(38, TURN_SPEED);
  // chassis.wait_drive();

  // expand();


  //////// ADD EXTRA 2 Roller code
  chassis.set_turn_pid(-135, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(28, DRIVE_SPEED, true);
  chassis.wait_drive();
  pros::delay(100);

  intake.move_velocity(600);
  chassis.set_drive_pid(30, 50, true);
  chassis.wait_drive();
  pros::delay(300);
  intake.move_velocity(0);
  flywheel.move_velocity(12000);

  chassis.set_turn_pid(-92, TURN_SPEED);
  chassis.wait_drive();

  timedShot(470);
  timedShot(470);
  timedShot(470);
  flywheel.move_velocity(0);*/

  chassis.set_drive_pid(10, DRIVE_SPEED,true);
  chassis.wait_drive();
  chassis.set_turn_pid(-90.0, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(5, DRIVE_SPEED,true);
  intake.move_velocity(200);
  pros::delay(1000);
  intake.move_velocity(0);

  chassis.set_drive_pid(-5, DRIVE_SPEED, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-70,TURN_SPEED);
  chassis.wait_drive();
  expand();

  // chassis.set_drive_pid(30, DRIVE_SPEED, true);
  // chassis.wait_drive();
}

void generatedAuton(){
  //Auton Was generated by Dheeshik's Cool Generator
  chassis.set_angle(0);

  /// ROLLER
  chassis.set_drive_pid(4, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.move_absolute(10, 300);


  chassis.set_drive_pid(-4, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Drive to disk and knock over 3 stack
  chassis.set_turn_pid(45.0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-33.941125496954285, DRIVE_SPEED, true);
  chassis.wait_drive();


  // Intake Disk
  chassis.set_turn_pid(135.0, TURN_SPEED);
  chassis.wait_drive();

  intake.move_velocity(600);
  chassis.set_drive_pid(5, DRIVE_SPEED, true);
  chassis.wait_drive();

  flywheel.move_velocity (600);

  chassis.set_drive_pid(-5, DRIVE_SPEED, true);
  chassis.wait_drive();
  pros::delay(500);
  intake.move_velocity(0);


  // Shoot 3 disks
  chassis.set_turn_pid(-28, TURN_SPEED);
  chassis.wait_drive();

  timedShot(570);
  timedShot(570);
  timedShot(570);
  flywheel.move_velocity (0);


  intake.move_velocity(600);
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(6, DRIVE_SPEED, true);
  chassis.wait_drive();

  flywheel.move_velocity (600);
  chassis.set_turn_pid(-28, TURN_SPEED);
  chassis.wait_drive();
  intake.move_velocity(0);

  timedShot(470);
  flywheel.move_velocity (0);


}

// This is the close left side auton
void LeftAuton(){
  default_constants();
  chassis.set_drive_pid(3.5, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.move_absolute(-200, 300); //Rollers
  pros::delay(500);

  intake.move_velocity(0);

  chassis.set_drive_pid(-5, DRIVE_SPEED, true);
  chassis.wait_drive();


 // Move backward towards disk
  chassis.set_turn_pid(48, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();

  intake.move_velocity(600);
  
  flywheel.move_voltage(12000);
  chassis.set_drive_pid(6, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(1000);

  chassis.set_drive_pid(-6, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.move_velocity(0);

  
  chassis.set_turn_pid(-27.5, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(0, DRIVE_SPEED);


  timedShot(500);
  timedShot(500);
  timedShot(500);
  // pros::delay(1900);
  // launchDisk();
  // pros::delay(500);
  // launchDisk();
  // pros::delay(500);
  // launchDisk();

  flywheel.move_velocity(0);
  // intake.move_velocity(600);
  // chassis.set_turn_pid(-135.0, TURN_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(101.82337649086286, 127, true);
  // chassis.wait_drive();
  // intake.move_velocity(0);
  
  // Forth intake and shot
  // chassis.set_turn_pid(-135, TURN_SPEED);
  // intake.move_velocity(600);
  // chassis.wait_drive();

  // chassis.set_drive_pid(8, DRIVE_SPEED, true);
  // chassis.wait_drive();
  // pros::delay(300);

  // chassis.set_turn_pid(-27, TURN_SPEED);
  // chassis.wait_drive();
  // pros::delay(350);
  // launchDisk();
  // pros::delay(100);
  // flywheel.move_velocity(0);

}


void rightAuton(){
  //Auton Was generated by Dheeshik's Cool Generator
  chassis.set_angle(-180);

  chassis.set_drive_pid(22.0, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(4.5, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.move_absolute(-200,300);
  pros::delay(500);
  intake.move_velocity(0);

  chassis.set_drive_pid(-4, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(135.0, TURN_SPEED);
  chassis.wait_drive();

  flywheel.move_voltage(12000);
  intake.move_velocity(600);
  chassis.set_drive_pid(6, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(500);

  chassis.set_drive_pid(-4, DRIVE_SPEED, true);
  chassis.wait_drive();
  intake.move_velocity(0);

  
  chassis.set_turn_pid(-86.5, TURN_SPEED);
  chassis.wait_drive();

  timedShot(530);
  timedShot(530);
  timedShot(530);
  flywheel.move_velocity (0);

}

///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}

/*
vex::motor LeftMotor1 = motor(PORT1);
vex::motor LeftMotor2 = motor(Port2);
vex::motor Left Motor3 = motor(Port3);
vex::motor RightMotor1
*/

float wheelCircumference = (4.0 * 3.1415);

void goFWD(float distance, int speed){
  float MotorDegrees = (distance / wheelCircumference) * 360;
}




///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at
  TunedPIDConstants();

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}
