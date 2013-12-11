This is still in progress.

Arduino Essentials
------------
You'll need the Zigduino core folder copied to <arduinoroot>/hardware/arduino/cores. - (ex. ~/arduino-1.0.5/hardware/arduino/cores/zigduino)

pins_arduino.h needs to go in a folder under <arduino root>/hardware/arduino/variants/meshthing - (ex. ~/arduino-1.0.5/hardware/arduino/variants/meshthing/pins_arduino.h)

boards.txt needs to replace the file in <arduino root>/hardware/arduino - (ex. ~/arduino-1.0.5/hardware/arduino/boards.txt)

Arduino Libraries
-------------
The libraries subfolder has modified Arduino standard libraries for use with the Meshthing.
Currently only Firmata has been modified though other libraries may work out of the box (Ex. SDCard). To use firmata:
Boards.h needs to replace existing file in <arduino root>/libraries/Firmata/Boards.h - (ex. ~/arduino-1.0.5/libraries/Firmata/Boards.h)

!!Be careful when using with a MeshUSB as the MeshUSB utilizes AD2/AD3 for battery monitoring and should be set as inputs!! Firmata seems to want to set these as outputs by default. It doesn't seem to cause any trouble, but may result in unexpected behaviour or damage.