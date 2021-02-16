#ifndef SRC_LIB_H
#define SRC_LIB_H

#endif //SRC_LIB_H
#pragma one
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
void readFromFile(char * pFirms);
void writeToConsole(char * pFirms, long count);
long fileSize(FILE * file);

struct Instrument{
    char* type;
    char* firm;
    int year;
};

enum Type{
    ACOUSTIC, OTHER
};
static char types[2][10] = {"Acoustic", "Other"};

/*enum Firm{
    STENOR, YAMAHA, MENDINI, CELICIO, FIDDLERMAN, CREMONA

};*/
static char firms[6][20] = {"Stenor", "Yamaha", "Mendini", "Cecilio", "Fiddlerman", "Cremona"};




void getFromFile(char* type, char* firm, int year);

void printInstrument(struct Instrument *instrument);