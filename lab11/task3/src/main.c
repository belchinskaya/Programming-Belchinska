#include "lib.h"

int main() {
	float* arrayIn = (float*)malloc(N * sizeof (float*));
	float* arrayOut = (float*)malloc(N * sizeof (float*));
	
	
	fillArray(arrayIn, N);
	
	int* countMax = getSequence (arrayIn, N);
	getResultArray(arrayIn, N, countMax, arrayOut);
	return 0;
}
