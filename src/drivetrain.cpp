#include "main.h"

std::shared_ptr<ChassisController> chassis = 
    ChassisControllerBuilder()
        .withMotors(-15, 12, 11, -14)
        .withDimensions(AbstractMotor::gearset::green, {{4_in, 12_in}, imev5GreenTPR})
        .build();

std::shared_ptr<XDriveModel> driveTrain = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());


void DrivetrainControl(void *_) {
    driveTrain->setBrakeMode(AbstractMotor::brakeMode::coast);

    while (true) {
        driveTrain->xArcade(controller.getAnalog(ControllerAnalog::leftX), controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightX), 0);

        pros::delay(20);
    }
}