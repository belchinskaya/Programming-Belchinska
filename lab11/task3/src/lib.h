#pragma once

/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 * для обчислення кількості незменшуванних ділянок, визначення максимальної та переписувааня її у інший масив
 *
 * @author Belchynska K.
 * @date 09-dec-2020
 * @version 1.0
 */
#include <stdlib.h>
#include <time.h>

/**
* Довжина заданого масиву
*/
#define N 10

/** 
* Заповнення заданого масиву псевдовипадковими речовинними числами {@link arrayIn}
*/
void fillArrOne(float* arrayIn, int lenIn);

/**
* {@link count} підраховує кількість ділянок в заданому масиві з незменшуванними значеннями 
* @return {@link count} кількість необхідних ділянок
*/
int countOfIncreasingSequences(float* arrayIn, int lenIn);

/**
* Визначення кількості елементів у найдовшій незменшуваній ділянці
* @return довжину найбільшої ділянки
*/
int findMaxIncreasingSequence(float* arrayIn, int lenIn, int* startOfMaxIncreasingSequence);

/**
* заповнення результуючого масиву максимальною послідовністю
*/
void fillArrayOut(float* arrayIn, int start, float* arrayOut, int lenOut);
