#ifndef __BIANLIANG_Definition_H
#define __BIANLIANG_Definition_H
#include <stm32f4xx.h>

/*
变量定义
*/

#define USART_REC_LEN3  			200  
#define IMU_DMA_RX_BUF_LEN    72u
#define IMU_FRAME_LENGTH      41u

#define HIGH_LEVEL  			    1
#define LOW_LEVEL  			      1 

#define PA0_high();  GPIO_SetBits(GPIOA,GPIO_Pin_0);
#define PA1_high();  GPIO_SetBits(GPIOA,GPIO_Pin_1);
#define PA2_high();  GPIO_SetBits(GPIOA,GPIO_Pin_2);
#define PA3_high();  GPIO_SetBits(GPIOA,GPIO_Pin_3);
#define PA4_high();  GPIO_SetBits(GPIOA,GPIO_Pin_4);
#define PA5_high();  GPIO_SetBits(GPIOA,GPIO_Pin_5);
#define PA6_high();  GPIO_SetBits(GPIOA,GPIO_Pin_6);
#define PA7_high();  GPIO_SetBits(GPIOA,GPIO_Pin_7);
#define PA8_high();  GPIO_SetBits(GPIOA,GPIO_Pin_8);
#define PA9_high();  GPIO_SetBits(GPIOA,GPIO_Pin_9);
#define PA10_high(); GPIO_SetBits(GPIOA,GPIO_Pin_10);

#define PB0_high();  GPIO_SetBits(GPIOB,GPIO_Pin_0);
#define PB1_high();  GPIO_SetBits(GPIOB,GPIO_Pin_1);
#define PB2_high();  GPIO_SetBits(GPIOB,GPIO_Pin_2);
#define PB3_high();  GPIO_SetBits(GPIOB,GPIO_Pin_3);
#define PB4_high();  GPIO_SetBits(GPIOB,GPIO_Pin_4);
#define PB5_high();  GPIO_SetBits(GPIOB,GPIO_Pin_5);
#define PB6_high();  GPIO_SetBits(GPIOB,GPIO_Pin_6);
#define PB7_high();  GPIO_SetBits(GPIOB,GPIO_Pin_7);
#define PB8_high();  GPIO_SetBits(GPIOB,GPIO_Pin_8);
#define PB9_high();  GPIO_SetBits(GPIOB,GPIO_Pin_9);
#define PB10_high(); GPIO_SetBits(GPIOB,GPIO_Pin_10);

#define PC0_high();  GPIO_SetBits(GPIOC,GPIO_Pin_0);
#define PC1_high();  GPIO_SetBits(GPIOC,GPIO_Pin_1);
#define PC2_high();  GPIO_SetBits(GPIOC,GPIO_Pin_2);
#define PC3_high();  GPIO_SetBits(GPIOC,GPIO_Pin_3);
#define PC4_high();  GPIO_SetBits(GPIOC,GPIO_Pin_4);
#define PC5_high();  GPIO_SetBits(GPIOC,GPIO_Pin_5);
#define PC6_high();  GPIO_SetBits(GPIOC,GPIO_Pin_6);
#define PC7_high();  GPIO_SetBits(GPIOC,GPIO_Pin_7);
#define PC8_high();  GPIO_SetBits(GPIOC,GPIO_Pin_8);
#define PC9_high();  GPIO_SetBits(GPIOC,GPIO_Pin_9);
#define PC10_high(); GPIO_SetBits(GPIOC,GPIO_Pin_10);
#define PC13_high(); GPIO_SetBits(GPIOC,GPIO_Pin_13);
#define PC14_high(); GPIO_SetBits(GPIOC,GPIO_Pin_14);
#define PC15_high(); GPIO_SetBits(GPIOC,GPIO_Pin_15);

