cmake_minimum_required(VERSION 3.5)

project(Definitions)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)
find_package(PostgreSQL REQUIRED)
find_package(libpqxx REQUIRED)

include(GNUInstallDirs)

include_directories(include)

add_library(Definitions STATIC
    include/Definitions.hpp
    src/createLogger.cpp
    src/SIGUSR1Handler.cpp
    src/TerminateHandler.cpp
    src/Definitions.cpp
)

target_link_libraries(Definitions PRIVATE spdlog::spdlog libpqxx::pqxx ${PostgreSQL_LIBRARIES})

install(TARGETS Definitions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(FILES include/Definitions.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Definitions)
