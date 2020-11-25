#include <stdio.h>
#include <time.h>

int rootExtract(int num1);// попереднє об'явлення функції
int main() {
	srand(time(NULL));
	
	int numForRootExtract = rand() % 49 + 3;//генерація числа, корінь якого треба знайти

	int result = rootExtract(numForRootExtract);//результат - функція від заданого числа

	return 0;
}

int rootExtract(int num1) {//надання функції значення
	int root = 1;
	int num = num1;
	int temp = 0;

	while (temp != root) {
		temp = num / root;
		if (temp == root) {
			break;
		}
		root++;
	}
	int result = -1;//якшо помилка (з числа не можна знайти цілий корінь) - результат -1
	if ((root * root) == num1) {
		result = root;
	}
	return result;//якщо корінь помноженний на корінь дає задане число, повертаємо результат 
}
