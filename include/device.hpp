#ifndef __KPVS_DEVICE_HPP_
#define __KPVS_DEVICE_HPP_

namespace kpvs
{
    class Device
    {
    public:
        virtual int clock();
    protected:
        std::size_t prescaler;
    }
}

#endif
