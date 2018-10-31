#define	F_CPU	1000000
#include "util.h"
#include "Smokesensorconfig.h"
#include "display.h"
#include<stdlib.h>
void smokesensorenable(){
	int mq2_smoke_sensor_output=0;
	_delay_ms(500);
	_delay_ms(500);
	_delay_ms(500);
	_delay_ms(500);
     for(;;)
	{
	if(mq2_smoke_sensor_output > MQ2_SENSOR_REF)
		{
			clear_scrn();
			_delay_ms(100);
			LCD_Disp("High Smoke");
			_delay_ms(50);
			/*String display in 1st row of LCD*/
		}
		//mq2_smoke_sensor_output=read_adc_channel(0);
		/*Reading MQ-2 Smoke Sensor output from channel 0*/
		
		/*Checking MQ-2 Smoke Sensor output with threshold to turn On or Off Buzzer*/
		if(mq2_smoke_sensor_output > MQ2_SENSOR_REF)
		{
			SET_BIT(*DDRC,1);
			/*Buzzer is On*/
		}
		else
		{
			CLR_BIT(*DDRC,1);
			/*Buzzer is Off*/
		}

		_delay_ms(500);
		/*Display stays for 500ms*/
	}
}

	
