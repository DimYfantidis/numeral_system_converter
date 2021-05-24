cmake_minimum_required(VERSION 3.19)
project(numeral_system_converter)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(numeral_system_converter
        binToHex.h
        decToOther.h
        hexToBin.h
        main.cpp
        otherToDec.h)
