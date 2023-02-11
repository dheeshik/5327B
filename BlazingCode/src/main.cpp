#include "main.h"
#include <string>

// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {3, -2, 1}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{-13, 11, -12}

  // IMU Port
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


void run_intake() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    intake.move_velocity(-600);
    pros::lcd::set_text(6, "r1");

  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    intake.move_velocity(600);
    pros::lcd::set_text(6, "r2");
    flywheel.set_brake_mode(MOTOR_BRAKE_BRAKE); // brakes the flywheel if velocity set to 0
  }
  else {
     intake.move_velocity(0);
     pros::lcd::set_text(6, "0");
  }
}

void run_flywheel() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    flywheel.set_brake_mode(MOTOR_BRAKE_COAST);
    flywheel.move_velocity(600);
    pros::lcd::set_text(6, "L1");
  }

  /*else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    flywheel.move_velocity(400);
    pros::lcd::set_text(6, "L2");
  }*/

  else {
    flywheel.move_velocity(0);
    pros::lcd::set_text(6, "0");
  }
}

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

void indexerOff() {
}

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
/*
void initialize() {
  pros::ADIDigitalIn increase('A');
  pros::ADIDigitalIn decrease('B');
  // Print our branding over your terminal :D
  //ez::print_ez_template();

  //pros::delay(500); // Stop the user from doing anything while legacy ports configure.

  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)
  default_constants(); // Set the drive to your own constants from autons.cpp!
  exit_condition_defaults(); // Set the exit conditions to your own constants from autons.cpp!
  chassis.set_joystick_threshold(15);
  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used.
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.add_autons({
    Auton("Example Drive\n\nDrive forward and come back.", drive_example),
    Auton("Example Turn\n\nTurn 3 times.", turn_example),
    Auton("Drive and Turn\n\nDrive forward, turn, come back. ", drive_and_turn),
    Auton("Drive and Turn\n\nSlow down during drive.", wait_until_change_speed),
    Auton("Swing Example\n\nSwing, drive, swing.", swing_example),
    Auton("Combine all 3 movements", combining_movements),
    Auton("Interference\n\nAfter driving forward, robot performs differently if interfered or not.", interfered_example),
    Auton("Left Side Auton", l_auton),
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
}
*/

void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "I was pressed!");
  } else {
    pros::lcd::clear_line(2);
  }
}

void initialize()
{
  pros::screen::set_pen(COLOR_RED);
  pros::lcd::initialize();
  //pros::lcd::register_btn0_cb(on_center_button);
  //pros::lcd::set_text(7, "Hello World!");
  pros::lcd::print(6, "Goofy ah", pros::lcd::read_buttons());
  //pros::lcd::initialize();
  //ez::as::initialize();
  //ez::as::auton_selector.add_autons({
    //Auton("Autonomous 1\nDrive Example", drive_example),
    //Auton("Autonomous 2\nDrive And Turn", drive_and_turn),
    //Auton("Autonomous 3\nTurn Example", turn_example),
    //Auton("Autonomous 4\nLeft Autonoumous", l_auton),
  //});
  //ez::as::auton_selector.print_selected_auton();
  //pros::lcd::register_btn0_cb(ez::as::page_down);
  //pros::lcd::register_btn2_cb(ez::as::page_up);
  //ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
  // //l_auton();
}

void competition_initialize() {
  // . . .
}

void autonomous() {
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD);

  ez::as::auton_selector.call_selected_auton();
  //
  //l_auton();
  //rollerAuton();
  //goofyahAuton();
  //drive_example();
  //generatedAuton();
  skillsAuton();
}

void opcontrol() {
  // This is preference to what you like to drive on.
  chassis.set_active_brake(0.1); // Sets the active brake kP. We recommend 0.1.
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  flywheel.set_brake_mode(MOTOR_BRAKE_COAST); // lets flywheel freespin
  int iter = 0;
  while (true) {
    chassis.arcade_standard(ez::SPLIT);
    run_intake();
    run_flywheel();
    indexer();
    expansion();
    int right_Y = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    pros::lcd::set_text(7, std::to_string(right_Y));
  }
    pros::delay(ez::util::DELAY_TIME);
    }
