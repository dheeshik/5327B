#include "main.h"
/*
#include "Vex.h"
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
void DheeshikConstants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 5, 1, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 5, 1, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
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
void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

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

void skillsAuton(){

}

void generatedAuton(){
  //first roller

  chassis.set_drive_pid(2.5, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.move_velocity(-600);
  pros::delay(700);
  intake.move_velocity(0);


  chassis.set_drive_pid(-5, DRIVE_SPEED, true);
  chassis.wait_drive();

  //////Move to second roller
  intake.move_velocity(600);
  chassis.set_turn_pid(135.0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(27, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  intake.move_velocity(0);


  ///// Second Roller
  flywheel.move_velocity (540);
  chassis.set_drive_pid(7.5, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.move_velocity(-600);
  pros::delay(500);
  intake.move_velocity(0);


  chassis.set_drive_pid(-5, DRIVE_SPEED, true);
  chassis.wait_drive();

  ///// Launch disks

  chassis.set_turn_pid(-3.6619355755198058, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-7, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(100);
  launchDisk();
  pros::delay(1500);
  launchDisk();
  pros::delay(1500);
  launchDisk();
  flywheel.move_velocity (-4);
  pros::delay(200);

///// Collect 3 disks
  intake.move_velocity(600);
  chassis.set_turn_pid(225, TURN_SPEED);
  flywheel.move_velocity(0);
  chassis.wait_drive();


  chassis.set_drive_pid(30, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(90);

  chassis.set_drive_pid(30, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(90);
  chassis.set_drive_pid(20,DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(90);
  chassis.set_turn_pid(-63, TURN_SPEED);
  chassis.wait_drive();
  intake.move_velocity(0);

///// Launch disks
  flywheel.move_velocity (540);
  pros::delay(2300);
  launchDisk();
  pros::delay(1500);
  launchDisk();
  pros::delay(1500);
  launchDisk();
  flywheel.move_velocity (-4);
  pros::delay(200);
  flywheel.move_velocity (0);

  chassis.set_drive_pid(30, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(67, TURN_SPEED);
  chassis.wait_drive();

  expand();

}

void rollerAuton(){
  chassis.set_drive_pid(4, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.move_velocity(-600);
  pros::delay(250);
  intake.move_velocity(0);


  chassis.set_drive_pid(-5, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(48, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, DRIVE_SPEED, true);
  chassis.wait_drive();

  //chassis.wait_drive();

  chassis.set_turn_pid(140, TURN_SPEED);
  chassis.wait_drive();

  intake.move_velocity(600);
  chassis.set_drive_pid(6, DRIVE_SPEED, true);
  chassis.wait_drive();
  pros::delay(1200);
  chassis.set_drive_pid(-3, DRIVE_SPEED, true);

  flywheel.move_velocity (600);
  intake.move_velocity(0);

  chassis.set_turn_pid(-28, TURN_SPEED);
  chassis.wait_drive();


  pros::delay(2500);
  launchDisk();
  pros::delay(1500);
  launchDisk();
  pros::delay(1500);
  launchDisk();
  pros::delay(1800);

  flywheel.move_velocity(0);

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


//Left Side Auton
void l_auton() {
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-61.25, DRIVE_SPEED, true);
  flywheel.move_velocity(600);
  chassis.wait_drive();

  chassis.set_turn_pid(-49, TURN_SPEED);
  chassis.wait_drive();


  pros::delay(2000);
  launchDisk();
  pros::delay(2000);
  launchDisk();
  pros::delay(2000);
  launchDisk();
  pros::delay(2000);

  flywheel.move_velocity(0);
}
void goofyahAuton(){
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(30, DRIVE_SPEED, true);
  //flywheel.move_velocity(600);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();
  intake.move_velocity(600);
  flywheel.move_velocity(600);
  chassis.set_drive_pid(10, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(200);

  intake.move_velocity(0);


  chassis.set_turn_pid(152, TURN_SPEED);
  chassis.wait_drive();

  pros::delay(2500);
  launchDisk();
  pros::delay(1750);
  launchDisk();
  pros::delay(1750);
  launchDisk();
  pros::delay(200);

  flywheel.move_velocity(0);

}
///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


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



// . . .
// Make your own autonomous functions here!
// . . .
