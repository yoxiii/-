#include "Motor.h"
#include "MOTOR_GPIO.h"
#include "line_gpio.h"
#include "line_patrol.h"
#include "pid.h"
#include "pwm.h"
void Motor_Init(void)
{
	MOTOR_GPIO_Init();
	motor_pwm_init();
	Line_GPIO_Init();
	//TIM3_Init_Init(99,71);//7199
	Timer_Init();
}
