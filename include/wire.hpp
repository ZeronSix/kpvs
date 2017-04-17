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
        int          connectPin(Pin* pin); // TODO: replace with references
        int          disconnectPin(Pin* pin);
        int          update();
        VoltageState getState() const;
    private:
        std::vector<Pin*> pins;
        VoltageState state;
    };
}
#endif
