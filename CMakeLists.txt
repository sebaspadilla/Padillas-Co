# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(PadillasCo)

# Add all the source files needed to build the executable
add_executable(
    PadillasCo
    src/main.cpp
    src/Account.cpp
    src/AccountManager.cpp
    src/AdultAccount.cpp
    src/KidAccount.cpp
)