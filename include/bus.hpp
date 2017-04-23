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
        int   connectPin(int n, Pin& p);
        int   disconnectPin(int n, Pin& p);
        Width getWidth();
        int   update();
    private:
        std::array<Wire, W> wires;
    };

    template <Width W>
    int Bus<W>::connectPin(int n, Pin& p)
    {
        wires.at(n).connectPin(p);
        return ERR_OK;
    }

    template <Width W>
    int Bus<W>::disconnectPin(int n, Pin& p)
    {
        wires.at(n).disconnectPin(p);
        return ERR_OK;
    }

    template <Width W>
    Width Bus<W>::getWidth()
    {
        return W;
    }

    template <Width W>
    int Bus<W>::update()
    {
        for (auto& w : wires)
            w.update();
        return ERR_OK;
    }
}
#endif
