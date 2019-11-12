#include "main.h"

  void Position_Switch(void)
{
      if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0)
			{
				TIM_SetCompare1(TIM5,500);
			}
			
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==1)
			{
				TIM_SetCompare1(TIM5,2500);
			}
			
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)==0)
			{
				TIM_SetCompare2(TIM5,500);
			}
			
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)==1)
			{
				TIM_SetCompare2(TIM5,2500);
			}


}
