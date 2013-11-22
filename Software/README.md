This folder has software for testing and working with the MeshThing. You may require some of the software for development found in the Resources folder one level up. It has a README describing each component's use.

LEDTest should blink the green LED. Makefile should work for most situations.

SerialTest will output a continuous series of the character '.' on UART0 until it is interrupted by a keypress, showing the function of both sending and receivng serial communications. Use Makefile.

PinExercise is an Arduino sketch that will set all the I/O pins as outputs and pulse them high in order of their XBee pinout.

SDCardTest holds an Arduino sketch based on the example sketch from the Arduino IDE that will test read & write to the SDCard.

