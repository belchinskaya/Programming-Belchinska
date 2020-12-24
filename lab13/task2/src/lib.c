/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 19-dec-2020
 * @version 1.0
 */
#include "lib.h"


int getComaCount(char* arr1) {
    int count = 0;
	int i = 0;
	
	do {
		if (*(arr1 + i) == ',') {
			count++;
		}
		i++;
	} while (*(arr1 + i) != '\0');

    return count;
}

void sortSequence(char ** strIn, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize - 1; j++) {
            if (strcmp(*(strIn + j), *(strIn + j + 1)) > 0) {
                char temp[11];
                strcpy(temp, *(strIn + j));
                strcpy(*(strIn + j), *(strIn + j + 1));
                strcpy(*(strIn + j + 1), temp);
            }
        }
    }
}

int deleteRepeat(char ** strIn, int arraySize) {
	int lenOut = 0;
    for (int i = 0; i < arraySize; i++) {
        if (strcmp(*(strIn + i), *(strIn + i + 1)) == 0) {
             strcpy(*(strIn + i), "\0");
        } else {
			lenOut += strlen(*(strIn + i)) + 1;
		}
    }
	return lenOut;
}

void fillArrayOut(char **strIn, int arraySize, char *result) {
	for (int i = 0; i < arraySize; i++) {
		if (strcmp(*(strIn + i), "\0") != 0) {
			strcat(result, *(strIn + i));
			strcat(result, ",");
		}
	}
	*(result + strlen(result) - 1) = '\0';
}
