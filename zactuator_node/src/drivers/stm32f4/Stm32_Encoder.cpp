#include "zan1/Stm32_Encoder.h"
#include "stm32g4xx_hal.h"

namespace zan1 {
    Stm32_Encoder::Stm32_Encoder(TIM_HandleTypeDef* encoder_htim) : m_encoder_htim(encoder_htim) {}

    float Stm32_Encoder::get_position() {
        return static_cast<float>(__HAL_TIM_GET_COUNTER(m_encoder_htim));
    }
}