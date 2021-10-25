#include <stdio.h>
#include <stdlib.h>

#include "Dissasembler.h"
#include "CPUEmulator.h"
int main() {
    FILE *f = fopen("C:\\Users\\lorie\\OneDrive - Carleton University\\Developer\\Emulator\\PokemonRedHex.txt", "rb");
    if(f == NULL){
        printf("File failed to open");
        exit(1);
    }
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    State GB;
    GB.memory =malloc(fsize);

    fread(GB.memory, fsize, 1, f);
    fclose(f);

    printf("%X", GB.memory[0x147]);


//    while (GB.PC < fsize)
//    {
//        Emulate(&GB);
//        printf("%d\n", GB.PC);
//    }
}
