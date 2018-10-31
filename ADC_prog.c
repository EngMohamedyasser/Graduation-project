/*
 * ADC_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: shehab
 */
#include "types.h"
#include "util.h"
#include "ADC_interface.h"
#include "ADCTEMP_config.h"
#include "ADC_private.h"
#include "DIO_interface.h"


const static u8 ADC_ChannelsConfig[ADC_u8CHANNELSNUMBER][CHANNEL_SELECTION_BITS] =
		{ { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1 }, { 0, 0, 0, 1, 0 }, { 0, 0, 0, 1,
				1 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 1 }, { 0, 0, 1, 1, 0 }, {
				0, 0, 1, 1, 1 } };
const static u8 ADC_ReferenceSelection[REFERENCE_SELECTION_OPTIONS][REFERENCE_SELECTION_BITS] =
		{ { 0, 0 }, { 0, 1 }, { 1, 1 } };
const static u8 ADC_PrescalerSelection[ADC_PRESCALER_OPTIONS][ADC_PRESCALER_BITS] =
		{ { 0, 0, 0 }, { 0, 0, 1 }, { 0, 1, 0 }, { 0, 1, 1 }, { 1, 0, 0 }, { 1,
				0, 1 }, { 1, 1, 0 }, { 1, 1, 1 } };
extern void ADC_voidEnable(void) {

	//SET_BIT(*ADCSRA, ADEN);

	*ADCSRA|=(1<<7);

	return;
}
extern void ADC_voidDisable(void) {
	CLR_BIT(*ADCSRA, ADEN);

	return;
}

extern void ADC_voidConfig(void) {

	/////	////////////////////////////////Assign the channel////////////////////////////////////////
	s8 Local_u8Counter;
	for (Local_u8Counter = CHANNEL_SELECTION_BITS - 1; Local_u8Counter >= 0;Local_u8Counter--) {

		ASSIGN_BIT(*ADMUX, Local_u8Counter,ADC_ChannelsConfig[TEMP_ADC_CHANNEL][4-Local_u8Counter]);

	}

	/////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////Adjustment////////////////////////////////////////////////
	ASSIGN_BIT(*ADMUX, 5, TEMP_ADC_RESULT);
	////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////Reference Selection//////////////////////////////////////
	for (Local_u8Counter = REFERENCE_SELECTION_BITS - 1; Local_u8Counter >= 0;
			Local_u8Counter--) {

		ASSIGN_BIT(*ADMUX,( Local_u8Counter + 6 ),ADC_ReferenceSelection[TEMP_ADC_REFERENCE][1-Local_u8Counter]);

	}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////Prescaler Selection///////////////////////////////////////////
	for (Local_u8Counter = ADC_PRESCALER_BITS - 1; Local_u8Counter >= 0;Local_u8Counter--) {

		ASSIGN_BIT(*ADCSRA, Local_u8Counter,ADC_PrescalerSelection[TEMP_ADC_PRESCALER][2-Local_u8Counter]);

	}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////ADC Interrupt enable/disbale///////////////////////////////////
	   ASSIGN_BIT(*ADCSRA, ADIE, TEMP_ADC_INTERRUPT_ED);
////	/////////////////////////////////////////////////////////////////////////////////////////////////
////	//////////////////////////////////ADC Auto trigger enable/disbale//////////////////////////////////////////
		ASSIGN_BIT(*ADCSRA, ADATE, TEMP_ADC_AUTOTRIGGER_ED);
//		/////////////////////////////////////////////////////////////////////////////////////////////////

	return;
}
extern void ADC_voidReadSingleShot(u16 *Copy_ptrToVal) {
	/*Comment!:Start Conversion*/
	GET_BIT(*MCUCR,SM0);
	SET_BIT(*ADCSRA,ADSC);

	/*Comment!:wait for the conersion to complete*/

    while (GET_BIT(*ADCSRA,ADIF)==0);

    /*Comment!:read the result */
    *Copy_ptrToVal=*ADC;
    /*Comment!:clear the flag */
    SET_BIT(*ADCSRA,ADIF);

	return;
}
extern void ADC_voidReadMulShot(u16 *Copy_ptrToVal){
    GET_BIT(*MCUCR,SM0);
	//MCUCR|=(1<<4);
	u16 Local_u16Result;
    u8 Local_u8Counter;
    	for (Local_u8Counter = 0; Local_u8Counter < 8 ;Local_u8Counter++) {

    		ADC_voidReadSingleShot(&Local_u16Result);
    		*Copy_ptrToVal+=Local_u16Result;

    	}
    	*Copy_ptrToVal/=8;

	return ;

}


