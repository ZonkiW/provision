#include "main.h"

/*----CAN2_TX-----PB13----*/
/*----CAN2_RX-----PB12----*/

void CAN2_Configuration(void)
{
	/* -------------- Enable Module Clock Source ----------------------------*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);
	/* -------------- Configure GPIO & CAN1 ---------------------------------*/
	{
		GPIO_InitTypeDef       gpio;
		CAN_InitTypeDef        can;
		CAN_FilterInitTypeDef  can_filter;
		
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource12, GPIO_AF_CAN2);
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_CAN2); 

		gpio.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 ;
		gpio.GPIO_Mode = GPIO_Mode_AF;
		GPIO_Init(GPIOB, &gpio);
		
		CAN_DeInit(CAN2);
		CAN_StructInit(&can);

		can.CAN_TTCM = DISABLE;
		can.CAN_ABOM = DISABLE;    
		can.CAN_AWUM = DISABLE;    
		can.CAN_NART = DISABLE;    
		can.CAN_RFLM = DISABLE;    
		can.CAN_TXFP = ENABLE;     
		can.CAN_Mode = CAN_Mode_Normal; 
		can.CAN_SJW  = CAN_SJW_1tq;
		can.CAN_BS1 = CAN_BS1_9tq;
		can.CAN_BS2 = CAN_BS2_4tq;
		can.CAN_Prescaler = 3;   //CAN BaudRate 42/(1+9+4)/3=1Mbps
		CAN_Init(CAN2, &can);

		can_filter.CAN_FilterNumber=14;
		can_filter.CAN_FilterMode=CAN_FilterMode_IdMask;
		can_filter.CAN_FilterScale=CAN_FilterScale_32bit;
		can_filter.CAN_FilterIdHigh=0x0000;
		can_filter.CAN_FilterIdLow=0x0000;
		can_filter.CAN_FilterMaskIdHigh=0x0000;
		can_filter.CAN_FilterMaskIdLow=0x0000;
		can_filter.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//the message which pass the filter save in fifo0
		can_filter.CAN_FilterActivation=ENABLE;
		CAN_FilterInit(&can_filter);

		CAN_ITConfig(CAN2,CAN_IT_FMP0,ENABLE);
		CAN_ITConfig(CAN2,CAN_IT_TME,ENABLE);
	}
  /* -------------- Configure NVIC ----------------------------------------*/
	{
		NVIC_InitTypeDef       nvic;
		
		nvic.NVIC_IRQChannel = CAN2_RX0_IRQn;
		nvic.NVIC_IRQChannelPreemptionPriority = 1;
		nvic.NVIC_IRQChannelSubPriority = 1;
		nvic.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&nvic);
		
		nvic.NVIC_IRQChannel = CAN2_TX_IRQn;
		nvic.NVIC_IRQChannelPreemptionPriority = 0;
		nvic.NVIC_IRQChannelSubPriority = 1;
		nvic.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&nvic);
	}
}
/*************************************************************************
                          CAN2_TX_IRQHandler
������CAN2�ķ����жϺ���
*************************************************************************/
void CAN2_TX_IRQHandler(void) //CAN TX
{
  if (CAN_GetITStatus(CAN2,CAN_IT_TME)!= RESET)    //if transmit mailbox is empty 
  {
	   CAN_ClearITPendingBit(CAN2,CAN_IT_TME);   
  }
}
/*************************************************************************
                          CAN2_RX0_IRQHandler
������CAN2�Ľ����жϺ���
*************************************************************************/
void CAN2_RX0_IRQHandler(void)
{
    CanRxMsg rx_message;
    if (CAN_GetITStatus(CAN2,CAN_IT_FMP0)!= RESET) 
    {
			CAN_ClearITPendingBit(CAN2, CAN_IT_FMP0);
			CAN_Receive(CAN2, CAN_FIFO0, &rx_message);  
		 //������������ݴ���
			//CanReceiveMsgProcess(&rx_message);
    }
}

void Set_CM_Speed(CAN_TypeDef *CANx, int16_t cm1_iq, int16_t cm2_iq, int16_t cm3_iq, int16_t cm4_iq)
{
    CanTxMsg tx_message;
    tx_message.StdId = 0x200;
    tx_message.IDE = CAN_Id_Standard;
    tx_message.RTR = CAN_RTR_Data;
    tx_message.DLC = 0x08;
    
    tx_message.Data[0] = (uint8_t)(cm1_iq >> 8);
    tx_message.Data[1] = (uint8_t)cm1_iq;
    tx_message.Data[2] = (uint8_t)(cm2_iq >> 8);
    tx_message.Data[3] = (uint8_t)cm2_iq;
    tx_message.Data[4] = (uint8_t)(cm3_iq >> 8);
    tx_message.Data[5] = (uint8_t)cm3_iq;
    tx_message.Data[6] = (uint8_t)(cm4_iq >> 8);
    tx_message.Data[7] = (uint8_t)cm4_iq;
    CAN_Transmit(CANx,&tx_message);
}

void Set_Gimbal_Current(CAN_TypeDef *CANx, int16_t gimbal_yaw_iq, int16_t gimbal_pitch_iq, int16_t cm7_iq)
{
    CanTxMsg tx_message;    
    tx_message.StdId = 0x1FF;
    tx_message.IDE = CAN_Id_Standard;//��׼��ʶ��
    tx_message.RTR = CAN_RTR_Data;
    tx_message.DLC = 0x08;
    
    tx_message.Data[0] = (unsigned char)(gimbal_yaw_iq >> 8);
    tx_message.Data[1] = (unsigned char)gimbal_yaw_iq;
    tx_message.Data[2] = (unsigned char)(gimbal_pitch_iq >> 8);
    tx_message.Data[3] = (unsigned char)gimbal_pitch_iq;
    tx_message.Data[4] = (unsigned char)(cm7_iq >> 8);
    tx_message.Data[5] = (unsigned char)cm7_iq;
    tx_message.Data[6] = 0xff;
    tx_message.Data[7] = 0xff;
    CAN_Transmit(CANx,&tx_message);
}

