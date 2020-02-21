#pragma once

#include <frc2020/components/Intake.h>
#include <cerberus/Hardware.h>
#include <cerberus/Settings.h>

#include <frc/Spark.h>

namespace frc2020 {
Intake::Intake() { }
Intake::~Intake() { }

void Intake::initialize() {
    cfg::get<int>("hardware::motor_intake1::channel", channel);
    cfg::get<double>("hardware::motor_intake1::set_speed", speed);
    
    channel = 6;
	speed = 1.0;

    motor = new frc::Spark(channel);
}

void Intake::deinitialize() {
    delete motor;
}
void Intake::update() {
    if(m_isOn == true) {
        motor->SetSpeed(speed);
    }
	else {
		motor->StopMotor();
	}
}

void Intake::toggle(bool isOn) {
    m_isOn = isOn;
}

}  // namespace frc2020