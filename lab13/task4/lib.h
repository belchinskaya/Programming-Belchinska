/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 *
 * @author Belchynska K.
 * @date 19-dec-2020
 * @version 1.0
 */
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
/**
 * Функція рахує кількість чисел у тексті
 * Приймає:
 * @param in заданий масив
 * @return кількість чисел
 */
int countOfDigits(char *in);

/**
 * Функція заповнює результуючий масив числами
 * Приймає:
 * @param заданий масив
 * @param резульиуючий масив
 * @param кількість чисел
 */
void fillArrayByDigits(int *out, char *in, int count);
