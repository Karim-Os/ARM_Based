/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*Size of Configuration Array */
#define CONFIGURED_PINS     10

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    NORMAL_MODE =0,
    SPECIAL_MODE = 1
}PortPinMode;

typedef enum
{
    DIRECTION_INPUT =0,
    DIRECTION_OUTPUT = 1
}PortPinDirection;

typedef enum
{
    PULL_UP =0,
    PULL_DOWN ,
    OPEN_DRAIN,
}PortPinInternalAttach;
typedef enum
{
    R2R,
    R4R,
    R8R
}PortPinOutputCurrent;

typedef enum
{
    LOW =0,
    HIGH = 1
}Dio_LevelType;

typedef enum
{
    PIN0 =0,
    PIN1 =0,
    PIN2 =0,
    PIN3 =0,
    PIN4 =0,
    PIN5 =0,
    PIN6 =0,
    PIN7 =0,
}Pin_type;

typedef enum
{
    PORTA ,
    PORTB ,
    PORTC ,
    PORTD ,
    PORTE ,
    PORTF
}Dio_PortType;

typedef struct
{
    Dio_PortType Port;
    Pin_type Pin;
}Dio_ChannelType;

typedef struct
{
    PortPinMode Mode;
    Dio_LevelType Value;
    PortPinOutputCurrent Current;
    PortPinInternalAttach Attach;
    PortPinDirection Direction;
    Dio_ChannelType Channel;
}Port_ConfigType[CONFIGURED_PINS];



typedef uint32_t Dio_PortLevelType;
#endif  /* GPIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Types.h
 *********************************************************************************************************************/
