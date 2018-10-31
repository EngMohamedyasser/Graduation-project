#ifndef _ADCTEMP_config_h_
#define _ADCTEMP_config_h_




/*Comment!: ADC voltage references (AREF,AVCC,INTERNAL) */

#define SS_ADC_REFERENCE AVCC

/*Comment!: ADC result adjusting (LEFT_ADJUSTED,RIGT_ADJUSTED) */

#define SS_ADC_RESULT	LEFT_ADJSUTED

/*Comment!: ADC Channel  (ADC0 , .. , ADC7)*/

#define SS_ADC_CHANNEL ADC5

/*Comment!: ADC Channel Mode (SINGLE_ENDED_INPUT,DIFFERENTIAL_INPUT) */

#define SS_ADC_CHANNELMODE SINGLE_ENDED_INPUT


/*Comment!: ADC Channel Prescaler (2,2,4,8,16,32,64,128)  */
#define SS_ADC_PRESCALER         ADC_PRESCAL16

/*Comment!: ADC Interrupt Enable (ADIE)  */
#define SS_ADC_INTERRUPT_ED         DISABLE

/*Comment!:ADC Auto Trigger Enable (ADATE) */
#define SS_ADC_AUTOTRIGGER_ED   	   DISABLE
/*sensor refrence to compare*/
#define		MQ2_SENSOR_REF		700



#endif /* ADC_CONFIG_H_ */