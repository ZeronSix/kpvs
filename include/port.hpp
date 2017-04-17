#ifndef __KPVS_PORT_HPP_
#define __KPVS_PORT_HPP_

#include <array>
#include <bitset>
#include "pin.hpp"

namespace kpvs
{
    template <Width W>
    class Port
    {
    public:
        Port(Pin::PinMode s = Pin::PINMODE_IN);
        uint64_t getModes () const;
        int      setModes (uint64_t mask);
        uint64_t getStates() const;
        int      setStates(uint64_t mask);
        Pin*     getPin(std::size_t n);
    private:
        std::array<Pin, W> pins;
    };

    template <Width W>
    Port<W>::Port(Pin::PinMode s)
    {
        static_assert(W <= 64, "Can't have more than 64 pins in port!");
        for (auto& pin : pins)
            pin.mode = s;
    }

    template <Width W>
    uint64_t Port<W>::getStates() const
    {
        static_assert(VSTATE_LOW  == 0b0, "Constant value is wrong!");
        static_assert(VSTATE_HIGH == 0b1, "Constant value is wrong!");
        std::bitset<W> psm(0);           //Pin state mask

        int cnt = 0;
        
        for (auto& pin : pins)
        {
            psm[cnt] = pin.state;
            cnt++;
        }

        return psm.to_ullong();
    }

    template <Width W>
    int Port<W>::setStates(uint64_t psMask)
    {
        static_assert(VSTATE_LOW  == 0b0, "Constant value is wrong!");
        static_assert(VSTATE_HIGH == 0b1, "Constant value is wrong!");
        std::bitset<W> psm(psMask);      // Pin state mask

        std::size_t cnt = 0;
        
        for (auto& pin : pins)
        {
            pin.state = (VoltageState)psm.test(cnt);
            cnt++;
        }

        return ERR_OK;
    }
    
    template <Width W>
    uint64_t Port<W>::getModes() const
    {
        static_assert(Pin::PINMODE_IN  == 0b0, "Constant value is wrong!");
        static_assert(Pin::PINMODE_OUT == 0b1, "Constant value is wrong!");
        std::bitset<W> pmm(0);           // Pin mode mask

        std::size_t cnt = 0;
        
        for (auto& pin : pins)
        {
            pmm[cnt] = pin.mode;
            cnt++;
        }

        return pmm.to_ullong();
    }

    template <Width W>
    int Port<W>::setModes(uint64_t pmMask)
    {
        static_assert(Pin::PINMODE_IN  == 0b0, "Constant value is wrong!");
        static_assert(Pin::PINMODE_OUT == 0b1, "Constant value is wrong!");
        std::bitset<W> pmm(pmMask);      // Pin mode mask

        std::size_t cnt = 0;
        
        for (auto& pin : pins)
        {
            pin.mode = (Pin::PinMode)pmm.test(cnt);
            cnt++;
        }

        return ERR_OK;
    }

    template <Width W>
    Pin* Port<W>::getPin(std::size_t n)
    {
        return &pins[n];
    }
}

#endif