#define PD0_high();  GPIO_SetBits(GPIOD,GPIO_Pin_0);
#define PD1_high();  GPIO_SetBits(GPIOD,GPIO_Pin_1);
#define PD2_high();  GPIO_SetBits(GPIOD,GPIO_Pin_2);
#define PD3_high();  GPIO_SetBits(GPIOD,GPIO_Pin_3);
#define PD4_high();  GPIO_SetBits(GPIOD,GPIO_Pin_4);
#define PD5_high();  GPIO_SetBits(GPIOD,GPIO_Pin_5);
#define PD6_high();  GPIO_SetBits(GPIOD,GPIO_Pin_6);
#define PD7_high();  GPIO_SetBits(GPIOD,GPIO_Pin_7);
#define PD8_high();  GPIO_SetBits(GPIOD,GPIO_Pin_8);
#define PD9_high();  GPIO_SetBits(GPIOD,GPIO_Pin_9);
#define PD10_high(); GPIO_SetBits(GPIOD,GPIO_Pin_10);

#define PA0_low();  GPIO_ResetBits(GPIOA,GPIO_Pin_0);
#define PA1_low();  GPIO_ResetBits(GPIOA,GPIO_Pin_1);
#define PA2_low();  GPIO_ResetBits(GPIOA,GPIO_Pin_2);
#define PA3_low();  GPIO_ResetBits(GPIOA,GPIO_Pin_3);
#define PA4_low();  GPIO_ResetBits(GPIOA,GPIO_Pin_4);
#define PA5_low();  GPIO_ResetBits(GPIOA,GPIO_Pin_5);
#define PA6_low();  GPIO_ResetBits(GPIOA,GPIO_Pin_6);
#define PA7_low();  GPIO_ResetBits(GPIOA,GPIO_Pin_7);
#define PA8_low();  GPIO_ResetBits(GPIOA,GPIO_Pin_8);
#define PA9_low();  GPIO_ResetBits(GPIOA,GPIO_Pin_9);
#define PA10_low(); GPIO_ResetBits(GPIOA,GPIO_Pin_10);

#define PB0_low();  GPIO_ResetBits(GPIOB,GPIO_Pin_0);
#define PB1_low();  GPIO_ResetBits(GPIOB,GPIO_Pin_1);
#define PB2_low();  GPIO_ResetBits(GPIOB,GPIO_Pin_2);
#define PB3_low();  GPIO_ResetBits(GPIOB,GPIO_Pin_3);
#define PB4_low();  GPIO_ResetBits(GPIOB,GPIO_Pin_4);
#define PB5_low();  GPIO_ResetBits(GPIOB,GPIO_Pin_5);
#define PB6_low();  GPIO_ResetBits(GPIOB,GPIO_Pin_6);
#define PB7_low();  GPIO_ResetBits(GPIOB,GPIO_Pin_7);
#define PB8_low();  GPIO_ResetBits(GPIOB,GPIO_Pin_8);
#define PB9_low();  GPIO_ResetBits(GPIOB,GPIO_Pin_9);
#define PB10_low(); GPIO_ResetBits(GPIOB,GPIO_Pin_10);

#define PC0_low();  GPIO_ResetBits(GPIOC,GPIO_Pin_0);
#define PC1_low();  GPIO_ResetBits(GPIOC,GPIO_Pin_1);
#define PC2_low();  GPIO_ResetBits(GPIOC,GPIO_Pin_2);
#define PC3_low();  GPIO_ResetBits(GPIOC,GPIO_Pin_3);
#define PC4_low();  GPIO_ResetBits(GPIOC,GPIO_Pin_4);
#define PC5_low();  GPIO_ResetBits(GPIOC,GPIO_Pin_5);
#define PC6_low();  GPIO_ResetBits(GPIOC,GPIO_Pin_6);
#define PC7_low();  GPIO_ResetBits(GPIOC,GPIO_Pin_7);
#define PC8_low();  GPIO_ResetBits(GPIOC,GPIO_Pin_8);
#define PC9_low();  GPIO_ResetBits(GPIOC,GPIO_Pin_9);
#define PC10_low(); GPIO_ResetBits(GPIOC,GPIO_Pin_10);
#define PC13_low(); GPIO_ResetBits(GPIOC,GPIO_Pin_13);
#define PC14_low(); GPIO_ResetBits(GPIOC,GPIO_Pin_14);
#define PC15_low(); GPIO_ResetBits(GPIOC,GPIO_Pin_15);

