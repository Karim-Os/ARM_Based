/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Wdt.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef WDT_H
#define WDT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Wdt_Types.h"
#include "Mc_Hw.h"
#include "Wdt_Lcfg.h"
/**********************************************************************************************************************
 *  APIs
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void Wdg_Init ( const Wdg_ConfigType* ConfigPtr )
* \Description     : initialize Wdt Module by parsing the Configuration 
*                    into wdt registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr: pointer to user configurations                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Wdg_Init ( const Wdg_ConfigType* ConfigPtr );

/******************************************************************************
* \Syntax          : void Wdg_SetTriggerCondition ( uint16 timeout )
* \Description     : initialize Wdt Module by parsing the Configuration 
*                    into wdt registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : timeout : set watchdog timeout value                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Wdg_SetTriggerCondition ( uint16 timeout );

#endif  /* WDT_H*/
/**********************************************************************************************************************
 *  END OF FILE: Wdt.h
 *********************************************************************************************************************/
