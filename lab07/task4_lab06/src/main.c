#include <stdlib.h>
#include <time.h>
#define LEN 6
int getNumWords(char strIn[]);
int main() {
	srand(time(NULL));
	
	char strIn[LEN];
	
	for (int i = 0; i < LEN - 1; i++) {
		strIn[i] = rand() % 39 + 32;//заповнюємо заданий масив рандомними символами
	}
	strIn[LEN - 1] = '\0';
	
	int numWords = getNumWords( strIn);
	

	return 0;
}


int getNumWords(char strIn[]) {
	
	int count = 0;
	
	for (int i = 0; i < LEN; i++) {//знайдемо кількість слів за допомогою останньої букви слова
		if (strIn[i] != ' ' && (strIn[i + 1] == ' ' || strIn[i + 1] == '\0')) {
			count++;
		} 
	}
	return count;
} 
