#include <avr/io.h>
#include <util/delay.h>

#define LEDDelayOn 1000
#define LEDDelayOff 250

int main(){
	DDRB = 0xFF;
	PORTB = 0;
	
	while(1){
		_delay_ms(LEDDelayOff);
		PORTB = 0xFF;
		_delay_ms(LEDDelayOn);
		PORTB = 0x00;
	}
}
