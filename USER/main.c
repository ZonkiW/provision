#include "main.h"
/*
外设 :光电管稳定距离40cm
外设分配：PA0，PA1，PA2出弹舵机
          PA8，PA9，PA10出弹光电管
					PB7，PB8，PB9判断弹量光电管
					CAN1，CM1_MOTOR分配弹丸电机
*/

int main(void)
{ 
	delay_init(168);	//延时初始化 
	delay_ms(2000);//
	           /*---------------定义------------------*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	CAN1_Configuration();//发送电机信息，并接收码盘数据处理，得到ENCODER值
	CAN2_Configuration();
	PWM_Configuration();//定义p波，控制舵机
	TASK_Init();//初始化
				       /*----------------任务-----------------*/
	TIM6_Configuration();//2ms进控制
	TIM6_Start();
	    
		while(1)
	{
  				
	}
			
}	




