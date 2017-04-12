#ifndef __KPVS_PORT_HPP_
#define __KPVS_PORT_HPP_

#include <array>
#include "pin.hpp"

namespace kpvs
{
    template <Width W>
    class Port
    {
    public:
        Port(State s);
        Port();
        int getState(int n);
        int setState(int n);
    private:
        std::array<Pin, W> pins;
    }
}
#endif
