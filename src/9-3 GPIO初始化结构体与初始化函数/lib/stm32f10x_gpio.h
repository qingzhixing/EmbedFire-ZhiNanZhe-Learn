#ifndef __LIB_STM32F10X_GPIO_H
#define __LIB_STM32F10X_GPIO_H
#include "stm32f10x.h"
// 用来定义GPIO相关功能
// 定义GPIO_PIN
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

enum GPIO_SpeedType
{
    GPIO_Speed_10MHz = 1, // 0b01
    GPIO_Speed_2MHz = 2,  // 0b10
    GPIO_Speed_50MHz = 3  // 0b11
};

enum GPIOMode_TypeDef
{
    GPIO_Mode_AIN = 0x0,          // 模拟输入     (0000 0000)b
    GPIO_Mode_IN_FLOATING = 0x04, // 浮空输入     (0000 0100)b
    GPIO_Mode_IPD = 0x28,         // 下拉输入     (0010 1000)b
    GPIO_Mode_IPU = 0x48,         // 上拉输入     (0100 1000)b

    GPIO_Mode_Out_OD = 0x14, // 开漏输出     (0001 0100)b
    GPIO_Mode_Out_PP = 0x10, // 推挽输出     (0001 0000)b
    GPIO_Mode_AF_OD = 0x1C,  // 复用开漏输出 (0001 1100)b
    GPIO_Mode_AF_PP = 0x18   // 复用推挽输出 (0001 1000)b
};
struct GPIO_InitType
{
    // 初始化的GPIO端口号
    uint16_t GPIO_Pin;

    // GPIO引脚速率
    GPIO_SpeedType GPIO_Speed;

    // 选择GPIO引脚工作模式
    GPIOMode_TypeDef GPIO_Mode;
};

void GPIO_SetBits(GPIO_Type *, uint16_t);
void GPIO_ResetBits(GPIO_Type *, uint16_t);
#endif /* __LIB_STM32F10X_GPIO_H */
