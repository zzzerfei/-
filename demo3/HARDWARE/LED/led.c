#include "led.h"

void My_LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;//����GPIO����Ϣ
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//��ʱ������
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//��������
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_13;//13
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,  &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOC, GPIO_Pin_13);//set����reset��
}
