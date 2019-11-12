#include "main.h"

void STATE_HANDLE_CHANGE (void)
{
	   
//	   if(AMMO_HANDLE())
//		 {
//		  STEERING_1=OPEN_STATE;
//			ammo_out_count=0;
//		 }
//		 else if(!AMMO_HANDLE())
//		 {
//		  ammo_out_count++;		 
//		 }
//		 
//		 if(ammo_out_count>=ammo_out_count_value)
//		 {
//		  STEERING_1=CLOSE_STATE;
//		 }

//-----------------------------------------触发放弹---------------------------------------------------
	    LAST_STEERING_1=STEERING_1;
	    LAST_STEERING_2=STEERING_2;
	    LAST_STEERING_3=STEERING_3;
	
      if((AMMO_HANDLE(PA8,&PA8_count))&&(channel1_count))
			{
			 STEERING_1=OPEN_STATE;
			 motor_around_flag=1;
			 channel1_taken_flag=yes;
			}
			else if(!AMMO_HANDLE(PA8,&PA8_count))
			{
			 STEERING_1=CLOSE_STATE;
			}
			
			 if((AMMO_HANDLE(PA9,&PA9_count))&&((channel2_count)||(motor_around_state==MOTOR_SECOND_STATE)))
			{
			 STEERING_2=OPEN_STATE;
			 channel2_taken_flag=yes;
			}
			else if(!AMMO_HANDLE(PA9,&PA9_count))
			{
			 STEERING_2=CLOSE_STATE;
			}
			
			if((AMMO_HANDLE(PA10,&PA10_count))&&(channel3_count))
			{
			 STEERING_3=OPEN_STATE;
			 channel3_taken_flag=yes;
			}
			else if(!AMMO_HANDLE(PA10,&PA10_count))
			{
			 STEERING_3=CLOSE_STATE;
			}
//-----------------------------------------------MOTOR转动-------------------------------------
      switch(motor_around_state)
	  {
	   case MOTOR_FIRST_STATE:
		 {
		   if(motor_around_flag==1)
			 {
			  motor_around_state=MOTOR_SECOND_STATE;
			//	channel2_count=1; 
			 } 
		 }break;
		 
		 case MOTOR_SECOND_STATE:
		 {
		   MOTOR_SECOND_STATE_count++;
			 if(MOTOR_SECOND_STATE_count>MOTOR_SECOND_STATE_value)
			 {
			  motor_around_state=MOTOR_INTER_STATE;
				if(channel2_taken_flag==no)
				{
					channel2_count=1;//点亮2口
				}
				motor_position=MOTOR_POSITION3;//转到3口
			 }
		 }break;
		 
		 case MOTOR_INTER_STATE://进入此状态前已经转到3口
		 {
		   //MOTOR_POSITION_CHANGE();
		 }break;
	 
	  }
			
			 
//---------------------------------------------弹量判断----------------------------------------------
		switch(channel1_count)
		{
		  case 1:
			{
			 light_state1=BRIGHT_STATE;
			}break;
			
			case 0:
			{
			 light_state1=BLACK_STATE;
			}
		
		}
		
		switch(channel2_count)
		{
		  case 1:
			{
			 light_state2=BRIGHT_STATE;
			}break;
			
			case 0:
			{
			 light_state2=BLACK_STATE;
			}
		
		}
		
		switch(channel3_count)
		{
		  case 1:
			{
			 light_state3=BRIGHT_STATE;
			}break;
			
			case 0:
			{
			 light_state3=BLACK_STATE;
			}
		
		}
//--------------------------------------------切换状态-----------------------------------------------
   if((LAST_STEERING_1==CLOSE_STATE)&&(STEERING_1==OPEN_STATE))
	 {
	   channel1_count=0;
	 }
   if((LAST_STEERING_2==CLOSE_STATE)&&(STEERING_2==OPEN_STATE))
	 {
	   channel2_count=0;
	 }
   if((LAST_STEERING_3==CLOSE_STATE)&&(STEERING_3==OPEN_STATE))
	 {
	   channel3_count=0;
	 }		 

		
}

int AMMO_HANDLE(int mes,int32_t* count)//滤信号
{
    switch(mes)
		{
		  case near:
			{
			 (*count)++;
			}break;
			
			case far:
			{
			 (*count)=0;
			}break;
		}
		
		if((*count)>ammo_handle_count_value)//2s左右
		{
		 return 1;
		}
		else
		{
		 return 0;
		}

}



int STEERING_DELAY(int32_t* count)
{

    (*count)++;
	  if((*count)>delay_value)
		{
		  return 1;
		}
		else
		{
		 return 0;		
		}
 
}
