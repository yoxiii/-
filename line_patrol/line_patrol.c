#include "stm32f10x.h"                  // Device header
#include "line_patrol.h"
#include "line_gpio.h"
#include "App_Motor.h"
#include "Delay.h"
#include "sys.h"
/*������Ϊ0���ô������ں�����*/
//void Line_Patrol(void)
//{
//		int L1=1,L2=1,R1=1,R2=1;
//		bsp_GetLineWalking(&L1,&L2,&R1,&R2);
////	if((L1==0||L2==0)&&R2==0)
////		{
////     Car_SpinLeft(1200, 1200);
////		Delay_ms(80);
////    }
//	
//	if (L2==0&&R1==0)
//	{Car_Run(1200);
//	Delay_ms(10);
//	}
//	else
//		Car_Stop();
//}

//int last_status=0;  
//int status_history[4];

	
//	float Kp=0.7;
//	float Ki=0.5;
//	float Kd=0;
float Gain=1;
static int a;
static float error,error_1;
//static float integral;
static int output1=1600,output2=1600;
static int output1_target=1600,output2_target=1600;
int PID_sd=0;//С������PID��������PWM���ֵ

static int PID_jc=0;//С�������ٶ�PID��������PWM���ֵ
static uint8_t Gray_Sensor=0;
static int num=0;
static int progressive=50;
//void TIM3_IRQHandler(void)   //TIM3�жϷ�����
//{
//	if(TIM3->SR&0X0001)//��ʱ��ÿ10ms��ʱ�ж�һ��
//	{TIM3->SR&=~(1<<0);
	
	
	void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		
		
		PID_sd=Position_PID()*(Gain);
		PID_jc=Position_P()*Gain;
		Restrict();
		num++;
		 Car_Run_Pid(output1,output2);
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

	
		
		
//	}
//}
void app_LineWalking(void)
{
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;

	bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	//��ȡ���߼��״̬	

	 Gray_Sensor=(uint8_t)((LineL1 << 3) | (LineL2 << 2) | (LineR1 << 1) | LineR2);



	

	
	
	if(Gray_Sensor==0x0B)        //1011
	{error=-10;a=0;	}
	else if(Gray_Sensor==0x0D)     // 1101 
		
	{error=10;a=0;}
	else if(Gray_Sensor==0x03)    //0011   //0111->0011
	{	if(error_1==-30)
		{	error=error_1;a=20;}
		else
	error=-20;a=10;}
	
	else if(Gray_Sensor==0x07)  // 0111 
	{error=-30;a=20;}
	else if(Gray_Sensor==0x0E)  //1110
	{error=30;a=20;}
	
	else if(Gray_Sensor==0x01||Gray_Sensor==0x05)  //0001   0101 
	{error=-45;a=20;}
	else if(Gray_Sensor==0x08||Gray_Sensor==0x0A)  //  1010 1000
	{error=45;a=20;}
	
	else if(Gray_Sensor==0x0C)   // 1100  //1110->1100
	{if(error_1==30)
		{	error=error_1;a=20;}
		else
	error=20;a=20;}
	else if(Gray_Sensor==0x09) //1001
//	{if(error_1==-45||error_1==45)
//		{error=error_1;a=20;}
//		else
{	error=0;a=00;}
	
		else if(Gray_Sensor==0x0F)  //1111
	{error=error_1;a=20;}
		else if(Gray_Sensor==0x00)  //0000
	{error=error_1;a=20;}
		
//integral+=error;
//	output=KP*error+Ki*integral+Kd*(error-error_1);
//	error_1=error;
//	if((100-output)<0)output=-100;
//	if((100+output)>3600)output=3500;
//Car_Run_Pid(100+output,100-output);
}

int Position_PID (void)
{
	float KP=50,KI=0,KD=7.7;  //  80   0    7
	static float pwm,integral;
	integral+=error;
	pwm=KP*error+KI*integral+KD*(error-error_1);
	//if(error_1!=error)
	error_1=error;
	return pwm;
}
int Position_P (void)
{
	float KP=8.5,KD=9;   //100  60    %100   80  100
 	static float pwm,integral;
	integral+=error;
	pwm=1600-KP*error+KD*(error-error_1);
	error_1=error;
	return pwm;
}
void Restrict(void)
{
	output1_target=PID_jc+PID_sd;//�����ٶ�+�ٶ�ƫ���� //�����ٶ�Ҳ���Ժ㶨Ϊĳ��ֵ�����������ٺͶ���ͱȽϺõ�
  output2_target=PID_jc-PID_sd;//�����ٶ�-�ٶ�ƫ����
	if(output1<output1_target)
		output1+=progressive;
	else if(output1>output1_target)
		output1-=progressive;
	else if(output1==output1_target)
		output1=output1_target;
	if(output2<output2_target)
		output2+=progressive;
	else if(output2>output2_target)
		output2-=progressive;
	else if(output2==output2_target)
		output2=output2_target;
//	if(output1_target>3600)output1_target=3600;
//		if(output1_target<0)output1_target=0;
//		if(output2_target>3600)output2_target=3600;
//		if(output2_target<0)output2_target=0;
}


int PID_jc_Get(void)   //�ú�������Ļ����pid����
{return PID_jc;}
int PID_err_Get(void)
{return error;}
int PID_last_err_Get(void)
{return error;}
int PID_output1_Get(void)
{return output1;}
int PID_output2_Get(void)
{return output2;}
uint8_t Gray_Sensor_Get(void)
{return Gray_Sensor;}
uint8_t Num_Get(void)
{return num;}
