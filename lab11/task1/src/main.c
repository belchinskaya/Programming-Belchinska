/*���� ����� � N ����� �����. ���������, �� � � ����� ��������, �� ������������; ���� ��� �, �� �������� �����, � ����� �������, ������ ���� �� �������� ������������. ����� �����, � ������������� ����� ����� �������� ������� - �����, �� ������������; ����� ������ - ������� �����������*/

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
