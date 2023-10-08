#ifndef __LIB_STM32F10X_GPIO_H
#define __LIB_STM32F10X_GPIO_H
#include "stm32f10x.h"
// 用来定义GPIO相关功能
void GPIO_SetBits(GPIO_Type *, uint16_t);
void GPIO_ResetBits(GPIO_Type *, uint16_t);
#endif /* __LIB_STM32F10X_GPIO_H */
