#include "main.h"

void Encoder_Position(void)
{
    GPIO_InitTypeDef gpio;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	  gpio.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_6;
    gpio.GPIO_Speed = GPIO_Speed_100MHz;
		gpio.GPIO_Mode = GPIO_Mode_AF;
		gpio.GPIO_PuPd = GPIO_PuPd_UP;
		GPIO_Init(GPIOC,&gpio);
		
		GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_TIM3);
		GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_TIM3);
	
    TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling, TIM_ICPolarity_Falling);
    TIM_Cmd(TIM3,ENABLE);	 
	//-------------------------------------------------------------------------------
	  GPIO_InitTypeDef GPIO;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
                                          
	  GPIO.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_0;
    GPIO.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO.GPIO_Mode = GPIO_Mode_AF;
		GPIO.GPIO_PuPd = GPIO_PuPd_UP;
		GPIO_Init(GPIOA,&GPIO);
		
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM5);
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM5);
	
    TIM_EncoderInterfaceConfig(TIM5, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling, TIM_ICPolarity_Falling);
    TIM_Cmd(TIM5,ENABLE);	 

}
