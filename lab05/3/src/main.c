#define NUM 123456
int main () {
	int result_for = 0;
	int num123_for = 0;
	int num456_for = 0;
	int result_while = 0;
	int num123_while = 0;
	int num456_while = 0;
	int result_do = 0;
	int num123_do = 0;
	int num456_do = 0;
	int half  =  NUM % 1000;
	for (int i = 1000; (NUM / i) > 0; i *= 10) { /* цикл відокремлює перші три цифри даного числа та сумує їх, знаходимо перше число “щасливого” квитку */
 		num123_for += NUM / i  % 10;
	}
	for (int j = 1; (half / j) > 0; j *= 10) { /* цикл відокремлює останні три цифри даного числа та сумує їх, знаходимо друге число “щасливого” квитку*/

 		num456_for += half / j % 10;
	}
	if (num123_for == num456_for) { // порівняння двох отриманих чисел
 		result_for = 1; // якщо квиток “щасливий”
	} else {
		result_for = -1;// якщо квиток не “щасливий”
	}

	int temp1_while = 1000; // змінна, що відокремлює перші три цифри даного числа, щоб сумувати їх у циклі
	while ((NUM / temp1_while) > 0) {
		num123_while += NUM / temp1_while  % 10;
		temp1_while *= 10;
	}
	int temp2_while = 1; // змінна, що відокремлює останні три цифри даного числа, щоб сумувати їх у циклі
	while ((half / temp2_while)  > 0) {
		num456_while += half / temp2_while % 10;
		temp2_while *= 10;
	}
	if (num123_while == num456_while) { // порівняння двох отриманих чисел
		result_while = 1; // якщо квиток “щасливий”
	} else {
		result_while = -1;// якщо квиток не “щасливий”
	}


	int temp1_do = 1000; // змінна, що відокремлює перші три цифри даного числа, щоб сумувати їх у циклі
	do {
		num123_do += NUM / temp1_do  % 10;
		temp1_do *= 10;
	} while ((NUM / temp1_do) > 0);
	int temp2_do = 1; // змінна, що відокремлює останні три цифри даного числа, щоб сумувати їх у цикл
	do {
		num456_do += half / temp2_do % 10;
		temp2_do *= 10;
	} while ((half / temp2_do)  > 0);
	if (num123_do == num456_do) { // порівняння двох отриманих чисел
		result_do = 1; // якщо квиток “щасливий”
	} else {
		result_do = -1;// якщо квиток не “щасливий”
	}
return 0;
}