#define PD0_low();  GPIO_ResetBits(GPIOD,GPIO_Pin_0);
#define PD1_low();  GPIO_ResetBits(GPIOD,GPIO_Pin_1);
#define PD2_low();  GPIO_ResetBits(GPIOD,GPIO_Pin_2);
#define PD3_low();  GPIO_ResetBits(GPIOD,GPIO_Pin_3);
#define PD4_low();  GPIO_ResetBits(GPIOD,GPIO_Pin_4);
#define PD5_low();  GPIO_ResetBits(GPIOD,GPIO_Pin_5);
#define PD6_low();  GPIO_ResetBits(GPIOD,GPIO_Pin_6);
#define PD7_low();  GPIO_ResetBits(GPIOD,GPIO_Pin_7);
#define PD8_low();  GPIO_ResetBits(GPIOD,GPIO_Pin_8);
#define PD9_low();  GPIO_ResetBits(GPIOD,GPIO_Pin_9);
#define PD10_low(); GPIO_ResetBits(GPIOD,GPIO_Pin_10);

#define PA0        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) 
#define PA1        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)
#define PA2        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)
#define PA3        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)
#define PA4        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)
#define PA5        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
#define PA6        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)
#define PA7        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)
#define PA8        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)
#define PA9        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_9)
#define PA10       GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10)

#define PB0        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) 
#define PB1        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
#define PB2        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)
#define PB3        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)
#define PB4        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)
#define PB5        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)
#define PB6        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)
#define PB7        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)
#define PB8        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)
#define PB9        GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)
#define PB10       GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)
#define PB14       GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)
#define PB15       GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)

#define PC0        GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0) 
#define PC1        GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)
#define PC2        GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)
#define PC3        GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)
#define PC4        GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)
#define PC5        GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)
#define PC6        GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)
#define PC7        GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)
#define PC8        GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8)
#define PC9        GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)
#define PC10       GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_10)

#define PD0        GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_0) 
#define PD1        GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_1)
#define PD2        GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)
#define PD3        GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)
#define PD4        GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)
#define PD5        GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_5)
#define PD6        GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)
#define PD7        GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_7)
#define PD8        GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_8)
#define PD9        GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_9)
#define PD10       GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_10)

#define enough     0
#define not_enough 1
#define yes        1
#define no         0
#define ammo_out_count_value    600
#define ammo_handle_count_value 1000

#define MOTOR_SECOND_STATE_value 3333
#define min_value                20000

#define CM1PositionPID_kp    15.0
#define CM1PositionPID_ki    0
#define CM1PositionPID_kd    0

#define CM1SpeedPID_kp       15.0
#define CM1SpeedPID_ki       0
#define CM1SpeedPID_kd       0

#define motor_init_angle     0
#define motor_second_angle   120
#define motor_third_angle    240

#define far                  1
#define near                 0
#define motor_around_count_value  400
#define delay_value         600

typedef struct PID_Regulator
{
	double ref;
	double fdb;
	double err[2];
	double kp;
	double ki;
	double kd;
	double componentKp;
	double componentKi;
	double componentKd;
	double componentKpMax;
	double componentKiMax;
	double componentKdMax;
	double output;
	double outputMax;
	void (*Calc)(struct PID_Regulator *pid);//函数指针
	void (*Reset)(struct PID_Regulator *pid);
	double componentoutput;
	double jump_out;
	double Reset_i;
}PID_Regulator;

typedef __packed struct
{
	uint32_t time_last;
	uint32_t time_now;
	int32_t time_error;
	uint8_t flag;
}Time_Count;


//20.0f 0.5f
#define CHASSIS_MOTOR_SPEED_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	20.0f,\
	0.5f,\
	0.0f,\
	0,\
	0,\
	0,\
	5000,\
	3500,\
	1500,\
	0,\
	5000,\
	&PID_Calc,\
	&PID_Reset,\
	0,\
	0,\
	0,\
}\

#define GIMBAL_MOTOR_PITCH_POSITION_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	0,\
	0,\
	0,\
	0,\
	0,\
	0,\
	4900,\
	1000,\
	1500,\
	0,\
	4900,\
	&PID_Calc,\
	&PID_Reset,\
	0,\
	0,\
	0,\
}\

#define CM1_POSITION_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	0,\
	0,\
	0,\
	0,\
	0,\
	0,\
	4900,\
	1000,\
	1500,\
	0,\
	4900,\
	&PID_Calc,\
	&PID_Reset,\
	0,\
	0,\
	0,\
}\

