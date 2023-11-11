#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "App_Motor.h"
#include "line_patrol.h"
#include "OLED.h"
#include "pwm.h"
int main(void)
{
Motor_Init();
	TIM_SetCompare3(TIM1, 200);
	TIM_SetCompare2(TIM1, 300);
	OLED_GPIO_Init();
	OLED_Init();
	OLED_ShowString(1,1,"p:");
//	OLED_ShowString(2,1,"err:");
	//Car_Left(1000,1000);
	//Car_Stop();

	while (1)
	{
		Car_Run(1000);
		//app_LineWalking();
		OLED_ShowNum(1,3,PID_jc_Get(),4);     OLED_ShowNum(1,8,Num_Get(),2);
		OLED_ShowBinNum( 2,5,Gray_Sensor_Get(),4);
		OLED_ShowSignedNum(3,5,PID_output1_Get(),4);
		OLED_ShowSignedNum(4,5,PID_output2_Get(),4);
		OLED_ShowSignedNum(2,10,PID_err_Get(),2);
		OLED_ShowSignedNum(3,10,PID_last_err_Get(),2);
	}
}
