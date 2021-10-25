cmake_minimum_required(VERSION 3.20)
project(Emulator C)

set(CMAKE_C_STANDARD 99)

add_executable(Emulator main.c Dissasembler.c Dissasembler.h PokemonRedHex.txt CPUEmulator.c CPUEmulator.h)
