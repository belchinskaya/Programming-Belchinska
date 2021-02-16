#include "lib.h"
long fileSize(FILE * file) {
    FILE *file = fopen("firms.txt", "r");
    long count = 0;
    while (!feof(file)) {
        fgetc(file);
        count++;
    }
    count--; // feof - is also hidden character
    printf("Filesize: %ld \n", count);
    fclose(file);
    return count;
}

void readFromFile(char * pFirms, long length) {
    FILE *file = fopen("firms.txt", "r");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
    }
    length = fileSize(file);
    fgets(pFirms, length, file);
    fclose(file);
}

void writeToConsole(char * pFirms, long count) {
    readFromFile(pFirms, count);
    printf("%s", pFirms);
}

void print_circle(struct Type* p, char dx, char dy) {

}

void printInstrument(struct Instrument *instrument, int year) {
    printf("Instrument info: \n");
    printf("\tType: %s\n", types[(*instrument).type)];
    printf("\tPosition: %s\n", firms[(*instrument).firm]);

    printf("\tProduction Year: %d\n", (*instrument).year);
}

void getFromFile(char* type, char* firm, int year) {
    scanf("")
}