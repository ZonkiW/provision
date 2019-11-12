#include "main.h"

/*
变量初始化
*/

int16_t ch0=1024;
int16_t ch1=1024;
int16_t ch2=1024;
int16_t ch3=1024;
int16_t s1=0;
int16_t s2=0;
int16_t left_right_ref=0;
int16_t forward_back_ref=0;
int16_t rotate_ref=0;
float up_down_ref=0;
int16_t Gyro[3];
int16_t encoder_cout=0;
int16_t encoder_cout1=0;
int16_t DEBUG=0;
int16_t STEERING_1_HANDLE=yes;
int16_t ammo_out_count=0;
int16_t ammo_handle_count=0;
double CM1PositionPID_ref=0;

int16_t DEBUG1=0;
int16_t DEBUG2=0;
int16_t DEBUG3=0;
int16_t DEBUG4=0;
int16_t DEBUG5=0;
int16_t DEBUG6=0;
int16_t motor_around_flag=0;
int16_t motor_around_count=0;
int16_t motor_around_order_flag=0;
int32_t MOTOR_SECOND_STATE_count=0;
int32_t MOTOR_INTER_STATE_count=1667;

int32_t PB14_count=0;
int32_t PB9_count=0;
int32_t PB15_count=0;
int32_t PA8_count=0;
int32_t PA9_count=0;
int32_t PA10_count=0;
int32_t channel1_count=1;
int32_t channel2_count=0;
int32_t channel3_count=0;
int16_t channel1_taken_flag=no;
int16_t channel2_taken_flag=no;
int16_t channel3_taken_flag=no;

RampGen_t GMPitchRamp  = RAMP_GEN_DAFAULT;
RampGen_t GMYawRamp = RAMP_GEN_DAFAULT;
RampGen_t frictionRamp = RAMP_GEN_DAFAULT;   //摩擦轮斜坡

STEERING_State STEERING_1=CLOSE_STATE;
STEERING_State LAST_STEERING_1=CLOSE_STATE;
STEERING_State STEERING_2=CLOSE_STATE;
STEERING_State LAST_STEERING_2=CLOSE_STATE;
STEERING_State STEERING_3=CLOSE_STATE;
STEERING_State LAST_STEERING_3=CLOSE_STATE;
MOTOR_POSITION motor_position=MOTOR_POSITION1;
MOTOR_AROUND_STATE motor_around_state=MOTOR_FIRST_STATE;
LIGHT_State light_state1=BLACK_STATE;
LIGHT_State light_state2=BLACK_STATE;
LIGHT_State light_state3=BLACK_STATE;
CHANNEL_STATE channel1_state=NO_STATE;
CHANNEL_STATE channel2_state=NO_STATE;
CHANNEL_STATE channel3_state=NO_STATE;
 

PID_Regulator CM1SpeedPID = CHASSIS_MOTOR_SPEED_PID_DEFAULT;
PID_Regulator CM1PositionPID=CM1_POSITION_PID_DEFAULT;
PID_Regulator CM2SpeedPID = CHASSIS_MOTOR_SPEED_PID_DEFAULT;
PID_Regulator CM3SpeedPID = CHASSIS_MOTOR_SPEED_PID_DEFAULT;
PID_Regulator CM4SpeedPID = CHASSIS_MOTOR_SPEED_PID_DEFAULT;
PID_Regulator CM7PositionPID = BOLUN_POSITION_PID_DEFAULT;
PID_Regulator CM7SpeedPID = BOLUN_SPEED_PID_DEFAULT;
PID_Regulator GMPPositionPID = GIMBAL_MOTOR_PITCH_POSITION_PID_DEFAULT;     
PID_Regulator GMPSpeedPID 	 = GIMBAL_MOTOR_PITCH_SPEED_PID_DEFAULT;
PID_Regulator GMYPositionPID = GIMBAL_MOTOR_YAW_POSITION_PID_DEFAULT;			
PID_Regulator GMYSpeedPID 	 = GIMBAL_MOTOR_YAW_SPEED_PID_DEFAULT;


volatile Encoder CM1Encoder			= {0,0,0,0,0,0,0,{0,0,0,0,0,0},0,0,0};
volatile Encoder CM2Encoder			= {0,0,0,0,0,0,0,{0,0,0,0,0,0},0,0,0};
volatile Encoder CM3Encoder			= {0,0,0,0,0,0,0,{0,0,0,0,0,0},0,0,0};
volatile Encoder CM4Encoder		 	= {0,0,0,0,0,0,0,{0,0,0,0,0,0},0,0,0};
volatile Encoder CM7Encoder		 	= {0,0,0,0,0,0,0,{0,0,0,0,0,0},0,0,0};
volatile Encoder GMPitchEncoder		 	= {0,0,0,0,0,0,0,{0,0,0,0,0,0},0,0,0};
volatile Encoder GMYawEncoder		 	= {0,0,0,0,0,0,0,{0,0,0,0,0,0},0,0,0};
