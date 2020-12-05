/*Дано масив з N*N цілих чиселю Елементи головної діагоналі записати в одномірний масив, отриманий масив упорядкувати за зростанням*/

#include"lib.h"

int main() {
	int** matrix = (int**)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		*(matrix + i) = (int*)malloc(N * sizeof(int));
	}
	void fillMatrix(int** matrix);

	int* mainDiag = (int*)malloc(N * sizeof(int));

	void fillOneDimArray(int** matrix, int* mainDiag);

	void sortArray(int* mainDiag);

	return 0;
}
