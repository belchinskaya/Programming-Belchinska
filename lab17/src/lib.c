/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 02-march-2021
 * @version 1.0
 */
#include "lib.h"
#define INSTRUMENT_COUNT_TEST 3

struct Instrument* readFromFile(struct Instrument **i) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab15/instruments.txt", "r");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(1);
    }
    for (int j = 0; j < INSTRUMENT_COUNT; j++) {
        struct Instrument *item = *(i + j);
        fscanf(file, "%s %s %d %f", item->type, item->firm, &(item->year), &(item->size));
        fscanf(file, "%d", &item->bow.weight);
        fscanf(file, "%d", &item->bow.material);
    }

    fclose(file);
}


/*struct Instrument* printInstrument(struct Instrument** instrument, struct Bow* bow) {
    printf("Instrument info: \n");
    for (int j = 0; j < 6; j++) {
        struct Instrument* item = *(instrument + j);
        printf("\tType: %s\n", item->type);
        printf("\tPosition: %s\n", item->firm);

        printf("\tProduction Year: %d\n", item->year);
        printf("\tSize: %f.2\n", item->size);
        printf("\tBow weight: %d\t", bow->weight);

    }

}
*/

struct Instrument** sortByYear(struct Instrument **instruments) {
//    for (int j = 0; j < 6; j++) {
//        struct Instrument *item = *(instruments + j);
//    }
    for (int i = 0; i < INSTRUMENT_COUNT_TEST; i++) {
        //struct Instrument* item = *(instruments + i);
        for (int j = 0; j < INSTRUMENT_COUNT_TEST - 1; j++) {
            if ((*(instruments + j))->year > (*(instruments + j + 1))->year) {
                struct Instrument *temp = *(instruments + j);
                *(instruments + j) = *(instruments + j + 1);
                *(instruments + j + 1) = temp;

            }
        }

    }
    return instruments;

}

struct Instrument *writeInFile(struct Instrument **instrument) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab15/instrumentsOut.txt", "w");
    for (int j = 0; j < 6; j++) {
        struct Instrument *item = *(instrument + j);
        fprintf(file, "\tType: %s\n", item->type);
        fprintf(file, "\tFirm: %s\n", item->firm);
        fprintf(file, "\tProduction Year: %d\n", item->year);
        fprintf(file, "\tSize: %f\n", item->size);
        fprintf(file, "\tBow weight: %d\n", item->bow.weight);
        switch (item->bow.material) {
            case BT: fprintf(file,"\tBow material: Brazilian Tree\n\n");
                break;
            case PERNAMBUCO: fprintf(file,"\tBow material: Pernambuco\n\n");
                break;
            case FIBERGLASS: fprintf(file,"\tBow material: Fiberglass\n\n");
                break;
        }
    }


    fclose(file);
}

void writeToBinaryFile(struct Instrument **instrument) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab15/instruments.bin", "w");
    for (int j = 0; j < 6; j++) {
        struct Instrument *item = *(instrument + j);
        fwrite(item->type, sizeof(struct Instrument), sizeof(*item->type), file);
        fwrite(item->firm, sizeof(struct Instrument), sizeof(*item->type), file);
        char temp[50];
        sscanf("%d", temp, item->year);
        fwrite(temp, sizeof(struct Instrument), sizeof(*item->type), file);
        sscanf("%f", temp, item->size);
        fwrite(temp, sizeof(struct Instrument), sizeof(item->size), file);
        sscanf("%d", temp, item->bow.weight);
        fwrite(temp, sizeof(struct Instrument), sizeof(item->bow.weight), file);
        sscanf("%d", temp, item->bow.material);
        fwrite(temp, sizeof(struct Instrument), sizeof(item->bow.material), file);
    }
    fclose(file);
}

struct Instrument *printTheOldestInstrument(struct Instrument **instrument) {
    int current = 0;
    for (int j = 0; j < INSTRUMENT_COUNT_TEST; j++) {
        struct Instrument *item = *(instrument + j);
        if ((strcmp(item->firm, "Yamaha")) == 0) {

            printf("\tThe oldest violin firm Yamaha\n\tType: %s\n", item->type);
            printf( "\tFirm: %s\n", item->firm);
            printf( "\tProduction Year: %d\n", item->year);
            printf("\tSize: %f\n", item->size);
            printf("\tBow weight: %d\n", item->bow.weight);
            switch (item->bow.material) {
                case BT: printf("\tBow material: Brazilian Tree\n\n");
                break;
                case PERNAMBUCO: printf("\tBow material: Pernambuco\n\n");
                break;
                case FIBERGLASS: printf("\tBow material: Fiberglass\n\n");
                break;
            }
            current = j;

        }


    }
    return  *(instrument + current);
}

void readFromBinary(struct Instrument** instrument) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab15/instruments.bin", "r");
    fseek(file, 0, SEEK_END);
    long count = ftell(file);

    //int pos = count / sizeof(struct Instrument** instrument);

    for (int j = 4; j < INSTRUMENT_COUNT; j++) {
        struct Instrument *item = *(instrument + j);
        fread(item->type, sizeof(struct Instrument), sizeof(*item->type), file);
        fread(item->firm, sizeof(struct Instrument), sizeof(*item->type), file);
        char temp[50];
        sscanf("%d", temp, item->year);
        fread(temp, sizeof(struct Instrument), sizeof(*item->type), file);
        sscanf("%f", temp, item->size);
        fread(temp, sizeof(struct Instrument), sizeof(item->size), file);
        sscanf("%d", temp, item->bow.weight);
        fread(temp, sizeof(struct Instrument), sizeof(item->bow.weight), file);
        sscanf("%d", temp, item->bow.material);
        fread(temp, sizeof(struct Instrument), sizeof(item->bow.material), file);

        printf("\tWrite fifth element from binary:\n");
        printf("\tType: %s\n", item->type);
        printf("\tPosition: %s\n", item->firm);
        printf("\tProduction Year: %d\n", item->year);
        printf("\tSize: %f\n", item->size);
        printf("\tBow weight: %d\n", item->bow.weight);
        switch (item->bow.material) {
            case BT: printf("\tBow material: Brazilian Tree\n\n");
                break;
            case PERNAMBUCO: printf("\tBow material: Pernambuco\n\n");
                break;
            case FIBERGLASS: printf("\tBow material: Fiberglass\n\n");
                break;
        }

    }
    //fseek(file, 0, (pos - 1) * sizeof(struct Instrument*));
    for (int j = 0; j < 6; j++) {
        struct Instrument *item = *(instrument + j);
        //if (j == pos - 1) {

        //}

    }
    fclose(file);
}
