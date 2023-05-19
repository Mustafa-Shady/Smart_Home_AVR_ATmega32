




#include <MCAL/ADC_interface.h>



Adc_ConfigurationType Adc_Configuration = {

	/*********************Adc_referenceType*********************/
	/*ADC_REF_AREF,*/
	/*ADC_REF_AVCC,*/
	/*ADC_REF_INTERNAL*/

	ADC_REF_AVCC,

	/*********************Adc_TriggerSourceType*********************/
	/*ADC_AUTO_TRIGGER_OFF,*/
	/*ADC_AUTO_TRIGGER_FREE_RUNNING,*/
	/*ADC_AUTO_TRIGGER_ANAL_COMP,*/
	/*ADC_AUTO_TRIGGER_EXTI0,*/
	/*ADC_AUTO_TRIGGER_TIM0_COMP,*/
	/*ADC_AUTO_TRIGGER_TIM0_OVF,*/
	/*ADC_AUTO_TRIGGER_TIMB_COMP,*/
	/*ADC_AUTO_TRIGGER_TIM1_OVF,*/
	/*ADC_AUTO_TRIGGER_TIM1_CAP*/
	
	ADC_AUTO_TRIGGER_TIM0_OVF,

	/*********************Adc_PrescalerType*********************/
	/*ADC_PRESCALER_2,*/
	/*ADC_PRESCALER_4,*/
	/*ADC_PRESCALER_8,*/
	/*ADC_PRESCALER_16,*/
	/*ADC_PRESCALER_32,*/
	/*ADC_PRESCALER_64,*/
	/*ADC_PRESCALER_128*/

	ADC_PRESCALER_128

};
