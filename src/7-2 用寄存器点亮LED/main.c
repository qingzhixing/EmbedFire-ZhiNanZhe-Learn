#include "lib/bit.h"
#include "lib/stm32f10x.h"

int main(void)
{
	/*
		打开GPIOB时钟:使用外设前需要打开时钟
	*/
	SET_DIGIT_1(GET_ADDR_DATA_BYTE(RCC_APB2_ENR), 3);

	/*
		配置CRL : 低八位IO口
		配置GPIOB_0为输出模式
		CNF + MODE 共4位一组控制一个端口
		MODE0 = 0x01 - 10MHz输出
		CNF0 = 0x00 - 推挽输出
	*/
	SET_DIGIT_1(GET_ADDR_DATA_BYTE(GPIOB_CRL_BASE + (4 * 0)), 1);

	// LED_R = GPIOB_0输出0 开灯
	SET_DIGIT_0(GET_ADDR_DATA_BYTE(GPIOB_ODR_BASE), 0);
}

void SystemInit(void)
{
	// 由汇编代码调用,在主函数前执行
}