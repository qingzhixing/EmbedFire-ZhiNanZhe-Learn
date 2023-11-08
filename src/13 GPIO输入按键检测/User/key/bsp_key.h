#ifndef __KEY_BSP_KEY_H
#define __KEY_BSP_KEY_H

#include "stdint.h"
#include "stm32f10x.h"
typedef enum
{
    KEY_OFF = 0,
    KEY_ON = !KEY_OFF
} KeyState;

#define KEY1_GPIO_CLK RCC_APB2Periph_GPIOA
#define KEY1_GPIO_PORT GPIOA
#define KEY1_GPIO_PIN GPIO_Pin_0

#define KEY2_GPIO_CLK RCC_APB2Periph_GPIOC
#define KEY2_GPIO_PORT GPIOC
#define KEY2_GPIO_PIN GPIO_Pin_13

void KEY_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
#endif /* __KEY_BSP_KEY_H */
