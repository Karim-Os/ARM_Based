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
extern USER_DATA g_user_data;
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
		APINT = VECT_KEY|(g_user_data.groupspriority_config<<7);  //05FA
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

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
