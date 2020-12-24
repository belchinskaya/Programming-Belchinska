/**
 * @mainpage
 * # Індивідуальне завдання
 * @brief Текст - це перелік прізвищ студентів через кому.
 * **Видалити** з тексту усі дублікати.
 *
 * @author Belchynska K.
 * @date 19-dec-2020
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Головний файл з викликом функцій,
 * виділенням пам'яті для динамічних масивів та заданням вхідного тексту.
 *
 * @author Belchynska K.
 * @date 19-dec-2020
 * @version 1.0
 */
#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - задання тексту для виконання завдання {@link phrase}
 * - обчислення кількості слів {@link temp1}
 * - звільнення пам'яті для масиву вказівників на масив вазівників {@link strIn}
 * - звільнення пам'яті для масиву вказівників на строки та заповнення строк словами із заданого тексту
 * - визначення довжини прізвища 
 * - виклик функції {@link sortSequence}
 * - виклик функції {@link deleteRepeat}
 * - виклик функції для заповнення результуючого масиву {@link fillArrayOut}
 * - звільнення пам'яті для викорастоного динамічного масиву
 * @return успішний код повернення з програми (0)
 */
int main() {
	char surname[] = "Бібік,Акулібаба,Зажерило,Бібік,Черепок,Чупилко,Гаврик,Шжопов,Шмонько,Гаврик";
	char *p_surname = surname;

	int comaCount = getComaCount(p_surname);
	int temp1 = comaCount + 1;

	char **strIn = (char**) malloc(temp1 * sizeof(char*));
	char *temp = strtok(p_surname, ",");
	int count = 0;
	int i = 0;
	*(strIn + i) = (char*) malloc ((strlen(temp) + 1) * sizeof(char));
	strcpy(*(strIn + i), temp);
	i++;

    
	while (p_surname != NULL) {
		count += strlen(p_surname) + 1;
		p_surname = surname;
		p_surname = strtok(p_surname + count, ",");
		if (p_surname == NULL) {
			break;
        	}
		*(strIn + i) = (char*) malloc((strlen(p_surname) + 1) * sizeof(char));
		strcpy(*(strIn + i), p_surname);
		i++;
	}

	sortSequence(strIn, temp1);
	int lenResult = deleteRepeat(strIn, temp1);
	char* result = (char*) malloc (lenResult * sizeof(char));
	for (int i = 0; i < lenResult; i++) {
		*(result + i) = '\0';
	}
	fillArrayOut(strIn, temp1, result);

	for (int i = 0; i < temp1; i++) {
		free(*(strIn + i));
	}
	free(strIn);
	free(result);
	return 0;
}
