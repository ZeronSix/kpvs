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
        Port(Pin::PinMode s = Pin::PINMODE_HI_Z);
        std::array<Pin::PinMode, W> getModes() const;
        std::array<VoltageState, W> getStates() const;

        int  setModes(std::array<Pin::PinMode, W> modes);
        int  setStates(std::array<VoltageState, W> mask);
        Pin& getPin(std::size_t n);
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
    std::array<VoltageState, W> Port<W>::getStates() const
    {
        static_assert(VSTATE_LOW  == 0b0, "Constant value is wrong!");
        static_assert(VSTATE_HIGH == 0b1, "Constant value is wrong!");
        std::array<VoltageState, W> states;

        int cnt = 0;
        for (auto& pin : pins)
        {
            states.at(cnt) = pin.state;
            cnt++;
        }

        return states;
    }

    template <Width W>
    int Port<W>::setStates(std::array<VoltageState, W> states)
    {
        static_assert(VSTATE_LOW  == 0b0, "Constant value is wrong!");
        static_assert(VSTATE_HIGH == 0b1, "Constant value is wrong!");

        std::size_t cnt = 0;
        for (auto& pin : pins)
        {
            pin.state = states.at(cnt);
            cnt++;
        }

        return ERR_OK;
    }

    template <Width W>
    std::array<Pin::PinMode, W> Port<W>::getModes() const
    {
        static_assert(Pin::PINMODE_IN  == 0b0, "Constant value is wrong!");
        static_assert(Pin::PINMODE_OUT == 0b1, "Constant value is wrong!");
        std::array<Pin::PinMode, W> modes;

        std::size_t cnt = 0;
        for (auto& pin : pins)
        {
            modes.at(cnt) = pin.mode;
            cnt++;
        }

        return modes;
    }

    template <Width W>
    int Port<W>::setModes(std::array<Pin::PinMode, W> modes)
    {
        static_assert(Pin::PINMODE_IN  == 0b0, "Constant value is wrong!");
        static_assert(Pin::PINMODE_OUT == 0b1, "Constant value is wrong!");

        std::size_t cnt = 0;
        for (auto& pin : pins)
        {
            pin.mode = modes.at(cnt);
            cnt++;
        }

        return ERR_OK;
    }

    template <Width W>
    Pin& Port<W>::getPin(std::size_t n)
    {
        return pins.at(n);
    }
}

#endif
