/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Lcfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_LCFG_H
#define INTCTRL_LCFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MAX_INTERRUPT  155
#define MAX_PRI_GROUP_VAL  7

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum{
USE_ALL_GROUPS = 4,                     // 8 Groups and 1 Subgroup
USE_4_GROUPS_2_SUBGROUPS = 5,           // 4 Groups and 2 Subgroups
USE_2_GROUPS_4_SUBGROUPS = 6,           // 2 Groups and 4 Subgroups
USE_ALL_SUBGROUPS = 7,                  // 1 Group and 8 Subgroups
}Group_SubgroupType;

typedef struct 
{
    uint8_t INT_STATE  :1;  // Assign to 1 to Enable it
    uint8_t            :3;
    uint8_t PRI_GRP    :3;  // Priority Groups Assigning
    uint8_t            :1;
}USER_INT_BF;
typedef union 
{
    uint8_t R;
    USER_INT_BF B;
}USER_INT_Tag;
typedef struct {
    Group_SubgroupType groupspriority_config; 
    USER_INT_Tag aUSER_DATA[MAX_INTERRUPT];
} USER_DATA;


/**********************************************************************************************************************
 *  APIs
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void Interrupt_Set_and_Cfg(uint8_t int_num,uint8_t pri_group)
* \Description     : Takes the input arguments and enable their exception     
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : int_num     Exception Number in vector Table index                                                       
* \Parameters (in) : pri_group   group priority for this Exception                                                       
*******************************************************************************/

void Interrupt_Set_and_Cfg(uint8_t int_num,uint8_t pri_group);
/******************************************************************************
* \Syntax          : void Groups_Cfg(Group_SubgroupType type)        
* \Description     : Set the Groups-Sub-Groups Priorities                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : type   Group-Subgroup set, please refer to Group_SubgroupType for more info                                                       
*******************************************************************************/
void Groups_Cfg(Group_SubgroupType type);

#endif  /* INTCTRL_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.h
 *********************************************************************************************************************/
