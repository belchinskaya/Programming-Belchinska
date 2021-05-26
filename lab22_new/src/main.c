#include "data.h"

int main() {
    FILE *fileIn = fopen("/home/kate/Programming-Belchynska/lab22_new/instruments.txt", "r");
    FILE *fileOut = fopen("/home/kate/Programming-Belchynska/lab22_new/instrumentsOut.txt", "w");
    bool result = true;

    struct Instrument ** instruments = malloc(INSTRUMENT_COUNT * sizeof(struct Instrument* ));
    for (int i = 0; i < 200; i++) {
        *(instruments + i) = malloc(sizeof(struct Instrument));
    }

    for (int i = 0; i < INSTRUMENT_COUNT; i++) {
        *(instruments + i) = readFromFile(fileIn);
        printf("%s\n", (*(*(instruments + i))).firm);
        writeInFile(fileOut, *(instruments + i));
    }

    for (int i = 0; i < INSTRUMENT_COUNT; i++) {
        result = isValidInstrument(*(instruments + i));
        if (result == true) {
            printDoubleWordInstrument(*(instruments + i));
        }
    }

    fclose(fileIn);
    return 0;
}