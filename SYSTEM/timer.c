#include "main.h"

//Timer 2 32-bit counter 


void TIM6_Configuration(void)
{
	/* -------------- Enable Module Clock Source ----------------------------*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	/* -------------- Configure TIM6 ----------------------------------------*/
	{
		TIM_TimeBaseInitTypeDef  tim;
    
    tim.TIM_Prescaler = 84-1;        //84M internal clock，1MHz
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
    TIM_Cmd(TIM6, ENABLE);	 //使能时钟
    TIM_ITConfig(TIM6, TIM_IT_Update,ENABLE);//使能中断
    TIM_ClearFlag(TIM6, TIM_FLAG_Update);	//清除中断标志位
}

void TIM6_DAC_IRQHandler(void)  
{
	if(TIM_GetITStatus(TIM6,TIM_IT_Update)!= RESET) 
	{
		TIM_ClearITPendingBit(TIM6,TIM_IT_Update);
		TIM_ClearFlag(TIM6, TIM_FLAG_Update);
		
		STATE_HANDLE_CHANGE();//状态判断与改变,主要控制逻辑
		
		STEERING_STATE();//舵机不同状态
		AMMO_MOTOR();//电机不同状态
    BRIGHT();	//数码管不同状态，数码管通过压差控制亮暗

    DEBUG1=PA8;	DEBUG2=PA9; DEBUG3=PA10;//调试变量
    DEBUG4=PB7; DEBUG5=PB8; DEBUG6=PB9;		
		
	}
	TIM_ClearITPendingBit(TIM6,TIM_IT_Update);  //清除中断标志位
		
}

