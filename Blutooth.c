#ifndef F_CPU
#define F_CPU 8000000
#endif
#include <avr/io.h>
#include <util/delay.h>
char rc[100]; // global buffer to store input and output strings for processing
void UART_init(){
	//set baud rate
	int baud =51;
	UBRRH=(unsigned char)(baud>>8);
	UBRRL=(unsigned char)baud;
	//asynchronous mode , only one stop bit , 8-bit data payload , not parity
	UCSRC|=(1<<URSEL)|(3<<UCSZ0);
	/* Enable receiver and transmitter */
	UCSRB|=(1<<RXEN);
	UCSRB|=(1<<TXEN);

}
void string_send(char* c){
	int i=0;
	while(c[i]!='\0'){
		while ( !( UCSRA & (1<<UDRE)) ); //stay here while busy sending a character
		/* Put data into buffer, sends the data */
		
		UDR = c[i];
		_delay_ms(50);
		i++;
	}
	while ( !( UCSRA & (1<<UDRE)) ); //stay here while busy sending a character
	UDR = c[i]; //manipulating '\0' , the terminating character
}
void start_Sharing(){
	string_send("Good Morning \n");
}
