/*Дано масив з N цілих чисел. Визначити, чи є в масиві елементи, що повторюються; якщо такі є, то створити масив, в якому вказати, скільки разів які елементи повторюються. Таким чином, в результуючому масиві кожен непарний елемент - число, що повторюється; кожен парний - кількість повторювань*/

#include "lib.h"

int main() {
	int* arrayIn = (int*)malloc(N * sizeof(int));
	fillArrayIn(arrayIn);

	int lenOut = countDuplicatingElements(arrayIn, N) * 2;

	int* arrayResult = (int*)malloc(lenOut * sizeof(int));
	for (int i = 0; i < lenOut; i++) {
		*(arrayResult + i) = 0;
	}

	writeDupElToResult(arrayIn, N, arrayResult, lenOut);
	writeCountsToResult(arrayIn, N, arrayResult, lenOut);


	return 0;
}
