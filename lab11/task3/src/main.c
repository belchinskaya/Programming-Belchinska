/**
 * @mainpage
 * # Загальне завдання
 * 1. **Створити** програму з використанням показчиків;
 *
 * 2. **Підрахувати** кількість ділянок заданого масиву з N речовинних чисел, які утворюють безперервні послідовності чисел з незменшуваними значеннями. Максимальну ділянку переписати в інший масив.
 *
 * @author Belchynska K.
 * @date 09-dec-2020
 * @version 1.0
 */
 
 /**
 * @file main.c
 * @brief Файл з викликом усіх функцій
 * використаних для заповнення результуючого масиву і підрахування кількості ділянок
 * @author Belchynska K.
 * @date 09-dec-2020
 * @version 1.0
 */
#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - виділення пам'яті для заданого масиву речовиних чисел 
 * {@link arrayIn}
 * - виклик функції для заповнення заданого масиву псевдовипадковими числами 
 * {@link fillArrayIn}
 * - виклик функції, що оприділяє кількість незменшуваних послідовностей 
 * {@link countOfIncreasingSequences}
 * - виклик функції, що визначає максимальну довжину ділянки 
 * {@link findMaxIncreasingSequence}
 * - виділення пам'ті під результуючий масив 
 * {@link arrayOut}
 * - виклик функції, що заповнює результуючий масив 
 * {@link fillArrayOut}
 * @return успішний код повернення з програми (0)
 */

int main() {
	float* arrayIn = (float*)malloc(N * sizeof (float));
	fillArrIn(arrayIn, N);

	int countOfSequences = countOfIncreasingSequences(arrayIn, N);

	int startOfMaxIncreasingSequence = 0;
	int lenOut = findMaxIncreasingSequence(arrayIn, N, &startOfMaxIncreasingSequence);

	float* arrayOut = (float*)malloc(lenOut * sizeof(float));
	fillArrayOut(arrayIn, startOfMaxIncreasingSequence, arrayOut, lenOut);


	return 0;
}
