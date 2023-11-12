#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "App_Motor.h"
#include "line_patrol.h"
#include "OLED.h"
#include "pwm.h"
RCC_ClocksTypeDef get_rcc_clock;    //
int main(void)
{
Motor_Init();

	//OLED_GPIO_Init();
	OLED_Init();
	OLED_ShowString(1,1,"p:");
//	OLED_ShowString(2,1,"err:");
	//Car_Left(1000,1000);
	//Car_Stop();


RCC_GetClocksFreq(&get_rcc_clock); 
	while (1)
	{
Car_Left(700,800);
		//app_LineWalking();
		OLED_ShowNum(1,3,PID_jc_Get(),4);     OLED_ShowNum(1,8,Num_Get(),2);
		OLED_ShowBinNum( 2,5,Gray_Sensor_Get(),4);
		OLED_ShowSignedNum(3,5,PID_output1_Get(),4);
		OLED_ShowSignedNum(4,5,PID_output2_Get(),4);
		OLED_ShowSignedNum(2,10,PID_err_Get(),2);
		OLED_ShowSignedNum(3,10,PID_last_err_Get(),2);
	}
}