#define GIMBAL_MOTOR_PITCH_SPEED_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	0,\
	0,\
	0,\
	0,\
	0,\
	0,\
	5000,\
	3500,\
	1500,\
	0,\
	5000,\
	&PID_Calc,\
	&PID_Reset,\
	0,\
	3,\
	0,\
}\

#define GIMBAL_MOTOR_YAW_POSITION_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	0,\
	0,\
	0,\
	0,\
	0,\
	0,\
	4900,\
	1000,\
	1500,\
	0,\
	5000,\
	&PID_Calc,\
	&PID_Reset,\
	0,\
	0,\
	1,\
}\


#define GIMBAL_MOTOR_YAW_SPEED_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	0,\
	0,\
	0,\
	0,\
	0,\
	0,\
	4900,\
	1000,\
	1500,\
	0,\
	4900,\
	&PID_Calc,\
	&PID_Reset,\
	0,\
	3,\
	0,\
}\

#define RAMP_GEN_DAFAULT \
{ \
							.count = 0, \
							.XSCALE = 0, \
							.out = 0, \
							.Init = &RampInit, \
							.Calc = &RampCalc, \
							.SetCounter = &RampSetCounter, \
							.ResetCounter = &RampResetCounter, \
							.SetScale = &RampSetScale, \
							.IsOverflow = &RampIsOverflow, \
} \

#define BOLUN_POSITION_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	0,\
	0,\
	0,\
	0,\
	0,\
	0,\
	4900,\
	1000,\
	1500,\
	0,\
	4900,\
	&PID_Calc,\
	&PID_Reset,\
	0,\
	0,\
	0,\
}\

#define BOLUN_SPEED_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	20.0f,\
	1.0f,\
	0.0f,\
	0,\
	0,\
	0,\
	5000,\
	3500,\
	1500,\
	0,\
	5000,\
	&PID_Calc,\
	&PID_Reset,\
	0,\
	0,\
	0,\
}\

#define VAL_LIMIT(val, min, max)\
if(val<=min)\
{\
	val = min;\
}\
else if(val>=max)\
{\
	val = max;\
}\

#define VAL_LIMIT2(val, min, max)\
if(val<=min)\
{\
	val = min;\
}\
else if(val>max)\
{\
	val = min;\
}\

#define TIME_COUNT_INIT \
{\
	0,\
	0,\
	0,\
	0,\
}\

#define CAN_BUS1_MOTOR1_FEEDBACK_MSG_ID           0x201
#define CAN_BUS1_MOTOR2_FEEDBACK_MSG_ID           0x202 
#define CAN_BUS1_MOTOR3_FEEDBACK_MSG_ID           0x203
#define CAN_BUS1_MOTOR4_FEEDBACK_MSG_ID           0x204
#define CAN_BUS1_MOTOR5_FEEDBACK_MSG_ID           0x205
#define CAN_BUS1_MOTOR6_FEEDBACK_MSG_ID           0x206
#define CAN_BUS1_MOTOR7_FEEDBACK_MSG_ID           0x207
#define RATE_BUF_SIZE 6

typedef enum//枚举型类
{    
  CLOSE_STATE,
	OPEN_STATE,
}STEERING_State;

typedef enum//枚举型类
{    
  BRIGHT_STATE,
	BLACK_STATE,
}LIGHT_State;

typedef enum//枚举型类
{    
  YES_STATE,
	NO_STATE,
}CHANNEL_STATE;

typedef enum//枚举型类
{    
  MOTOR_POSITION1,
	MOTOR_POSITION2,
	MOTOR_POSITION3,
}MOTOR_POSITION;

typedef enum//枚举型类
{    
  MOTOR_FIRST_STATE,
	MOTOR_SECOND_STATE,
	MOTOR_INTER_STATE,
}MOTOR_AROUND_STATE;

typedef struct{
	int32_t raw_value;   									//编码器不经处理的原始值
	int32_t last_raw_value;								//上一次的编码器原始值
	int32_t ecd_value;                       //经过处理后连续的编码器值
	int32_t diff;													//两次编码器之间的差值,可以理解为速度
	uint8_t buf_count;								//滤波更新buf用
	int32_t ecd_bias;											//初始编码器值	
	int32_t ecd_raw_rate;									//通过编码器计算得到的速度原始值
	int32_t rate_buf[RATE_BUF_SIZE];	//保存RATE_BUF_SIZE次的diff
	int32_t round_cnt;										//记录圈数
	int32_t filter_rate;											//速度,对diff識ATE_BUF_SIZE次平均
	double ecd_angle;											//角度
}Encoder;

