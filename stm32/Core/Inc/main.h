
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "stm32f4xx_it.h"
#include "stm32f4xx_hal_conf.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "queue.h" 
#include "croutine.h"

#include "string.h"
#include "stdint.h"
#include "stdio.h"


extern uint32_t trig_time;
extern uint32_t echo_time;

extern CAN_HandleTypeDef  hcan1;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

void SystemClock_Config(void);
void Error_Handler(void);


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

void HAL_CAN_MspInit(CAN_HandleTypeDef* hcan);
void HAL_CAN_MspDeInit(CAN_HandleTypeDef* hcan);
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart);
void HAL_UART_MspInit(UART_HandleTypeDef* huart);

void MX_GPIO_Init(void);
void MX_CAN1_Init(void);
void MX_USART1_UART_Init(void);
void MX_USART3_UART_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
