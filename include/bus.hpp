#ifndef __KPVS_BUS_HPP_
#define __KPVS_BUS_HPP_

#include <array>
#include "wire.hpp"

namespace kpvs
{
    template <Width W>
    class Bus
    {
    public:
        Bus();
        int connectPin(int n, Pin& p);
        int disconnectPin(int n, Pin& p);
        int getWidth();
        int transmit();
    private:
        std::array<Wire, W> wires;
    }
}
#endif
