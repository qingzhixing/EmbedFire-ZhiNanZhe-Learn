#ifndef __LIB_STM32F10X_GPIO_H
#define __LIB_STM32F10X_GPIO_H
#include "stm32f10x.h"
// 用来定义GPIO相关功能
#pragma region 定义GPIO_PIN
#define GPIO_PIN_x(index) (uint16_t(1 << index))
#define GPIO_PIN_0 GPIO_PIN_x(0)
#define GPIO_PIN_1 GPIO_PIN_x(1)
#define GPIO_PIN_2 GPIO_PIN_x(2)
#define GPIO_PIN_3 GPIO_PIN_x(3)
#define GPIO_PIN_4 GPIO_PIN_x(4)
#define GPIO_PIN_5 GPIO_PIN_x(5)
#define GPIO_PIN_6 GPIO_PIN_x(6)
#define GPIO_PIN_7 GPIO_PIN_x(7)
#define GPIO_PIN_8 GPIO_PIN_x(8)
#define GPIO_PIN_9 GPIO_PIN_x(9)
#define GPIO_PIN_10 GPIO_PIN_x(10)
#define GPIO_PIN_11 GPIO_PIN_x(11)
#define GPIO_PIN_12 GPIO_PIN_x(12)
#define GPIO_PIN_13 GPIO_PIN_x(13)
#define GPIO_PIN_14 GPIO_PIN_x(14)
#define GPIO_PIN_15 GPIO_PIN_x(15)
#define GPIO_PIN_ALL 0xFFFF
#pragma endregion

void GPIO_SetBits(GPIO_TypeDef *, uint16_t);
void GPIO_ResetBits(GPIO_TypeDef *, uint16_t);
#endif /* __LIB_STM32F10X_GPIO_H */
