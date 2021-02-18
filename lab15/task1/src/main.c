#include "lib.h"
#include <stdio.h>


int main() {
    FILE * file = fopen("/home/kate/Programming-Belchynska/lab15/Instruments.txt", "r");
    struct Instrument *instruments = malloc(1 * sizeof(struct Instrument));

    readFromFile(instruments);

    return 0;
}


