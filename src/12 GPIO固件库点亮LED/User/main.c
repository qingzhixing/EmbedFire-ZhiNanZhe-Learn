#include "stdint.h"
#include "stm32f10x.h"

#include "bsp_led.h"

// 软件延迟
void Delay(uint32_t countDown)
{
	while (countDown--)
	{
		for (; countDown != 0; countDown--);
	}
}

int main(void)
{
	// 此时系统时钟已经是72MHz
	LED_GPIO_Config();
	// 阻塞
	while (1)
	{
		GPIO_SetBits(LED_GPIO_PORT, LED_R_GPIO_PIN);
		Delay(0xFFFFF);
		GPIO_ResetBits(LED_GPIO_PORT, LED_R_GPIO_PIN);
		Delay(0xFFFfF);
	}
}