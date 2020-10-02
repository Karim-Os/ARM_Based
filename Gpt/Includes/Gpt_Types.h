/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

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
    GPT_PREDEF_TIMER_1US_16BIT,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;

typedef enum
{
    GPT_MODE_NORMAL,
    GPT_MODE_SLEEP
}Gpt_ModeType;

typedef uint32_t GptGptChannelTickFrequency ;
typedef uint32_t GptChannelTickValueMax ;
typedef void (*GptNotification) (void);

typedef enum
{
    GPT_CH_MODE_CONTINUOUS,
    GPT_CH_MODE_ONESHOT
}ChannelMode;

typedef struct
{
    GptGptChannelTickFrequency ticks;
    GptChannelTickValueMax Max_Ticks;
    ChannelMode Mode;
    GptNotification Cb_Fun;
}GptChannelConfigSet;

typedef struct
{
  GptChannelConfigSet Conf_Set;
}Gpt_ConfigType;

typedef enum
{
    /*16-32 Timers*/
    TIMER_0,
    TIMER_1,
    TIMER_2,
    TIMER_3,
    TIMER_4,
    TIMER_5,
    /*32-64 Timers*/
    WIDE_TIMER_0,
    WIDE_TIMER_1,
    WIDE_TIMER_2,
    WIDE_TIMER_3,
    WIDE_TIMER_4,
    WIDE_TIMER_5,
}Gpt_ChannelType;

typedef uint32_t Gpt_ValueType;
#endif  /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Types.h
 *********************************************************************************************************************/
