#include "bsp_key.h"

void KEY_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 初始化RCC时钟
    RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);

    // 初始化GPIO
    GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;
    // 浮空输入
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
}

// 返回按键的状态
uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
    {
        // 松手检测
        while (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
        {
            // 空转
        }
        return KEY_ON;
    }
    return KEY_OFF;
}