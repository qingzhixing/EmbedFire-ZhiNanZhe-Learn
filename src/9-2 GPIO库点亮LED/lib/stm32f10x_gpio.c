#include "stm32f10x_gpio.h"
#include "stdint.h"

/*
    设置 GPIOx_ODR
    仅会将ODR中GPIO_Pin为 1 的位设置为 1
*/
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    // BSRR低16位中:为1的位会设置GPIOx_ODR对应位为1
    GPIOx->BSRR |= GPIO_Pin;
}

/*
    设置 GPIOx_ODR
    仅会将ODR中GPIO_Pin为 1 的位设置为 0
*/
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->BRR |= GPIO_Pin;
}