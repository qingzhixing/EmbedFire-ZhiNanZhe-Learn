#include "stdint.h"
#include "stm32f10x.h"

#include "bsp_key.h"
#include "bsp_led.h"

// 软件延迟
void Delay(uint32_t countDown)
{
	while (countDown--)
	{
		for (; countDown != 0; countDown--)
			;
	}
}

int main(void)
{
	// 此时系统时钟已经是72MHz
	LED_GPIO_Config();
	KEY_GPIO_Config();

	GPIO_SetBits(LED_GPIO_PORT, LED_G_GPIO_PIN);
	// 阻塞
	while (1)
	{
		if (Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)
		{
			LED_TOGGLE(LED_G_GPIO_PIN);
		}
	}
}