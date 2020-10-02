/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  Represents the Static Part of Interrupt Controller
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt.h"
#include "Common.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define TIMERA_MASK 0
#define TIMERB_MASK 8
#define ONR_SHOT_MASK 0
#define TATOIM 0
#define TAEN_MASK 0
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
uint32_t Set_Time;
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



/******************************************************************************
* \Syntax          : void Gpt_Init ( const Gpt_ConfigType* ConfigPtr )                                      
* \Description     : initialize General Purpose Timers Module by parsing the Configuration 
*                    into System registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr: user configuration                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init ( const Gpt_ConfigType* ConfigPtr )
{
    #warning Add Right Offset of the Timers
    #warning CallBack too
    Set_Time = ConfigPtr->Conf_Set.ticks;
}


/******************************************************************************
* \Syntax          :  void Gpt_DisableNotification ( Gpt_ChannelType Channel )                                      
* \Description     : Disable Timers Notification                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel: timer channel                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_DisableNotification ( Gpt_ChannelType Channel )
{
    CLEAR_BIT(GPTMIMR,TIMERA_MASK);
    CLEAR_BIT(GPTMIMR,TIMERB_MASK);}


/******************************************************************************
* \Syntax          :  void Gpt_EnableNotification ( Gpt_ChannelType Channel )                                      
* \Description     : Enable Timers Notification                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel: timer channel                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_EnableNotification ( Gpt_ChannelType Channel )
{
    SET_BIT(GPTMIMR,TIMERA_MASK);
    SET_BIT(GPTMIMR,TIMERB_MASK);
}

/******************************************************************************
* \Syntax          : void Gpt_StartTimer ( Gpt_ChannelType Channel, Gpt_ValueType Value )                                      
* \Description     : Starts selected timer cahnnel with defined target time                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel: timer channel                     
* \Parameters (in) : Value: target counter value                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StartTimer ( Gpt_ChannelType Channel, Gpt_ValueType Value )
{
    
    CLEAR_BIT(GPTMCTL,TAEN_MASK);
    GPTMCFG =0;
    /*Set Mode -> One shot*/
    SET_BIT(GPTMTAMR,ONR_SHOT_MASK);
    /*Load Values*/
    GPTMTAILR = Value;
    /*Enable Interrupts*/
    SET_BIT(GPTMIMR,TATOIM);
    SET_BIT(GPTMCTL,TAEN_MASK);
}

/******************************************************************************
* \Syntax          : void Gpt_StopTimer ( Gpt_ChannelType Channel )                                      
* \Description     : Stops selected timer cahnnel with defined target time                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel: timer channel                                          
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StopTimer ( Gpt_ChannelType Channel)
{
    #warning support Timers B 
    CLEAR_BIT(GPTMCTL,TAEN_MASK);
}
/******************************************************************************
* \Syntax          : void Gpt_Notification( void )                                      
* \Description     : Callback Notification                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None       
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
//void Gpt_Notification_<channel> ( void )
void Gpt_Notification ( void )
{

}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel )                                      
* \Description     : Gets the Elapsed time of a specific channel                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel: timer channel
* \Parameters (out): None                                                      
* \Return value:   : Time Elapsed
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel )
{
    return (Set_Time - GPTMTAILR);
}


/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining ( Gpt_ChannelType Channel )                                      
* \Description     : Gets the Remaining time of a specific channel                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel: timer channel
* \Parameters (out): None                                                      
* \Return value:   : Time Remaining
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining ( Gpt_ChannelType Channel )
{
    return GPTMTAILR;
}

/******************************************************************************
* \Syntax          : Std_ReturnType Gpt_GetPredefTimerValue ( Gpt_PredefTimerType PredefTimer,uint32_t* TimeValuePtr )                                      
* \Description     : Gets timer value of predefined timers                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PredefTimer: predefined timer channel
* \Parameters (out): TimeValuePtr: predefined timer value                                                      
* \Return value:   : returns SUCCESS if there is no errors, otherwise check return errors
*******************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue ( Gpt_PredefTimerType PredefTimer,uint32_t* TimeValuePtr )
{
#warning to be implemented
}
/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/
