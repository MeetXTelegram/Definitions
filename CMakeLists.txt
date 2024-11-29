cmake_minimum_required(VERSION 3.5)

project(Definitions)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)

include(GNUInstallDirs)

include_directories(include)

add_library(Definitions SHARED include/Definitions.hpp src/createLogger.cpp src/SIGUSR1Handler.cpp
    src/TerminateHandler.cpp)

target_link_libraries(Definitions PRIVATE spdlog::spdlog libpqxx.so)
