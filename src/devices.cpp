#include "main.h"

Motor catapult(19, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);

void DevicesControl(void* _) {
    catapult.setBrakeMode(AbstractMotor::brakeMode::hold);

    while (true) {
        if (controller.getDigital(ControllerDigital::down)) {
            catapult.moveVoltage(12000);
        } else {
            catapult.moveVoltage(0);
        }

        pros::delay(20);
    }
}


