#include "stm32f10x.h"                  // Device header
#include "pid.h"
#include "line_patrol.h"
#include "App_Motor.h"

extern int error;
extern int a;

typedef struct
{
	 //相关速度PID参数
	float Kp;
	float Ki;
	float Kd;
	float Ur;				//限幅值
	
	uint8_t PID_is_Enabled;		//PID使能
	int Un;					//期望输出值
	int error_1;				//上一次的误差值
	int error_2;				//上上次的误差值
	int output;				//输出比较值
	
}PID_InitDefStruct;


void PID_Init(PID_InitDefStruct* p)
{
	p->Kp = 200;
	p->Ki = 0.5;
	p->Kd = 0;
	p->Ur = 3600;
	p->PID_is_Enabled = 1;
	p->Un = 0;
	p->error_1 = 0;
	p->error_2 = 0;
	p->output = 0;
}
 
void PID_Calc(int error,int a,PID_InitDefStruct* p)
{if(p->PID_is_Enabled == 1){
	static float Integral=0;
	Integral+=error;
	p->output = p->Kp * error + p->Ki * Integral + p->Kd * (error-p->error_1);
	p->error_2 = p->error_1;
  p->error_1 = error;

}}


