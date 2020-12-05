#include "lib.h"

void fillArray(float* arrIn, int lenIn) {
	srand(time(0));
	for (int i = 0; i < lenIn; i++) {
		*(arrIn + i) = rand() % 6 - 2;
	}
}


int getSequence (float* arrIn, int lenIn) {
	int count = 0;
	int countMax = 0;
	for (int i = 0; i < lenIn; i++) {
		
		if (*(arrIn + i) >= 0) {
			count++;
		} else {
			break;
		}
	}
	if (countMax < count) {
		countMax = count;
	}
	
	return &countMax;

}

void getResultArray (float* arrIn, int lenIn, int* countMax, float* arrOut) {
	int check = countMax;
	int value = 0;
	for (int i = 0; i < N; i++) {
		
		if (*(arrIn + i) >= 0) {
			*(arrIn + i) == *(arrOut + i);
			value++;
		} else {
			if ( value != check) {
				value = 0;
				for (int j = 0; j < lenIn; j++) {
					*(arrOut + j) = 0;
				}
			}
			break;
		}
		
	}
}
