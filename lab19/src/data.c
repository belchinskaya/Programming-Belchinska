#include "lib.h"
/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 02-march-2021
 * @version 1.0
 */

char * insert(char * arr1, char * arrCenter, size_t position) {
    char *new_array = malloc((strlen(arr1) + 1) * sizeof(char ));
    if (position > strlen(arr1)) {
        position = strlen(arr1);
    }
    for (int i = 0; i < strlen(arr1); i++) {
        if (position == i) {
            memcpy(new_array, arr1, position * sizeof(char));
            memcpy(new_array + position, arrCenter, strlen(arrCenter) * sizeof(char));
            memcpy(new_array + position + strlen(arrCenter), arr1 + position, strlen(arr1) - position);
            *(new_array + strlen(new_array)) = '\0';
            break;
        }
    }
    return new_array;
    //free(arr1);
}

char * delete_array(char * arr, size_t start, size_t end) {
    if ((end - start) == 0) {
        return 0; // nothing to delete
    }
    char * new_array = malloc((strlen(arr) - 1) * sizeof(char ));
    if (start >= strlen(arr)) {
        start = strlen(arr) - 1;
    }
    memcpy(new_array, arr, start * sizeof(char ));
    memcpy(new_array + start, arr + end, (strlen(arr) - (end - start)) * sizeof(char ));
    *(new_array + strlen(new_array)) = '\0';
    return new_array;
    //free(arr);;
}

struct Instrument* readFromFile(struct Instrument **i, struct Bow* bow, enum Material* material) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab18/instruments.txt", "r");
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(1);
    }
    for (int j = 0; j < INSTRUMENT_COUNT; j++) {
        struct Instrument *item = *(i + j);
        fscanf(file, "%s %s %d %f", item->type, item->firm, &(item->year), &(item->size));
        fscanf(file, "%d", &bow->weight);
        fscanf(file, "%d", material + j);

    }

    fclose(file);
}

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

struct Instrument *writeInFile(struct Instrument **instrument, struct Bow* bow, enum Material* material) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab18/instrumentsOut.txt", "w");
    for (int j = 0; j < 6; j++) {
        struct Instrument *item = *(instrument + j);

        fprintf(file, "\tType: %s\n", item->type);
        fprintf(file, "\tFirm: %s\n", item->firm);
        fprintf(file, "\tProduction Year: %d\n", item->year);
        fprintf(file, "\tSize: %f\n", item->size);
        fprintf(file, "\tBow weight: %d\n", bow->weight);
        switch (*(material + j)) {
            case BT: fprintf(file,"\tBow material: Brazilian Tree\n\n");
                break;
            case PERNAMBUCO: fprintf(file,"\tBow material: Pernambuco\n\n");
                break;
            case FIBERGLASS: fprintf(file,"\tBow material: Fiberglass\n\n");
                break;
        }
        //fseek(file, 0, SEEK_SET);
        //deleteStructElement(instrument, bow, material, file);
    }


    fclose(file);
}

void writeToBinaryFile(struct Instrument **instrument, struct Bow* bow, enum Material* material) {
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
        sscanf("%d", temp, bow->weight);
        fwrite(temp, sizeof(struct Instrument), sizeof(bow->weight), file);
        sscanf("%d", temp, material);
        fwrite(temp, sizeof(struct Instrument), sizeof(material), file);
    }
    fclose(file);
}

struct Instrument *printTheOldestInstrument(struct Instrument **instrument, struct Bow* bow, enum Material* material) {
    char seekInstrument[10] = "Yamaha";



