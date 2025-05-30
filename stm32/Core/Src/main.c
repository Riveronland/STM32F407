#include "main.h"



TaskHandle_t handle_main_task;
static int cnt_main_task = 0;

uint8_t info[64];

void main_task(void *param)
{
    MX_GPIO_Init();
    MX_CAN1_Init();
    MX_USART1_UART_Init();
    MX_USART3_UART_Init();

    HAL_CAN_MspInit(&hcan1);
    HAL_UART_MspInit(&huart1);
    HAL_UART_MspInit(&huart3);

    while(1)
    {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        HAL_Delay(1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

// int sprintf(char *string, char *format [,argument,...]);

        sprintf((char *)info,"mea is : %ld\r\n",(echo_time - trig_time));

        cnt_main_task ++;
        HAL_UART_Transmit(&huart3, info, sizeof(info), 100);
        vTaskDelay(200);
    }
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();



    xTaskCreate( main_task,"main_task",300, 0, 2,&handle_main_task);

    vTaskStartScheduler();
}

