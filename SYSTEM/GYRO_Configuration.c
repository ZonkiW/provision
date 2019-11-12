#include "main.h"

/*
�������ݽ���
*/

static uint8_t IMU_DMA_RX_BUF[2][IMU_DMA_RX_BUF_LEN];
void GYRO_Configuration(void)
{
	/* -------------- Enable Module Clock Source ----------------------------*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
	/* -------------- Configure GPIO & USART6 -------------------------------*/
	{
		GPIO_InitTypeDef  gpio;
    USART_InitTypeDef usart;
		
    GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_USART6);
    GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_USART6); 
	
    gpio.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    gpio.GPIO_Mode = GPIO_Mode_AF;
    gpio.GPIO_OType = GPIO_OType_PP;
    gpio.GPIO_Speed = GPIO_Speed_100MHz;
    gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC,&gpio);
	
    usart.USART_BaudRate = 115200;
    usart.USART_WordLength = USART_WordLength_8b;
    usart.USART_StopBits = USART_StopBits_1;
    usart.USART_Parity = USART_Parity_No;
    usart.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
    usart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART6,&usart);

		USART_DMACmd(USART6, USART_DMAReq_Rx, ENABLE);
		USART_Cmd(USART6,ENABLE);
    USART_ITConfig(USART6,USART_IT_IDLE,ENABLE);
	}
		/* -------------- Configure DMA2_Stream2 --------------------------------*/
	{
		DMA_InitTypeDef dma;
		
    DMA_DeInit(DMA2_Stream2);
    DMA_StructInit(&dma);
    dma.DMA_Channel = DMA_Channel_5;
    dma.DMA_PeripheralBaseAddr = (uint32_t)(&USART6->DR);
    dma.DMA_Memory0BaseAddr = (uint32_t)&IMU_DMA_RX_BUF[0][0];
    dma.DMA_DIR = DMA_DIR_PeripheralToMemory;
    dma.DMA_BufferSize = sizeof(IMU_DMA_RX_BUF)/2;
    dma.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    dma.DMA_MemoryInc = DMA_MemoryInc_Enable;
    dma.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    dma.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    dma.DMA_Mode = DMA_Mode_Circular;
    dma.DMA_Priority = DMA_Priority_Medium;
    dma.DMA_FIFOMode = DMA_FIFOMode_Disable;
    dma.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;
    dma.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    dma.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_Init(DMA2_Stream2, &dma);
    
    //����Memory1,Memory0�ǵ�һ��ʹ�õ�Memory
    DMA_DoubleBufferModeConfig(DMA2_Stream2, (uint32_t)&IMU_DMA_RX_BUF[1][0], DMA_Memory_0);   //first used memory configuration
    DMA_DoubleBufferModeCmd(DMA2_Stream2, ENABLE);
    
    DMA_Cmd(DMA2_Stream2, ENABLE);
	}
	/* -------------- Configure NVIC ----------------------------------------*/
	{
		NVIC_InitTypeDef  nvic;
		
		nvic.NVIC_IRQChannel = USART6_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 0;
    nvic.NVIC_IRQChannelSubPriority = 2;
    nvic.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&nvic);
	}
}

void USART6_IRQHandler(void)                	//����6�жϷ������
{
	static uint32_t usart6_this_time_rx_len = 0;
	if(USART_GetITStatus(USART6, USART_IT_IDLE) != RESET)
	{
		//clear the idle pending flag 
		(void)USART6->SR;
		(void)USART6->DR;

		//Target is Memory0
		if(DMA_GetCurrentMemoryTarget(DMA2_Stream2) == 0)
		{
			DMA_Cmd(DMA2_Stream2, DISABLE);
			usart6_this_time_rx_len = IMU_DMA_RX_BUF_LEN - DMA_GetCurrDataCounter(DMA2_Stream2);
			DMA2_Stream2->NDTR = (uint16_t)IMU_DMA_RX_BUF_LEN;     //relocate the dma memory pointer to the beginning position
			DMA2_Stream2->CR |= (uint32_t)(DMA_SxCR_CT);                  //enable the current selected memory is Memory 1
			DMA_Cmd(DMA2_Stream2, ENABLE);
      if(usart6_this_time_rx_len == IMU_FRAME_LENGTH)
			{
				IMUDataProcess(IMU_DMA_RX_BUF[0]);
			}
		}
		else //Target is Memory1
		{
			DMA_Cmd(DMA2_Stream2, DISABLE);
			usart6_this_time_rx_len = IMU_DMA_RX_BUF_LEN - DMA_GetCurrDataCounter(DMA2_Stream2);
			DMA2_Stream2->NDTR = (uint16_t)IMU_DMA_RX_BUF_LEN;      //relocate the dma memory pointer to the beginning position
			DMA2_Stream2->CR &= ~(uint32_t)(DMA_SxCR_CT);                  //enable the current selected memory is Memory 0
			DMA_Cmd(DMA2_Stream2, ENABLE);
      if(usart6_this_time_rx_len == IMU_FRAME_LENGTH)
			{
				IMUDataProcess(IMU_DMA_RX_BUF[1]);
			}
		}
	}       
}


//�����м��ٶȼ�\������\�������ܹ��Ÿ�����,����оƬ�Դ��˲�����,ֱ�����ŷ����.

void IMUDataProcess(uint8_t *pData)    //IMU��ʵ�ǽ�����̬��
{

		if(pData == NULL)
		{
			return;
		}
		Gyro[0] = ((float)(int16_t)(pData[16] + (pData[17]<<8)));//roll
		Gyro[1] = ((float)(int16_t)(pData[18] + (pData[19]<<8)));//pitch
		Gyro[2] = ((float)(int16_t)(pData[20] + (pData[21]<<8)));//yaw

}
