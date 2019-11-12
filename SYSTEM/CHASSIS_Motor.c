#include "main.h"

void CHASSIS_Motor_TASK(void)
{
     						
			CM1SpeedPID.ref= forward_back_ref - left_right_ref + rotate_ref;
			CM2SpeedPID.ref= -forward_back_ref + left_right_ref + rotate_ref;
			CM3SpeedPID.ref= -forward_back_ref - left_right_ref + rotate_ref;
			CM4SpeedPID.ref= forward_back_ref + left_right_ref + rotate_ref;
							
			CM1SpeedPID.fdb = CM1Encoder.filter_rate;
			CM2SpeedPID.fdb = CM2Encoder.filter_rate;
			CM3SpeedPID.fdb = CM3Encoder.filter_rate;
			CM4SpeedPID.fdb = CM4Encoder.ecd_raw_rate;

			CM1SpeedPID.Calc(&CM1SpeedPID);
			CM2SpeedPID.Calc(&CM2SpeedPID);
			CM3SpeedPID.Calc(&CM3SpeedPID);
			CM4SpeedPID.Calc(&CM4SpeedPID);
	
	    Set_CM_Speed(CAN1,CM1SpeedPID.output,CM2SpeedPID.output,CM3SpeedPID.output,CM4SpeedPID.output);//can1Êä³öµ×ÅÌËÙ¶È
}


