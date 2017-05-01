#include "pin.hpp"

namespace kpvs
{
    Pin::Pin():
        mode  (PINMODE_IN),
        state (VSTATE_LOW)
    {
    }
}
