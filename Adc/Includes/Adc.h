/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Adc.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef ADC_H
#define ADC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Adc_Types.h"
#include "Mc_Hw.h"
#include "Adc_Lcfg.h"
/**********************************************************************************************************************
 *  APIs
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Adc_Init ( const Adc_ConfigType* ConfigPtr )                                      
* \Description     : initialize Analog to Digital Module by parsing the Configuration 
*                    into System registers                                                                 
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr: user configuration                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_Init ( const Adc_ConfigType* ConfigPtr );


/******************************************************************************
* \Syntax          : Std_ReturnType Adc_SetupResultBuffer ( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr )                                      
* \Description     : Initializes ADC driver with the group specific result buffer start address where the conversion results
*					 will be stored.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Group: ADC group                     
* \Parameters (in) : DataBufferPtr:pointer to conversion result plave                     
* \Parameters (out): None                                                      
* \Return value:   : returns SUCCESS if there is no errors, otherwise check return errors
*******************************************************************************/
Std_ReturnType Adc_SetupResultBuffer ( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr );

/******************************************************************************
* \Syntax          : void Adc_StartGroupConversion ( Adc_GroupType Group )                                      
* \Description     : Starts ADC conversion                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Group: ADC group                
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_StartGroupConversion ( Adc_GroupType Group );

/******************************************************************************
* \Syntax          : void Adc_StopGroupConversion ( Adc_GroupType Group )                                      
* \Description     : Stop ADC conversion                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Group: ADC group                
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_StopGroupConversion ( Adc_GroupType Group );

/******************************************************************************
* \Syntax          : Std_ReturnType Adc_ReadGroup ( Adc_GroupType Group, Adc_ValueGroupType*DataBufferPtr )                                      
* \Description     : Read an ADC group                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group: ADC group                                          
* \Parameters (out): DataBufferPtr: Buffer to store conversion data                                                      
* \Return value:   : returns SUCCESS if there is no errors, otherwise check return errors
*******************************************************************************/
Std_ReturnType Adc_ReadGroup ( Adc_GroupType Group, Adc_ValueGroupType*DataBufferPtr );

/******************************************************************************
* \Syntax          : Adc_StatusType Adc_GetGroupStatus ( Adc_GroupType Group )                         
* \Description     : Get Group Status                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group: ADC Group       
* \Parameters (out): None                                                      
* \Return value:   : Status of ADC group, check @Adc_StatusType for more information
*******************************************************************************/
Adc_StatusType Adc_GetGroupStatus ( Adc_GroupType Group );

/******************************************************************************
* \Syntax          : Adc_StreamNumSampleType Adc_GetStreamLastPointer ( Adc_GroupType Group,Adc_ValueGroupType** PtrToSamplePtr )                                      
* \Description     : Gets last pointer of the stream                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group: ADC Group
* \Parameters (out):  PtrToSamplePtr pointer to pointer of data buffer                                                      
* \Return value:   : value of sample type check @Adc_StreamNumSampleType for more information
*******************************************************************************/
Adc_StreamNumSampleType Adc_GetStreamLastPointer ( Adc_GroupType Group,Adc_ValueGroupType** PtrToSamplePtr );

/******************************************************************************
* \Syntax          : void Adc_EnableHardwareTrigger ( Adc_GroupType Group )                                      
* \Description     : Enable HW triggers                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group : ADC Group
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_EnableHardwareTrigger ( Adc_GroupType Group );

/******************************************************************************
* \Syntax          : void Adc_DisableHardwareTrigger ( Adc_GroupType Group )                                      
* \Description     : Disable HW triggers                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group : ADC Group
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_DisableHardwareTrigger ( Adc_GroupType Group );

/******************************************************************************
* \Syntax          : void Adc_EnableGroupNotification ( Adc_GroupType Group )                                      
* \Description     : Enable an ADC group Notification                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group : ADC Group
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
 void Adc_EnableGroupNotification ( Adc_GroupType Group );

/******************************************************************************
* \Syntax          : void Adc_DisableGroupNotification ( Adc_GroupType Group )                                      
* \Description     : Disable an ADC group Notification                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group : ADC Group
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
 void Adc_DisableGroupNotification ( Adc_GroupType Group );


#endif  /* ADC_H*/
/**********************************************************************************************************************
 *  END OF FILE: Adc.h
 *********************************************************************************************************************/
