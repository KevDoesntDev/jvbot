#include "devices.hpp"
#include "main.h"
#include "okapi/impl/device/button/adiButton.hpp"
Motor expansion(16, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
Motor catapult(19, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
Motor intake(20, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
IMU inertial(10);
ADIButton limitSwitch ('H', false);
void DevicesControl(void* _) {
    catapult.setBrakeMode(AbstractMotor::brakeMode::hold);
//code for manual catapult
   /* while (true) {
        if (controller.getDigital(ControllerDigital::down)) {
            catapult.moveVoltage(12000);
        } else {
            catapult.moveVoltage(0);
        }
        pros::delay(20);
    }
    */
    //AUTOMATIC CATAPULT 
    while(true){
       if (!limitSwitch.isPressed() || controller.getDigital(ControllerDigital::R2)) {
            catapult.moveVoltage(12000);
        } else {
            // The limit switch is being pressed AND R2 isnt pressed
            catapult.moveVoltage(0);
        }

        if(controller.getDigital(ControllerDigital::L2)){
           intake.moveVoltage(-12000);
        } else if(controller.getDigital(ControllerDigital::L1)) {
            intake.moveVoltage(12000);
        } else {
            intake.moveVoltage(0);
        }

        if(controller.getDigital(ControllerDigital::X)){
            if(controller.getDigital(ControllerDigital::left)){
               
               expansion.moveVoltage(12000);
            }
        } else {
            expansion.moveVoltage(0);
        }

        pros::delay(20);
    }
}