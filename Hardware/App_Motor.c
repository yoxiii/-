#include "App_Motor.h"
#include "Motor.h"

#define  LeftMotor_Go()			{GPIO_SetBits(Motor_Port, Left_MotoA_Pin); GPIO_ResetBits(Motor_Port, Left_MotoB_Pin);}
#define  LeftMotor_Back()		{GPIO_ResetBits(Motor_Port, Left_MotoA_Pin); GPIO_SetBits(Motor_Port, Left_MotoB_Pin);}
#define  LeftMotor_Stop()		{GPIO_ResetBits(Motor_Port, Left_MotoA_Pin); GPIO_ResetBits(Motor_Port, Left_MotoB_Pin);}

#define  RightMotor_Go()		{GPIO_SetBits(Motor_Port, Right_MotoA_Pin); GPIO_ResetBits(Motor_Port, Right_MotoB_Pin);}
#define  RightMotor_Back()		{GPIO_ResetBits(Motor_Port, Right_MotoA_Pin); GPIO_SetBits(Motor_Port, Right_MotoB_Pin);}
#define  RightMotor_Stop()		{GPIO_ResetBits(Motor_Port, Right_MotoA_Pin); GPIO_ResetBits(Motor_Port, Right_MotoB_Pin);}

		

void Car_Run(int Speed)
{
	LeftMotor_Go();
	RightMotor_Go();
	LeftMotorPWM(Speed);		  
	RightMotorPWM(Speed);	
}
void Car_Run_Pid(int Speed1,int Speed2)
{if(Speed1>=0)
	{LeftMotor_Go();LeftMotorPWM(Speed1);}
	if(Speed1<0)
	{LeftMotor_Back();LeftMotorPWM(1300-Speed1);}
	if(Speed2>=0)
	{RightMotor_Go();RightMotorPWM(Speed2);	}
	if(Speed2<0)
	{RightMotor_Back();RightMotorPWM(1300-Speed2);	}

}
void Car_Back(int Speed)
{
	LeftMotor_Back();
	RightMotor_Back();

	LeftMotorPWM(Speed);		  
	RightMotorPWM(Speed);	
}
void Car_Left(int Speed1,int Speed2)
{
	LeftMotor_Go();
	RightMotor_Go();

	LeftMotorPWM(Speed1);		  
	RightMotorPWM(Speed2);		
}
void Car_Right(int Speed1,int Speed2)
{
	LeftMotor_Go();
	RightMotor_Go();

	LeftMotorPWM(Speed1);		  
	RightMotorPWM(Speed2);		
}

void Car_SpinLeft(int LeftSpeed, int RightSpeed)
{
	LeftMotor_Back();
	RightMotor_Go();
	LeftMotorPWM(LeftSpeed);		  
	RightMotorPWM(RightSpeed);	
}

void Car_SpinRight(int LeftSpeed, int RightSpeed)
{
	LeftMotor_Go();
	RightMotor_Back();
	LeftMotorPWM(LeftSpeed);		  
	RightMotorPWM(RightSpeed);	
}
void Car_Stop(void)
{
	LeftMotor_Stop();
	RightMotor_Stop();

	LeftMotorPWM(0);		  
	RightMotorPWM(0);		
}
