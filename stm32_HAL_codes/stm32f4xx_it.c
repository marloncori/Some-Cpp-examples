#include "stn32f4xx.h"
#include "stn32f4xx_hal.h"
#include "stn32f4xx_it.h"

extern uint16_t tDelay;

void SysTick_Handler(void)
{
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}

void RCC_IRQHandler(void)
{
    //user code for irqn
}

void EXIT15_10_IRQHandler(void)
{
    int i;
    for(i = 0; i < 65535; i++)
    {
        if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13))
        {
            if(tDelay == 250)
            {
                tDelay = 1000;
            }
            else
            {
                tDelay = 250;
            }
        }
    }
}