typedef struct RampGen_t
{
	int32_t count;
	int32_t XSCALE;
	float out;
	void (*Init)(struct RampGen_t *ramp, int32_t XSCALE);
	float (*Calc)(struct RampGen_t *ramp);
	void (*SetCounter)(struct RampGen_t *ramp, int32_t count);
	void (*ResetCounter)(struct RampGen_t *ramp);
	void (*SetScale)(struct RampGen_t *ramp, int32_t scale);
	uint8_t (*IsOverflow)(struct RampGen_t *ramp);
}RampGen_t;


extern float pitch_angle_static_ref;
extern float yaw_angle_static_ref;

extern volatile Encoder CM1Encoder;
extern volatile Encoder CM2Encoder;
extern volatile Encoder CM3Encoder;
extern volatile Encoder CM4Encoder;
extern volatile Encoder CM7Encoder;
extern volatile Encoder GMPitchEncoder;
extern volatile Encoder GMYawEncoder;

extern int16_t ch0;
extern int16_t ch1;
extern int16_t ch2;
extern int16_t ch3;
extern int16_t s1;
extern int16_t s2;
extern int16_t forward_back_ref;
extern int16_t left_right_ref;
extern int16_t rotate_ref;
extern int16_t encoder_cout;
extern int16_t encoder_cout1;
extern float up_down_ref;
extern u8  USART_RX_BUF3[USART_REC_LEN3]; 
extern u16 USART_RX_STA3;  
extern PID_Regulator CM1SpeedPID;
extern PID_Regulator CM1PositionPID;

extern PID_Regulator CM2SpeedPID;
extern PID_Regulator CM3SpeedPID;
extern PID_Regulator CM4SpeedPID;
extern PID_Regulator CM7PositionPID;
extern PID_Regulator CM7SpeedPID;
extern PID_Regulator GMPPositionPID;     
extern PID_Regulator GMPSpeedPID;
extern PID_Regulator GMYPositionPID;			
extern PID_Regulator GMYSpeedPID;
extern int16_t Gyro[3];
extern RampGen_t GMPitchRamp;
extern RampGen_t GMYawRamp;
extern RampGen_t frictionRamp;   //摩擦轮斜坡
extern int16_t DEBUG1;
extern int16_t DEBUG2;
extern int16_t DEBUG3;
extern int16_t DEBUG4;
extern int16_t DEBUG5;
extern int16_t DEBUG6;
extern int16_t ammo_out_count;
extern int16_t motor_around_flag;
extern int16_t motor_around_count;
extern int16_t motor_around_order_flag;
extern int16_t ammo_handle_count;
extern int32_t PB14_count;
extern int32_t PB9_count;
extern int32_t PB15_count;
extern int32_t PA8_count;
extern int32_t PA9_count;
extern int32_t PA10_count;
extern int32_t MOTOR_SECOND_STATE_count;
extern int32_t channel1_count;
extern int32_t channel2_count;
extern int32_t channel3_count;
extern int32_t MOTOR_INTER_STATE_count;

extern int16_t channel1_taken_flag;
extern int16_t channel2_taken_flag;
extern int16_t channel3_taken_flag;

extern int16_t STEERING_1_HANDLE;
extern STEERING_State STEERING_1;
extern STEERING_State LAST_STEERING_1;
extern STEERING_State STEERING_2;
extern STEERING_State LAST_STEERING_2;
extern STEERING_State STEERING_3;
extern STEERING_State LAST_STEERING_3;
extern MOTOR_POSITION motor_position;
extern MOTOR_AROUND_STATE motor_around_state;

extern LIGHT_State light_state1;
extern LIGHT_State light_state2;
extern LIGHT_State light_state3;

extern CHANNEL_STATE channel1_state;
extern CHANNEL_STATE channel2_state;
extern CHANNEL_STATE channel3_state;

extern double CM1PositionPID_ref;

#endif


