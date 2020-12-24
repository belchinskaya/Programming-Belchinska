/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 20-dec-2020
 * @version 1.0
 */
#include "lib.h"

int countOfDigits(char *in) {
	char *text = (char*) malloc ((strlen(in) + 1) * sizeof(char));
	strcpy(text, in);

	int result = 0;
	int elCount = 0;
	
	while (true) {
		text = strpbrk(text, "0123456789");
		if (text != NULL) {
			result++;
			elCount = strspn(text, "0123456789");
			text = text + elCount;
		} else {
			break;
		}
	}
		

	return result;
}

void fillArrayByDigits(int *out, char *in, int count) {
	for (int i = 0; i < count; i++) {
		in = strpbrk(in, "0123456789");
		int temp = strspn(in, "0123456789");
		*(out + i) = atoi(in);
		in = in + temp;
	}
}
