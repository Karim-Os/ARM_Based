/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_TYPES_H
#define MCU_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define EXT_MASK 0
#define POR_MASK 1
#define BOR_MASK 2
#define WDT0_MASK 3
#define SW_MASK  4
#define WDT1_MASK 5
#define MOSCFAIL_MASK  16

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{  
    PLL_UNLOCKED   = 0,
    PLL_LOCKED  = 1,
}Mcu_PllStatusType;

typedef enum
{  
    MOSC   = 0,
    PIOSC  = 1,
    PIOSC_4 =2,
    LFIOSC  =3
}Mcu_Clock_src_Type; 

typedef enum
{  
    FREQ_4_MHZ   = 0x06,
    FREQ_4_096_MHZ   = 0x07,
    FREQ_4_9152_MHZ   = 0x08,
    FREQ_5_MHZ   = 0x09,
    FREQ_5_12_MHZ   = 0x0A,
    FREQ_6_MHZ   = 0x0B,
    FREQ_6_144_MHZ   = 0x0C,
    FREQ_7_3728_MHZ   = 0x0D,
    FREQ_8_192_MHZ   = 0x0E,
    FREQ_8_MHZ   = 0x0F,
    FREQ_10_MHZ   = 0x10,
    FREQ_12_MHZ   = 0x11,
    FREQ_12_288_MHZ   = 0x12,
    FREQ_13_56_MHZ   = 0x13,
    FREQ_14_31818_MHZ   = 0x14,
    FREQ_16_MHZ   = 0x15,
    FREQ_16_384_MHZ   = 0x16,
    FREQ_18_MHZ   = 0x17,
    FREQ_20_MHZ   = 0x18,
    FREQ_24_MHZ   = 0x19,
    FREQ_25_MHZ   = 0x1A
}Freq_Vale_Type; 

#warning Add Clock Gates Registers
typedef enum 
{
INVALID =0xFF,
}Mcu_Peripheral_ClockType;

typedef enum
{
EXT = 1<<EXT_MASK,
POR = 1<<POR_MASK,
BOR = 1<<BOR_MASK,
WDT0 = 1<<WDT0_MASK,
SW = 1<<SW_MASK,
WDT1 = 1<<WDT1_MASK,
MOSCFAIL = 1<<MOSCFAIL_MASK
}Mcu_RawResetType;

typedef struct 
{
Mcu_Peripheral_ClockType Clock_Type;
Mcu_Clock_src_Type Clock_Source;
}Mcu_ClockType;

typedef struct 
{
uint8_t PllUSe;
Freq_Vale_Type Freq;
Mcu_ClockType Clock;
}Mcu_ConfigType;




#endif  /* MCU_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Types.h
 *********************************************************************************************************************/
