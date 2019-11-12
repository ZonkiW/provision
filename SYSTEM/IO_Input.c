#include "main.h"

void IO_Input(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;	
				
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				    
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	
  //  GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_UP;//上拉
		GPIO_Init(GPIOA,&GPIO_InitStructure);			
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				    
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	
 //   GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_UP;//上拉
		GPIO_Init(GPIOA,&GPIO_InitStructure);			
	
}
