#include "main.h"
/*
���� :�����ȶ�����40cm
������䣺PA0��PA1��PA2�������
          PA8��PA9��PA10��������
					PB7��PB8��PB9�жϵ�������
					CAN1��CM1_MOTOR���䵯����
*/

int main(void)
{ 
	delay_init(168);	//��ʱ��ʼ�� 
	delay_ms(2000);//
	           /*---------------����------------------*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	CAN1_Configuration();//���͵����Ϣ���������������ݴ����õ�ENCODERֵ
	CAN2_Configuration();
	PWM_Configuration();//����p�������ƶ��
	TASK_Init();//��ʼ��
				       /*----------------����-----------------*/
	TIM6_Configuration();//2ms������
	TIM6_Start();
	    
		while(1)
	{
  				
	}
			
}	




