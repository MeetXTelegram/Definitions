#include <Definitions.hpp>

#include <iostream>

void signalsUtils::SIGUSR1Handler(int signal) {
    if (signal != SIGUSR1) {
        spdlog::get("SignalHandler")->log(spdlog::level::warn, "Invalid signal provided({}) but expected {}", signal, SIGUSR1);
        return;
    }
    spdlog::get("SignalHandler")->log(spdlog::level::warn, "The operation of MeetX was interrupted by signal {}, what should i do?\n\n1 -- Normal shutdown of MeetX\n2 -- Try to continue working");
    while (true) {
        int action; std::cin >> action;
        switch (action) {
            case 1: {
                spdlog::get("SignalHandler")->log(spdlog::level::info, "Selected action: 1(shutdown)");
                std::exit(signal);
            }

            case 2: {
                spdlog::get("SignalHandler")->log(spdlog::level::info, "Selected action: 2(continue)");
                return;
            }

            default: {
                spdlog::get("SignalHandler")->log(spdlog::level::warn, "Invalid action provided, please try again");
                continue;
            }
        }
    }
}
