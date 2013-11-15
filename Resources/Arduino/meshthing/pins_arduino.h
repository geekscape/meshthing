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
	Robert Powers 2013 Sep
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            15
#define NUM_ANALOG_INPUTS           7
#define analogInputToDigitalPin(p)  ((p < 6) ? (p) + 14 : -1)
#define digitalPinHasPWM(p)         ((p) == 3 ||(p) == 4 ||(p) == 6 ||(p) == 8 ||(p) == 9 ||(p) == 10 ||(p) == 11)

/*const static uint8_t SS   = 10*/
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

// A majority of the pins are NOT PCINTs, SO BE WARNED (i.e. you cannot use them as receive pins)
// Only pins available for RECEIVE (TRANSMIT can be on any pin):
// Pins: 4,8,10,11,12

#define digitalPinToPCICR(p)    ( ( (((p) >= 10) && ((p) <= 12)) || ((p) == 4) || ((p) == 8)) ) ? (&PCICR) : ((uint8_t *)0) )

//I don't know what this does - RDP
#define digitalPinToPCICRbit(p) ( ((p) == 7) ? 1 : 0 ) 

//This either - RDP
#define digitalPinToPCMSK(p)    ( ((((p) >= 8) && ((p) <= 13)) || ((p) == 20)) ? (&PCMSK0) : \
                                ( ((p) == 7) ? (&PCMSK1) : \
                                ((uint8_t *)0) ) )

//This. Complete mystery right now.
#define digitalPinToPCMSKbit(p) ( ((p) == 7) ? 0 : \
                                ( ((p) == 8) ? 4 : \
                                ( ((p) == 9) ? 7 : \
                                ( ((p) == 10) ? 6 : \
                                ( ((p) == 11) ? 5 : \
                                ( ((p) == 12) ? 3 : \
                                ( ((p) == 13) ? 1 : \
                                ( ((p) == 20) ? 2 : \
                                0 ) ) ) ) ) )

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

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	NOT_A_PIN,
	NOT_A_PIN,
	(uint16_t)&PINC,
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
	PF	, // PF 0 ** 0 ** DIO0/AD0	-- 20
	PF	, // PF 1 ** 1 ** DIO1/AD1	-- 19
	PF	, // PF 2 ** 2 ** DIO2/AD2	-- 18
	PF	, // PF 3 ** 3 ** DIO3/AD3  	-- 17
	PE	, // PE 4 ** 4 ** DIO4		-- 11
	PF	, // PF 5 ** 5 ** DIO5/AD5/Assoc-- 15
	PF	, // PF 6 ** 6 ** DIO6/AD6/~RTS	-- 16
	PF	, // PF 7 ** 7 ** DIO7/AD7/~CTS -- 12
	PD	, // PD 3 ** 8 ** DO8/UART1 TX/INT3-- 4
	PD	, // PD 1 ** 9 ** SDA/~DTR/DI8  -- 9
	PB	, // PB 5 ** 10 ** PWM0/RSSI	-- 6

	PB	, // PB 2 ** 11 ** MOSI		-- SDCard Pin 3 (CMD/DI)
	PB	, // PB 3 ** 12 ** MISO		-- SDCard Pin 7 (Dat0)
	PB	, // PB 1 ** 13 ** SCK		-- SDCard Pin 5 (Clk)	

	PB	, // PB 4 ** 14 ** PWM1		-- 7
	PE	, // PE 5 ** 15 ** PWM3?(OC3C/Int5)--14	
	PD	, // PD 0 ** 16 ** SCL/ON	-- 13
	PE	, // PE 2 ** 17 ** SDCD/DAT3	-- SDCard Pin 2	



	PE	, // PE 1 ** 18 ** USART0_TX	-- XBee Pin 2
	PE	, // PE 0 ** 19 ** USART0_RX	-- XBee Pin 3
	PD	, // PD 2 ** 20 ** USART1_RX    -- XBee Pin 8
	PD	, // PD 0 ** 21 ** 
	PB	, // PB 0 ** 22 ** --Dummy PB0 for SD card?
	PD  , // PD 5 ** 23 ** RFTX		--These aren't wired to anything either.
	PD  , // PD 6 ** 24 ** RFRX
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------
	// Comments not up to date!		
	_BV( 0 )	, // PE 6 ** 0 ** D2
	_BV( 1 )	, // PE 5 ** 1 ** PWM3
	_BV( 2 )	, // PE 2 ** 2 ** PWM4
	_BV( 3 )	, // PE 3 ** 3 ** D5
	_BV( 4 )	, // PE 4 ** 4 ** PWM6
	_BV( 5 )	, // PE 7 ** 5 ** D7
	_BV( 6 )	, // PB 4 ** 6 ** PWM8
	_BV( 7 )	, // PB 7 ** 7 ** PWM9
	_BV( 3 )	, // PB 6 ** 8 ** PWM10
	_BV( 1 )	, // PB 5 ** 9 ** PWM11
	_BV( 5 )	, // PB 5 ** 10 ** PWM11

	_BV( 2 )	, // PF 4 ** 11 ** A4
	_BV( 3 )	, // PF 2 ** 12 ** A2	
	_BV( 1 )	, // PF 3 ** 13 ** A3	

	_BV( 4 )	, // PB 3 ** 14 ** SPI_MISO
	_BV( 5 )	, // PD 0 ** 15 ** D0
	_BV( 0 )	, // PF 0 ** 16 ** A0	
	_BV( 2 )	, // PF 1 ** 17 ** A1	


	
	_BV( 1 )	, // PF 5 ** 18 ** A5
	_BV( 0 )	, // PB 2 ** 19 ** SPI_MOSI
	_BV( 2 )	, // PD 0 ** 20 ** I2C_SCL
	_BV( 0 )	, // PD 1 ** 21 ** I2C_SDA	
	_BV( 0 )	, // PD 1 ** 22 ** I2C_SDA	
	_BV( 5 )  	, // PD 5 ** 23 ** RFTX
	_BV( 6 )  	, // PD 6 ** 24 ** RFRX
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
	NOT_ON_TIMER	, // PD 0 ** 21 ** I2C_SCL
	NOT_ON_TIMER	, // PD 1 ** 22 ** I2C_SDA	
	NOT_ON_TIMER  	, // PD 5 ** 23 ** RFTX
	NOT_ON_TIMER  	, // PD 6 ** 24 ** RFRX
};	

#endif

#endif
