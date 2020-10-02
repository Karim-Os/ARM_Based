/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_H
#define MCU_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Types.h"
#include "Mc_Hw.h"
#include "Mcu_Lcfg.h"
/**********************************************************************************************************************
 *  APIs
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Mcu_Init( const Mcu_ConfigType* ConfigPtr)                                      
* \Description     : Initialize MCU Module by parsing the Configuration 
*                    into System registers                                    

* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr: Pointer to User Configuration                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_Init( const Mcu_ConfigType* ConfigPtr);

/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue( void )                                      
* \Description     : Gets Reset value                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr: Pointer to User Configuration                     
* \Parameters (out): None                                                      
* \Return value:   : Reset reason, check @Mcu_RawResetType for more information
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue( void );

/******************************************************************************
* \Syntax          : void Mcu_PerformReset(void)                                      
* \Description     : Resets the system                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_PerformReset(void);

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting)                                      
* \Description     : Initialize system clocks       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting: settings for Clock initialization                     
* \Parameters (out): None                                                      
* \Return value:   : returns SUCCESS if there is no errors, otherwise check return errors
*******************************************************************************/
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting);

/******************************************************************************
* \Syntax          : Std_ReturnType DistributePllClock( Mcu_ClockType ClockSetting)                                      
* \Description     : configure PLL clocks      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : returns SUCCESS if there is no errors, otherwise check return errors
*******************************************************************************/
Std_ReturnType DistributePllClock( void );

/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus( void)                                      
* \Description     : Gets PLL Status
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : PLL status, check @Mcu_PllStatusType for more information
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus( void);

#endif  /* MCU_H*/
/**********************************************************************************************************************
 *  END OF FILE: Mcu.h
 *********************************************************************************************************************/
