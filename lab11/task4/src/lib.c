#include"lib.h"

void fillMatrix(int** matr) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			*(*(matr + i) + j) = rand() % 201 - 80;
		}
	}
}

void fillOneDimArray(int** matr, int* arr) {
	
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				*(arr + i) = *(*(matr + i) + j);
			}
		}
	}*/
	for (int i = 0; i < N; i++) {
		*(arr + i) = *(*(matr + i) + i);
	}
}

void sortArray(int* arr) {
	int temp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (*(arr + j) < *(arr + i)) {
				temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}