#include <frc2020/components/DriveTrain.h>
#include <cerberus/Hardware.h>
#include <cerberus/Settings.h>

#include <frc/Spark.h>

#include <stdio.h>

namespace frc2020 {
DriveTrain::DriveTrain() {}

DriveTrain::~DriveTrain() {}

void DriveTrain::initialize() {
    // cfg::load(settingsPath);

    cfg::get<int>("hardware::motor_right1::pin", pin_right1);
    cfg::get<int>("hardware::motor_right2::pin", pin_right2);
    cfg::get<int>("hardware::motor_left1::pin", pin_left1);
    cfg::get<int>("hardware::motor_left2::pin", pin_left2);

    pin_right1 = 7;
    // pin_right2 = 2;
    pin_left1 = 3;
    pin_left2 = 4;

    motor_right1 = new frc::Spark(pin_right1);
    // motor_right2 = new frc::Spark(pin_right2);
    motor_left1 = new frc::Spark(pin_left1);
    motor_left2 = new frc::Spark(pin_left2);

	m_isInitialized = true;
}
void DriveTrain::deinitialize() {
	delete motor_right1;
	// delete motor_right2;
	delete motor_left1;
	delete motor_left2;

	m_isInitialized = false;
}

void DriveTrain::driveArcade(const double& speed, const double& turn) {
    driveTank(speed + turn, speed - turn);
}

void DriveTrain::driveTank(const double& right, const double& left) {
    // TODO: Make right and left speed class variables so they can be manipulateed outside of driveTank.
    motor_right1->SetSpeed(right);
    // motor_right2->SetSpeed(right);

    motor_left1->SetSpeed(left);
    motor_left2->SetSpeed(left);

    std::cout << "drivetrain r:" << right << " l:" << left << std::endl;
}

void DriveTrain::update() {}

}  // namespace frc2020