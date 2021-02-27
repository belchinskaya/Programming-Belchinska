#include "lib.h"



int main() {
    //FILE * file = fopen("/home/kate/Programming-Belchynska/lab15/InstrumentsOut.txt", "r");
    struct Instrument ** instruments = malloc(INSTRUMENT_COUNT * sizeof(struct Instrument* ));
    for (int i = 0; i < 200; i++) {
        *(instruments + i) = malloc(sizeof(struct Instrument));
    }
    readFromFile(instruments);
    sortByYear(instruments);
    printInstrument(instruments);
    //writeInFile(instruments);
    //writeToBinaryFile(instruments);


    for (int j = 0; j < 200; j++) {
   //   free(*(instruments + j));
    }
    free(instruments);
    return 0;
}


