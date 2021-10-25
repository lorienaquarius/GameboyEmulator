//
// Created by lorie on 2021-10-01.
//
#include <stdio.h>
#include "Dissasembler.h"
#include <stdint.h>
int Disassemble(unsigned char *buffer, int pc){
    unsigned char *opCode = &buffer[pc];
    int opBytes = 1;
    unsigned char code = *opCode;
    printf("%X ", code);
    return opBytes;
}