/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/

/*
	This version of pins_arduino.h is for the Zigduino r1
	Pierce Nichols 2011 Oct 11

	Modified for the meshthing
	Robert Powers 2013 Sep/Dec
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

//This is the number of I/O pins, including those that double as analogue.
#define NUM_DIGITAL_PINS            28

#define NUM_ANALOG_INPUTS           7

//This is some strange thing to do with addressing analogue pins as digital(?). 
//It seems like others have been putting this offset as A0->MAX(DigitalPin#)+1
//so for Meshthing if you get D21 -> A0
#define analogInputToDigitalPin(p)  ((p < 7) ? (p) + 21 : -1)


#define digitalPinHasPWM(p)         ( (p) == 4 || (p) == 10 || (p) == 14 || (p) == 15 )

//Addressing here seems to be at the chip pinout level.(?)-RDP
/*const static uint8_t SS   = 10*/
/*
const static uint8_t SS   = 26;
const static uint8_t MOSI = 28;
const static uint8_t MISO = 29;
const static uint8_t SCK  = 27;

const static uint8_t SDA = 18;
const static uint8_t SCL = 17;
const static uint8_t LED = 17;

const static uint8_t A0 = 46;
const static uint8_t A1 = 47;
const static uint8_t A2 = 48;
const static uint8_t A3 = 1;
const static uint8_t A4 = 2;
const static uint8_t A5 = 3;
const static uint8_t A6 = 4;
*/

//Using arduino digital pin mappings to specifc keywords
const static uint8_t SS   = 17;
const static uint8_t MOSI = 11;
const static uint8_t MISO = 12;
const static uint8_t SCK  = 13;

const static uint8_t SDA = 18;
const static uint8_t SCL = 16;
const static uint8_t LED = 13;

const static uint8_t A0 = 21;
const static uint8_t A1 = 22;
const static uint8_t A2 = 23;
const static uint8_t A3 = 24;
const static uint8_t A4 = 25;
const static uint8_t A5 = 26;
const static uint8_t A6 = 27;


// Disregard this comment - RDP
// A majority of the pins are NOT PCINTs, SO BE WARNED (i.e. you cannot use them as receive pins)
// Only pins available for RECEIVE (TRANSMIT can be on any pin):
// Pins: 4,8,10,11,12

//I'm not sure which addressing is used for all of this. I'm using the chip pinout. Could be this is supposed to use the arduino pinout?
//Still checking... -RDP
//#define digitalPinToPCICR(p)    ( ( (((p) >= 26) && ((p) <= 34)) ) ? (&PCICR) : ((uint8_t *)0) )
//Using Arduino digital pin mapping to set which pins have pin change interrupts.
#define digitalPinToPCICR(p)    ( ( (((p) >= 10) && ((p) <= 14)) || ((p) == 17) || ((p) == 19) ) ? (&PCICR) : ((uint8_t *)0) )

//I don't know what this does 
//Looks like something to do with a PC control register, but I can't suss it out. - RDP
#define digitalPinToPCICRbit(p) ( ((p) == 7) ? 1 : 0 ) 

//This returns the PC mask register associated with each pin. PCINT0-7 are on PCMSK0, PCINT8 is on PCMSK1
#define digitalPinToPCMSK(p)    ( ( (((p) >= 10) && ((p) <= 14)) || ((p) <= 17) ) ? (&PCMSK0) : \
                                ( ((p) == 19) ? (&PCMSK1) : \
                                ((uint8_t *)0) ) )

//Looks like this maps the pin to the PC mask register control bit
// PCINT0-7 are 0-7 on PCMSK0, PCINT8 is bit 0 on PCMSK1
#define digitalPinToPCMSKbit(p) ( ((p) == 17) ? 0 : \
                                ( ((p) == 13) ? 1 : \
                                ( ((p) == 11) ? 2 : \
                                ( ((p) == 12) ? 3 : \
                                ( ((p) == 14) ? 4 : \
                                ( ((p) == 10) ? 5 : \
                                ( ((p) == 19) ? 0 : \
                                0 ) ) ) ) ) ) )

#ifdef ARDUINO_MAIN

const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t)&DDRB,
	NOT_A_PORT,
	(uint16_t)&DDRD,
	(uint16_t)&DDRE,
	(uint16_t)&DDRF,
	(uint16_t)&DDRG,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t)&PORTB,
	NOT_A_PORT,
	(uint16_t)&PORTD,
	(uint16_t)&PORTE,
	(uint16_t)&PORTF,
	(uint16_t)&PORTG,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
};

