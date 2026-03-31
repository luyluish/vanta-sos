#include "MorseMachine.h"
#include <thread>
#include <chrono>

namespace SaveOurSouls {

MorseMachine::MorseMachine(ILedController& led, int timeMs)
    : led(led), timeUnit(timeMs) {}

void MorseMachine::dot() {
    led.on();
    std::this_thread::sleep_for(std::chrono::milliseconds(timeUnit));
    led.off();
    midPause();
}

void MorseMachine::dash() {
    led.on();
    std::this_thread::sleep_for(std::chrono::milliseconds(3 * timeUnit));
    led.off();
    midPause();
}

}