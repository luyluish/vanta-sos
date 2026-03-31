#include "BeagleBoneLed.h"
#include "MorseMachine.h"
#include <iostream>

// BeagleBone Black has USR0-3 leds, use only 0
const std::string ledPath = "/sys/class/leds/beaglebone::green:usr0/brightness";

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error. Must contain input to encode." << argv[0] << " \"MESSAGE\"\n";
        return 1;
    }

    // Receive message as console argument
    std::string message = argv[1];

    SaveOurSouls::BeagleBoneLed led(ledPath);
    SaveOurSouls::MorseMachine morse(led, 300);

    morse.encode(message);

    return 0;
}