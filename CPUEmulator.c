//
// Created by lorie on 2021-10-01.
//
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "CPUEmulator.h"

void Emulate(State *state){
    unsigned char *opCode = &state->memory[state->PC];
    signed char n = 0;
    int opBytes = 1;
    switch(*opCode){
        //TODO Implement Operational codes from gameboy manual. Going to be painstaking, do it anyway.
        //ld  nn, n, nn is a register, n is a number commands
        //Note: ld (register) (16bit register/immediate) means put value at
        //MEMORY LOCATION of register or value
        //cause registers are only 8 bit
        case 0x06:
            state->B = opCode[1]; opBytes = 2; break;
        case 0x0e:
            state->C = opCode[1]; opBytes = 2; break;
        case 0x16:
            state->D = opCode[1]; opBytes = 2; break;
        case 0x1e:
            state->E = opCode[1]; opBytes = 2; break;
        case 0x26:
            state->H = opCode[1]; opBytes = 2; break;
        case 0x2e:
            state->L = opCode[1]; opBytes = 2; break;
        //ld r1 r2, put contents of register r2 into r1
        case 0x7f:
            state->A = state->A; break;
        case 0x78:
            state->A = state->B; break;
        case 0x79:
            state->A = state->C; break;
        case 0x7a:
            state->A = state->D; break;
        case 0x7b:
            state->A = state->E; break;
        case 0x7c:
            state->A = state->H; break;
        case 0x7d:
            state->A = state->L; break;
        case 0x7e:
            state->HL = (state->H << 8) | state->L;
            state->A = state->memory[state->HL]; opBytes = 2; break;
        case 0x40:
            state->B = state->B; break;
        case 0x41:
            state->B = state->C; break;
        case 0x42:
            state->B = state->D; break;
        case 0x43:
            state->B = state->E; break;
        case 0x44:
            state->B = state->H; break;
        case 0x45:
            state->B = state->L; break;
        case 0x46:
            state->HL = (state->H << 8) | state->L;
            state->B = state->memory[state->HL]; opBytes = 2; break;
        case 0x48:
            state->C = state->B; break;
        case 0x49:
            state->C = state->C; break;
        case 0x4a:
            state->C = state->D; break;
        case 0x4b:
            state->C = state->E; break;
        case 0x4c:
            state->C = state->H; break;
        case 0x4d:
            state->C = state->L; break;
        case 0x4e:
            state->HL = (state->H << 8) | state->L;
            state->C = state->memory[state->HL]; opBytes = 2; break;
        case 0x50:
            state->D = state->B; break;
        case 0x51:
            state->D = state->C; break;
        case 0x52:
            state->D = state->D; break;
        case 0x53:
            state->D = state->E; break;
        case 0x54:
            state->D = state->H; break;
        case 0x55:
            state->D = state->L; break;
        case 0x56:
            state->HL = (state->H << 8) | state->L;
            state->D = state->HL;opBytes = 2; break;
        case 0x58:
            state->E = state->B; break;
        case 0x59:
            state->E = state->C; break;
        case 0x5a:
            state->E = state->D; break;
        case 0x5b:
            state->E = state->E; break;
        case 0x5c:
            state->E = state->H; break;
        case 0x5d:
            state->E = state->L; break;
        case 0x5e:
            state->HL = (state->H << 8) | state->L;
            state->E = state->HL;opBytes = 2; break;
        case 0x60:
            state->H = state->B; break;
        case 0x61:
            state->H = state->C; break;
        case 0x62:
            state->H = state->D; break;
        case 0x63:
            state->H = state->E; break;
        case 0x64:
            state->H = state->H; break;
        case 0x65:
            state->H = state->L; break;
        case 0x66:
            state->HL = (state->H << 8) | state->L;
            state->H = state->HL;opBytes = 2; break;
        case 0x68:
            state->L = state->B; break;
        case 0x69:
            state->L = state->C; break;
        case 0x6a:
            state->L = state->D; break;
        case 0x6b:
            state->L = state->E; break;
        case 0x6c:
            state->L = state->H; break;
        case 0x6d:
            state->L = state->L; break;
        case 0x6e:
            state->HL = (state->H << 8) | state->L;
            state->L = state->memory[state->HL];opBytes = 2; break;
        case 0x70:
            state->HL = (state->H << 8) | state->L;
            state->memory[state->HL] = state->B; opBytes = 2; break;
        case 0x71:
            state->HL = state->C; opBytes = 2; break;
        case 0x72:
            state->HL = state->D; opBytes = 2; break;
        case 0x73:
            state->HL = state->E; opBytes = 2; break;
        case 0x74:
            state->HL = state->H; opBytes = 2; break;
        case 0x75:
            state->HL = state->L; opBytes = 2; break;
        case 0x36:
            state->HL = opCode[2]; opBytes = 3; break;
        //LD A n, n is a register
        case 0x0a:
            state->A = state->BC; opBytes = 2; break;
        case 0x1a:
            state->A = state->memory[state->DE]; opBytes = 2; break;
        case 0xfa:
            state->A = state->memory[(opCode[1] << 4) | opCode[2]];
        default:
            printf("Unhandled opCode %X\n", opCode);



    }
    state->PC += opBytes;
}
