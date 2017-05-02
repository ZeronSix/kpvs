#ifndef __KPVS_TERMINAL_HPP_
#define __KPVS_TERMINAL_HPP_
#include "common.hpp"
#include <string>

namespace kpvs
{
    class TerminalOptHandler
    {
    public:
        std::size_t frequency;
        TerminalOptHandler(int argc, char* argv[]);
    };

    class Terminal
    {
        bool isRunning;
        std::size_t totalTicks;
        std::size_t frequency;
    public:
        const std::string PROMPT = ">> ";
        Terminal(std::size_t freq = DEFAULT_FREQUENCY);
        int run();
        int tick();
        int info(const std::string& arg) const;
    };
}

#endif /* ifndef __KPVS_TERMINAL_HPP_ */
