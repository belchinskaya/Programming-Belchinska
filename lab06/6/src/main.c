#define N 3
int main() {
	int matrixIn[N][N];//дана матриця NxN
	int matrixOut[N][N];//матриця, яка буде помножуватися 
	
		for (int i = 0; i < N; i++) {//обчислимо з даного масиву елементи матриці
			for (int j = 0; j < N; j++) {
				matrixIn[i][j] = i * N + j;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				matrixOut[i][j] = 0;
				for (int k = 0; k < N; k++) {//вводимо додаткову змінну, щоб помножити по черзі кожну строку на кожний стовпчик
					matrixOut[i][j] += matrixIn[i][k] * matrixIn[k][j];
				}
			}
		} 

	return 0;
}
