#pragma once

namespace SaveOurSouls {

class ILedController {
public:
    virtual ~ILedController() = default;
    virtual void on() = 0;
    virtual void off() = 0;
    
};

}