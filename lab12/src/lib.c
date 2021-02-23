/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 * для обчислення кількості незменшуванних ділянок, визначення максимальної та переписувааня її у інший масив
 *
 * @author Belchynska K.
 * @date 23-feb-2021
 * @version 1.0
 */
#include <unistd.h>
#include "lib.h"

void fillArrOne(float * arrIn, int lenIn) {

	fwrite("Введіть елементи масиву: \n", sizeof(char), 45, stderr);

	for (int i = 0; i < lenIn; i++) {
		scanf("%f", arrIn + i);
	}
	char temp[100];
    for (int i = 0; i < lenIn; i++) {
        //sscanf("%f", arrIn);
        //fgets(temp, lenIn + 1, stdin);
        //*(arrIn + i) = getc(stdin);
    }
	//puts("Введіть елементи масиву: ");
    /*for (int i = 0; i < lenIn; i++) {

    }*/


    fread(arrIn, sizeof(char), lenIn, stdin);

}

int countOfIncreasingSequences(float * arrIn, int lenIn) {
	int count = 0;
	for (int i = 0; i < lenIn - 1; ) {
		int j;
		if (*(arrIn + i) > *(arrIn + i + 1)) {
			i++;
			continue;
		} else {
			j = i;
			count++;
			while (*(arrIn + j) < *(arrIn + j + 1)) {
				j++;
			}
		}
		i = j + 1;
	}


	return count;
}

int findMaxIncreasingSequence(float* arrayIn, int lenIn, int* startOfMaxIncreasingSequence) {
	int lenMax = 0;
	int lenCurrent;
	for (int i = 0; i < lenIn - 1; ) {
		int j;
		if (*(arrayIn + i) > *(arrayIn + i + 1)) {
			i++;
			continue;
		} else {
			lenCurrent = 1;
			j = i;
			while (*(arrayIn + j) < *(arrayIn + j + 1)) {
				lenCurrent++;
				j++;
			}
		}
		if (lenCurrent > lenMax) {
			lenMax = lenCurrent;
			*startOfMaxIncreasingSequence = i;
		}
		i = j + 1;
	}


	return lenMax;
}

void fillArrayOut(float* arrayIn, int start, float * arrayOut1, int lenOut) {
    char arrForPrint[50];
    for (int i = 0; i < lenOut; i++) {
        *(arrayOut1 + i) = *(arrayIn + start);
        start++;
       // sprintf(arrForPrint, "%f", *(arrayOut1 + i));

    }
}



void printArrayOut(float* arrayIn, int start, float * arrayOut, int arrayLength){
    printf("\nРезультуючий масив:\n");

    char temp[50];
    for (int i = 0; i < arrayLength; i++) {
        *(arrayOut + i) = *(arrayIn + start);
        sprintf(temp,"%f ", *(arrayOut + i));
        start++;
    }
    for (int i = 0; i < arrayLength; i++) {
        scanf("%f", arrayIn + start);
        *(arrayOut + i) = *(arrayIn + start);
        //sprintf(temp, "%f", *(arrayOut +i));
        puts(temp);
        fwrite(&temp, sizeof(char), arrayLength + 1, stdout);

    }
}