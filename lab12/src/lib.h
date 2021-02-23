#pragma once

/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 * для обчислення кількості незменшуванних ділянок, визначення максимальної та переписувааня її у інший масив
 *
 * @author Belchynska K.
 * @date 23-feb-2021
 * @version 1.0
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <syscall.h>
#include <string.h>
/**
* Довжина заданого масиву
*/


/** 
* Заповнення заданого масиву псевдовипадковими речовинними числами {@link arrayIn}
*/
void fillArrOne(float * arrayIn, int lenIn);

/**
* {@link count} підраховує кількість ділянок в заданому масиві з незменшуванними значеннями 
* @return {@link count} кількість необхідних ділянок
*/
int countOfIncreasingSequences(float * arrayIn, int lenIn);

/**
* Визначення кількості елементів у найдовшій незменшуваній ділянці
* @return довжину найбільшої ділянки
*/
int findMaxIncreasingSequence(float* arrayIn, int lenIn, int* startOfMaxIncreasingSequence);

/**
* заповнення результуючого масиву максимальною послідовністю
*/

void fillArrayOut(float* arrayIn, int start, float * arrayOut1, int lenOut);


void printArrayOut(float* arrayIn, int start, float * arrayOut, int arrayLength);