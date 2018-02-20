/*
 Usage: ./codesend pin protocol repeat decimalcode
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

	// This pin is not the first pin on the RPi GPIO header!
	// Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
	// for more information.
    int pin = atoi(argv[1]);
    int proto = atoi(argv[2]);
    int repeat = atoi(argv[3]);
	int code = atoi(argv[4]);

	if (wiringPiSetup () == -1) return 1;
	printf("sending code[%i] %i times on pin %i\n", code, repeat, pin);
	RCSwitch rcSwitch = RCSwitch();
	int err = rcSwitch.setProtocol(proto);
    if (err){
        std::cout << "Could not set protocol\n";
        return 0;
    }
	rcSwitch.setRepeatTransmit(repeat);
	rcSwitch.enableTransmit(pin);

	rcSwitch.send(code, 24);

	return 0;
}
