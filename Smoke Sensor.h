#ifndef F_CPU
#define F_CPU 8000000
#endif
#include<avr/io.h>
/*Includes io.h header file where all the Input/Output Registers and its Bits are defined for all AVR microcontrollers*/
#include<util/delay.h>
/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/
#include<stdlib.h>
/*ADC Function Declarations*/

int mq3_alcohol_sensor_output;
char buffer[70];
int LM35_TEMP;
char Sensor[70];
void adc_init(void);
int read_adc_channel(unsigned char channel);
void Diplay_Smoke_ratio();


void adc_init(void)
{
	ADCSRA=(1<<ADEN)|(1<<ADSC)|(1<<ADATE)|(1<<ADPS2);
	SFIOR=0x00;
}

int read_adc_channel(unsigned char channel)
{
	int adc_value;
	unsigned char temp;
	ADMUX=(1<<REFS0)|channel;
	_delay_ms(1);
	temp=ADCL;
	adc_value=ADCH;
	adc_value=(adc_value<<8)|temp;
	return adc_value;
}
void Diplay_Smoke_ratio(){
     itoa( mq3_alcohol_sensor_output , buffer , 10);	
	mq3_alcohol_sensor_output=read_adc_channel(5);
	mq3_alcohol_sensor_output-=100;
	if(mq3_alcohol_sensor_output<150){
		LCD_Disp("the Smoke Ratio= ");
		go_to_2nd_line();
		LCD_Disp(buffer);
		_delay_ms(500);
	}
	if (mq3_alcohol_sensor_output>300)
	{
		LCD_Disp("Danger..!");
		_delay_ms(1000);
		clear_scrn();
		_delay_ms(1000);
		LCD_Disp("Danger..!");
		_delay_ms(1000);
		clear_scrn();
		_delay_ms(1000);
		LCD_Disp("Danger..!");
		_delay_ms(500);
	}
	_delay_ms(500);
	clear_scrn();
	
}
void Diplay_Temprture(){
	itoa( LM35_TEMP , Sensor , 10);
	LM35_TEMP=read_adc_channel(0);
	
	//if(LM35_TEMP>50){
		//1×9/5+32
		LM35_TEMP=(LM35_TEMP-32)*5/9;
		if(LM35_TEMP<50){
		LCD_Disp("the Temp is ");
		go_to_2nd_line();
		LCD_Disp(Sensor);
		}
	
	else{
		LCD_Disp("DANGER");
	}
}
//}
void send_Smokereading_to_mob(){
	string_send("Smoke Ratio= ");
	string_send(buffer);
	string_send("\n");
     if (mq3_alcohol_sensor_output>300)
     {
		 string_send("DANGER!!!");
		 string_send("\n");
     }
}
void send_Temp_to_mob(){
	string_send("Temprture is = ");
	string_send(Sensor);
	string_send("\n");
	if (LM35_TEMP>70)
	{
		string_send("DANGER!!!");
		string_send("\n");
	}
	
	
}
	