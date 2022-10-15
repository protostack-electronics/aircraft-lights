#include <avr/io.h>
#include <util/delay.h>

/*
PA0 Landing
PA1 Nav-Starboard
PA2 Nav-Port
PA3 Beacon 1
PA4 Beacon 2

PB0 Landing Gear Signal  1 = Landing
*/

#define is_landing() PINB & 0b00000001


int main (void) {
	//1 = output, 0 = input
	DDRA  = 0b11111111;
	
	unsigned char led_flying[8] = {
		0b00001110, 
		0b00001110, 
		0b00010110, 
		0b00010110, 
		0b00000110, 
		0b00000110, 
		0b00000110, 
		0b00000110 
	};
	unsigned char led_landing[8] = {
		0b00001011, 
		0b00001001, 
		0b00010011, 
		0b00010001, 
		0b00000101, 
		0b00000001, 
		0b00000101, 
		0b00000001
	};
	
	uint8_t step = 0;
	
    while(1)  {
		step = (step + 1) % 8;
		
		if (is_landing()) {
			PORTA = led_landing[step];
		} else {
			PORTA = led_flying[step];
		}
		_delay_ms(125);
    }
	
	 return(0);
}
