#include "main.h"
#include <string>
// variable declarations
  float currentSpeed;
  float output;
  float error;
  float prevError;
  float gain = 2;
  float prevOutput;

void FlyTBH (int goal){
if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
  currentSpeed = flywheel.get_actual_velocity();
  error = goal - currentSpeed;
  output += gain * error;
//Checks L2 being pressed and updates global variables 

  if (std::signbit(error) != std::signbit(prevError)) {
    output = 0.5 * (output + prevOutput);
    prevOutput = output;
//Checks whether the output is higher than the goal or not and then TBH
  }
prevError = error; // updates previous error
flywheel.move_velocity(output); 
printf ("Speed: %F , Error: %F", currentSpeed, error); 
// prints speed and error
pros::delay(10);
} else {
    flywheel.move_velocity(0);
    prevError = 0;
    prevOutput = 0;
    output = 0;
// if L2 not pressed, resets flywheel and variables

}
}