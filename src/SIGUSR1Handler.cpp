#include <Definitions.hpp>

void signalsUtils::SIGUSR1Handler(int signal) {
    if (signal != SIGUSR1) {
        spdlog::get("SignalHandler")->log(spdlog::level::warn, "Invalid signal provided({}) but expected {}", signal, SIGUSR1);
    }
}
