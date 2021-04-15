#include "data.h"
/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 02-march-2021
 * @version 1.0
 */



void writeToBinaryFile(struct Instrument **instrument) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab15/instruments.bin", "w");
    for (int j = 0; j < 6; j++) {
        struct Instrument *item = *(instrument + j);
        fwrite(item, sizeof(struct Instrument), 1, file);
    }
    fclose(file);
}

struct Instrument *printTheOldestInstrument(struct Instrument **instrument) {
    char seekInstrument[10] = "Yamaha";



    for (int i = 0; i < INSTRUMENT_COUNT; i++) {

        struct Instrument *item = *(instrument + i);
        for (int j = 0; j < 11; j++) {
            if ((strcmp(item->firm, seekInstrument)) == 0) {
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
                break;
            }
        }
    }

}

void readFromBinary(struct Instrument** instrument) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab15/instruments.bin", "r");
    fseek(file, 0, SEEK_END);
    long count = ftell(file);

    int pos = count / sizeof(struct Instrument);
    int n = 1;
    fseek(file, (pos - 1) * sizeof(struct Instrument), SEEK_SET);

    //for (int j = 5; j < 6; j++) {
    struct Instrument item;
    fread(&item, sizeof(struct Instrument), 1, file);


    printf(".");

    // }

    fclose(file);

}

void print_result(int return_value){
    if (return_value == 0) printf("Pattern found.\n");
    else if (return_value == REG_NOMATCH) printf("Pattern not found.\n");
    else printf("An error occured.\n");
}