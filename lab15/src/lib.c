/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 02-march-2021
 * @version 1.0
 */
#include "lib.h"


struct Instrument* readFromFile(struct Instrument **i, struct Bow **bow) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab15/instruments.txt", "r");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(1);
    }
    for (int j = 0; j < INSTRUMENT_COUNT; j++) {
        struct Instrument *item = *(i + j);
        fscanf(file, "%s %s %d %f", item->type, item->firm, &(item->year), &(item->size));
        fscanf(file, "%d", &(*(bow + j))->weight);
        fscanf(file, "%d", &(*(bow + j))->material);
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

struct Instrument *sortByYear(struct Instrument **instruments) {
//    for (int j = 0; j < 6; j++) {
//        struct Instrument *item = *(instruments + j);
//    }
    for (int i = 0; i < INSTRUMENT_COUNT; i++) {
        //struct Instrument* item = *(instruments + i);
        for (int j = 0; j < INSTRUMENT_COUNT - 1; j++) {
            if ((*(instruments + j))->year > (*(instruments + j + 1))->year) {
                struct Instrument *temp = *(instruments + j);
                *(instruments + j) = *(instruments + j + 1);
                *(instruments + j + 1) = temp;

            }
        }

    }

}

struct Instrument *writeInFile(struct Instrument **instrument, struct Bow** bow) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab15/instrumentsOut.txt", "w");
    for (int j = 0; j < 6; j++) {
        struct Instrument *item = *(instrument + j);
        fprintf(file, "\tType: %s\n", item->type);
        fprintf(file, "\tFirm: %s\n", item->firm);
        fprintf(file, "\tProduction Year: %d\n", item->year);
        fprintf(file, "\tSize: %f\n", item->size);
        fprintf(file, "\tBow weight: %d\n", (*(bow + j))->weight);
        switch ((*(bow + j))->material) {
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
    }
    fclose(file);
}

struct Instrument *printTheOldestInstrument(struct Instrument **instrument, struct Bow** bow) {
    char seekInstrument[10] = "Yamaha";



    for (int i = 0; i < INSTRUMENT_COUNT; i++) {

        struct Instrument *item = *(instrument + i);
        for (int j = 0; j < 11; j++) {
            if ((strcmp(item->firm, seekInstrument)) == 0) {
                printf("\tThe oldest violin firm Yamaha\n\tType: %s\n", item->type);
                printf( "\tFirm: %s\n", item->firm);
                printf( "\tProduction Year: %d\n", item->year);
                printf("\tSize: %f\n", item->size);
                printf("\tBow weight: %d\n", (*(bow + j))->weight);
                switch ((*(bow + j))->material) {
                    case BT: printf("\tBow material: Brazilian Tree\n\n");
                        break;
                    case PERNAMBUCO: printf("\tBow material: Pernambuco\n\n");
                        break;
                    case FIBERGLASS: printf("\tBow material: Fiberglass\n\n");
                        break;
                }
                break;
            }
        }
    }

}

