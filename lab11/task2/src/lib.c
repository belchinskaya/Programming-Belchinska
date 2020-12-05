#include "lib.h"

void fillArrIn(int* arrIn, int lenIn) {
	srand(time(0));
	for (int i = 0; i < lenIn; i++) {
		*(arrIn + i) = rand() % 6 - 2;
	}
}


int getPositiveSequence(int* arrIn, int* arrResult, int lenIn) {
	int sumCurrent = 0;
	int sumMax = 0;
	
	for (int i = 0; i < lenIn - 1; i++) {
		sumCurrent = 0;
		if (*(arrIn + i) > 0) {
			
			sumCurrent += *(arrIn + i);
			if (sumCurrent >= sumMax) {
				sumMax = sumCurrent;
			}
		
		} else if (*(arrIn + i) < 0) {
			
			break;
		}
		
		
	}
	return sumMax;
}

void fillArrayResult (int* arrIn, int lenIn, int* arrResult, int sum) {
	int maxSum = sum;
	
	for (int j = 0; j < lenIn; j++) {
		int value = *(arrIn + j);
		if (*(arrIn + j) > 0) {
			*(arrResult + j) = value;
			int checker = checkSum(lenIn, arrResult);
			if (checker == maxSum) {
				break;
			}
		} else {
			for (int i = 0; i < lenIn; i++) {
				*(arrResult + j) = 0;
			} 
			break;
		}
		
	}
} 

int checkSum(int lenIn, int* arrResult) {
	int summa = 0;
	for (int i = 0; i < lenIn; i++) {
		summa += *(arrResult + i);
	}
	return summa;
}
		
		
		
		
		
		
