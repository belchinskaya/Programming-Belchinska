#include "data.h"

struct Instrument* readFromFile(FILE * fileIn) {
    struct Instrument * instrument = malloc(sizeof (struct Instrument));
    if (fileIn == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(1);
    }
    fgets(instrument->firm, 100, fileIn);
    //fscanf(fileIn, "\n");
    fscanf(fileIn, "%d\n", &instrument->year);
    fscanf(fileIn, "%f\n", &instrument->size);
    return instrument;
}

void writeInFile(FILE * fileOut, struct Instrument* instruments) {
    fputs((*(instruments)).firm, fileOut);
    fprintf(fileOut, "\n");
    fprintf(fileOut, "%d\n", (*(instruments)).year);
    fprintf(fileOut, "%f\n", (*(instruments)).size);
}

bool isValidInstrument(struct Instrument * instruments) {
    bool result = false;
    regex_t regex;
    regcomp(&regex, "[a-zA-Z0-9]",0);
    int return_value = regexec(&regex, (*(instruments)).firm, 0, NULL, 0);

    regcomp(&regex, " ",0);

    int return_value2 = regexec(&regex, (*(instruments)).firm, 0, NULL, 0);
    if (return_value == 0 && return_value2 == 0) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

void printDoubleWordInstrument(struct Instrument * instruments) {
    printf("Find instrument which firm`s name consists of two words:\n");
    printf("%s\n", (*(instruments)).firm);
}

