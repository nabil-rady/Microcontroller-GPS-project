#include <int/tm4c123gh6pm.h>
#include <stdio.h>
#include <cmath>
////*                SYSTICK TIMER       *////
void systick_int (void)
{
    NVIC_ST_CTRL_R=0;
    NVIC_ST_RELOAD_R=0X00FFFFFF;
    NVIC_ST_CURRENT_R=0;
    NVIC_ST_CTRL_R=0X05; // Enabling the timer with the processor clock //
}
void systick_delay (uint32_t ms)
{
    uint32_t counts=(ms*10^-3)/(12.5*10^-9);
    NVIC_ST_CTRL_R=0;
    NVIC_ST_RELOAD_R=counts;
    NVIC_ST_CURRENT_R=0;
    while (NVIC_ST_CTRL_R&0x10000==0)
    {}
}
void systick_double(uint32_t double,uint32_t counts)
{
    unsigned long i;
    for (i=0;i<double;i++)
    {
        //Enter delay in milli seconds)
        //10 ms delay
        systick_delay(10);
        
    }
}