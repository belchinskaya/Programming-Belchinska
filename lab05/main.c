#define N 3//число, що підводиться у ступінь
#define M 4//ступінь числа
int main() {
	int ResultFor = 1;
	for (int i = 1; i <= M; i++) {
		ResultFor *= N;	
	}
	int ResultWhile = 1;
	int TempWhile = 1; /*змінна, що характерізує кількість разів множення N самого на себе, доки ступінь не стане М*/
	while (tempwhile <= M) {
		resultwhile *= N;
		tempwhile++;
	}
	int ResultDo = 1;
	int TempDo = 1; /*змінна, що характерізує кількість разів множення N самого на себе, доки ступінь не стане М*/
	do {
		ResultDo *= N;
		TempDo++;
	} while (TempDo <= M);
return 0; 
