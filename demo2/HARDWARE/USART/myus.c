#include "myus.h"


void My_US_Init(void)
{
	// ���������ṹ��
	GPIO_InitTypeDef GPIO_InitStrue; // GPIO
	USART_InitTypeDef USART_InitStrue; // ����
	NVIC_InitTypeDef NVIC_InitStrue; // �ж�
	
	//ʹ�ܴ��ڣ�GPIo
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//���ڣ�GPIO��ʱ��ʹ��
	
	//��ʼ��GPIO
	//PA9-TX,PA10-RX
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP;//��������
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrue);
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;//����
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrue);
	
	//��ʼ������
	USART_InitStrue.USART_BaudRate=9600;
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//��ʹ��Ӳ����
	USART_InitStrue.USART_Mode=USART_Mode_Rx |USART_Mode_Tx ;//RXTX��Ҫ
	USART_InitStrue.USART_Parity=USART_Parity_No;//������żУ��
	USART_InitStrue.USART_StopBits=USART_StopBits_1;//ֹͣλΪ1
	USART_InitStrue.USART_WordLength=USART_WordLength_8b;//û����żУ�飬8λ
	USART_Init(USART1,&USART_InitStrue);
	
	USART_Cmd(USART1,ENABLE);//ʹ�ܴ���
	
	//�����ж� 
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//ITConfig������ʲô����¿����ж� ���ջ������ǿ�
	//��ʼ���ж�
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn; // ����1�ж�
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1;//��ռ���ȼ�
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStrue);//�жϳ�ʼ��
}	
// �����жϷ�����
void USART1_IRQHandler(void)
{
	u8 res;
	if(USART_GetITStatus(USART1,USART_IT_RXNE)!= RESET)
	{
		res=USART_ReceiveData(USART1);
			USART_SendData(USART1,res);
	}

}

