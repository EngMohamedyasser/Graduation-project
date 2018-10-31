#define F_CPU 8000000UL
#include <avr\io.h>
#include <util\delay.h>
#include "util.h"
#include <stdlib.h>
#include "display.h"
#include "Smoke Sensor.h"

    int main()
    {
		//int mq3_alcohol_sensor_output=0;
		//char buffer[70];
		//itoa( mq3_alcohol_sensor_output , buffer , 10);
     adc_init();
     LCD_Init();
     UART_init();
     start_LCD();
     start_Sharing();
	 LCD_Disp("Hello in");
     go_to_2nd_line();
     LCD_Disp("  smart Village");
     _delay_ms(200);
     clear_scrn();
     _delay_ms(50);
     while(1)
     {
		 Diplay_Smoke_ratio();
		 _delay_ms(500);
		 clear_scrn();
		 _delay_ms(500);
		 Diplay_Temprture();
		 _delay_ms(500);
		 clear_scrn();
		 _delay_ms(500);
	      string_send("The new Reading is \n ");
	      _delay_ms(300);
           send_Smokereading_to_mob();
		   _delay_ms(500);
		   send_Temp_to_mob();
	       _delay_ms(5000);
	  
	 }
     }