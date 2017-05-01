#ifndef __KPVS_TERMINAL_HPP_
#define __KPVS_TERMINAL_HPP_
#include "common.hpp"
#include <string>

namespace kpvs
{
    class Terminal
    {
        bool isRunning;
        std::size_t totalTicks;
        std::size_t frequency;
    public:
        Terminal(size_t freq = DEFAULT_FREQUENCY);
        int run();
        int tick();
        int info(const std::string& arg) const;
    };
}

#endif /* ifndef __KPVS_TERMINAL_HPP_ */
