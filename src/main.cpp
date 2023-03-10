#include "main.h"

/* Globals */
Controller controller(ControllerId::master);

std::shared_ptr<ChassisController> chassis = 
    ChassisControllerBuilder()
        .withMotors(-15, 12, 11, -14)
        .withDimensions(AbstractMotor::gearset::green, {{4_in, 12_in}, imev5GreenTPR})
        .build();

std::shared_ptr<XDriveModel> driveTrain = std::dynamic_pointer_cast<XDriveModel>(chassis->getModel());

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	driveTrain->stop();

	driveTrain->driveVectorVoltage(-15, 0);
	pros::delay(10);
	driveTrain->stop();

	intake.moveVoltage(12000);
	pros::delay(750);
	intake.moveVoltage(0);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Task drivetrainControl(DrivetrainControl, (void*) "", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Drivetrain Task");

	pros::Task devicesControl(DevicesControl, (void *)"", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Devices Control");

	while (true) {
		pros::delay(20);
	}
}
