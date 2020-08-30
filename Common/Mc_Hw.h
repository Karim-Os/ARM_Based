/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       File:  Mc_Hw.h
 *       Module: contains the addresses of NVIC-SCB registers
 *  
 *********************************************************************************************************************/
#ifndef MC_HW_H
#define MC_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define PER_BASE_ADD  0xE000E000
/*****************/
/*NVIC Registers */
/*****************/
/*Interrupt 0-31 Set Enable*/
#define EN0 *((volatile uint32_t*)(PER_BASE_ADD+0x0100))
/*Interrupt 32-63 Set Enable*/
#define EN1 *((volatile uint32_t*)(PER_BASE_ADD+0x0104))
/*Interrupt 64-95 Set Enable*/
#define EN2 *((volatile uint32_t*)(PER_BASE_ADD+0x0108))
/*Interrupt 96-127 Set Enable*/
#define EN3 *((volatile uint32_t*)(PER_BASE_ADD+0x010C))
/*Interrupt 128-138 Set Enable*/
#define EN4 *((volatile uint32_t*)(PER_BASE_ADD+0x0110))

/*Interrupt 0-31 Active Bit*/
#define ACTIVE0 *((volatile uint32_t*)(PER_BASE_ADD+0x0300))
/*Interrupt 32-63 Active Bit*/
#define ACTIVE1 *((volatile uint32_t*)(PER_BASE_ADD+0x0304))
/*Interrupt 64-95 Active Bit*/
#define ACTIVE2 *((volatile uint32_t*)(PER_BASE_ADD+0x0308))
/*Interrupt 96-127 Active Bit*/
#define ACTIVE3 *((volatile uint32_t*)(PER_BASE_ADD+0x030C))
/*Interrupt 128-138 Active Bit*/
#define ACTIVE4 *((volatile uint32_t*)(PER_BASE_ADD+0x0310))
	/*Base Address of PRIx*/
