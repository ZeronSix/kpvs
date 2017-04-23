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
            PINMODE_IN,
            PINMODE_OUT,
            PINMODE_HI_Z
        };

        Pin();
        PinMode      mode;
        VoltageState state;
    };
}
#endif
