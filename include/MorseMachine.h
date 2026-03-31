#pragma once

#include "ILedController.h"
#include <string>

namespace SaveOurSouls {

class MorseMachine {
public:
    MorseMachine(ILedController& led, int timeMs = 300);

    void encode(const std::string& message);

private:
    void dot();
    void dash();
    void midPause();
    void letterPause();
    void wordPause();

    ILedController& led;
    int timeUnit;
};

}