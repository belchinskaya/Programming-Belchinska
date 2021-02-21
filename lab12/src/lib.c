/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 * для обчислення кількості незменшуванних ділянок, визначення максимальної та переписувааня її у інший масив
 *
 * @author Belchynska K.
 * @date 09-dec-2020
 * @version 1.0
 */
#include <unistd.h>
#include "lib.h"

void fillArrOne(float * arrIn, int lenIn) {
	printf("Введіть елементи масиву: \n");
	for (int i = 0; i < lenIn; i++) {
		scanf("%s", arrIn + i);
	}
    for (int i = 0; i < lenIn; i++) {
        //sscanf("%f", arrIn);
        fgets(arrIn, lenIn + 1, stdin);
        *(arrIn + i) = getc(stdin);
    }
	//puts("Введіть елементи масиву: ");
    /*for (int i = 0; i < lenIn; i++) {

    }*/


    fread(arrIn, sizeof(char), lenIn, stdin);

}

int countOfIncreasingSequences(char* arrIn, int lenIn) {
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

    printf("\nКількість незменшуваних послідовностей: %d\n", count);
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

void fillArrayOut(float* arrayIn, int start, char * arrayOut1, int lenOut) {
    for (int i = 0; i < lenOut; i++) {
        *(arrayOut1 + i) = *(arrayIn + start);
        start++;
        sscanf("%s", *(arrayOut1 + i));
    }

}

/*int read(int lenIn) {

    fread(&lenIn, 1, 1, stdin);
    char* n;
    gcvt(lenIn, 5, n);
    n = getc(stdin);
    int n1;
    n1 = atoi(n);
    return n1;
}*/

void printArrayOut(float* arrayIn, int start, char * arrayOut, int arrayLength){
    printf("\nРезультуючий масив:\n");


    for (int i = 0; i < arrayLength; i++) {
        *(arrayOut + i) = *(arrayIn + start);
        sprintf("%s ", *(arrayOut + i));
        start++;
    }
    for (int i = 0; i < arrayLength; i++) {
        sscanf("%s", arrayIn + start);
        *(arrayOut + i) = *(arrayIn + start);
        putc(*(arrayOut + i), stdout);
        write(arrayOut + i, sizeof(char), arrayLength + 1);

    }

    for (int j = 0; j < arrayLength; j++) {

    }
  //printf("%f", *(arrayOut + i));
        //write(arrayOut + i, sizeof(arrayOut), 1, stderr);

        //char sArrayOut[50];
        //printf(sArrayOut, "%f", *(arrayOut + i));
        //puts(sArrayOut);




}