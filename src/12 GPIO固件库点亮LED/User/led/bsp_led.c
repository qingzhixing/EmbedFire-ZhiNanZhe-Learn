// bsp: board support package - 板级支持包
#include "bsp_led.h"

void LED_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 初始化RCC时钟
    RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);

    // 初始化GPIO
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    // LED_G
    GPIO_InitStructure.GPIO_Pin = LED_G_GPIO_PIN;
    GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);
    // LED_R
    GPIO_InitStructure.GPIO_Pin = LED_R_GPIO_PIN;
    GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);
    // LED_B
    GPIO_InitStructure.GPIO_Pin = LED_B_GPIO_PIN;
    GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);

    // 关闭所有LED
    LED_OFF(LED_R_GPIO_PIN);
    LED_OFF(LED_G_GPIO_PIN);
    LED_OFF(LED_B_GPIO_PIN);
}