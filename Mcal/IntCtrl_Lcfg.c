/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  Represents the Dynamic Part "user-defined" of Interrupt Controller
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Lcfg.h"
#include "IntCtrl.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/*Container for User Data*/
const User_data_type g_user_data = 
{
	.groupspriority_config = USE_2_GROUPS_4_SUBGROUPS,
	
	.Int_Cfg[0].Interrupt_idx = GPIOA_IRQ,
	.Int_Cfg[0].Group_Prio = GROUP_PRIO_0,
	.Int_Cfg[0].Sub_Group_Prio = SUB_GROUP_PRIO_1,
	
	.Int_Cfg[1] = {GPIOB_IRQ,GROUP_PRIO_1,SUB_GROUP_PRIO_1},
	.Int_Cfg[2] = {GPIOC_IRQ,GROUP_PRIO_1,SUB_GROUP_PRIO_0},
};
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
* \Syntax          : void Interrupt_Set_and_Cfg(uint8_t int_num,uint8_t pri_group)
* \Description     : Takes the input arguments and enable their exception     
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : int_num     Exception Number in vector Table index                                                       
* \Parameters (in) : pri_group   group priority for this Exception                                                       
*******************************************************************************/


void Interrupt_Set_and_Cfg(uint8_t int_num,uint8_t pri_group)
{
    if((int_num < MAX_INTERRUPT) || (pri_group < MAX_PRI_GROUP_VAL) )
    {
        g_user_data.aUSER_DATA[int_num].B.INT_STATE=ENABLED;
        g_user_data.aUSER_DATA[int_num].B.PRI_GRP = pri_group;
    }
    else
    {
//        printf("Invalid Arguments, Func %s, line %d \r\n",__func__ , __LINE__);
    }
    
}
/******************************************************************************
* \Syntax          : void Groups_Cfg(Group_SubgroupType type)        
* \Description     : Set the Groups-Sub-Groups Priorities                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : type   Group-Subgroup set, please refer to Group_SubgroupType for more info                                                       
*******************************************************************************/
void Groups_Cfg(Group_SubgroupType type)
{
   g_user_data.groupspriority_config = type;
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
