#include "BeagleBoneLed.h"
#include <fstream>

namespace SaveOurSouls {

BeagleBoneLed::BeagleBoneLed(const std::string& path)
    : brightnessPath(path) {}

void BeagleBoneLed::on() {
    std::ofstream file(brightnessPath);
    file << "1";
}

void BeagleBoneLed::off() {
    std::ofstream file(brightnessPath);
    file << "0";
}

}