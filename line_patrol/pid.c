#include "stm32f10x.h"                  // Device header
#include "pid.h"
#include "line_patrol.h"
#include "App_Motor.h"

extern int error;
extern int a;

typedef struct
{
	 //����ٶ�PID����
	float Kp;
	float Ki;
	float Kd;
	float Ur;				//�޷�ֵ
	
	uint8_t PID_is_Enabled;		//PIDʹ��
	int Un;					//�������ֵ
	int error_1;				//��һ�ε����ֵ
	int error_2;				//���ϴε����ֵ
	int output;				//����Ƚ�ֵ
	
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


