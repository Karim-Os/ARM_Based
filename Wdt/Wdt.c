/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Wdt.c
 *        \brief  Represents the Static Part of Watchdog timer
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Wdt.h"
#include "Common.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define IN_PROGRESS 1
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32_t Wdt_Max_Timeout =0;
uint32_t Wdt_Initial_Timeout =0;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
Wdt_Cb Wdg_Cb;
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


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
void Wdg_Init ( const Wdg_ConfigType* ConfigPtr )
{
    if (NULL != ConfigPtr)
    {   
        /*Enable WDT1*/
        RCGCWD->B.R1=1;
        /*Setting Interrupt Type*/
        WDTCTL->B.INTEN = ConfigPtr->InterruptType;
        /*Setting WDT Initial WDT values Could be used to reset the timer by using Wdg_SetTriggerCondition */
        Wdt_Initial_Timeout = ConfigPtr->WdgInitialTimeout;
        /*Setting WDT Max WDT values*/
        Wdt_Max_Timeout = ConfigPtr->WdgMaxTimeout;
    }
    else
    {
        /* Invalid Argument !!! */
    }
    Wdg_Cb = ConfigPtr->NotificationEN;
}

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
void Wdg_SetTriggerCondition ( uint16_t timeout )
{
    #warning Convert time into Ticks before setting it to the Registers
    if (Wdt_Max_Timeout >= timeout)
    {
        WDTLOAD = timeout;
        /*Wait for the Module to be ready*/
        while(IN_PROGRESS==WDTCTL->B.WRC);
        /*Enable Resetting */
        WDTCTL->B.RESEN = ENABLED;
        /*Wait for the Module to be ready*/
        while(IN_PROGRESS==WDTCTL->B.WRC);
        /*Enable WDT*/
        WDTCTL->B.INTEN = ENABLED;
    }
    else
    {
        /* Timeout value Exceeds the Max Value*/
    }
}

/*******************************************************************************/
/*Implement IRQ of the Function*/
/*******************************************************************************/
void WDT0_Handler (void)
{
    Wdg_Cb();
}
/**********************************************************************************************************************
 *  END OF FILE: Wdt.c
 *********************************************************************************************************************/
