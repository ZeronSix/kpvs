#include "terminal.hpp"

int main(int argc, char* argv[])
{
    kpvs::TerminalOptHandler termOpt(argc, argv);
    kpvs::Terminal term(termOpt.frequency);
    term.run();

    return 0;
}
