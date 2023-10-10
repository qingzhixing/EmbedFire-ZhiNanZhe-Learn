#ifndef __LIB_STM32F10X_H
#define __LIB_STM32F10X_H
#include "stdint.h"
// 用来存储 stm32f10x 的寄存器映射

// 防止编译器自动优化GPIO端口
#define __IO volatile

// 外设基地址
#define PERIPHERAL_BASE ((uint32_t)0x40000000)

// 外设三个类型
#define APB1_PERIPHERAL_BASE PERIPHERAL_BASE
#define APB2_PERIPHERAL_BASE (PERIPHERAL_BASE + 0x10000)
// 实际上AHB从SDIO(PERIPHERAL_BASE + 0x18000)开始，为了方便计算，取 + 0x20000
#define AHB_PERIPHERAL_BASE (PERIPHERAL_BASE + 0x20000)

// GPIO结构:
typedef struct
{
    __IO uint32_t CRL;
    __IO uint32_t CRH;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t BRR;
    __IO uint32_t LCKR;
} GPIO_Type;

// GPIO
#define GPIOB_BASE (APB2_PERIPHERAL_BASE + 0x0C00)
#define GPIOB ((GPIO_Type *)GPIOB_BASE)

// RCC 结构
typedef struct
{
    __IO uint32_t CR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t APB2RSTR;
    __IO uint32_t APB1RSTR;
    __IO uint32_t AHBENR;
    __IO uint32_t APB2ENR;
    __IO uint32_t APB1ENR;
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
} RCC_Type;

// 时钟RCC外设地址
#define RCC_BASE (AHB_PERIPHERAL_BASE + 0x1000)
#define RCC ((RCC_Type *)RCC_BASE)

#define GET_ADDR_DATA_BYTE(address) (*(uint32_t *)(address))

#endif /* __LIB_STM32F10X_H */
