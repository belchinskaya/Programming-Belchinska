#pragma one
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define INSTRUMENT_COUNT

void readFromFile(struct Instrument *instruments);
//void writeToConsole(char * pFirms, long count);
long fileSize(FILE * file);

struct Instrument {
    const char* type;
    const char* firm;
    int year;
};


void getFromFile(char* type, char* firm, int year);

void printInstrument(struct Instrument violin);
void sortByYear(struct Instrument violin);