#define PRIX *((volatile PRI_Tag*)(PER_BASE_ADD+0x0400))
/*Interrupt Priority 0-3 */
#define PRI0 *((volatile PRI_Tag*)(PER_BASE_ADD+0x0400))
/*Interrupt Priority 4-7 */
#define PRI1 *((volatile uint32_t*)(PER_BASE_ADD+0x0404))
/*Interrupt Priority 8-11 */
#define PRI2 *((volatile uint32_t*)(PER_BASE_ADD+0x0408))
/*Interrupt Priority 12-15 */
#define PRI3 *((volatile PRI_Tag*)(PER_BASE_ADD+0x040C))
/*Interrupt Priority 16-19 */
#define PRI4 *((volatile uint32_t*)(PER_BASE_ADD+0x0410))
/*Interrupt Priority 20-23 */
#define PRI5 *((volatile PRI_Tag*)(PER_BASE_ADD+0x0414))
/*Interrupt Priority 24-27 */
#define PRI6 *((volatile uint32_t*)(PER_BASE_ADD+0x0418))
/*Interrupt Priority 28-31 */
#define PRI7 *((volatile uint32_t*)(PER_BASE_ADD+0x041C))
/*Interrupt Priority 32-35 */
#define PRI8 *((volatile uint32_t*)(PER_BASE_ADD+0x0420))
/*Interrupt Priority 36-39 */
#define PRI9 *((volatile uint32_t*)(PER_BASE_ADD+0x0424))
/*Interrupt Priority 40-43 */
#define PRI10 *((volatile uint32_t*)(PER_BASE_ADD+0x0428))
/*Interrupt Priority 44-47 */
#define PRI11 *((volatile uint32_t*)(PER_BASE_ADD+0x042C))
/*Interrupt Priority 48-51 */
#define PRI12 *((volatile uint32_t*)(PER_BASE_ADD+0x0430))
/*Interrupt Priority 52-55 */
#define PRI13 *((volatile uint32_t*)(PER_BASE_ADD+0x0434))
/*Interrupt Priority 56-59 */
#define PRI14 *((volatile uint32_t*)(PER_BASE_ADD+0x0438))
/*Interrupt Priority 60-63 */
#define PRI15 *((volatile uint32_t*)(PER_BASE_ADD+0x043C))
/*Interrupt Priority 64-67 */
#define PRI16 *((volatile uint32_t*)(PER_BASE_ADD+0x0440))
/*Interrupt Priority 68-71 */
#define PRI17 *((volatile uint32_t*)(PER_BASE_ADD+0x0444))
/*Interrupt Priority 72-75 */
#define PRI18 *((volatile uint32_t*)(PER_BASE_ADD+0x0448))
/*Interrupt Priority 76-79 */
#define PRI19 *((volatile uint32_t*)(PER_BASE_ADD+0x044C))
/*Interrupt Priority 80-83 */
#define PRI20 *((volatile uint32_t*)(PER_BASE_ADD+0x0450))
/*Interrupt Priority 84-87 */
#define PRI21 *((volatile uint32_t*)(PER_BASE_ADD+0x0454))
/*Interrupt Priority 88-91 */
#define PRI22 *((volatile uint32_t*)(PER_BASE_ADD+0x0458))
/*Interrupt Priority 92-95 */
#define PRI23 *((volatile uint32_t*)(PER_BASE_ADD+0x045C))
/*Interrupt Priority 96-99 */
#define PRI24 *((volatile uint32_t*)(PER_BASE_ADD+0x0460))
/*Interrupt Priority 100-103 */
#define PRI25 *((volatile uint32_t*)(PER_BASE_ADD+0x0464))
/*Interrupt Priority 104-107 */
#define PRI26 *((volatile uint32_t*)(PER_BASE_ADD+0x0468))
/*Interrupt Priority 108-111 */
#define PRI27 *((volatile uint32_t*)(PER_BASE_ADD+0x046C))
/*Interrupt Priority 112-115 */
#define PRI28 *((volatile uint32_t*)(PER_BASE_ADD+0x0470))
/*Interrupt Priority 116-119 */
#define PRI29 *((volatile uint32_t*)(PER_BASE_ADD+0x0474))
/*Interrupt Priority 120-123 */
#define PRI30 *((volatile uint32_t*)(PER_BASE_ADD+0x0478))
/*Interrupt Priority 124-127 */
#define PRI31 *((volatile uint32_t*)(PER_BASE_ADD+0x047C))
/*Interrupt Priority 128-131 */
#define PRI32 *((volatile uint32_t*)(PER_BASE_ADD+0x0480))
/*Interrupt Priority 132-135 */
#define PRI33 *((volatile uint32_t*)(PER_BASE_ADD+0x0484))
/*Interrupt Priority 136-138 */
#define PRI34 *((volatile uint32_t*)(PER_BASE_ADD+0x0488))
/*Software Trigger Interrupt*/
#define SWTRIG *((volatile uint32_t*)(PER_BASE_ADD+0x0F00))
/*****************/
/**SCB Registers**/
/*****************/
/* Interrupt Control and State */
#define INTCTRL *((volatile uint32_t*)(PER_BASE_ADD+0x0D04))
/* Vector Table Offset*/
#define VTABLE *((volatile uint32_t*)(PER_BASE_ADD+0x0D08))
/* Application Interrupt and Reset Control */
#define APINT 	*((volatile uint32_t*)(PER_BASE_ADD+0xD0C))
/* System Handler Priority1 */
#define SYSPRI1 ((volatile SYSPRI1_Tag*)(PER_BASE_ADD+0x0D18))
/* System Handler Priority2 */
#define SYSPRI2 ((volatile SYSPRI2_Tag*)(PER_BASE_ADD+0x0D1C))
/* System Handler Priority3 */
#define SYSPRI3 ((volatile SYSPRI3_Tag*)(PER_BASE_ADD+0x0D20))
/* System Handler Control and State */
#define SYSHNDCTRL ((volatile SYSHNDCRTL_Tag*)(PER_BASE_ADD+0x0D24))
/* Configurable Fault Status */
#define FAULTSTAT *((volatile uint32_t*)(PER_BASE_ADD+0x0D28))
/* Hard Fault Status */
#define HFAULTSTAT *((volatile uint32_t*)(PER_BASE_ADD+0x0D2C))


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32_t VECACT   :8;
    uint32_t          :3;
    uint32_t RETBASE  :1;
    uint32_t VECPEND  :8;
    uint32_t          :2;
    uint32_t ISRPEND  :1;
    uint32_t ISRPRE   :1;
    uint32_t          :1;
    uint32_t PENDSTCLR:1;
    uint32_t PENDSTSET:1;
    uint32_t UNPENDSV :1;
    uint32_t PENDSV   :1;
    uint32_t          :2;
    uint32_t NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32_t R;
    INTCTRL_BF B;
}INTCTRL_Tag;

/*BASEPRI*/
typedef struct 
{
    uint32_t          :5;
    uint32_t BASEPRI  :3;
    uint32_t          :24;
}BASEPRI_BF;
typedef union 
{
    uint32_t R;
    BASEPRI_BF B;
}BASEPRI_Tag;

/*SWTRIG*/
typedef struct 
{
    uint32_t INTID     :8;
    uint32_t           :24;
}SWTRIG_BF;
typedef union 
{
    uint32_t R;
    SWTRIG_BF B;
}SWTRIG_Tag;
/*SYSHNDCRTL*/
typedef struct 
{
    uint32_t MEMA     :1;
    uint32_t BUSA     :1;
    uint32_t          :1;
    uint32_t USGA     :1;
    uint32_t          :3;
    uint32_t SVCA     :1;
    uint32_t MON      :1;
    uint32_t          :1;
    uint32_t PNDSV    :1;
    uint32_t TICK     :1;
    uint32_t USAGEP    :1;
    uint32_t MEMP     :1;
    uint32_t BUSP     :1;
    uint32_t SVC      :1;
    uint32_t MEM      :1;
    uint32_t BUS      :1;
    uint32_t USAGE    :1;
    uint32_t          :13;
}SYSHNDCRTL_BF;
typedef union 
{
    uint32_t R;
    SYSHNDCRTL_BF B;
}SYSHNDCRTL_Tag;

