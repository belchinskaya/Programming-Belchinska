#pragma once
/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 *
 * @author Belchynska K.
 * @date 19-dec-2020
 * @version 1.0
 */

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
/**
 * Функція {@link getWordCount}
 * - обчислення кількості пропусків в тексті
 * - кількість слів - кількість пропусків + 1
 * @param stringIn
 * @param sym
 * @return кількість слів
 */
int getWordCount(char* stringIn, char sym);

/**
 * Функція {@link sortWord}
 * @param stringIn
 * @param arraySize
 */
void sortWord(char** stringIn, int arraySize);