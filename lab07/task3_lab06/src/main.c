#include <stdlib.h>
#include <time.h>
int compareNums(int arrayNums[], int len);//попереднє оголошення масиву для порівняння чисел
int copyOne(char numAsString[], int iStart, char numStr[], int sizeWord) {/*масив переписує потрібні значення у результуючий масив (числівник або розряд) починаючи з першого незаповненого елементу*/
	for (int t = 0; t < sizeWord; t++) {
		numAsString[iStart] = numStr[t];
		iStart++;
	}
	return iStart;//після будь-якого заповнення елементу наступне заповнення починається з пустого елементу
}

int copyNum(int num, char numAsString[], int iStart) {/*виходячи з того, що за цифра, виділяємо кількість елементів в масиві для запису назви числа*/
	char one[3] = {'o','n','e'};
	char two[3] = {'t','w','o'};
	char three[5] = {'t','h','r','e','e'};
	char four[4] = {'f','o','u','r'};
	char five[4] = {'f','i','v','e'};
	char six[3] = {'s','i','x'};
	char seven[5] = {'s','e','v','e','n'};
	char eight[5] = {'e','i','g','h','t'};
	char nine[4] = {'n','i','n','e'};
	switch (num) {
		case 1:
			iStart = copyOne(numAsString, iStart, one, 3);
			break;
		case 2:
			iStart = copyOne(numAsString, iStart, two, 3);
			break;
		case 3:
			iStart = copyOne(numAsString, iStart, three, 5);
			break;
		case 4:
			iStart = copyOne(numAsString, iStart, four, 4);
			break;
		case 5:
			iStart = copyOne(numAsString, iStart, five, 4);
			break;
		case 6:
			iStart = copyOne(numAsString, iStart, six, 3);
			break;
		case 7:
			iStart = copyOne(numAsString, iStart, seven, 5);
			break;
		case 8:
			iStart = copyOne(numAsString, iStart, eight, 5);
			break;
		case 9:
			iStart = copyOne(numAsString, iStart, nine, 4);
			break;
		}
	return iStart;
}


void fillStr(char numAsString[], int numIn) {//заповнюємо масив назвами числа та розряду
	short size = 0;
	int num = numIn;
	char thousand[10] = {' ','t','h','o','u','s','a','n','d',' '};
	char hundred[9] = {' ','h','u','n','d','r','e','d',' '};
	char decade[8] = {' ','d','e','c','a','d','e',' '};
	int cond = 0;

	for (int i = 10000; i > 0; i /= 10) {//оприділяємо розрядність заданого числа
		if (num > 0) {
			cond = num % i;
			if (cond != num) {
				size++;
			}
			num %= i;
		}
	}

	num = numIn;
	int iStart = 0;

	if (size == 4) {
		num = numIn / 1000;
		iStart = copyNum(num, numAsString, iStart);//число
		iStart = copyOne(numAsString, iStart, thousand, 10);//разряд
		size--;
		num = numIn % 1000;
	}
	if (size == 3) {
		num = num / 100;
		iStart = copyNum(num, numAsString, iStart);
		iStart = copyOne(numAsString, iStart, hundred, 9);
		size--;
		num = num % 100;
	}

	if (size == 2) {
		num = num / 10;
		iStart = copyNum(num, numAsString, iStart);
		iStart = copyOne(numAsString, iStart, decade, 8);
		size--;
	}

	if (size == 1) {
		num = num % 10;
		iStart = copyNum(num, numAsString, iStart);
		numAsString[iStart] = '\0';
	}
}

int main() {
	srand(time(0));
	int numIn = rand() % 9999 + 1;
	char arr[50] = {0};/*усі дії у функції будуть проходити з цим масивом*/
	fillStr(arr, numIn);
	
	
	
	const int len = 5;//довжинна масиву для порівняння чисел поряд
	char arrayNums[len];
	int numOfCompare = compareNums(arrayNums, len);
	
	return 0;
	
	
}

int compareNums(int arrayNums[], int len) {//порівняти число з наступним, порахувати кількість пар де наступне число більше минулого
	int count = 0;
	for (int j = 0; j < len - 1; j++) {//рандомними числами заповнюємо масив
		arrayNums[j] = rand() % 5 - 2;
	}
	for (int i = 0; i < len - 1; i++) {//порівнюємо числа поряд
		if (arrayNums[i] < arrayNums[i + 1]) {
			count++;
		}
	}
	return count;//повертаємо результат у функцію main
}
