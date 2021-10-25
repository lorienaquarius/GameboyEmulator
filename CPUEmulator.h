//
// Created by lorie on 2021-10-01.
//
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#ifndef EMULATOR_CPUEMULATOR_H
#define EMULATOR_CPUEMULATOR_H

#endif //EMULATOR_CPUEMULATOR_H
typedef struct Flags{
    uint8_t Z:1;
    uint8_t N:1;
    uint8_t H:1;
    uint8_t C:1;
}Flag;

typedef struct State{
    uint8_t A;
    uint8_t B;
    uint8_t C;
    uint8_t D;
    uint8_t E;
    uint8_t F;
    uint8_t H;
    uint8_t L;
    uint16_t HL;
    uint16_t AF;
    uint16_t BC;
    uint16_t DE;
    uint8_t *memory;
    uint8_t int_enable;
    uint16_t SP;
    uint32_t PC;
    Flag f;
}State;

void Emulate(State *state);
