#include <avr/io.h>
#include <util/delay.h>

#ifndef UCSRB
# ifdef UCSR1A
#  define UCSRA UCSR1A
#  define UDRE  UDRE1
#  define UCSRB UCSR1B
#  define RXEN  RXEN1
#  define TXEN  TXEN1
#  define UCSRC UCSR1C

#  define UBRR UBRR1L
#  define UDR UDR1
# endif
#endif

#define BAUDRATE 38400
#define BAUD_PRESCALE (F_CPU / 16 / BAUDRATE -1)                    // 25.0416

int main(void) {
  unsigned char ch = '.';

// Clear double speed operation
  UCSRA &= ~(1 << U2X1);

// Enable TX and RX circuitry
  UCSRB |= (1 << RXEN) | (1 << TXEN);

// 8-bit data, 1 stop bit
  UCSRC |= (0 << USBS1) | (1 << UCSZ10) | (1 << UCSZ11);

// Initialize baud rate
  UBRR1H = (BAUD_PRESCALE >> 8);
  UBRR1L =  BAUD_PRESCALE;

  DDRD  = 0xff;
  PORTD = 0;

  while(1) {
    if (UCSRA & (1 << RXC1)) ch = UDR1;


// Wait till transmitter is ready
    while ((UCSRA & (1 << UDRE)) == 0) {};

    UDR1 = ch;

    _delay_ms(500);
/*    PORTD |= 1;

    _delay_ms(1500);
    PORTD &= ~(1 << 0);
*/
  }
}
