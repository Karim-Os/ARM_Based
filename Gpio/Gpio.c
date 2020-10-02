/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**       \file   GPIO.c
 *        \brief  Represents the Static Part of General Purpose I/O
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpio.h"
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
* \Syntax          : void Port_Init ( const Port_ConfigType* ConfigPtr )                               
* \Description     : initialize GPIO Module                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr: Pointer to User Configuration                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init ( const Port_ConfigType* ConfigPtr )
{
    for (uint8_t i =0 ; i< CONFIGURED_PINS ; i++)
    {
            #warning Adjust Port Offset 
                /*Setting Direction*/
                GPIODIR |= ((ConfigPtr[i]->Direction)>>ConfigPtr[i]->Channel.Pin);
                /*Setting Attach Resistor*/
                if (ConfigPtr[i]->Attach == PULL_DOWN)
                {
                    GPIOPUR |= (1>>ConfigPtr[i]->Channel.Pin);

                }
                else if (ConfigPtr[i]->Attach == PULL_UP)
                {
                    GPIOPDR |= (1>>ConfigPtr[i]->Channel.Pin);
                }
                else if (ConfigPtr[i]->Attach == OPEN_DRAIN)
                {
                    GPIOODR |= (1>>ConfigPtr[i]->Channel.Pin);
                }
                /*Setting Attach Output Current*/
                if (ConfigPtr[i]->Current == R2R)
                {
                    GPIODR2R |= (1>>ConfigPtr[i]->Channel.Pin);

                }
                else if (ConfigPtr[i]->Current == R4R)
                {
                    GPIODR4R |= (1>>ConfigPtr[i]->Channel.Pin);
                }
                else if (ConfigPtr[i]->Current == R8R)
                {
                    GPIODR8R |= (1>>ConfigPtr[i]->Channel.Pin);
                }
                /*Setting Pin Mode*/
                GPIOAFSEL |= ((ConfigPtr[i]->Mode)>>ConfigPtr[i]->Channel.Pin);
                /* Setting PortPinLevelValue */
                GPIODATA |= ((ConfigPtr[i]->Value)>>ConfigPtr[i]->Channel.Pin);
    }

}


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)                               
* \Description     : Read GPIO Channel                                    

* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId: GPIO Pin index                     
* \Parameters (out): None                                                      
* \Return value:   : return Level of the Pin check @Dio_LevelType for more information
*******************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{   
#warning Use atomic operation instead of read modify write , GPIO Ports
 return (GET( GPIODATA,ChannelId.Pin));
}


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
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    #warning Use atomic operation instead of read modify write , GPIO Ports
    if (LOW == Level)
    {
        CLEAR_BIT(GPIODATA,ChannelId.Pin);
    }
    else
    {
        SET_BIT(GPIODATA,ChannelId.Pin);
    }

}

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)                               
* \Description     : Read GPIO Port                                    

* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId: GPIO Port index                     
* \Parameters (out): None                                                      
* \Return value:   : return Level of the Pin check @Dio_PortLevelType for more information
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    #warning Use atomic operation instead of read modify write , GPIO Ports
    return GPIODATA;

}

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
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
    #warning GPIO PORT Offset
    GPIODATA = Level;
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)                               
* \Description     : Toggles value of GPIO Pin                                    

* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChaneelId: GPIO Port index                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)
{
    #warning GPIO PORT Offset
    TOGGLE_BIT(GPIODATA,ChannelId.Pin);
}


/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
