
#include "main.h"

void NMI_Handler(void)
{
    while (1)
    {

    }
}

void HardFault_Handler(void)
{
    while (1)
    {

    }
}

void MemManage_Handler(void)
{
    while (1)
    {

    }
}

void BusFault_Handler(void)
{
    while (1)
    {

    }
}

void UsageFault_Handler(void)
{
    while (1)
    {

    }
}


void DebugMon_Handler(void)
{

}

// void SysTick_Handler(void)
// {

//   HAL_IncTick();
// }


void EXTI9_5_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_6)
    {
        trig_time = uwTick;
        while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)== 1)
        {
            echo_time = uwTick;
        }  
    }
    
}



void CAN1_RX0_IRQHandler(void)
{
    HAL_CAN_IRQHandler(&hcan1);
}

void USART1_IRQHandler(void)
{
    HAL_UART_IRQHandler(&huart1);
}
void USART3_IRQHandler(void)
{
    HAL_UART_IRQHandler(&huart3);
}


