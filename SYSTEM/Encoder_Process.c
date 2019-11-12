#include "main.h"

/*
����can1���յ���Ϣ���õ�����Ĳ���
*/

static uint32_t can_count = 0;
int16_t  pitch_ecd_bias = 100;
int16_t  yaw_ecd_bias   = 3179;

void CanReceiveMsgProcess(CanRxMsg * msg)
{
    can_count++;
		switch(msg->StdId)
		{
			case CAN_BUS1_MOTOR1_FEEDBACK_MSG_ID:
			{
				(can_count<=50) ? GetEncoderBias(&CM1Encoder ,msg):
				Motor_3510_EncoderProcess(&CM1Encoder ,msg);       //��ȡ���������ĳ�ʼƫ��ֵ    
			}break;
			case CAN_BUS1_MOTOR2_FEEDBACK_MSG_ID:
			{
				(can_count<=50) ? GetEncoderBias(&CM2Encoder ,msg):
				Motor_3510_EncoderProcess(&CM2Encoder ,msg);
			}break;
			case CAN_BUS1_MOTOR3_FEEDBACK_MSG_ID:
			{
				(can_count<=50) ? GetEncoderBias(&CM3Encoder ,msg):
				Motor_3510_EncoderProcess(&CM3Encoder ,msg); 
			}break;
			case CAN_BUS1_MOTOR4_FEEDBACK_MSG_ID:
			{
				(can_count<=50) ? GetEncoderBias(&CM4Encoder ,msg):
				Motor_3510_EncoderProcess(&CM4Encoder ,msg);
			}break;
			case CAN_BUS1_MOTOR7_FEEDBACK_MSG_ID:
			{
				(can_count<=50) ? GetEncoderBias(&CM7Encoder ,msg):
				Motor_2310_EncoderProcess(&CM7Encoder ,msg);
				
			}break;
			case CAN_BUS1_MOTOR5_FEEDBACK_MSG_ID:
			{
				if(can_count<50)
				{
					GetEncoderBias(&GMYawEncoder ,msg);
					if(GMYawEncoder.ecd_bias-yaw_ecd_bias>4096)
						yaw_ecd_bias+=8192;
					else if(GMYawEncoder.ecd_bias-yaw_ecd_bias<-4096)
						yaw_ecd_bias-=8192;
				}
				else 
				{
					GMYawEncoder.ecd_bias = yaw_ecd_bias;
					Motor_6623_EncoderProcess(&GMYawEncoder ,msg);
				}
				
			}break;
			
			case CAN_BUS1_MOTOR6_FEEDBACK_MSG_ID:
			{
				if(can_count<50)
				{
					GetEncoderBias(&GMPitchEncoder ,msg);
					if(GMPitchEncoder.ecd_bias-pitch_ecd_bias>4096)
						pitch_ecd_bias+=8192;
					else if(GMPitchEncoder.ecd_bias-pitch_ecd_bias<-4096)
						pitch_ecd_bias-=8192;
				}
				else
				{
					GMPitchEncoder.ecd_bias = pitch_ecd_bias;
					Motor_6623_EncoderProcess(&GMPitchEncoder ,msg);
				}
		
			}break;
			
       		
			default:
			{
			}
	}
}

void GetEncoderBias(volatile Encoder *v, CanRxMsg * msg)
{
		v->ecd_bias = (msg->Data[0]<<8)|msg->Data[1];  //�����ʼ������ֵ��Ϊƫ��  
		v->raw_value= v->ecd_bias;
		v->ecd_value = v->ecd_bias;
}


