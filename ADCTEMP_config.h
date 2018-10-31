/*
 * ADC_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: shehab
 */

#ifndef _ADCTEMP_config_h_
#define _ADCTEMP_config_h_




/*Comment!: ADC voltage references (AREF,AVCC,INTERNAL) */

#define TEMP_ADC_REFERENCE AVCC

/*Comment!: ADC result adjusting (LEFT_ADJUSTED,RIGT_ADJUSTED) */

#define TEMP_ADC_RESULT	LEFT_ADJSUTED

/*Comment!: ADC Channel  (ADC0 , .. , ADC7)*/

#define TEMP_ADC_CHANNEL ADC0

/*Comment!: ADC Channel Mode (SINGLE_ENDED_INPUT,DIFFERENTIAL_INPUT) */

#define TEMP_ADC_CHANNELMODE SINGLE_ENDED_INPUT


/*Comment!: ADC Channel Prescaler (2,2,4,8,16,32,64,128)  */
#define TEMP_ADC_PRESCALER         ADC_PRESCAL16

/*Comment!: ADC Interrupt Enable (ADIE)  */
#define TEMP_ADC_INTERRUPT_ED         DISABLE

/*Comment!:ADC Auto Trigger Enable (ADATE) */
#define TEMP_ADC_AUTOTRIGGER_ED   	   DISABLE



#endif /* ADC_CONFIG_H_ */
