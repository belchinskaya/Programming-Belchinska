/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 * для обчислення кількості незменшуванних ділянок, визначення максимальної та переписувааня її у інший масив
 *
 * @author Belchynska K.
 * @date 09-dec-2020
 * @version 1.0
 */
#include "lib.h"

void fillArrOne(float* arrIn, int lenIn) {
	srand(time(0));
	for (int i = 0; i < lenIn; i++) {
		*(arrIn + i) = (float) rand() / RAND_MAX * (5 - 1) + 1;
	}
}

int countOfIncreasingSequences(float* arrayIn, int lenIn) {
	int count = 0;
	for (int i = 0; i < lenIn - 1; ) {
		int j;
		if (*(arrayIn + i) > *(arrayIn + i + 1)) {
			i++;
			continue;
		} else {
			j = i;
			count++;
			while (*(arrayIn + j) < *(arrayIn + j + 1)) {
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

void fillArrayOut(float* arrayIn, int start, float* arrayOut, int lenOut) {
	for (int i = 0; i < lenOut; i++) {
		*(arrayOut + i) = *(arrayIn + start);
		start++;
	}
}
