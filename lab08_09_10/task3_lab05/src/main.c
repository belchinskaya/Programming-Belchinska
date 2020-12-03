#include <stdio.h>
#include <time.h>

int compare_nums(int num);//попереднє оголошення функції
int main() {
	srand(time(NULL));
	
	int num = rand() % 899999 + 100000;//генерація псевдорандомного числа

	
	int result = compare_nums(num);//функція порівнює дві половини числа
	

	return 0;
}

int compare_nums(int num) {
	int sum_half1 = 0;
	for (int i = 1000; (num / i) > 0; i *= 10) { /* цикл відокремлює перші три цифри даного числа та сумує їх, знаходимо перше число “щасливого” квитку */
		sum_half1 += num / i  % 10;
	}
	
	int half = num % 1000;
	int sum_half2 = 0;
	for (int j = 1; (half / j) > 0; j *= 10) { /* цикл відокремлює останні три цифри даного числа та сумує їх, знаходимо друге число “щасливого” квитку*/
 		sum_half2 += half / j % 10;
	}
	
	
	
	int temp1_while = 1000; // змінна, що відокремлює перші три цифри даного числа, щоб сумувати їх у циклі
	int num123_while = 0;
	while ((num / temp1_while) > 0) {
		num123_while += num / temp1_while  % 10;
		temp1_while *= 10;
	}
	int temp2_while = 1; // змінна, що відокремлює останні три цифри даного числа, щоб сумувати їх у циклі
	int num456_while = 0;
	while ((half / temp2_while)  > 0) {
		num456_while += half / temp2_while % 10;
		temp2_while *= 10;
	}
	
	
	
	int temp1_do = 1000; // змінна, що відокремлює перші три цифри даного числа, щоб сумувати їх у циклі
	int num123_do = 0;
	
	do {
		num123_do += num / temp1_do  % 10;
		temp1_do *= 10;
	} while ((num / temp1_do) > 0);
	int temp2_do = 1; // змінна, що відокремлює останні три цифри даного числа, щоб сумувати їх у цикл
	int num456_do = 0;
	do {
		num456_do += half / temp2_do % 10;
		temp2_do *= 10;
	} while ((half / temp2_do)  > 0);
	
	int result = -1;
	
	

	if (sum_half1 == sum_half2 && num123_while == num456_while && num123_do == num456_do) { // порівняння двох отриманих чисел
 		result = 1; // якщо квиток “щасливий”
 		
 		
	} else {
		result = -1;// якщо квиток не “щасливий”
		
		
	}
	
	return result;
}
	
	