void Motor_3510_EncoderProcess(volatile Encoder *v, CanRxMsg * msg)
{
	int i=0;
	int32_t temp_sum = 0;    
	v->last_raw_value = v->raw_value;
	v->raw_value = (msg->Data[0]<<8)|msg->Data[1];
	v->diff = v->raw_value - v->last_raw_value;
	
	if(v->diff < -4096)    //���α������ķ���ֵ���̫�󣬱�ʾȦ�������˸ı�
	{
		v->round_cnt++;
		v->ecd_raw_rate = v->diff + 8192;
	}
	else if(v->diff>4096)
	{
		v->round_cnt--;
		v->ecd_raw_rate = v->diff- 8192;
	}
	else
	{
		v->ecd_raw_rate = v->diff;
	}
	//����diff
	v->rate_buf[v->buf_count++] = v->ecd_raw_rate;
	
	//����õ������ı��������ֵ
	v->ecd_value = v->raw_value + v->round_cnt * 8192;//Ĭ�ϳ�ʼֵ0
	
	//����õ��Ƕ�ֵ����Χ���������
	v->ecd_angle = (double)(v->raw_value - v->ecd_bias)*(360/19.0)/8192 + v->round_cnt * 360/19.0;//���ٱ�36:1
	
	if(v->buf_count == RATE_BUF_SIZE)
	{
			v->buf_count = 0;
		
		//�����ٶ�ƽ��ֵ
		for(i = 0;i < RATE_BUF_SIZE; i++)
		{
			temp_sum += v->rate_buf[i];
		}
		v->filter_rate = (int32_t)(temp_sum/RATE_BUF_SIZE);	
  }	
}

void Motor_6623_EncoderProcess(volatile Encoder *v, CanRxMsg * msg)
{
	int i=0;
	int32_t temp_sum = 0;    
	v->last_raw_value = v->raw_value;
	v->raw_value = (msg->Data[0]<<8)|msg->Data[1];
	v->diff = v->raw_value - v->last_raw_value;
	
	if(v->diff < -4096)    //���α������ķ���ֵ���̫�󣬱�ʾȦ�������˸ı�
	{
		v->round_cnt++;
		v->ecd_raw_rate = v->diff + 8192;
	}
	else if(v->diff>4096)
	{
		v->round_cnt--;
		v->ecd_raw_rate = v->diff- 8192;
	}
	else
	{
		v->ecd_raw_rate = v->diff;
	}
	//����diff
	v->rate_buf[v->buf_count++] = v->ecd_raw_rate;
	
	//����õ������ı��������ֵ
	v->ecd_value = v->raw_value + v->round_cnt * 8192;
	
	//����õ��Ƕ�ֵ����Χ���������
	v->ecd_angle = (double)(v->raw_value - v->ecd_bias)*360/8192 + v->round_cnt * 360;
	
	if(v->buf_count == RATE_BUF_SIZE)
	{
		v->buf_count = 0;
	}
	//�����ٶ�ƽ��ֵ
	for(i = 0;i < RATE_BUF_SIZE; i++)
	{
		temp_sum += v->rate_buf[i];
	}
	v->filter_rate = (int32_t)(temp_sum/RATE_BUF_SIZE);			
}

void Motor_2310_EncoderProcess(volatile Encoder *v, CanRxMsg * msg)
{
	int i=0;
	int32_t temp_sum = 0;    
	v->last_raw_value = v->raw_value;
	v->raw_value = (msg->Data[0]<<8)|msg->Data[1];
	v->diff = v->raw_value - v->last_raw_value;
	
	if(v->diff < -4096)    //���α������ķ���ֵ���̫�󣬱�ʾȦ�������˸ı�
	{
		v->round_cnt++;
		v->ecd_raw_rate = v->diff + 8192;
	}
	else if(v->diff>4096)
	{
		v->round_cnt--;
		v->ecd_raw_rate = v->diff- 8192;
	}
	else
	{
		v->ecd_raw_rate = v->diff;
	}
	//����diff
	v->rate_buf[v->buf_count++] = v->ecd_raw_rate;
	
	//����õ������ı��������ֵ
	v->ecd_value = v->raw_value + v->round_cnt * 8192;
	
	//����õ��Ƕ�ֵ����Χ���������
	v->ecd_angle = (double)(v->raw_value - v->ecd_bias)*(360/36.0)/8192 + v->round_cnt * 360/36.0;//���ٱ�36:1
	
	if(v->buf_count == RATE_BUF_SIZE)
	{
			v->buf_count = 0;
		
		//�����ٶ�ƽ��ֵ
		for(i = 0;i < RATE_BUF_SIZE; i++)
		{
			temp_sum += v->rate_buf[i];
		}
		v->filter_rate = (int32_t)(temp_sum/RATE_BUF_SIZE);		
  }	
}


