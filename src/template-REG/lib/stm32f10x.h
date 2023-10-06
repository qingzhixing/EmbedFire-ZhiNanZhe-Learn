#ifndef __LIB_STM32F10X_H
#define __LIB_STM32F10X_H
#include "stdint.h"
// 用来存储 stm32f10x 的寄存器映射

// 外设基地址
#define PERIPHERAL_BASE ((uint32_t)0x40000000)

// 外设三个类型
#define APB1_PERIPHERAL_BASE PERIPHERAL_BASE
#define APB2_PERIPHERAL_BASE (PERIPHERAL_BASE + 0x10000)
// 实际上AHB从SDIO(PERIPHERAL_BASE + 0x18000)开始，为了方便计算，取 + 0x20000
#define AHB_PERIPHERAL_BASE (PERIPHERAL_BASE + 0x20000)

/* GPIO结构:
    typedef struct
    {
    __IO uint32_t CRL;
    __IO uint32_t CRH;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t BRR;
    __IO uint32_t LCKR;
    } GPIO_TypeDef;
*/
// GPIO
#define GPIOB_BASE (APB2_PERIPHERAL_BASE + 0x0C00)

// GPIO_ODR
#define ODR_OFFSET 0x0C
#define GPIOB_ODR_BASE (GPIOB_BASE + ODR_OFFSET)

// GPIO_CRL
#define CRL_OFFSET 0x00
#define GPIOB_CRL_BASE (GPIOB_BASE + CRL_OFFSET)

// 时钟RCC外设地址
#define RCC_BASE (AHB_PERIPHERAL_BASE + 0x1000)
#define RCC_APB2_ENR_BASE (RCC_BASE + 0x18)

#define GET_ADDR_DATA_BYTE(address) (*(uint32_t *)(address))

#endif /* __LIB_STM32F10X_H */
