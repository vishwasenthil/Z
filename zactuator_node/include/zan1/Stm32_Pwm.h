#pragma once

#include "stm32g4xx_hal.h"

namespace zan1 {
    class Stm32_Pwm {
        public:
            Stm32_Pwm(TIM_HandleTypeDef* pwm_htim);
            void set_duty_cycle(uint32_t percent);

        private:
            TIM_HandleTypeDef* m_pwm_htim;
    };
}