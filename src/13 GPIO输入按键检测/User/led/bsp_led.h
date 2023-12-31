#ifndef __LED_BSP_LED_H
#define __LED_BSP_LED_H

#include "stm32f10x.h"

#define LED_G_GPIO_PIN GPIO_Pin_0
#define LED_R_GPIO_PIN GPIO_Pin_5
#define LED_B_GPIO_PIN GPIO_Pin_1
#define LED_GPIO_PORT GPIOB
#define LED_GPIO_CLK RCC_APB2Periph_GPIOB

#define LED_TOGGLE(LED_PIN)              \
    {                                    \
        LED_GPIO_PORT->ODR ^= (LED_PIN); \
    }

#define LED_ON(LED_PIN)                 \
    {                                   \
        LED_GPIO_PORT->BRR = (LED_PIN); \
    }

#define LED_OFF(LED_PIN)                 \
    {                                    \
        LED_GPIO_PORT->BSRR = (LED_PIN); \
    }

void LED_GPIO_Config(void);

#endif /* __LED_BSP_LED_H */
