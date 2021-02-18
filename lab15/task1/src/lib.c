#include "lib.h"
long fileSize(FILE * file) {

    file = fopen("/home/kate/Programming-Belchynska/lab15", "r");
    fseek(file, 0, SEEK_END);
    long count = ftell(file);
    printf("Filesize: %ld \n", count);
    fclose(file);
    return count;
}



void readFromFile(struct Instrument *instruments) {
    FILE * file = fopen("/home/kate/Programming-Belchynska/lab15/Instruments.txt", "r");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(1);
    }
    scanf("%s", "%s", "%d", instruments->type, instruments->firm, instruments->year);

    fclose(file);
}



//void print_circle(struct Type* p, char dx, char dy) {



/*void printInstrument(struct Instrument *instrument, int year) {
    printf("Instrument info: \n");
    printf("\tType: %s\n", (*instrument).type);
    printf("\tPosition: %s\n", (*instrument).firm);

    printf("\tProduction Year: %d\n", (*instrument).year);
}
*/

void sortByYear(struct Instrument *instruments) {
    for (int i = 0; i < INSTRUMENT_COUNT ; i++) {
        for (int j = 0; j < INSTRUMENT_COUNT -1; j++) {
            if ((instruments + i)->year < (instruments + j + 1)->year) {
                struct Employee *temp = (instruments + j);
                strcpy((instruments + j), (instruments + j + 1));
                strcpy((instruments + j + 1), temp);
            }
        }
    }
}
//    for (int i = 0; i < INSTRUMENT_COUNT; i++) {
        //printEmployee(&employees[i]);
//    }