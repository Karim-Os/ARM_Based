/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"
#include "Mc_Hw.h"
#include "Gpt_Lcfg.h"
/**********************************************************************************************************************
 *  APIs
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
void Gpt_Init ( const Gpt_ConfigType* ConfigPtr );


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
void Gpt_DisableNotification ( Gpt_ChannelType Channel );


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
void Gpt_EnableNotification ( Gpt_ChannelType Channel );

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
void Gpt_StartTimer ( Gpt_ChannelType Channel, Gpt_ValueType Value );

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
void Gpt_StopTimer ( Gpt_ChannelType Channel);

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
void Gpt_Notification ( void );

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel )                                      
* \Description     : Gets the Elapsed time of a specific channel                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel: timer channel
* \Parameters (out): None                                                      
* \Return value:   : Time Elapsed
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel );

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining ( Gpt_ChannelType Channel )                                      
* \Description     : Gets the Remaining time of a specific channel                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel: timer channel
* \Parameters (out): None                                                      
* \Return value:   : Time Remaining
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining ( Gpt_ChannelType Channel );

/******************************************************************************
* \Syntax          : Std_ReturnType Gpt_GetPredefTimerValue ( Gpt_PredefTimerType PredefTimer,uint32_t* TimeValuePtr )                                      
* \Description     : Gets timer value of predefined timers                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PredefTimer: predefined timer channel
* \Parameters (out): TimeValuePtr: predefined timer value                                                      
* \Return value:   : returns SUCCESS if there is no errors, otherwise check return errors
*******************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue ( Gpt_PredefTimerType PredefTimer,uint32_t* TimeValuePtr );

#endif  /* GPT_H*/
/**********************************************************************************************************************
 *  END OF FILE: Gpt.h
 *********************************************************************************************************************/
