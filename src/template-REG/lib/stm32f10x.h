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

// GPIO结构:
typedef struct
{
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t BRR;
    uint32_t LCKR;
} GPIO_Type;

// GPIO
#define GPIOB_BASE (APB2_PERIPHERAL_BASE + 0x0C00)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)

// RCC 结构
typedef struct
{
    uint32_t CR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t APB2RSTR;
    uint32_t APB1RSTR;
    uint32_t AHBENR;
    uint32_t APB2ENR;
    uint32_t APB1ENR;
    uint32_t BDCR;
    uint32_t CSR;
} RCC_TypeDef;

// 时钟RCC外设地址
#define RCC_BASE (AHB_PERIPHERAL_BASE + 0x1000)
#define RCC ((RCC_TypeDef *)RCC_BASE)

#define GET_ADDR_DATA_BYTE(address) (*(uint32_t *)(address))

#endif /* __LIB_STM32F10X_H */
