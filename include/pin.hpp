#ifndef __KPVS_PIN_HPP_
#define __KPVS_PIN_HPP_
#include "common.hpp"

namespace kpvs
{
    class Pin
    {
    public:
        enum PinMode  
        {
            PINMODE_IN  = 0,
            PINMODE_OUT = 1,
        };

        Pin();
        PinMode      mode;
        VoltageState state;
    };
}
#endif
