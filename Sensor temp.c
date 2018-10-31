#ifndef _TEMP_
#define _TEMP_
#include "types.h"
#include "util.h"
#include "ADCTEMP_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "interrupt.h"
#include "DELAY.h"
void tempsensorEnable()
{
u16 Local_u8AdcResult;
for(;;) 
    {	
		ADC_voidReadSingleShot(&Local_u8AdcResult);
		DIO_u8WritePortVal(1,Local_u8AdcResult);
		DIO_u8WritePortVal(2,Local_u8AdcResult>>8);
		u8 adcres[2];
		itoa((Local_u8AdcResult/128)-1,adcres,10);
         /*interruption*/
			if((Local_u8AdcResult/128)-1>=45||(Local_u8AdcResult/128)-1<5)
		{
			LCD_voidWriteString("DANGER temp!                                                    Plz Call The CR");
		    delay_ms(50);
		    LCD_voidClearSceen();
		     delay_ms(50);
			 
    }
	//normal mode
	else
	{
				LCD_voidWriteString("temp=");
				LCD_voidWriteString(adcres);
				delay_ms(150);
				LCD_voidClearSceen();
				delay_ms(150);
	}
	}

}
#endif