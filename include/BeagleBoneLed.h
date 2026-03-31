#pragma once

#include "include/ILedController.h"
#include <string>

namespace SaveOurSouls {

class BeagleBoneLed : public ILedController {
public:
    explicit BeagleBoneLed(const std::string& path);

    void on() override;
    void off() override;

private:
    std::string brightnessPath;
};

}