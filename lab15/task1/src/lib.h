#pragma one
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define INSTRUMENT_COUNT 6

struct Instrument* readFromFile(struct Instrument** i);

//long fileSize(FILE * file);

struct Instrument {
    char type[15];
    char firm[15];
    int year;
};




struct Instrument* printInstrument(struct Instrument** instrument);
struct Instrument* sortByYear(struct Instrument** i);
struct Instrument* writeInFile(struct Instrument** instrument);
void writeToBinaryFile(struct Instrument** instrument);