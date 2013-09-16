#include <avr/io.h>
#include <util/delay.h>

#define LEDDelayOn 1000
#define LEDDelayOff 250

int main(){
	DDRD = 0xFF;
	PORTD = 0;
	
	while(1){
		_delay_ms(LEDDelayOff);
		PORTD = 0xFF;
		_delay_ms(LEDDelayOn);
		PORTD = 0x00;
	}
}
