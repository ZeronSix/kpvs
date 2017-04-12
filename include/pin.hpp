#ifndef __KPVS_PIN_HPP_
#define __KPVS_PIN_HPP_

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
