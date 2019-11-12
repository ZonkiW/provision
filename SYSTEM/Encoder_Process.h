#ifndef __Encoder_Process_H__
#define __Encoder_Process_H__
#include <stm32f4xx.h>
#include "BIANLIANG_Definition.h"

void GetEncoderBias(volatile Encoder *v, CanRxMsg * msg);
void Motor_3510_EncoderProcess(volatile Encoder *v, CanRxMsg * msg);
void Motor_6623_EncoderProcess(volatile Encoder *v, CanRxMsg * msg);
void Motor_2310_EncoderProcess(volatile Encoder *v, CanRxMsg * msg);

void CanReceiveMsgProcess(CanRxMsg * msg);
#endif

