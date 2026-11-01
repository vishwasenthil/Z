#include "Stm32_Pwm.h"
#include "Stm32_Encoder.h"
#include "zan1/Motor.h"
#include "stm32g4xx_hal.h"

namespace zan1 {
    TIM_HandleTypeDef* pwm_htim = nullptr;
    TIM_HandleTypeDef* encoder_htim = nullptr;

    Stm32_Pwm pwm_driver(pwm_htim);
    Stm32_Encoder encoder_driver(encoder_htim);

    using MotorType = Motor<Stm32_Pwm, Stm32_Encoder>;
    MotorType motor(pwm_driver, encoder_driver);

    MotorType& get_motor() {
        return motor;
    }
}