/**
 * @mainpage
 * # Індивідуальне завдання
 * @brief **Знайти** всі числа, що зустрічаються в тексті
 *
 * @author Belchynska K.
 * @date 20-dec-2020
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Головний файл з викликом функцій,
 * виділенням пам'яті для динамічних масивів та заданням вхідного тексту.
 *
 *
 * @author Belchynska K.
 * @date 20-dec-2020
 * @version 1.0
 */
#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - завдання масиву с текстом
 * - виділення пам'яті для результуючого масиву
 * - виклик функції для знаходження чисел
 * - виклик функції для заповнення результуючого масиву
 * @return 0 при успішному завершенні програми
 */

int main() {
	char text[] = "3when76 you're 123 1 r567ead4y 548 , 9 come &677 get itÎ";
	char *ptext = text;

	int digitCount = countOfDigits(ptext);

	int *arr = (int*) malloc (digitCount * sizeof(int));

	fillArrayByDigits(arr, ptext, digitCount);

	return 0;
}
