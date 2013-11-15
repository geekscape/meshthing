This folder has software for developing with the MeshThing. Instructions are relevant to Linux, but should be similar for Windows or OSX.

AVRDUDERC.avrduderc is the avrprofile for the rfr2 - it should be copied and renamed to ~/.arvduderc

Arduino folder has settings and cores as needed for the Arduino environment and has it's own README.

Currently, avr-gcc doesn't compile against the target atmega2564rfr2. It is expected this will be included in future releases, but for now, one will be required to us the ATMEL toolchain. Find relevant files and instructions for use [here](http://www.atmel.com/tools/ATMELAVRTOOLCHAINFORLINUX.aspx). Note that the MeshThing uses an 8-bit processor.

Once added, you'll likely want to add the toolchain to your system PATH so it is invoked automatically.
For example, to accomplish this for bash, assuming the x64 toolchain was unpacked in your home directory:
>echo 'export PATH=~/avr8-gnu-toolchain-linux_x86_64/bin:$PATH' >> ~/.bashrc


