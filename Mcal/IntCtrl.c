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
#include "IntCtrl.h"
#include "Common.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
 //0xE000E000
#define PRIx(i)	*((volatile uint32_t*)(PER_BASE_ADD+((0x0400+((i/4)*4)))))
#define ENX(i) *((volatile uint32_t*)(PER_BASE_ADD+0x0100+((i/32)*32)))

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
//User configurations container
extern const User_data_type g_user_data;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void SetPriorityGrouping(Group_SubgroupType PriorityGrouping);
static void IntCrtl_SetPriority(IntCtrl_InterruptType IntrNum, uint8_t u8_IntPriority);
static void IntCrtl_EnableInterrupt(IntCtrl_InterruptType IntrNum);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static void SetPriorityGrouping(Group_SubgroupType PriorityGrouping)
{
    uint32_t APINT_Temp = APINT;
    uint32_t u32_PriorityGroupingTemp = ((uint32_t)PriorityGrouping & 7UL);
    
    APINT_Temp &= ~((uint32_t)(VECT_KEY_MSK | APINT_PRIGROUP_MSK));
    
    APINT = (APINT_Temp                                                         |
             VECT_KEY                                             							|
            (u32_PriorityGroupingTemp << APINT_PRIGROUP_POS)           );
}

static void IntCrtl_SetPriority(IntCtrl_InterruptType IntrNum, uint8_t u8_IntPriority)
{
    uint8_t InterruptPriority = ((u8_IntPriority & 0x07) << 5);
    /*NVIC_PRIx*/
    if(SysTick_IRQ < IntrNum)
    {
        NVIC->SETPRI[IntrNum] = InterruptPriority;
    }
    /*SCB_SYSPRIx*/
    else
    {
        switch(IntrNum)
        {
            case MemoryManagement_IRQ:
                SYSPRI->SYSPRI_SET[0] = InterruptPriority;
                break;
            case BusFault_IRQ:
                SYSPRI->SYSPRI_SET[1] = InterruptPriority;
                break;
            case UsageFault_IRQ:
                SYSPRI->SYSPRI_SET[2] = InterruptPriority;
                break;
            case SVCall_IRQ:
                SYSPRI->SYSPRI_SET[7] = InterruptPriority;
                break;
            case DebugMonitor_IRQ:
                SYSPRI->SYSPRI_SET[8] = InterruptPriority;
                break;
            case PendSV_IRQ:
                 SYSPRI->SYSPRI_SET[10] = InterruptPriority;
               break;
            case SysTick_IRQ:
                 SYSPRI->SYSPRI_SET[11] = InterruptPriority;
               break;            
            default:
                break;
        }
    }
}

