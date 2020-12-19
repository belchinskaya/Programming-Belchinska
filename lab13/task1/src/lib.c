/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 19-dec-2020
 * @version 1.0
 */

#include "lib.h"

int getWordCount(char* p_string, char sym) {
    int countWords = 0;
    while ((p_string = strchr(p_string, sym)) != NULL) {
        countWords++;
        p_string++;
    }
    countWords += 1;
    return countWords;
}

void sortWord(char** stringIn, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; j++) {
            *(*(stringIn + i) + j) = tolower(*(*(stringIn + i) + j));
        }
    }
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize - 1; j++) {
            if (strcmp(*(stringIn + j), *(stringIn + j + 1)) > 0) {
                char temp[10];
                strcpy(temp, *(stringIn + j));
                strcpy(*(stringIn + j), *(stringIn + j + 1));
                strcpy(*(stringIn + j + 1), temp);
            }
        }
    }
}



