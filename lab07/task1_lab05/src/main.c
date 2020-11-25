#include <stdlib.h>
#include <time.h>
int get_nod_while(int num1, int num2);//попереднє оголошення функції
int get_nod_for(int num1, int num2);//попереднє оголошення функції
int get_nod_do(int num1, int num2);//попереднє оголошення функції

int main() {
	srand(time(NULL));

	int x = rand() % 23 + 2;
	int y = rand() % 23 + 2;
	
	int result_while = get_nod_while(x, y);//повертаємо результат функціїї
	int result_for = get_nod_for(x, y);//повертаємо результат функціїї
	int result_do = get_nod_do(x, y);//повертаємо результат функціїї

	return 0;
}


int get_nod_while(int num1, int num2) {//функція, яка знаходить найбільший спільний дільник з циклу while do
	int nod_while = 0;
	while (num1 > 0 && num2 > 0) {
		if (num1 > num2) {
			num1 %= num2;
		} else if (num1 < num2) {
			num2 %= num1;
		}
	nod_while = num1 + num2;
	}
	int result_while = nod_while;
	return result_while;//повертаємо результат у функцію main
}

int get_nod_for(int num1, int num2) {//функція, яка знаходить найбільший спільний дільник з циклу for
	int nod_for = 0;
	for (; num1 > 0 && num2 > 0;) {
		(num1 > num2) ? (num1 %= num2) : (num2 %= num1);
		nod_for = num1 + num2;
	}
	int result_for = nod_for;
	return result_for;//повертаємо результат у функцію main
}

int get_nod_do(int num1, int num2) {//функція, яка знаходить найбільший спільний дільник з циклу do while
	int nod_do = 0;
	do {
		if (num1 > num2) {
			num1 %= num2;
		} else if (num1 < num2) {
			num2 %= num1;
		}
	nod_do = num1 + num2;
	} while (num1 > 0 && num2 > 0);
	int result_do = nod_do;
	return result_do;//повертаємо результат у функцію main
}