//I don't know what this does... might need a look. 
//It looks like it's saying where input ports exist... -RDP
const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	NOT_A_PIN,
	(uint16_t)&PINB,
	NOT_A_PIN,
	(uint16_t)&PIND,
	(uint16_t)&PINE,
	(uint16_t)&PINF,
	(uint16_t)&PING,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST		
	// -------------------------------------------	

	//THIS PINOUT IS USED FOR SDCARD ACCESSS, NO LONGER BREAKS BLINK EXAMPLE! (as of v1.1)
	PF	, // PF 0 ** 0 ** DIO0/AD0	-- XBee Pin 20
	PF	, // PF 1 ** 1 ** DIO1/AD1	-- XBee Pin 19
	PF	, // PF 2 ** 2 ** DIO2/AD2	-- XBee Pin 18
	PF	, // PF 3 ** 3 ** DIO3/AD3  	-- XBee Pin 17
	PE	, // PE 4 ** 4 ** DIO4		-- XBee Pin 11
	PF	, // PF 5 ** 5 ** DIO5/AD5/Assoc-- XBee Pin 15
	PF	, // PF 6 ** 6 ** DIO6/AD6/~RTS	-- XBee Pin 16
	PF	, // PF 7 ** 7 ** DIO7/AD7/~CTS -- XBee Pin 12
	PD	, // PD 3 ** 8 ** DO8/UART1 TX/INT3-- XBee Pin 4
	PD	, // PD 1 ** 9 ** SDA/~DTR/DI8  -- I2C_SCA XBee Pin 9
	PB	, // PB 5 ** 10 ** PWM0/RSSI	-- XBee Pin 6

	PB	, // PB 2 ** 11 ** MOSI		-- SDCard Pin 3 (CMD/DI)
	PB	, // PB 3 ** 12 ** MISO		-- SDCard Pin 7 (Dat0)
	PB	, // PB 1 ** 13 ** SCK		-- SDCard Pin 5 (Clk)	

	PB	, // PB 4 ** 14 ** PWM1		-- XBee Pin 7
	PE	, // PE 5 ** 15 ** PWM3?(OC3C/Int5)-- XBee Pin 14	
	PD	, // PD 0 ** 16 ** SCL/ON	-- I2C_SCL XBee Pin 13
	PB	, // PB 0 ** 17 ** 		-- SDCard Pin 2 (CS/CD/DAT3)



	PE	, // PE 1 ** 18 ** USART0_TX	-- XBee Pin 2
	PE	, // PE 0 ** 19 ** USART0_RX	-- XBee Pin 3
	PD	, // PD 2 ** 20 ** USART1_RX    -- XBee Pin 8

};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------
	// Comments not up to date!		
	_BV( 0 )	, // PF 0 ** 0 ** DIO0/AD0	-- 20
	_BV( 1 )	, // PF 1 ** 1 ** DIO1/AD1	-- 19
	_BV( 2 )	, // PF 2 ** 2 ** DIO2/AD2	-- 18
	_BV( 3 )	, // PF 3 ** 3 ** DIO3/AD3  	-- 17
	_BV( 4 )	, // PE 4 ** 4 ** DIO4		-- 11
	_BV( 5 )	, // PF 5 ** 5 ** DIO5/AD5/Assoc-- 15
	_BV( 6 )	, // PF 6 ** 6 ** DIO6/AD6/~RTS	-- 16
	_BV( 7 )	, // PF 7 ** 7 ** DIO7/AD7/~CTS -- 12
	_BV( 3 )	, // PD 3 ** 8 ** DO8/UART1 TX/INT3-- 4
	_BV( 1 )	, // PD 1 ** 9 ** SDA/~DTR/DI8  -- 9
	_BV( 5 )	, // PB 5 ** 10 ** PWM0/RSSI	-- 6

	_BV( 2 )	, // PB 2 ** 11 ** MOSI		-- SDCard Pin 3 (CMD/DI)
	_BV( 3 )	, // PB 3 ** 12 ** MISO		-- SDCard Pin 7 (Dat0)	
	_BV( 1 )	, // PB 1 ** 13 ** SCK		-- SDCard Pin 5 (Clk)	

	_BV( 4 )	, // PB 4 ** 14 ** PWM1		-- 7
	_BV( 5 )	, // PE 5 ** 15 ** PWM3?(OC3C/Int5)--14
	_BV( 0 )	, // PD 0 ** 16 ** SCL/ON	-- 13	
	_BV( 0 )	, // PB 0 ** 17 ** 		--SDCard Pin 2 (CS/CD/DAT3)	


	
	_BV( 1 )	, // PE 1 ** 18 ** USART0_TX	-- XBee Pin 2
	_BV( 0 )	, // PE 0 ** 19 ** USART0_RX	-- XBee Pin 3
	_BV( 2 )	, // PD 2 ** 20 ** USART1_RX    -- XBee Pin 8

};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		
	// -------------------------------------------
	// Ignore comments not indented!	
	NOT_ON_TIMER	, // PE 0 ** 0 ** USART0_RX	
	NOT_ON_TIMER	, // PE 1 ** 1 ** USART0_TX	
	NOT_ON_TIMER	, // PE 2 ** 2 ** D2
	NOT_ON_TIMER	, // PE 3 ** 3 ** PWM3
	TIMER3B			, // PE 4 ** 4 ** PWM6
	NOT_ON_TIMER	, // PE 3 ** 5 ** PWM5
	NOT_ON_TIMER	, // PE 4 ** 6 ** PWM6
	NOT_ON_TIMER	, // PE 7 ** 7 ** D7
	TIMER1B		, 	// PB 6 ** 8 ** PWM8
	NOT_ON_TIMER	, // PB 7 ** 9 ** PWM9
	TIMER1A		, 	// PB 5 ** 10 ** PWM10
	TIMER2A		, 	// PB 4 ** 11 ** PWM11
	TIMER3C		, 	// PE 5 ** 12 ** 
	NOT_ON_TIMER	, // PB 1 ** 13 ** SPI_SCK
	NOT_ON_TIMER	, // PE 5 ** 14 ** A0	
	NOT_ON_TIMER	, // PF 1 ** 15 ** A1	
	NOT_ON_TIMER	, // PF 2 ** 16 ** A2	
	NOT_ON_TIMER	, // PF 3 ** 17 ** A3	
	NOT_ON_TIMER	, // PF 4 ** 18 ** A4	
	NOT_ON_TIMER	, // PF 5 ** 19 ** A5
	NOT_ON_TIMER	, // PB 2 ** 20 ** SPI_MOSI

};	

#endif

#endif
