#ifndef __KPVS_WIRE_HPP_
#define __KPVS_WIRE_HPP_

#include <vector>
#include "pin.hpp"

namespace kpvs
{
    class Wire 
    {
    public:
        Wire();
        int appendPin(Pin& pin);
        int deletePin(Pin& pin);
        int transmit();
    private:
        std::vector<Pin&> pins;
    }
}
#endif
