#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#define F_CPU 1000000
#include <util/delay.h>
#define    E   5
#define RS  6
static volatile int pulse = 0; //interger  to access all though the program

static volatile int i = 0;     // interger  to access all though the program
void garageincreament(){
void send_a_command(unsigned char command);

void send_a_character(unsigned char character);

void send_a_string(char *string_of_characters);

	DDRB = 0xFF;

	//putting portB output pins

	DDRD = 0b11111011;

	_delay_ms(50);//giving delay of 50ms

	DDRC = 0xFF;//Taking portA as output.

	GICR|=(1<<INT0);//enabling interrupt0

	MCUCR|=(1<<ISC00);//setting interrupt triggering logic change

	int16_t COUNTA = 0;//storing digital output

	char SHOWA [3];//displaying digital output as temperature in 16*2 lcd

	send_a_command(0x01); //Clear Screen 0x01 = 00000001

	_delay_ms(50);

	send_a_command(0x38);//telling lcd we are using 8bit command /data mode

	_delay_ms(50);

	send_a_command(0b00001111);//LCD SCREEN ON and courser blinking

	sei();// enabling global interrupts

		

		//displaying name
         int counter;
		 char counterc[2];
		 if(COUNTA!=150) //distance which will change accourding to the real distance
		 {
			 for(counter;counter<=50;counter++){
               send_a_string ("No.of.cars=");		
			 itoa(counter,counterc,10);
			 send_a_string (counterc);
			send_a_command(0x80 + 0x40 + 0); // shifting cursor  to 1st  shell  of second line
	 		send_a_string ("DISTANCE=");// displaying name
	 	    PORTD|=(1<<PIND0);

	 	    _delay_us(15);///triggering the sensor for 15usec

	 	    PORTD &=~(1<<PIND0);

	 	    COUNTA = pulse/58;//getting the distance based on formula on introduction
		 	itoa(COUNTA,SHOWA,10); //command for putting variable number in LCD(variable number, in which character to replace, which base is variable(ten here as we are counting number in base10))
	 		send_a_string(SHOWA); //telling the display to show character(replaced by variable number) after positioning the courser on LCD
	 		send_a_string ("cm       ");

	 		send_a_command(0x80 + 0); //retuning to first line first shell
		 }
		 
			 }
			 send_a_string("Not Free Space");
		 }
		 

ISR(INT0_vect)//interrupt service routine when there is a change in logic level

{

	if (i==1)//when logic from HIGH to LOW

	{

		TCCR1B=0;//disabling counter

		pulse=TCNT1;//count memory is updated to integer

		TCNT1=0;//resetting the counter memory

		i=0;

	}

	if (i==0)//when logic change from LOW to HIGH

	{

		TCCR1B|=(1<<CS10);//enabling counter

		i=1;

	}

}

void send_a_command(unsigned char command)

{

	PORTC = command;

	PORTD &= ~ (1<<RS); //putting 0 in RS to tell lcd we are sending command

	PORTD |= 1<<E; //telling lcd to receive command /data at the port

	_delay_ms(50);

	PORTD &= ~1<<E;//telling lcd we completed sending data

	PORTC= 0;

}

void send_a_character(unsigned char character)

{

	PORTC= character;

	PORTD |= 1<<RS;//telling LCD we are sending data not commands

	PORTD |= 1<<E;//telling LCD to start receiving command/data

	_delay_ms(50);

	PORTD &= ~1<<E;//telling lcd we completed sending data/command

	PORTC = 0;

}

void send_a_string(char *string_of_characters)

{

	while(*string_of_characters > 0)

	{

		send_a_character(*string_of_characters++);

	}

}