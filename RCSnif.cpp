/*
  RF_Sniffer

  Hacked from http://code.google.com/p/rc-rcSwitch/

  by @justy to provide a handy RF code sniffer
*/

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

	// This pin is not the first pin on the RPi GPIO header!
	// Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
	// for more information.
    int pin = atoi(argv[1]);
    //int proto = atoi(argv[2]);

	if(wiringPiSetup() == -1)
		return 0;

    RCSwitch rcSwitch = RCSwitch();
	//rcSwitch.setProtocol(proto);
	rcSwitch.enableReceive(pin);  // Receiver on inerrupt 0 => that is pin #2

	printf("listening for rf 433 codes on pin[%i]\n", pin);

	while(1)
	{
		if (rcSwitch.available())
		{
			int value = rcSwitch.getReceivedValue();

			if (value == 0) {
				printf("Unknown encoding");
			} else {
				printf("Received %i %i %i\n", rcSwitch.getReceivedValue(), rcSwitch.getReceivedBitlength(), rcSwitch.getReceivedProtocol() );
				unsigned int* raw = rcSwitch.getReceivedRawdata();
				for(int i = 0 ; i < 67 ; ++i)
					printf("%i\n", *raw++ );

		}

		rcSwitch.resetAvailable();
	 }
  }
  exit(0);
}
