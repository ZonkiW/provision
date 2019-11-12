#include "main.h"

//Timer 2 32-bit counter 


void TIM6_Configuration(void)
{
	/* -------------- Enable Module Clock Source ----------------------------*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	/* -------------- Configure TIM6 ----------------------------------------*/
	{
		TIM_TimeBaseInitTypeDef  tim;
    
    tim.TIM_Prescaler = 84-1;        //84M internal clock��1MHz
    tim.TIM_CounterMode = TIM_CounterMode_Up;
    tim.TIM_ClockDivision = TIM_CKD_DIV1;
    tim.TIM_Period = 3000;  //2ms
    TIM_TimeBaseInit(TIM6,&tim);
	}
	/* -------------- Configure NVIC ----------------------------------------*/
	{
		NVIC_InitTypeDef         nvic;

    nvic.NVIC_IRQChannel = TIM6_DAC_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority =0;
    nvic.NVIC_IRQChannelSubPriority = 0;
    nvic.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic);
	}
}

void TIM6_Start(void)
{
    TIM_Cmd(TIM6, ENABLE);	 //ʹ��ʱ��
    TIM_ITConfig(TIM6, TIM_IT_Update,ENABLE);//ʹ���ж�
    TIM_ClearFlag(TIM6, TIM_FLAG_Update);	//����жϱ�־λ
}

void TIM6_DAC_IRQHandler(void)  
{
	if(TIM_GetITStatus(TIM6,TIM_IT_Update)!= RESET) 
	{
		TIM_ClearITPendingBit(TIM6,TIM_IT_Update);
		TIM_ClearFlag(TIM6, TIM_FLAG_Update);
		
		STATE_HANDLE_CHANGE();//״̬�ж���ı�,��Ҫ�����߼�
		
		STEERING_STATE();//�����ͬ״̬
		AMMO_MOTOR();//�����ͬ״̬
    BRIGHT();	//����ܲ�ͬ״̬�������ͨ��ѹ���������

    DEBUG1=PA8;	DEBUG2=PA9; DEBUG3=PA10;//���Ա���
    DEBUG4=PB7; DEBUG5=PB8; DEBUG6=PB9;		
		
	}
	TIM_ClearITPendingBit(TIM6,TIM_IT_Update);  //����жϱ�־λ
		
}

