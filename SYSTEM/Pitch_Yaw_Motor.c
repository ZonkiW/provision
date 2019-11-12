#include "main.h"

/*
��̨����,λ�û����ٶȻ�����
*/

float pitch_angle_dynamic_ref = 0.0f;
void Pitch_Motor_TASK(void)
{
	
		GMPPositionPID.kp = 300;//���p���ڣ�С��i���ڣ�d����һ�㲻��
		GMPPositionPID.ki = 0.05;
		GMPPositionPID.kd = 0;
			
		GMPSpeedPID.kp = 5.0;
		GMPSpeedPID.ki = 0.02;
		GMPSpeedPID.kd = 0;
	  	 
		GMPPositionPID.ref = 0;//���򷴼Ӹ���;
		GMPPositionPID.fdb = GMPitchEncoder.ecd_angle * GMPitchRamp.Calc(&GMPitchRamp);//����һ��б�º���  
		GMPPositionPID.Calc(&GMPPositionPID);   
		
		GMPSpeedPID.ref = GMPPositionPID.output;//���򷴼Ӹ���
		GMPSpeedPID.fdb = Gyro[0];//�仯���ķ���
		GMPSpeedPID.Calc(&GMPSpeedPID);
	
	  Set_Gimbal_Current(CAN1,(int16_t)(GMYSpeedPID.output),(int16_t)(GMPSpeedPID.output),(int16_t)(CM7SpeedPID.output)); 
	
}

float yaw_angle_dynamic_ref = 0.0f;
void Yaw_Motor_TASK(void)
{
	 	
	  GMYPositionPID.kp = 150;
		GMYPositionPID.ki =	0.02;
		GMYPositionPID.kd = 0;
			
		GMYSpeedPID.kp = 3.5;
		GMYSpeedPID.ki = 0.002;
		GMYSpeedPID.kd = 0;
    			
		GMYPositionPID.ref = 0;
		GMYPositionPID.fdb = -GMYawEncoder.ecd_angle * GMYawRamp.Calc(&GMYawRamp); 
		GMYPositionPID.Calc(&GMYPositionPID); 
			  	
		GMYSpeedPID.ref = GMYPositionPID.output;
		GMYSpeedPID.fdb = -Gyro[2];
		GMYSpeedPID.Calc(&GMYSpeedPID);
	
	  Set_Gimbal_Current(CAN1,(int16_t)(GMYSpeedPID.output),(int16_t)(GMPSpeedPID.output),(int16_t)(CM7SpeedPID.output)); 
}