    for (int i = 0; i < INSTRUMENT_COUNT; i++) {

        struct Instrument *item = *(instrument + i);
        for (int j = 0; j < 11; j++) {
            if ((strcmp(item->firm, seekInstrument)) == 0) {
                printf("\tThe oldest violin firm Yamaha\n\tType: %s\n", item->type);
                printf( "\tFirm: %s\n", item->firm);
                printf( "\tProduction Year: %d\n", item->year);
                printf("\tSize: %f\n", item->size);
                printf("\tBow weight: %d\n", bow->weight);
                switch (*(material + i) + j) {
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

void readFromBinary(struct Instrument** instrument, struct Bow* bow, enum Material* material) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab15/instruments.bin", "r");
    fseek(file, 0, SEEK_END);
    long count = ftell(file);

    //int pos = count / sizeof(struct Instrument** instrument);

    for (int j = 5; j < 6; j++) {
        struct Instrument *item = *(instrument + j);
        fread(item->type, sizeof(struct Instrument), sizeof(*item->type), file);
        fread(item->firm, sizeof(struct Instrument), sizeof(*item->type), file);
        char temp[50];
        sscanf("%d", temp, item->year);
        fread(temp, sizeof(struct Instrument), sizeof(*item->type), file);
        sscanf("%f", temp, item->size);
        fread(temp, sizeof(struct Instrument), sizeof(item->size), file);
        sscanf("%d", temp, bow->weight);
        fread(temp, sizeof(struct Instrument), sizeof(bow->weight), file);
        sscanf("%d", temp, bow->material);
        fread(temp, sizeof(struct Instrument), sizeof(bow->material), file);

        printf("\tWrite fifth element from binary:\n");
        printf("\tType: %s\n", item->type);
        printf("\tPosition: %s\n", item->firm);
        printf("\tProduction Year: %d\n", item->year);
        printf("\tSize: %f\n", item->size);
        printf("\tBow weight: %d\n", bow->weight);
        switch (*(material + j)) {
            case BT: printf("\tBow material: Brazilian Tree\n\n");
                break;
            case PERNAMBUCO: printf("\tBow material: Pernambuco\n\n");
                break;
            case FIBERGLASS: printf("\tBow material: Fiberglass\n\n");
                break;
        }

    }

    fclose(file);
}

void copyStructElement(struct Instrument** pInstrument, struct Bow* bow, enum Material* material) {
    FILE *file = fopen("/home/kate/Programming-Belchynska/lab18/instrumentsOut.txt", "a");
    struct Instrument** doubleInstrument = malloc(2 * sizeof(struct Instrument));
    for (int i = 0; i < 200; i++) {
        *(doubleInstrument + i) = malloc(sizeof(struct Instrument));
    }
    struct Bow* doubleBow = malloc(sizeof(struct Bow));
    enum Material* doubleMaterial = malloc(sizeof(enum Material));


    memcpy(*(doubleInstrument), *(pInstrument), sizeof(struct Instrument));
    memcpy(doubleBow, bow, sizeof(struct Bow));
    memcpy(doubleMaterial, material, sizeof(enum Material));
    fprintf(file, "\nCopy first instrument:\n");
    fprintf(file, "\tType: %s\n", (*(doubleInstrument))->type);
    fprintf(file, "\tFirm: %s\n", (*(doubleInstrument))->firm);
    fprintf(file, "\tProduction Year: %d\n", (*(doubleInstrument))->year);
    fprintf(file, "\tSize: %f\n", (*(doubleInstrument))->size);
    fprintf(file, "\tBow weight: %d\n", doubleBow->weight);
    switch (*(doubleMaterial)) {
        case BT: fprintf(file,"\tBow material: Brazilian Tree\n\n");
            break;
        case PERNAMBUCO: fprintf(file,"\tBow material: Pernambuco\n\n");
            break;
        case FIBERGLASS: fprintf(file,"\tBow material: Fiberglass\n\n");
            break;
    }


    free(doubleBow);
    free(doubleInstrument);
    free(doubleMaterial);
}

void deleteStructElement(struct Instrument** pInstrument, struct Bow* bow, enum Material* material, FILE* file) {
    file = fopen("/home/kate/Programming-Belchynska/lab18/instrumentsOut.txt", "a");

    for (int i = 0; i < INSTRUMENT_COUNT; i++){
        if (i == 2){
            //file = fopen("/home/kate/Programming-Belchynska/lab18/instrumentsOut.txt", "a");

            memset(*(pInstrument + i), 0, sizeof(struct Instrument));
            memset(bow + i, 0,sizeof(struct Bow));
            memset(material + i, 0, sizeof(enum Material));
            /*fprintf(file, "\nDelete second element from struct:\n");
            fprintf(file, "\tType: %s\n", (*(pInstrument + i))->type);
            fprintf(file, "\tFirm: %s\n", (*(pInstrument + i))->firm);

            fprintf(file, "\tProduction Year: %d\n", (*(pInstrument + i))->year);
            fprintf(file, "\tSize: %f\n", (*(pInstrument + i))->size);
            fprintf(file, "\tBow weight: %d\n", (*(bow + i)).weight);
            switch (*(material + i)) {
                case BT: fprintf(file,"\tBow material: Brazilian Tree\n\n");
                    break;
                case PERNAMBUCO: fprintf(file,"\tBow material: Pernambuco\n\n");
                    break;
                case FIBERGLASS: fprintf(file,"\tBow material: Fiberglass\n\n");
                    break;
            }
            break;*/
        }

    }


}
