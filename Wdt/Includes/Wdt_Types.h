/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Wdt_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef WDT_TYPES_H
#define WDT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef void (*Wdt_Cb) (void);

typedef enum {
STANDARD =0,
NON_MASKABLE
}enu_InterruptType;
typedef struct 
{
    Wdt_Cb NotificationEN;
    enu_InterruptType InterruptType;
    uint32_t WdgInitialTimeout;
    uint32_t WdgMaxTimeout; 
}Wdg_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


#endif  /* WDT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Wdt_Types.h
 *********************************************************************************************************************/
