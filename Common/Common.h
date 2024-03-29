/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Common.h
 *       Module:  Contains the common used Macros and Definitions 
 *
*********************************************************************************************************************/
#ifndef COMMON_H
#define COMMON_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SET_BIT(u32_reg,bit_pos)    (u32_reg |= (1UL<<bit_pos))
#define CLEAR_BIT(u32_reg,bit_pos)  (u32_reg &= (~(1UL<<bit_pos)))
#define TOGGLE_BIT(u32_reg,bit_pos)  (u32_reg ^= ((1UL<<bit_pos)))
#define GET_BIT(u32_reg,bit_pos)    ((0u==(u32_reg&(1<<bit_pos)))?0u:1u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#endif  /* COMMON_H */

/**********************************************************************************************************************
 *  END OF FILE: Common.h
 *********************************************************************************************************************/
