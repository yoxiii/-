#ifndef __APP_MOTOR_H__
#define __APP_MOTOR_H__


#include "MOTOR_GPIO.h"
#define  LeftMotorPWM(Speed)	TIM_SetCompare2(TIM1, Speed);
#define  RightMotorPWM(Speed)	TIM_SetCompare3(TIM1, Speed);


void Car_Run(int Speed);
void Car_Run_Pid(int Speed1,int Speed2);
void Car_Back(int Speed);
void Car_Left(int Speed1,int Speed2);
void Car_Right(int Speed1,int Speed2);
void Car_Stop(void);
void Car_SpinStop(void);
void Car_SpinLeft(int LeftSpeed, int RightSpeed);
void Car_SpinRight(int LeftSpeed, int RightSpeed);


#endif
