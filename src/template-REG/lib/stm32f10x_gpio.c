#include "stm32f10x_gpio.h"
#include "stdint.h"

/*
    设置 GPIOx_ODR
    仅会将ODR中GPIO_Pin为1的位设置为1
*/
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    // BSRR为1的位会设置GPIOx_ODR对应位为1
    GPIOx->BSRR |= GPIO_Pin;
}