/*PRIx*/
typedef struct 
{
    uint32_t          :5;
    uint32_t INTA     :3;   /*4n*/
    uint32_t          :5;
    uint32_t INTB     :3;   /*4n+1*/
    uint32_t          :5;
    uint32_t INTC     :3;   /*4n+2*/
    uint32_t          :5;
    uint32_t INTD     :3;   /*4n+3*/
}PRI_BF;
typedef union 
{
    uint32_t R;
    PRI_BF B;
}PRI_Tag;

/*APINT*/
typedef struct 
{
    uint32_t VECTRESET  :1;
    uint32_t VECTCLRACT :1;
    uint32_t SYSREQ     :1;
    uint32_t            :5;
    uint32_t PRIGROUP   :3;
    uint32_t            :4;
    uint32_t ENDIANESS  :1;
    uint32_t VECTKEY    :16;         //0xFA05

}APINT_BF;
typedef union 
{
    uint32_t R;
    APINT_BF B;
}APINT_Tag;


/*SYSPRI1*/
typedef struct 
{
    uint32_t       :5;
    uint32_t MEM   :3;
    uint32_t       :5;
    uint32_t BUS   :3;
    uint32_t       :5;
    uint32_t USAGE :3;
    uint32_t       :8;
}SYSPRI1_BF;
typedef union 
{
    uint32_t R;
    SYSPRI1_BF B;
}SYSPRI1_Tag;


/*SYSPRI2*/
typedef struct 
{
    uint32_t       :29;
    uint32_t SVC   :3;
}SYSPRI2_BF;
typedef union 
{
    uint32_t R;
    SYSPRI2_BF B;
}SYSPRI2_Tag;


/*SYSPRI3*/
typedef struct 
{
    uint32_t         :5;
    uint32_t DEBUG   :3;
    uint32_t         :13;
    uint32_t PENDSV  :3;
    uint32_t         :5;
    uint32_t TICK    :3;
}SYSPRI3_BF;
typedef union 
{
    uint32_t R;
    SYSPRI3_BF B;
}SYSPRI3_Tag;


/*VTABLE*/
typedef struct 
{
    uint32_t         :10;
    uint32_t OFFSET  :22;
}VTABLE_BF;
typedef union 
{
    uint32_t R;
    VTABLE_BF B;
}VTABLE_Tag;

/*PSR*/
typedef struct 
{
    uint32_t ISRNUM   :8;
    uint32_t          :2;
    uint32_t ICI      :6;
    uint32_t GE       :4;
    uint32_t          :4;
    uint32_t THUMB    :1;
    uint32_t ICT      :2;
    uint32_t Q    :1;
    uint32_t V    :1;
    uint32_t C    :1;
    uint32_t Z    :1;
    uint32_t N    :1;
}PSR_BF;
typedef union 
{
    uint32_t R;
    PSR_BF B;
}PSR_Tag;


/*FAULTHANDL*/
typedef struct 
{
    uint32_t IERR       :1;
    uint32_t DERR       :1;
    uint32_t            :1;
    uint32_t MUSTKE     :1;
    uint32_t MSTKE      :1;
    uint32_t MLSPERR    :1;
    uint32_t            :1;
    uint32_t MMARU      :1;
    uint32_t IBUS       :1;
    uint32_t PRECISE    :1;
    uint32_t IMPRE      :1;
    uint32_t BUSTKE     :1;
    uint32_t BSTKE      :1;
    uint32_t BLSPERR    :1;
    uint32_t            :1;
    uint32_t BFARU      :1;
    uint32_t UNDEF      :1;
    uint32_t INVSTAT    :1;
    uint32_t INVPC      :1;
    uint32_t NOCP       :1;
    uint32_t            :4;
    uint32_t UNALIGNED  :1;
    uint32_t DEV0       :1;
    uint32_t            :6;
}FAULTHANDL_BF;
typedef union 
{
    uint32_t R;
    FAULTHANDL_BF B;
}FAULTHANDL_Tag;

/*HFAULTHANDL*/
typedef struct 
{
    uint32_t            :1;
    uint32_t VECT       :1;
    uint32_t            :28;
    uint32_t FORCED     :1;
    uint32_t PBG        :1;
}HFAULTHANDL_BF;
typedef union 
{
    uint32_t R;
    HFAULTHANDL_BF B;
}HFAULTHANDL_Tag;


#endif /*MC_HW_H*/
/**********************************************************************************************************************
 *  END OF FILE: Mc_Hw.h
 *********************************************************************************************************************/