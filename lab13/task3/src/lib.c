/*
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 20-dec-2020
 * @version 1.0
 */

#include"lib.h"

int countTextLength(char* arr) {
    int count = 0;
    int i = 0;
    while (*(arr + i) != NULL) {
        count++;
        i++;
    }
    return count;
}

int countOfUniqueElements(char* arr, int size) {
    int count = 0;
    int i = 0;
    int k = 0;
    char* arrTemp = (char*)malloc(size * sizeof(char));
    strncpy(arrTemp, arr, 1);

    for (i = 0; i < size + 1; i++) {
        char value = *(arr + i);
        bool check = checker(arrTemp, k, value);
        for (int j = i + 1; j < size + 1; j++) {
            if (check == false) {
                *(arrTemp + k) = value;
                count++;
                k++;
                break;
            }
        }
    }
    free(arrTemp);
    return count;
}

bool checker(char* arr, int currentIndex, char value) {
    bool flag = false;
    for (int i = 0; i < currentIndex; i++) {
        if (*(arr + i) == value) {
            flag = true;
        }
    }
    return flag;
}

void getsymbols(char* strIn, int sizeIn, char* symbols, int sizeOut) {
    int i;
    int k = 0;
    for (i = 0; i < sizeIn + 1; i++) {
        char value = *(strIn + i);
        bool check = checker(symbols, k, value);
        for (int j = i + 1; j <= sizeIn; j++) {
            if (check == false) {
                *(symbols + k) = value;
                k++;
                break;
            }
        }
    }
    *(symbols + k) = '\0';
}

void getSymbolsCounts(char* strIn, int sizeIn, char* elements, int* elCounts, int sizeOut) {

    for (int i = 0; i < sizeOut; i++) {
        //char value = *(elements + i);
        for (int j = 0; j < sizeIn; j++) {
            if (*(elements + i) == *(strIn + j)) {
                *(elCounts + i) += 1;
            }
        }
    }
}

void fillZeros(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = 0;
    }
}

void getSymbolsFrequencies(int* elCounts, double* elFreaqs, int size, int totalCount) {
    for (int i = 0; i < size; i++) {
        int current = *(elCounts + i);
        *(elFreaqs + i) = (double)current / totalCount;
    }
}
