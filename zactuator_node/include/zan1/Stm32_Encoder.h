#pragma once

#include "stm32g4xx_hal.h"

namespace zan1 {
    class Stm32_Encoder {
        public:
            Stm32_Encoder(TIM_HandleTypeDef* encoder_htim);
            float get_position();

        private:
            TIM_HandleTypeDef* m_encoder_htim;
    };
}