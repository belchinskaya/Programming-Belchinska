#define N 3
int main() {
	int arrayIn[N][N];
	for (int i = 0; i < N; i++) {//перебираємо елементи масиву
		for (int j = 0;j < N; j++) {
			arrayIn[i][j] = i * N + j;
		}
	}
	for (int i = 0; i < N; i++) {//за допомгою додаткової змінної k перебираємо строки заданої матриці
		int k = arrayIn[i][0];
		for (int j = 0; j < N; j++) {//зміщуємо елементи масиву на 1 вправо
			arrayIn[i][j] = arrayIn[i][j + 1]; 
		}
		arrayIn[i][N - 1] = k;//закінчуємо зміщення елементів, ставлячи останній елемент на місце першого
	}
	return 0;
}
