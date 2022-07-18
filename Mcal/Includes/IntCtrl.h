/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_H
#define INTCTRL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"
#include "Mc_Hw.h"
#include "IntCtrl_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {/*Page 16 in TivaC TM4C123GH6PM Microcontroller Datasheet */
  Reset_IRQ                    = -15,
  NonMaskableInt_IRQ           = -14,
  HardFault_IRQ                = -13,
  MemoryManagement_IRQ         = -12,
  BusFault_IRQ                 = -11,
  UsageFault_IRQ               = -10,
  SVCall_IRQ                   =  -5,
  DebugMonitor_IRQ             =  -4,
  PendSV_IRQ                   =  -2,
  SysTick_IRQ                  =  -1,
  GPIOA_IRQ                    =   0,
  GPIOB_IRQ                    =   1,
  GPIOC_IRQ                    =   2,
  GPIOD_IRQ                    =   3,
  GPIOE_IRQ                    =   4,
  UART0_IRQ                    =   5,
  UART1_IRQ                    =   6,
  SSI0_IRQ                     =   7,
  I2C0_IRQ                     =   8,
  PWM0_FAULT_IRQ               =   9,
  PWM0_0_IRQ                   =  10,
  PWM0_1_IRQ                   =  11,
  PWM0_2_IRQ                   =  12,
  QEI0_IRQ                     =  13,
  ADC0SS0_IRQ                  =  14,
  ADC0SS1_IRQ                  =  15,
  ADC0SS2_IRQ                  =  16,
  ADC0SS3_IRQ                  =  17,
  WATCHDOG0_1_IRQ              =  18,
  TIMER0A_IRQ                  =  19,
  TIMER0B_IRQ                  =  20,
  TIMER1A_IRQ                  =  21,
  TIMER1B_IRQ                  =  22,
  TIMER2A_IRQ                  =  23,
  TIMER2B_IRQ                  =  24,
  COMP0_IRQ                    =  25,
  COMP1_IRQ                    =  26,
  SYSCTL_IRQ                   =  28,
  FLASH_CTRL_IRQ               =  29,
  GPIOF_IRQ                    =  30,
  UART2_IRQ                    =  33,
  SSI1_IRQ                     =  34,
  TIMER3A_IRQ                  =  35,
  TIMER3B_IRQ                  =  36,
  I2C1_IRQ                     =  37,
  QEI1_IRQ                     =  38,
  CAN0_IRQ                     =  39,
  CAN1_IRQ                     =  40,
  HIB_IRQ                      =  43,
  USB0_IRQ                     =  44,
  PWM0_3_IRQ                   =  45,
  UDMA_IRQ                     =  46,
  UDMAERR_IRQ                  =  47,
  ADC1SS0_IRQ                  =  48,
  ADC1SS1_IRQ                  =  49,
  ADC1SS2_IRQ                  =  50,
  ADC1SS3_IRQ                  =  51,
  SSI2_IRQ                     =  57,
  SSI3_IRQ                     =  58,
  UART3_IRQ                    =  59,
  UART4_IRQ                    =  60,
  UART5_IRQ                    =  61,
  UART6_IRQ                    =  62,
  UART7_IRQ                    =  63,
  I2C2_IRQ                     =  68,
  I2C3_IRQ                     =  69,
  TIMER4A_IRQ                  =  70,
  TIMER4B_IRQ                  =  71,
  TIMER5A_IRQ                  =  92,
  TIMER5B_IRQ                  =  93,
  WTIMER0A_IRQ                 =  94,
  WTIMER0B_IRQ                 =  95,
  WTIMER1A_IRQ                 =  96,
  WTIMER1B_IRQ                 =  97,
  WTIMER2A_IRQ                 =  98,
  WTIMER2B_IRQ                 =  99,
  WTIMER3A_IRQ                 = 100,
  WTIMER3B_IRQ                 = 101,
  WTIMER4A_IRQ                 = 102,
  WTIMER4B_IRQ                 = 103,
  WTIMER5A_IRQ                 = 104,
  WTIMER5B_IRQ                 = 105,
  SYSEXC_IRQ                   = 106,
  PWM1_0_IRQ                   = 134,
  PWM1_1_IRQ                   = 135,
  PWM1_2_IRQ                   = 136,
  PWM1_3_IRQ                   = 137,
  PWM1_FAULT_IRQ               = 138,
}Interrupt_idx_Type;

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
typedef enum
{
	SUB_GROUP_PRIO_0 = 0,
	SUB_GROUP_PRIO_1 = 1,
	SUB_GROUP_PRIO_2 = 2,
	SUB_GROUP_PRIO_3 = 3,
	SUB_GROUP_PRIO_4 = 4,
	SUB_GROUP_PRIO_5 = 5,
	SUB_GROUP_PRIO_6 = 6,
	SUB_GROUP_PRIO_7 = 7,
	
}Sub_Group_Prio_Type;

typedef enum
{
	GROUP_PRIO_0 = 0,
	GROUP_PRIO_1 = 1,
	GROUP_PRIO_2 = 2,
	GROUP_PRIO_3 = 3,
	GROUP_PRIO_4 = 4,
	GROUP_PRIO_5 = 5,
	GROUP_PRIO_6 = 6,
	GROUP_PRIO_7 = 7,
}Group_Prio_Type;
typedef struct 
{
	Interrupt_idx_Type Interrupt_idx;
	Group_Prio_Type Group_Prio;
	Sub_Group_Prio_Type Sub_Group_Prio;
} Int_Cfg_Type;
typedef struct 
{
    Group_SubgroupType groupspriority_config; 
		Int_Cfg_Type Int_Cfg[CFG_INT_NUM];
} User_data_type;


/**********************************************************************************************************************
 *  APIs
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void);
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

#endif  /* INTCTRL_H*/
/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/
