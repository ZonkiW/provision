#include "main.h"

void AMMO_MOTOR(void)
{
   CM1PositionPID.kp=CM1PositionPID_kp;   CM1PositionPID.ki=CM1PositionPID_ki;  CM1PositionPID.kd=CM1PositionPID_kd;
	 CM1SpeedPID.kp   =CM1SpeedPID_kp;      CM1SpeedPID.ki   =CM1SpeedPID_ki;     CM1SpeedPID.kd   =CM1SpeedPID_kd;
	
//----------------------------------------切换状态------------------------------------------------
	 switch(motor_around_state)
	 {
	   case MOTOR_FIRST_STATE:
		 {
		   motor_position=MOTOR_POSITION1;
		 }break;
		 
		 case MOTOR_SECOND_STATE:
		 {
		   motor_position=MOTOR_POSITION2;
		 }break;
		 
		 case MOTOR_INTER_STATE:
		 {
		   MOTOR_POSITION_CHANGE();
		 }break;
	 
	 }
//----------------------------------------位置状态------------------------------------------------
	 switch(motor_position)
	 {
	   case MOTOR_POSITION1:
		 {
		  CM1PositionPID_ref=motor_init_angle;
		 }break;
		 
		 case MOTOR_POSITION2:
		 {
		  CM1PositionPID_ref=motor_second_angle;
		 }break;
		 
		 case MOTOR_POSITION3:
		 {
		  CM1PositionPID_ref=motor_third_angle;
		 }break;
			 
	 }
	
//----------------------------------------PID计算-------------------------------------------------
	 CM1PositionPID.ref=CM1PositionPID_ref;
	 CM1PositionPID.fdb=CM1Encoder.ecd_angle;
	 CM1PositionPID.Calc(&CM1PositionPID);
	 
	 CM1SpeedPID.ref = CM1PositionPID.output;
	 CM1SpeedPID.fdb = CM1Encoder.filter_rate;
   CM1SpeedPID.Calc(&CM1SpeedPID);  
//-----------------------------------------输出---------------------------------------------------
	 Set_CM_Speed(CAN1,CM1SpeedPID.output,0,0,0);//can1输出底盘速度
}

void MOTOR_POSITION_CHANGE(void)
{
  MOTOR_INTER_STATE_count++;
  if(MOTOR_INTER_STATE_count>min_value)
	{
	  if(motor_position==MOTOR_POSITION1){channel1_count=1;}//刷新已有弹通道
		if(motor_position==MOTOR_POSITION2){channel2_count=1;}
		if(motor_position==MOTOR_POSITION3){channel3_count=1;}
		

		if(!channel3_count)                                       {motor_position=MOTOR_POSITION3;}//切换等待落弹通道
		if((!channel2_count)&&(channel3_count))                   {motor_position=MOTOR_POSITION2;}
		if((channel2_count)&&(!channel1_count)&&(channel3_count)) {motor_position=MOTOR_POSITION1;}
		
		MOTOR_INTER_STATE_count=0;
		channel1_taken_flag=no;
    channel2_taken_flag=no;
    channel3_taken_flag=no;
	}	

}
