#include "lib.h"


int getComaCount(char * arr1) {
    int count = 0;
    for (int i = 0; ; i++) {
        if (*(arr1 + i) == ",") {
            count++;
        }
    }
    return count;
}

void sortSequence(char ** strIn, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize - 1; j++) {
            if (strcmp(*(strIn + j), *(strIn + j + 1)) > 0) {
                char temp[50];
                strcpy(temp, *(strIn + j));
                strcpy(*(strIn + j), *(strIn + j + 1));
                strcpy(*(strIn + j + 1), temp);
            }
        }
    }
}

void deleteRepeat(char ** strIn, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (*(strIn + i) == *(strIn + i +1)) {
             strcpy(*(strIn + i), "\0");
        }
    }

    char textOut[100] = {0};

    for (int i = 0; i < arraySize - 1; i++) {
        if (strlen(*(strIn + i)) > 0) {
             strcat(textOut, *(strIn + i));
             strcat(textOut, " ");
             
        }
    }
}