static void IntCrtl_EnableInterrupt(IntCtrl_InterruptType IntrNum)
{    
    /*NVIC_ENx*/
    if(SysTick_IRQ < IntrNum)
    {
        SET_BIT(NVIC->ENINT[((uint8)IntrNum >> 5)] , (IntrNum % 32));
    }
    /*SCB_Sys*/
    else
    {
        switch(IntrNum)
        {
            case MemoryManagement_IRQ:
                SET_BIT(SYSHNDCTRL->SysCtrlHandler , 16);
                break;
            case BusFault_IRQ:
                SET_BIT(SYSHNDCTRL->SysCtrlHandler , 17);
                break;
            case UsageFault_IRQ:
                SET_BIT(SYSHNDCTRL->SysCtrlHandler , 18);
               break;
            /* case SysTick_IRQ:
                 SYSPRI->SYSPRI_SET[11] = ;
               break;*/            
            default:
                break;
        } 
        
    }
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
    uint8_t   u8_idx = 0;
    
	/*Configure Grouping\SubGrouping System in APINT register in SCB*/
    SetPriorityGrouping(g_user_data.groupspriority_config);
    
    /*Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
    for(u8_idx = 0; u8_idx < CFG_INT_NUM; u8_idx++)
    {
        uint8_t u8_IntrPrioriity          = 0;
        uint8_t u8_GroupPriority          = (uint8_t)g_user_data.Int_Cfg[u8_idx].Group_Prio;
        uint8_t u8_SubGroupPriority       = (uint8_t)g_user_data.Int_Cfg[u8_idx].Sub_Group_Prio;
        
        Interrupt_idx_Type IntrNum   = g_user_data.Int_Cfg[u8_idx].Interrupt_idx;
        
        if(USE_ALL_GROUPS == g_user_data.groupspriority_config)
        {
            u8_IntrPrioriity = u8_GroupPriority;
        }
        else if(USE_4_GROUPS_2_SUBGROUPS == g_user_data.groupspriority_config)
        {
            u8_IntrPrioriity = ((u8_GroupPriority & 0x03) << 1UL) | ((u8_SubGroupPriority & 0x01) << 0);
        }
        else if(USE_2_GROUPS_4_SUBGROUPS == g_user_data.groupspriority_config)
        {
            u8_IntrPrioriity = ((u8_GroupPriority & 0x01) << 2UL) | ((u8_SubGroupPriority & 0x03) << 0);
        }
        else if(USE_ALL_SUBGROUPS == g_user_data.groupspriority_config)
        {
            u8_IntrPrioriity = u8_SubGroupPriority;           
        }
        else
        {
            /*Do nothing*/
        }
        
        /*Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/ 
        IntCrtl_SetPriority(IntrNum, u8_IntrPrioriity);
        
        
        /*Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
        IntCrtl_EnableInterrupt(IntrNum);
    

    }
}

#if 0
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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{

	uint8_t i=0;
	uint32_t temp = 0;
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    //APINT = 0xFA05|g_user_data.groupspriority_config;
		APINT = VECT_KEY|(uint32_t)(g_user_data.groupspriority_config<<7);  //05FA
		//APINT = 0x00000380;
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
    for(i=0;i<MAX_INTERRUPT;i++)
    {	
			if(ENABLED == g_user_data.aUSER_DATA[i].B.INT_STATE)
				{
			//6 110
			//11-1  //7
					 switch (i)
					{
							case USAGE_FAULT:
							SYSPRI1->B.USAGE = g_user_data.aUSER_DATA[i].B.PRI_GRP;
							break;
							case MEMORY_MANAGEMENT:
							SYSPRI1->B.MEM = g_user_data.aUSER_DATA[i].B.PRI_GRP;
							break;
							case BUS_FAULT:
							SYSPRI1->B.BUS = g_user_data.aUSER_DATA[i].B.PRI_GRP;
							break;
							case SV_CALL:
							SYSPRI2->B.SVC = g_user_data.aUSER_DATA[i].B.PRI_GRP;
							break;
							case DEBUG_MONITOR:
							SYSPRI3->B.DEBUG = g_user_data.aUSER_DATA[i].B.PRI_GRP;           
							break;
							case PENDSV:
							SYSPRI3->B.PENDSV = g_user_data.aUSER_DATA[i].B.PRI_GRP;
							break;
							case SYS_TICK:
							SYSPRI3->B.TICK = g_user_data.aUSER_DATA[i].B.PRI_GRP;
							break;
							default:
								
								if((i-16)%4 ==0)
								{
									temp = PRIx((i-16));
									PRIx((i-16)) =temp |((g_user_data.aUSER_DATA[(i)].B.PRI_GRP)<<5);								
								}
								else if(i%4 ==1)
								{
									temp = PRIx((i-16));
									PRIx((i-16)) =temp |(g_user_data.aUSER_DATA[(i)].B.PRI_GRP<<13);
								}
								else if(i%4 ==2)
								{
									temp = PRIx((i-16));
									PRIx((i-16)) =temp |(g_user_data.aUSER_DATA[(i)].B.PRI_GRP<<21);
								}							
								else if(i%4 ==3)
								{
									temp = PRIx((i-16));
									PRIx((i-16)) =temp |(g_user_data.aUSER_DATA[(i)].B.PRI_GRP<<29);
								}

							break;
					}
				}
			}

	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
		for(i=0;i<MAX_INTERRUPT;i++)
    {
			if(ENABLED == g_user_data.aUSER_DATA[i].B.INT_STATE)
			{			
        switch (i)
        {
            case USAGE_FAULT:
            SYSHNDCTRL->B.USAGE= g_user_data.aUSER_DATA[i].B.PRI_GRP;
            break;
            case MEMORY_MANAGEMENT:
            SYSHNDCTRL->B.MEM= g_user_data.aUSER_DATA[i].B.PRI_GRP;
            break;
            case BUS_FAULT:
            SYSHNDCTRL->B.BUS = g_user_data.aUSER_DATA[i].B.PRI_GRP;
            break;
            case SV_CALL:
            //SYSHNDCTRL->B.SVC = g_user_data.aUSER_DATA[i].B.PRI_GRP;
            break;
            case DEBUG_MONITOR:
            //SYSPRI3->B.DEBUG = g_user_data.aUSER_DATA[i].B.PRI_GRP;           
            break;
            case PENDSV:
            //SYSHNDCTRL->B.PNDSV = g_user_data.aUSER_DATA[i].B.PRI_GRP;
            break;
            case SYS_TICK:
            //SYSHNDCTRL->B.TICK = g_user_data.aUSER_DATA[i].B.PRI_GRP;
            break;
            default:
								if(i/32 ==0)
								{
									SET_BIT(EN0,((i-16)%32));
								}
								else if(i/32==1)
								{
									SET_BIT(EN1,GET_ENABLE_BIT_OFFSET(i));
								}
								else if(i/32 ==2)
								{
									SET_BIT(EN2,((i-16)%32));;
								}							
								else if(i/32 ==3)
								{
									SET_BIT(EN3,((i-16)%32));;
								}
								else if(i/32 ==4)
								{
									SET_BIT(EN4,((i-16)%32));;
								}
								break;
							}
      			}
		}

}
#endif
/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
