#include "port.hpp"
#include <iostream>
#include <array>

int main()
{
    kpvs::Port<8> port;

    std::array<kpvs::Pin::PinMode, 8> modes{{kpvs::Pin::PINMODE_IN, kpvs::Pin::PINMODE_IN,
                                             kpvs::Pin::PINMODE_IN, kpvs::Pin::PINMODE_IN,
                                             kpvs::Pin::PINMODE_OUT, kpvs::Pin::PINMODE_IN,
                                             kpvs::Pin::PINMODE_IN, kpvs::Pin::PINMODE_IN}};
    port.setModes(modes);
    if (port.getModes() != modes)
    {
        std::cerr << "Port::getModes does not work!" << std::endl;
        return 1;
    }

    std::array<kpvs::VoltageState, 8> states{{kpvs::VSTATE_HIGH, kpvs::VSTATE_HIGH,
                                              kpvs::VSTATE_HIGH, kpvs::VSTATE_HIGH,
                                              kpvs::VSTATE_LOW, kpvs::VSTATE_HIGH,
                                              kpvs::VSTATE_HIGH, kpvs::VSTATE_HIGH}};

    port.setStates(states);
    if (port.getStates() != states)
    {
        std::cerr << "Port::getStates does not work!" << std::endl;
        return 1;
    }

    std::cout << "Port tests have been passed." << std::endl;

    return 0;
}
