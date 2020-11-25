#include <stdio.h>
#include <time.h>
void numWords(char strIn[], int len);
int main() {
	srand(time(NULL));
	int const len = 6;
	char strIn[len];
	
	for (int i = 0; i < len - 1; i++) {
		strIn[i] = rand() % 24 + 11;//заповнюємо заданий масив рандомними символами
	}
	strIn[len - 1] = '\0';
	
	
	
	numWords(strIn, len);
	return 0;
}


void numWords(char strIn[], int len) {
	
	int count = 0;
	char strOut[len];
	for (int i = 0; i < len;) {//копіюємо заданий масив, щоб використовувати його у функції
		for (int j = 0; j < len; j++) {
			strOut[i] = strIn[j];
			i++;
		}
	}
	for (int i = 0; i < len; i++) {//знайдемо кількість слів за допомогою останньої букви слова
		if (strOut[i] != ' ' && (strOut[i + 1] == ' ' || strOut[i + 1] == '\0')) {
			count++;
		} 
	}
	
} 
