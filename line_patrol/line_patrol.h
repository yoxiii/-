#ifndef __LINE_PATROL_H__
#define __LINE_PATROL_H__


void TIM3_IRQHandler(void);
//void Line_Patrol(void);
void app_LineWalking(void);
int Position_PID (void);
int Position_P (void);
void Restrict(void);
int PID_jc_Get(void);
int PID_err_Get(void);
int PID_last_err_Get(void);
int PID_output1_Get(void);
int PID_output2_Get(void);
uint8_t Gray_Sensor_Get(void);
uint8_t Num_Get(void);
#endif
