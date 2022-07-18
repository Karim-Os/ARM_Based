/****************************************************************************/
/** Copyright (c) 2020 Mahmoud Kassify. All Rights Reserved. 			   **/
/****************************************************************************/

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  main.c
 *        \brief  This file is an example for Add a variable in a specific section in the ROM/RAM.
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define COMPILER_ATTRIBUTE              (1)                                         /** @brief: Enable Compiler arrtribue or not*/

#if defined(COMPILER_ATTRIBUTE) && (COMPILER_ATTRIBUTE == 1)
    #define SPRINTS_SECTION             __attribute__((section(".sprints")))        /** @brief: Compiler attribute puts the variable in .sprints section*/    
#else
    #define SPRINTS_SECTION
#endif

#define ARR_SIZE                        (6)                                        /** @brief: The size of the global array*/
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
SPRINTS_SECTION uint8_t     gu8MainArray[ARR_SIZE] = {1};                      /** @brief: Global variable array should be declared in a defined section in Flash*/
SPRINTS_SECTION uint32_t    gu32MainVar = 0;                                   /** @brief: Global variable should be declared in a defined section in Flash*/

uint8_t gu8MainTempVar = 0;                                                    /** @brief: Global variable should be declared in the default place*/ 
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

uint32_t main(void)
{    
    if(1 == gu8MainArray[0])
    {
        gu8MainTempVar = 0;
    }
    else
    {
        gu8MainTempVar = 4;
    }

    for(;;);
    
    return 0;
}

/**********************************************************************************************************************
 *  END OF FILE: main.c
 *********************************************************************************************************************/

