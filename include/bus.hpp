#ifndef __KPVS_BUS_HPP_
#define __KPVS_BUS_HPP_

#include <array>
#include <iostream>
#include "wire.hpp"

namespace kpvs
{
    template <Width W>
    class Bus
    {
    public:
        int   connectPin(int n, Pin* p);
        int   disconnectPin(int n, Pin* p);
        Width getWidth();
        int   transmit();
    private:
        std::array<Wire, W> wires;
    };

    template <Width W>
    int Bus<W>::connectPin(int n, Pin* p)
    {
        wires[n].connectPin(p);
        return ERR_OK;
    }
    
    template <Width W>
    int Bus<W>::disconnectPin(int n, Pin* p)
    {
        wires[n].disconnectPin(p);
        return ERR_OK;
    }

    template <Width W>
    Width Bus<W>::getWidth()
    {
        return W;
    }

    template <Width W>
    int Bus<W>::transmit()
    {   
        for (auto& w : wires)
            w.update();
        return ERR_OK;
    }
}
#endif
