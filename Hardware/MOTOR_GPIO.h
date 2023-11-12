#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__	



#define Motor_RCC		 RCC_APB2Periph_GPIOB
#define Motor_Port		 GPIOB
#define Left_MotoA_Pin 	 GPIO_Pin_9
#define Left_MotoB_Pin 	 GPIO_Pin_8

#define Right_MotoA_Pin	 GPIO_Pin_4
#define Right_MotoB_Pin  GPIO_Pin_5

void MOTOR_GPIO_Init(void);

#endif
