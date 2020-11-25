#include<stdlib.h>
#include<time.h>
#define N 3
void moveValue(int arrayIn[N][N]);
int main() {
	srand(time(NULL));

	int arrayIn[N][N];//дана матриця NxN елементів

	for (int i = 0; i < N; i++) {//заповнюємо матрицю за допомогою рандому
		for (int j = 0; j < N; j++) {
			arrayIn[i][j] = rand() % 11 - 5;
		}
	}
	
	moveValue(arrayIn);//функція нічого не повертає, лиш змінює значення всередині себе
	return 0;
}

void moveValue(int arrayIn[N][N]) {
	char arrayOut[N][N];
	for (int i = 0; i < N; i++) {//за допомгою додаткової змінної k перебираємо строки заданої матриці
		int k = arrayIn[i][0];
		for (int j = 0; j < N; j++) {//зміщуємо елементи масиву на 1 вправо
			arrayOut[i][j] = arrayIn[i][j + 1]; 
		}
		arrayOut[i][N - 1] = k;//закінчуємо зміщення елементів, ставлячи останній елемент на місце першого
	}
	return 0;
}
