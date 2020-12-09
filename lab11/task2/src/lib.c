#include "lib.h"

void fillArrIn(int* arrIn, int lenIn) {
	srand(time(0));
	for (int i = 0; i < lenIn; i++) {
		*(arrIn + i) = rand() % 8 - 2;
	}
}


int findMaxPositiveSequence(int* arrIn, int lenIn, int* lenOut) {
	int sumMax = 0;
	int iStart;
	for (int i = 0; i < lenIn; i++) {
		int sumCurrent = 0;
		int lenCurrent = 0;
		for (int j = i; j < lenIn; j++) {
			if (*(arrIn + j) > 0) {
				sumCurrent += *(arrIn + j);
				lenCurrent++;
			} else break;
		}
		if (sumCurrent > sumMax) {
			iStart = i;
			sumMax = sumCurrent;
			*lenOut = lenCurrent;
		}
	}

	return iStart;
}

void fillArrayResult (int* arrIn, int start, int* arrResult, int lenOut) {
	for (int i = 0; i < lenOut; i++) {
		*(arrResult + i) = *(arrIn + start);
		start++;
	}
}