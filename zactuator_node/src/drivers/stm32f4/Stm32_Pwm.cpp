#include "zan1/Stm32_Pwm.h"
#include "stm32g4xx_hal.h"

namespace zan1 {
    Stm32_Pwm::Stm32_Pwm(TIM_HandleTypeDef* pwm_htim) : m_pwm_htim(pwm_htim) {}

    void Stm32_Pwm::set_duty_cycle(uint32_t percent) {
        
    }
}