#pragma once
#include "main.h"
#include "okapi/impl/device/button/adiButton.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
extern Controller controller;
extern ADIButton limitSwitch;
extern Motor catapult;
extern Motor intake;
extern IMU inertial;
extern Motor expansion;