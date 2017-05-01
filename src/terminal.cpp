#include "terminal.hpp"
#include <string>
#include <iostream>
#include <sstream>

namespace kpvs
{
    Terminal::Terminal(std::size_t freq): isRunning(false),
                                          totalTicks(0),
                                          frequency(freq)
    {
    }

    // TODO: what should we do with conflicts in beginnings of command names?
    inline bool checkCommand(const std::string& str, const std::string& cmd)
    {
        return cmd.find(str) == 0 && str.length() <= cmd.length();
    }

    inline void shiftCommand(std::istringstream& ss, std::string& str)
    {
        str.clear();
        std::getline(ss, str, ' ');
    }

    int Terminal::run()
    {
        while (true)
        {
            std::string line;
            std::string command;
            std::getline(std::cin, line);

            std::istringstream ss(line);
            shiftCommand(ss, command);

            if (checkCommand(command, "start"))
            {
                // TODO: implement ticks
                while (true)
                {
                    tick();
                }
            }
            else if (checkCommand(command, "quit"))
            {
                std::cout << "Aborting simulation..." << std::endl;
                break;
            }
            else if (checkCommand(command, "info"))
            {
                shiftCommand(ss, command);
                info(command);
            }
            else if (checkCommand(command, "next"))
            {
                shiftCommand(ss, command);
                std::size_t ticksToRun = 1;
                if (!command.empty())
                {
                    try
                    {
                        ticksToRun = std::stoul(command);
                    }
                    catch (const std::invalid_argument& err)
                    {
                        std::cerr << "Invalid argument: " << command << std::endl;
                        continue;
                    }
                }
                while (ticksToRun > 0)
                {
                    tick();
                    ticksToRun--;
                }
            }
            else
            {
                std::cerr << "Wrong command! Try again." << std::endl;
            }

            shiftCommand(ss, command);
            if (!command.empty())
            {
                std::cerr << "Ignoring extra arguments." << std::endl;
            }
        }

        return ERR_OK;
    }

    int Terminal::tick()
    {
        // TODO: MB::tick()
        std::cout << "TICK " << totalTicks << std::endl;
        totalTicks++;

        return ERR_OK;
    }

    int Terminal::info(const std::string& arg) const
    {
        if (arg.empty())
            std::cout << "Ticks since the start of the simulation: "
                      << totalTicks << std::endl;
        else if (arg == "time")
            std::cout << "Time passed since the start of the simulation: "
                      << (double)totalTicks / frequency * 1000000 << " μs" << std::endl;
        else
            std::cerr << "Unknown info argument: " << arg << std::endl;

        return ERR_OK;
    }
}
