#include "lib/bit.h"
#include "lib/stm32f10x_gpio.h"

// 0-G 1-B 5-R
#define LED_PIN_INDEX 1

#define LED_GPIO_PORT GPIOB
#define LED_GPIO_CLK_ENABLE (SET_DIGIT_1(RCC->APB2ENR, 3))
#define LED_GPIO_PIN GPIO_PIN_x(LED_PIN_INDEX)

void Delay(uint32_t nCount)
{
	for (; nCount != 0; nCount--)
	{
		uint32_t x;
		x += nCount;
	}
}

int main(void)
{
	/*
		打开GPIOB时钟:使用外设前需要打开时钟
	*/
	LED_GPIO_CLK_ENABLE;

	/*
		配置CRL : 低八位IO口
		配置GPIOB_0为输出模式
		CNF + MODE 共4位一组控制一个端口
		MODE_LED_PIN_INDEX = 0x01 - 10MHz输出
		CNF_LED_PIN_INDEX = 0x00 - 推挽输出
	*/

	GPIO_InitType GPIOB_InitStruct;

	GPIOB_InitStruct.GPIO_Pin = LED_GPIO_PIN;
	GPIOB_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOB_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;

	GPIO_Init(LED_GPIO_PORT, &GPIOB_InitStruct);

	while (1)
	{
		// LED_x = GPIOB_(LED_PIN_INDEX)输出 0 开灯
		GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);
		Delay(0xFFFF);
		// LED_x = GPIOB_(LED_PIN_INDEX)输出 1 关灯
		GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);
		Delay(0xFFFF);
	}
}

void SystemInit(void)
{
	// 由汇编代码调用,在主函数前执行
}