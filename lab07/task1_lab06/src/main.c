#include <stdlib.h>
#include <time.h>

#define LENOUT 15

void get_center(char strIn[], char zap, int lenIn);//попереднє оголошення  функції, функція не повертає результат в main
void get_center(char strIn2[], char zap, int lenIn);//попереднє оголошення  функції, функція не повертає результат в main

int main() {
	srand(time(NULL));
	
	int x = 97;
	char zap = '_';
	int y = 122;
		
	int range_for_rand;//з заданих чисел для рандому оприділити, що є кількістю чисел в діапазоні, а що є "відступ" від нуля
	int min_number_of_range;
	if (x < y) {
		range_for_rand = y - x + 1;
		min_number_of_range = x;
	} else if (y < x) {
		range_for_rand = x - y + 1;
		min_number_of_range = y;
	}
	int const lenIn = 5;// довжина заданого слова
	char strIn[lenIn];//масив з заданого слова
	

	for (int i = 0; i < lenIn - 1; i++) {
		strIn[i] = rand() % range_for_rand + min_number_of_range;//рандомне заповнення масиву
	}
	strIn[lenIn - 1] = '\0';



	char strIn2[lenIn];
	
	for (int i = 0; i < lenIn - 1; i++) {
		strIn2[i] = rand() % range_for_rand + min_number_of_range;
	}
	strIn2[lenIn - 1] = '\0';



	get_center(strIn, zap, lenIn);//функція змінює параметри всередені себе, але нічого не повертає
	get_center(strIn2, zap, lenIn);
	return 0;
}



void get_center(char strIn[], char zap, int lenIn) {//функція, яка центрує задане слово

	char strResult[LENOUT];
	int lenZap = LENOUT - lenIn;//кількість елементів в  масиві, виділених на заповнювач 
	int halfLenZap = lenZap / 2;//кількість заповнювачей перед заданм рядком


	for (int i = 0; i < halfLenZap; i++) {//в початок результуючого масиву вставимо необхідну кількість заповнювачей
		strResult[i] = zap;
	}

	for (int i = halfLenZap; i < halfLenZap + lenIn - 1;) {//вставимо заданий на початку текст по центру результуючого масиву
		for (int j = 0; j < lenIn; j++) {
			strResult[i] = strIn[j];
			i++;
		}
	}

	for (int i = (halfLenZap + lenIn - 1); i < LENOUT - 1; i++) {//додаємо у результуючий масив заповнювач до його кінця
		strResult[i] = zap;
	}
	
	strResult[LENOUT - 1] = '\0';//масив повинен закінчуватися '\0'
	if (lenIn % 2 == 1) {
		strResult[LENOUT - 2] = '\0';
	}
}
