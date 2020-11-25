#include <stdio.h>
#include <time.h>

int get_sum_half1(int num);//попереднє оголошення функції
int get_sum_half2(int num);//попереднє оголошення функції
int compare_nums_for(int num1, int num2);//попереднє оголошення функції

int main() {
	srand(time(NULL));
	
	int num = rand() % 999999 + 100000;//генерація псевдорандомного числа

	int sum_half1 = get_sum_half1(num);//функція , яка сумує перші три цифри
	int sum_half2 = get_sum_half2(num);//функція , яка сумує перші три цифри
	int result_for = compare_nums_for(sum_half1, sum_half2);//функція порівнює дві половини числа


	return 0;
}

int get_sum_half1(int num) {
	int sum_half1 = 0;
	for (int i = 1000; (num / i) > 0; i *= 10) { /* цикл відокремлює перші три цифри даного числа та сумує їх, знаходимо перше число “щасливого” квитку */
		sum_half1 += num / i  % 10;
	}
	return sum_half1;
}
int get_sum_half2(int num) {
	int half = num % 1000;
	int sum_half2 = 0;
	for (int j = 1; (half / j) > 0; j *= 10) { /* цикл відокремлює останні три цифри даного числа та сумує їх, знаходимо друге число “щасливого” квитку*/
 		sum_half2 += half / j % 10;
	}
	return sum_half2;
}

int compare_nums_for(int num1, int num2) {

	int result_for = -1;
	//int sum_half1 = int get_sum_half1(int num);
	//int sum_half2 = int get_sum_half2(int num);
	if (num1 == num2) { // порівняння двох отриманих чисел
 		result_for = 1; // якщо квиток “щасливий”
	} else {
		result_for = -1;// якщо квиток не “щасливий”
	}
	return result_for;
}
