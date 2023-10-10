#include "lib/bit.h"
#include "lib/stm32f10x_gpio.h"

// 0-G 1-B 5-R
#define OPEN_GPIOB_IDX 1

int main(void)
{
	/*
		打开GPIOB时钟:使用外设前需要打开时钟
	*/
	SET_DIGIT_1(RCC->APB2ENR, 3);

	/*
		配置CRL : 低八位IO口
		配置GPIOB_0为输出模式
		CNF + MODE 共4位一组控制一个端口
		MODE_OPEN_GPIOB_IDX = 0x01 - 10MHz输出
		CNF_OPEN_GPIOB_IDX = 0x00 - 推挽输出
	*/
	// 清空设置
	GPIOB->CRL &= ~(0xF << (4 * OPEN_GPIOB_IDX));
	// 设置控制置为0b0001
	SET_DIGIT_1(GPIOB->CRL, 4 * OPEN_GPIOB_IDX);

	// LED_x = GPIOB_(OPEN_GPIOB_IDX)输出 0 开灯
	GPIO_ResetBits(GPIOB, 1 << OPEN_GPIOB_IDX);

	while (1)
		;
}

void SystemInit(void)
{
	// 由汇编代码调用,在主函数前执行
}