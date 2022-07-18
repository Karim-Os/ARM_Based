/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       File:  Gpio.h
 *       Module:  -
 *
 *  Description:       
 *  
 *********************************************************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpio_Types.h"
#include "Mc_Hw.h"
#include "Gpio_Lcfg.h"
/**********************************************************************************************************************
 *  APIs
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Port_Init ( const Port_ConfigType* ConfigPtr )                               
* \Description     : initialize GPIO Module                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr: Pointer to User Configuration                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init ( const Port_ConfigType* ConfigPtr );


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)                               
* \Description     : Read GPIO Channel                                    

* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId: GPIO Pin index                     
* \Parameters (out): None                                                      
* \Return value:   : return Level of the Pin check @Dio_LevelType for more information
*******************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);

/******************************************************************************
* \Syntax          : void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)                               
* \Description     : Write GPIO Channel                                    

* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId: GPIO Pin index                     
* \Parameters (in) : Level: Value to be written                     
* \Parameters (out): None                                                      
* \Return value:   : return Level of the Pin check @Dio_LevelType for more information
*******************************************************************************/
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)                               
* \Description     : Read GPIO Port                                    

* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId: GPIO Port index                     
* \Parameters (out): None                                                      
* \Return value:   : return Level of the Pin check @Dio_PortLevelType for more information
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);

/******************************************************************************
* \Syntax          : void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)                               
* \Description     : Write GPIO Port                                    

* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId: GPIO Port index                     
* \Parameters (in) : Level: Level to be written                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)                               
* \Description     : Toggles value of GPIO Pin                                    

* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChaneelId: GPIO Port index                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);



#endif  /* GPIO_H*/
/**********************************************************************************************************************
 *  END OF FILE: Gpio.h
 *********************************************************************************************************************/
