/*���� ����� � N ����� �����. ������ ��������� ����������� ���������� ����� � �������� �����, ���� �������� ��� �����������, �� ���������� �� � �������� �����*/

#include "lib.h"

int main() {
	int* arrayIn = (int*)malloc(N * sizeof(int)); 
	fillArrIn(arrayIn, N);

	int lenOut = 0;
	int startIndex = findMaxPositiveSequence(arrayIn, N, &lenOut);

	int* arrayOut = (int*)malloc(lenOut * sizeof(int));
	fillArrayResult(arrayIn, startIndex, arrayOut, lenOut);

	return 0;
}