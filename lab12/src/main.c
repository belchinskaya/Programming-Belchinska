/**
 * @mainpage
 * # Загальне завдання
 * **Створити** програму з використанням показчиків;
 *
 * # Індивідуальне завдання
 * **Підрахувати** кількість ділянок заданого масиву з N речовинних чисел, які утворюють безперервні послідовності чисел з незменшуваними значеннями. Максимальну ділянку переписати в інший масив.
 *
 * @author Belchynska K.
 * @date 23-feb-2021
 * @version 1.0
 */
 
 /**
 * @file main.c
 * @brief Файл з викликом усіх функцій
 * використаних для заповнення результуючого масиву і підрахування кількості ділянок
 * @author Belchynska K.
 * @date 23-feb-2021
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
    printf("Лабораторна робота #12 \nБельчинська Катерина\n");
    puts("Взаємодія з користувачем шляхом механізму введення-виведення");
    fwrite("КІТ-320", sizeof(char), 9, stdout);
    int N;
   //long N3;
    //char N2;
    //char lenStr[2];
    //lenStr[0] = N2;
    //lenStr[1] = '\0';
    printf("\nВведіть довжину масиву: ");



    scanf("%d", &N);
    //N2 = getc(stdin);
    //N3 = strtol(lenStr, NULL, 10);

	float* arrayIn = (float*)malloc(N * sizeof(float));
	fillArrOne(arrayIn, N);

	int countOfSequences = countOfIncreasingSequences(arrayIn, N);

    printf("\nКількість незменшуваних послідовностей: %d", countOfSequences);

	int startOfMaxIncreasingSequence = 0;
	int lenOut = findMaxIncreasingSequence(arrayIn, N, &startOfMaxIncreasingSequence);

	float * arrayOut1 = (float *)malloc(lenOut * sizeof(float ));

	fillArrayOut(arrayIn, startOfMaxIncreasingSequence, arrayOut1, lenOut);


	//fwrite(&countOfSequences, sizeof(countOfSequences), 1, stderr);
    //char sCountOfSequences[50];
    //printf( "Кількість послідовностей: %d", countOfSequences);



    //puts("Результуючий масив: ");



    printArrayOut(arrayIn, startOfMaxIncreasingSequence, arrayOut1, lenOut);
    free(arrayIn);
    free(arrayOut1);
	return 0;
}

