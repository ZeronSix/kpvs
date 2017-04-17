#include "port.hpp"
#include <iostream>

int main()
{
    kpvs::Port<8> port;

    port.setModes(0b01100110);
    if (port.getModes() != 0b01100110)
    {
        std::cerr << "Port::getModes does not work!" << std::endl;
        return 1;
    }

    port.setStates(0b01100110);
    if (port.getStates() != 0b01100110)
    {
        std::cerr << "Port::getStates does not work!" << std::endl;
        return 1;
    }

    std::cout << "Port tests have been passed." << std::endl;

    return 0;
}
