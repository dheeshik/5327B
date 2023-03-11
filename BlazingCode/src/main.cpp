#include "main.h"
#include <string>

/**
 * The constructor for the ChassisControllerPID class through the EZ-Template library
*/
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {3, -2, 1}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{-13, 11, -12}

  // IMU (Intertial Mass Unit) Port
  ,5

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,4.125

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,200

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,1

  // Uncomment if using tracking wheels

  // Left Tracking Wheel Ports (negative port will reverse it!)
  //,{1, 2} // 3 wire encoder
  // ,8 // Rotation sensor

  // Right Tracking Wheel Ports (negative port will reverse it!)
  //,{-3, -4} // 3 wire encoder
  // ,-9 // Rotation sensor


  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  // ,1
);




/**
 * This function is for the intake subsystem of the robot
 * It detects the button pressed on the controller and runs the intake motor at the desired velocity of 600 rpm
*/
void run_intake() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { // run intake forward
    intake.move_velocity(-600);
    pros::lcd::set_text(6, "r1");
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { // run intake backward when the other right trigger is pressed
    intake.move_velocity(600);
    pros::lcd::set_text(6, "r2");
    // When intakeing disks, the flywheel motor will be set to the brake mode to stop disks from flying out the back of the robot
    flywheel.set_brake_mode(MOTOR_BRAKE_BRAKE); 
  }
  else {
     intake.move_velocity(0); // if neither bumper is pressed then stop the intake
     pros::lcd::set_text(6, "0");
  }
}

/**
 * This functions detects the button pressed on the controller and runs the flywheel motor at the desired velocity of 600 rpm
*/
void run_flywheel() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    flywheel.set_brake_mode(MOTOR_BRAKE_COAST);
    flywheel.move_velocity(600);
    pros::lcd::set_text(6, "L1");
  }
  else { // when the button is not pressed, the flywheel motor is set to 0 rpm but will still be in the coast mode
    flywheel.move_velocity(0);
    pros::lcd::set_text(6, "0");
  }

  // std::cout << "Flywheel Velocity: "<< std::to_string(flywheel.get_actual_velocity()) << "\n";
  controller.set_text(0, 0, std::to_string(flywheel.get_actual_velocity()));
}

/*
void TakeBackHalf(int goal){
  currentSpeed = flywheel.get_actual_velocity();

  error = goal - currentSpeed;
  output = gain * error + output;
  if (error < 0){
    output = 0.5 * (prevOutput + output);
  }
  prevOutput = output;
  flywheel.move_voltage(output*20);
  cout << "Current Flywheel Voltage is: " << output * 20 << " Milivolts\n" << "Current Velocity: " << currentSpeed;
}
*/

/**
 * This function detects the button pressed on the controller's B button and extends the indexer piston to shoot the disk
 * only when the button is realeased will the piston retract
*/
void indexer() {
  bool pistonExtended;
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
    piston.set_value(true);
    pros::lcd::set_text(6, "B");
    pistonExtended = true;
  }
  else{
    piston.set_value(false);
    pros::lcd::set_text(6, "A");
    pistonExtended = false;
  }
}

/**
 * This function detects the button pressed on the controller's Y button and extends the the two pistons on the expansion mechanism
*/
void expansion() {
  bool piston2Extended;
  bool piston3Extended;
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
    piston2.set_value(true);
    piston3.set_value(true);
    pros::lcd::set_text(6, "Y");
    piston2Extended = true;
    piston3Extended = true;
  }
  else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
    piston2.set_value(false);
    piston3.set_value(false);
    pros::lcd::set_text(6, "B");
    piston2Extended = false;
    piston3Extended = false;
  }
}

/**
 * Initializes the robot and sets up the LCD
*/
void initialize() {
  pros::screen::set_pen(COLOR_RED);
  pros::lcd::initialize();
  pros::lcd::print(6, "Hello World", pros::lcd::read_buttons());
}

/***/
// void competition_initialize() { // runs before the standard initialize function starts
//   // . . .
// }

/**
 * This function first sets up the standard constants and settings for the robot to use during it's autonoumous routines
 * Then, depending on the autonoumous routine selected, the robot will run the desired autonoumous routine
*/
void autonomous() {
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD);


  // Uncomment the autonomous routine you want to run (Remember to only uncomment one at a time)
  //flywheelTest();
  //LeftAuton();
  //drive_example();
  //generatedAuton();
  skillsAuton();
  //flywheelTest();
  //turn_example();
  //swing_example();
}

/**
 * This function in run during Operator Control
 * it contains the main loop for the robot's movement, and subsystems
*/
void opcontrol() {
  // This is preference to what you like to drive on.
  chassis.set_active_brake(0.1); // Sets the active brake kP. We recommend 0.1.
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  flywheel.set_brake_mode(MOTOR_BRAKE_COAST); // lets flywheel freespin
  while (true) { // This is the main loop for the robot where all the subsystems are called
    chassis.arcade_standard(ez::SPLIT); // This is the drive function implemented by EZ-Template
    run_intake();
    run_flywheel();
    indexer();
    expansion();
    int right_Y = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    pros::lcd::set_text(7, std::to_string(right_Y));

  }
  pros::delay(ez::util::DELAY_TIME);
}
