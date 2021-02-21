/**
 * @mainpage
 * # Загальне завдання
 * **Створити** програму з використанням показчиків;
 *
 * # Індивідуальне завдання
 * **Підрахувати** кількість ділянок заданого масиву з N речовинних чисел, які утворюють безперервні послідовності чисел з незменшуваними значеннями. Максимальну ділянку переписати в інший масив.
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
 * - виділення пам'яті під результуючий масив
 * {@link arrayOut}
 * - виклик функції, що заповнює результуючий масив 
 * {@link fillArrayOut}
 * @return успішний код повернення з програми (0)
 */

int main() {
    printf("Лабораторна робота #12 \"Взаємодія з користувачем шляхом механізму введення-виведення\"\nБельчинська Катерина\n");
    int N;

    printf("Введіть довжину масиву: ");


    scanf("%d", &N);




	float* arrayIn = (float*)malloc(N * sizeof(float));
	fillArrOne(arrayIn, N);

	int countOfSequences = countOfIncreasingSequences(arrayIn, N);

	int startOfMaxIncreasingSequence = 0;
	int lenOut = findMaxIncreasingSequence(arrayIn, N, &startOfMaxIncreasingSequence);

	char * arrayOut1 = (char *)malloc(lenOut * sizeof(char));

	fillArrayOut(arrayIn, startOfMaxIncreasingSequence, arrayOut1, lenOut);


	//fwrite(&countOfSequences, sizeof(countOfSequences), 1, stderr);
    char sCountOfSequences[50];
    printf(sCountOfSequences, "%d", countOfSequences);
    puts(sCountOfSequences);

    printf("\nРезультуючий масив:\n");



    printArrayOut(arrayIn, startOfMaxIncreasingSequence, arrayOut1, lenOut);

	return 0;
}

