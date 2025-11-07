#include "dc_motor.hpp"
#include "encoder.hpp"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/i2c.h"
#include "pico/cyw43_arch.h"


// Motor 1 pins
constexpr uint MOTOR_PWM_PIN1 = 15;
constexpr uint MOTOR_DIR_PIN1 = 2;
// Motor 2 pins
constexpr uint MOTOR_PWM_PIN2 = 14;
constexpr uint MOTOR_DIR_PIN2 = 3;

//Encoder 1 I2C0
constexpr uint ENCODER_SDA_PIN1 = 4;
constexpr uint ENCODER_SCL_PIN1 = 5;

// Encoder 2 I2C1
constexpr uint ENCODER_SDA_PIN2 = 6;
constexpr uint ENCODER_SCL_PIN2 = 7;




