#include "main.h"

Motor catapult(19, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
MotorGroup intake(
    {Motor(18, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees), 
    Motor(10, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)});

void DevicesControl(void* _) {
    catapult.setBrakeMode(AbstractMotor::brakeMode::hold);

    while (true) {
        if (controller.getDigital(ControllerDigital::down)) {
            catapult.moveVoltage(12000);
        } else {
            catapult.moveVoltage(0);
        }

        if(controller.getDigital(ControllerDigital::L2)) {
            intake.moveVoltage(-12000);
        } else if (controller.getDigital(ControllerDigital::L1)) {
            intake.moveVoltage(12000);
        } else {
            intake.moveVoltage(0);
        }

        pros::delay(20);
    }
}


