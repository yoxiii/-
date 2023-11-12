#ifndef __PWM_H
#define __PWM_H


//void PWM1_SetCompare4(uint16_t Compare);
//void Servo_HorizentalAngle(uint16_t angle);
//void TIM4_PWM_Init(u16 arr,u16 psc);

#include "stm32f10x.h"

void motor_pwm_init(void);
void Timer_Init(void);
#endif
