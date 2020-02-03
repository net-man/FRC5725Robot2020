#pragma once

#include <vector>

#include <frc/PWMSpeedController.h>
#include <frc/Spark.h>
#include <frc/VictorSP.h>
#include <frc/Victor.h>
#include <frc/Talon.h>
#include <frc/Jaguar.h>
#include <rev/SparkMax.h>

#include <frc/DigitalInput.h>
#include <frc/DigitalOutput.h>

#include <frc/AnalogInput.h>

using namespace std;

#ifndef PWM_COUNT
#define PWM_COUNT 9
#endif

#ifndef DIO_COUNT
#define DIO_COUNT 9
#endif

#ifndef AIO_COUNT
#define AIO_COUNT 3
#endif

namespace hardware {
namespace {
vector<frc::PWM*> ptr_pwms = vector<frc::PWM*>(PWM_COUNT);
vector<frc::DigitalInput*> ptr_dio = vector<frc::DigitalInput*>(DIO_COUNT);
vector<frc::DigitalOutput*> ptr_do = vector<frc::DigitalOutput*>(DIO_COUNT);
vector<frc::AnalogInput*> ptr_ai = vector<frc::AnalogInput*>(AIO_COUNT);
}

bool addPWM(frc::PWM* pwm);
template <class T> T* getPWM(int pin);
template <> frc::PWM* getPWM<frc::PWM>(int pin);

/** @brief Removes a PWM from the PWM list by its pin.
 *
 * @param pin: the pin of the PWM that should be removed.
 * @return true: if the PWM is removed successfully.
 * @return false: if the PWM fails to get removed.
 *
 */
bool removePWM(int pin);

bool isPWMEmpty(int pin);

}  // namespace Hardware
