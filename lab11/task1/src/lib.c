#include "lib.h"

void fillArrayIn(int* arrIn) {
	srand(time(0));
	for (int i = 0; i < N; i++) {
		*(arrIn + i) = rand() % 6;
	}
}

bool checker(int* arr, int currentIndex, int value) {
	bool flag = false;
	for (int i = 0; i < currentIndex; i++) {
		if (*(arr + i) == value) {
			flag = true;
		}
	}
	return flag;
}

int countDuplicatingElements(int* arr, int len) {
	int count = 0;
	int lenTemp = len / 2;
	int k = 0;

	int* arrTemp = (int*)malloc(lenTemp * sizeof(int));

	for (int i = 0; i < len; i++) {
		int value = *(arr + i);
		bool check = checker(arrTemp, k, value);
		for (int j = i + 1; j < len; j++) {
			if ((*(arr + j) == value) && (check == false)) {
				*(arrTemp + k) = value;
				count++;
				k++;
				break;
			}
		}
	}
	return count;
}

void writeDupElToResult(int* arrIn, int lenIn, int* arrOut, int lenOut) {
	int k = 0;
	for (int i = 0; i < lenIn; i++) {
		int value = *(arrIn + i);
		bool check = checker(arrOut, k, value);
		for (int j = i + 1; j < lenIn; j++) {
			if ((*(arrIn + j) == value) && (check == false)) {
				*(arrOut + k) = value;
				k += 2;
				break;
			}
		}
	}
}

void writeCountsToResult(int* arrIn, int lenIn, int* arrOut, int lenOut) {
	for (int i = 0; i < lenOut; i += 2) {
		int count = 0;
		for (int j = 0; j < lenIn; j++) {
			if (*(arrOut + i) == *(arrIn + j)) {
				count++;
				*(arrOut + i + 1) = count;
			}
		}
	}
}
