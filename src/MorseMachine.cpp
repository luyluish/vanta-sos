#include "MorseMachine.h"
#include <thread>
#include <chrono>
#include <cctype>

namespace SaveOurSouls {

MorseMachine::MorseMachine(ILedController& led, int timeMs)
    : led(led), timeUnit(timeMs) {}

// . Morse Standard: 1 unit
void MorseMachine::dot() {
    led.on();
    std::this_thread::sleep_for(std::chrono::milliseconds(timeUnit));
    led.off();
    midPause();
}

// - Morse Standard: 3 units
void MorseMachine::dash() {
    led.on();
    std::this_thread::sleep_for(std::chrono::milliseconds(3 * timeUnit));
    led.off();
    midPause();
}

// Morse Standard: 1 unit
void MorseMachine::midPause() {
    std::this_thread::sleep_for(std::chrono::milliseconds(timeUnit));
}

// Morse Standard: 3 units
void MorseMachine::letterPause() {
    std::this_thread::sleep_for(std::chrono::milliseconds(3 * timeUnit));
}

// Morse Standard: 7 units
void MorseMachine:: wordPause() {
    std::this_thread::sleep_for(std::chrono::milliseconds(7 * timeUnit));
}

void MorseMachine::encode(const std::string& message) {
    for (char c : message) {
        switch (toupper(c)) {
            case 'A': 
                dot(); dash();
                break;
            case 'B': 
                dash(); dot(); dot(); dot();
                break;
            case 'C': 
                dash(); dot(); dash(); dot();
                break;
            case 'D':
                dash(); dot(); dot();
                break;
            case 'E':
                dot();
                break;
            case 'F':
                dot(); dot(); dash(); dot();
                break;
            case 'G':
                dash(); dash(); dot();
                break;
            case 'H':
                dot(); dot(); dot(); dot();
                break;
            case 'I':
                dot(); dot();
                break;
            case 'J':
                dot(); dash(); dash(); dash();
                break;
            case 'K':
                dash(); dot(); dash();
                break;
            case 'L':
                dot(); dash(); dot(); dot();
                break;
            case 'M':
                dash(); dash();
                break;
            case 'N':
                dash(); dot();
                break;
            case 'O':
                dash(); dash(); dash();
                break;
            case 'P':
                dot(); dash(); dash(); dot();
                break;
            case 'Q':
                dash(); dash(); dot(); dash(); 
                break;
            case 'R':
                dot(); dash(); dot();
                break;
            case 'S':
                dot(); dot(); dot();
                break;
            case 'T':
                dash();
                break;
            case 'U':
                dot(); dot(); dash();
                break;
            case 'V':
                dot(); dot(); dot(); dash();
                break;
            case 'W':
                dot(); dash(); dash();
                break;
            case 'X':
                dash(); dot(); dot(); dash();
                break;
            case 'Y':
                dash(); dot(); dash(); dash();
                break;
            case 'Z':
                dash(); dash(); dot(); dot();
                break;

            case ' ':
                wordPause();
                continue;

            default:
                continue;
        }

        letterPause();
    }
}

}