/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 *
 * @author Belchynska K.
 * @date 19-dec-2020
 * @version 1.0
 */
#pragma once

#include <stdlib.h>
#include <string.h>

/**
 * Функція {@link getComaCount}
 * @param arr1 - функція приймає заданий масив прізвищ
 * @return кількість ком у тексті
 */
int getComaCount(char * arr1);

/**
 * Функція {@link sortSequence}
 * @brief сортування прізвищ
 * для встановлення повторів один біля одного
 * @param strIn приймає масив вказівників на масив вказівників на строки
 * @param arraySize приймає довжину цього масиву
 */
void sortSequence(char ** strIn, int arraySize);

/**
 * Функція {@link deleteRepeat}
 * @brief заповнення строк-повторів '\0'
 * та заповнення результуючого прізвищами без повторів {@link textOut}
 * @param strIn приймає масив вказівників на масив вказівників на строки
 * @param arraySize приймає довжину цього масиву
 */
void deleteRepeat(char ** strIn, int arraySize);