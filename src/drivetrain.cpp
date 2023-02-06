#include "main.h"

void DrivetrainControl(void *_) {
    driveTrain->setBrakeMode(AbstractMotor::brakeMode::coast);

    while (true) {
        driveTrain->xArcade(controller.getAnalog(ControllerAnalog::leftX), controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightX), 0);

        pros::delay(20);
    }
}