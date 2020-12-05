/*Дано масив з N цілих чисел. Знайти безпервну послідовність позитивних чисел у вхідному масиві, сума елементів якої максимальна, та переписати їх у вихідний масив*/

#include "lib.h"

int main() {
	int* arrayIn = (int*)malloc(N * sizeof (int*));
	int* arrayOut = (int*)malloc(N * sizeof (int*));
	for (int i = 0; i < N; i++) {
		*(arrayOut + i) = 0;
	}
	fillArrIn(arrayIn, N);
	int maxSum = getPositiveSequence(arrayIn, arrayOut, N);
	
	fillArrayResult (arrayIn, N, arrayOut, maxSum);
	
	return 0;
}
