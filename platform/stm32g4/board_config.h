#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include "stm32g4xx_hal.h"

#define I_SENSE_A_Pin GPIO_PIN_0
#define I_SENSE_A_GPIO_Port GPIOA
#define I_SENSE_C_Pin GPIO_PIN_1
#define I_SENSE_C_GPIO_Port GPIOA
#define V_BUS_SENSE_Pin GPIO_PIN_2
#define V_BUS_SENSE_GPIO_Port GPIOA
#define T_SENSE_Pin GPIO_PIN_3
#define T_SENSE_GPIO_Port GPIOA
#define PWM_UL_Pin GPIO_PIN_7
#define PWM_UL_GPIO_Port GPIOA
#define PWM_VL_Pin GPIO_PIN_0
#define PWM_VL_GPIO_Port GPIOB
#define PWM_WL_Pin GPIO_PIN_1
#define PWM_WL_GPIO_Port GPIOB
#define PWM_UH_Pin GPIO_PIN_8
#define PWM_UH_GPIO_Port GPIOA
#define PWM_VH_Pin GPIO_PIN_9
#define PWM_VH_GPIO_Port GPIOA
#define PWM_WH_Pin GPIO_PIN_10
#define PWM_WH_GPIO_Port GPIOA

#endif