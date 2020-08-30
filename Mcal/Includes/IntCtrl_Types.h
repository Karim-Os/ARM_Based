/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
RESET=1,
NMI=2,
HARD_FAULT=3,
MEMORY_MANAGEMENT=4,
BUS_FAULT=5,
USAGE_FAULT=6,
SV_CALL=11,
DEBUG_MONITOR=12,
PENDSV=14,
SYS_TICK=15,
/*Interrupts (Vector Number = Interrupt Number + 16)*/
GPIO_PORT_A=16,
GPIO_PORT_B=17,
GPIO_PORT_C=18,
GPIO_PORT_D=19,
GPIO_PORT_E=20,
UART_0=21,
UART1=22,
SSI0=23,
I2C0=24,
PWM0_FAULT=25,
PWM0_GENERATOR0=26,
PWM0_GENERATOR1=27,
PWM0_GENERATOR2=28,
QEI0=29,
ADC0_SEQUENCE0=30,
ADC0_SEQUENCE1=31,
ADC0_SEQUENCE2=32,
ADC0_SEQUENCE3=33,
WATCHDOG_TIMERS=34,
TIMER_16_32_0A=35,
TIMER_16_32_0B=36,
TIMER_16_32_1A=37,
TIMER_16_32_1B=38,
TIMER_16_32_2A=39,
TIMER_16_32_2B=40,
ANALOG_COMPARATOR0=41,
ANALOG_COMPARATOR1=42,
/*Reserved = 43*/
SYSTEM_CONTROL=44,
FLASH_MEMORY_CONTROL=45,
GPIO_PORT_F=46,
/*Reserved 47-48*/
UART2=49,
SSI1=50,
TIMER_16_32_3A=51,
TIMER_16_32_3B=52,
I2C1=53,
QEI1=54,
CAN0=55,
CAN1=56,
/*Reserved 57-58*/
HIBERNATION_MODULE=59,
USB=60,
PWM0_GENERATOR3=61,
uDMA_SOFTWARE=62,
uDMA_ERROR=63,
ADC1_SEQUENCE0=64,
ADC1_SEQUENCE1=65,
ADC1_SEQUENCE2=66,
ADC1_SEQUENCE3=67,
/*Reserved 68-72*/
SSI2=73,
SSI3=74,
UART3=75,
UART4=76,
UART5=77,
UART6=78,
UART7=79,
/*Reserved 80-83*/
I2C2=84,
I2C3=85,
TIMER_16_32_4A=86,
TIMER_16_32_4B=87,
/*Reserved 88-107*/
TIMER_16_32_5A=108,
TIMER_16_32_5B=109,
TIMER_32_64_0A=110,
TIMER_32_64_0B=111,
TIMER_32_64_1A=112,
TIMER_32_64_1B=113,
TIMER_32_64_2A=114,
TIMER_32_64_2B=115,
TIMER_32_64_3A=116,
TIMER_32_64_3B=117,
TIMER_32_64_4A=118,
TIMER_32_64_4B=119,
TIMER_32_64_5A=120,
TIMER_32_64_5B=121,
SYSTEM_EXCEPTION=122,
/*Reserved 123-149*/
PWM1_GENERATOR0=150,
PWM1_GENERATOR1=151,
PWM1_GENERATOR2=152,
PWM1_GENERATOR3=153,
PWM1_FAULT=154,
}IntCtrl_InterruptType;

#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
