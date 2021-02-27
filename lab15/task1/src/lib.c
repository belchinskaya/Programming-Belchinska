#include "lib.h"
/*long fileSize(FILE * file) {

    file = fopen("/home/kate/Programming-Belchynska/lab15/instruments.txt", "r");
    fseek(file, 0, SEEK_END);
    long count = ftell(file);
    printf("Filesize: %ld \n", count);
    fclose(file);
    return count;
}*/



struct Instrument* readFromFile(struct Instrument** i) {
    FILE * file = fopen("/home/kate/Programming-Belchynska/lab15/instruments.txt", "r");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(1);
    }
    for (int j = 0; j < 6; ++j) {
        struct Instrument* item = *(i + j);
        fscanf(file, "%s %s %d", item->type, item->firm, &(item->year));
    }


    fclose(file);
}



struct Instrument* printInstrument(struct Instrument** instrument) {
    printf("Instrument info: \n");
    for (int j = 0; j < 6; j++) {
        struct Instrument* item = *(instrument + j);
        printf("\tType: %s\n", item->type);
        printf("\tPosition: %s\n", item->firm);

        printf("\tProduction Year: %d\n", item->year);
    }

}


struct Instrument* sortByYear(struct Instrument** instruments) {
//    for (int j = 0; j < 6; j++) {
//        struct Instrument *item = *(instruments + j);
//    }
    for (int i = 0; i < INSTRUMENT_COUNT; i++) {
        struct Instrument* item = *(instruments + i);
        for (int j = 0; j < INSTRUMENT_COUNT - i - 1; j++) {
            if (item ->year < (item + 1)->year) {
                struct Instrument** temp = (item + j);
                (item + j) = (item + j + 1);
                (item + j) = (temp + j);

            }
        }
        writeInFile(instruments);
    }
}

struct Instrument* writeInFile(struct Instrument** instrument) {
    FILE * file = fopen("/home/kate/Programming-Belchynska/lab15/instrumentsOut.txt", "w");
    for (int j = 0; j < 6; j++) {
        struct Instrument* item = *(instrument + j);
        fprintf(file,"\tType: %s\n", item->type);
        fprintf(file, "\tPosition: %s\n", item->firm);

        fprintf(file,"\tProduction Year: %d\n", item->year);
    }
    fclose(file);
}
/*void writeToBinaryFile(struct Instrument** instrument){
    FILE * file = fopen("/home/kate/Programming-Belchynska/lab15/instruments.bin", "w");
    for (int j = 0; j < 6; j++) {
        struct Instrument *item = *(instrument + j);
        fwrite(item->type, sizeof(struct Instrument), sizeof(*item->type), file);
        fwrite(item->firm, sizeof(struct Instrument), sizeof(*item->type), file);
        char temp[50];
        sscanf("%d", temp, item->year);
        fwrite(temp, sizeof(struct Instrument), sizeof(*item->type), file);
    }
    fclose(file);
}
*/
