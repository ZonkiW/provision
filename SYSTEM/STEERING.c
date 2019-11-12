#include "main.h"

void STEERING_STATE(void)
{
    switch(STEERING_1)//PA0¶æ»ú1
		{
			case CLOSE_STATE:
			{
				TIM_SetCompare1(TIM5,1600);
			}break;
		
			case OPEN_STATE:
			{
				TIM_SetCompare1(TIM5,500);
			}break;
		
		}
//---------------------------------------------------------------------------------
	  switch(STEERING_2)//PA1¶æ»ú2
		{
			case CLOSE_STATE:
			{
				TIM_SetCompare2(TIM5,1600);
			}break;
		
			case OPEN_STATE:
			{
				TIM_SetCompare2(TIM5,500);
			}break;
		
		}
//----------------------------------------------------------------------------------
	  switch(STEERING_3)//PA2¶æ»ú3
		{
			case CLOSE_STATE:
			{
				TIM_SetCompare3(TIM5,1600);
			}break;
		
			case OPEN_STATE:
			{
				TIM_SetCompare3(TIM5,2100);
			}break;
		
		}

}
