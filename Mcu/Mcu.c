/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Mcu.c
 *        \brief  Represents the Static Part of Mcu Controller
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu.h"
#include "Common.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void Mcu_Init( const Mcu_ConfigType* ConfigPtr)
{
    /*Following Section 5.3 in Datasheet */
    RCC->B.BYPASS = ENABLED;
    RCC->B.USESYSDIV = DISABLED;
    RCC->B.PWRDN = DISABLED;
    RCC->B.XTAL = ConfigPtr->Freq;
    RCC->B.OSCSRC = ConfigPtr->Clock.Clock_Source;
    RCC->B.USESYSDIV = ENABLED;
    while(DISABLED == GET_BIT(RIS,PLLLRIS_MASK));
    RCC->B.BYPASS = ConfigPtr->PllUSe;
}

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
Mcu_RawResetType Mcu_GetResetRawValue( void )
{
    return RESC;
}

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
void Mcu_PerformReset(void)
{
    APINT = VECT_KEY|(1<<SYSRESREQ_MASK);
}

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
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting)
{
    #warning to be implemented
    /*to be implemented*/
}

/******************************************************************************
* \Syntax          : Std_ReturnType DistributePllClock( Mcu_ClockType ClockSetting)                                      
* \Description     : Configure PLL clocks      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : returns SUCCESS if there is no errors, otherwise check return errors
*******************************************************************************/
Std_ReturnType DistributePllClock( void )
{
    RCC->B.BYPASS = ENABLED;
}

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
Mcu_PllStatusType Mcu_GetPllStatus( void)
{
    return GET_BIT(PLLSTAT,LOCK_MASK);
}

/**********************************************************************************************************************
 *  END OF FILE: Mcu.c
 *********************************************************************************************************************/
