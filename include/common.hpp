#ifndef __KPVS_COMMON_HPP_
#define __KPVS_COMMON_HPP_
#include <cstddef>

namespace kpvs 
{
    typedef std::size_t Width;

    enum VoltageState
    {
        VSTATE_LOW          = 0,
        VSTATE_HIGH         = 1
    };

    enum ErrorCode
    {
        ERR_OK              = 0,
        ERR_UNKNOWN         = 1,
        ERR_WRONG_VSTATE    = 2,
        ERR_WRONG_MASK_SIZE = 3,
        ERR_SHORT_CIRCUIT   = 4
    };
}

#endif
