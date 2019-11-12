#include "main.h"
/*
  PA8，PA9，PA10出弹光电管
	PC0，PC1，PC2，PC13，PC14，PC15数码管
*/
  void TASK_Init()
{
    GPIO_InitTypeDef GPIO_InitStructure;	
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);		
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
////---------------------------------pa0（压力传感器口）---------------------------------------		
//		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				    
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	
//  	GPIO_Init(GPIOA,&GPIO_InitStructure);			
//---------------------------------pa1------------------------------------------------------    
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				    
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	
//	GPIO_Init(GPIOA,&GPIO_InitStructure);	

//-----------------------------------出弹光电管--------------------------------------------------
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				    
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	
 	  GPIO_Init(GPIOA,&GPIO_InitStructure);	

   	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				    
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	
 	  GPIO_Init(GPIOA,&GPIO_InitStructure);	
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;				    
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	
 	  GPIO_Init(GPIOA,&GPIO_InitStructure);
//-----------------------------------判断弹量光电管----------------------------------------------	
//  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;				    
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	
// 	  GPIO_Init(GPIOB,&GPIO_InitStructure);	

//   	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				    
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	
// 	  GPIO_Init(GPIOB,&GPIO_InitStructure);	
//	
//	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				    
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	
// 	  GPIO_Init(GPIOB,&GPIO_InitStructure);
//------------------------------------数码管------------------------------------------------------ 
    GPIO_InitTypeDef       GPIOC0;//
				
    GPIOC0.GPIO_Pin = GPIO_Pin_0;
    GPIOC0.GPIO_Mode= GPIO_Mode_OUT;
    GPIOC0.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(GPIOC, &GPIOC0);
		
		PC0_high();
		
		GPIO_InitTypeDef       GPIOC1;//
				
    GPIOC1.GPIO_Pin = GPIO_Pin_1;
    GPIOC1.GPIO_Mode= GPIO_Mode_OUT;
    GPIOC1.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(GPIOC, &GPIOC1);
		
		PC1_high();
		
		GPIO_InitTypeDef       GPIOC2;//
				
    GPIOC2.GPIO_Pin = GPIO_Pin_2;
    GPIOC2.GPIO_Mode= GPIO_Mode_OUT;
    GPIOC2.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(GPIOC, &GPIOC2);
		
		PC2_high();
		
		GPIO_InitTypeDef       GPIOC13;//
				
    GPIOC13.GPIO_Pin = GPIO_Pin_13;
    GPIOC13.GPIO_Mode= GPIO_Mode_OUT;
    GPIOC13.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(GPIOC, &GPIOC13);
		
		PC13_high();
		
		GPIO_InitTypeDef       GPIOC14;//
				
    GPIOC14.GPIO_Pin = GPIO_Pin_14;
    GPIOC14.GPIO_Mode= GPIO_Mode_OUT;
    GPIOC14.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(GPIOC, &GPIOC14);
		
		PC14_high();
		
		GPIO_InitTypeDef       GPIOC15;//
				
    GPIOC15.GPIO_Pin = GPIO_Pin_15;
    GPIOC15.GPIO_Mode= GPIO_Mode_OUT;
    GPIOC15.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(GPIOC, &GPIOC15);
		
		PC15_high();
		
}
