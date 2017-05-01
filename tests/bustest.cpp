#include "bus.hpp"
#include "port.hpp"

int main()
{
    kpvs::Port<1> port1;
    kpvs::Port<1> port2(kpvs::Pin::PINMODE_OUT);

    kpvs::Bus<1> bus;
    bus.connectPin(0, port1.getPin(0));
    bus.connectPin(0, port2.getPin(0));

    bus.update();

    return 0;
}
