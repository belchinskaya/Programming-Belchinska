/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 *
 * @author Belchynska K.
 * @date 19-dec-2020
 * @version 1.0
 */
#pragma once


#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

/**
 *
 * Функція для обчислення довжини заданого масиву
 *
 * @param arr приймає заданий масив
 * @return довжину масиву
 */
int countTextLength(char* arr);

/**
 *
 * Функція обчислює кількість унікальних елементів
 *
 * @param arr приймає заданий масив
 * @param size приймає розмір заданого масиву
 * @return кількість унікальних елементів
 */
int countOfUniqueElements(char* arr, int size);

/**
 *
 * Функція перевіряє кожен елемент на повтори
 *
 * @param arr приймає заданий масив
 * @param currentIndex приймає номер елементу в заповнюванному масиві
 * @param value елемент, який перевіряється на унікальність
 * @return true/false в залежності від знаходження повторів
 */
bool checker(char* arr, int currentIndex, char value);

/**
 *
 * Функція переписує унікальні елементи в масив
 * @param strIn приймає заданий масив
 * @param sizeIn приймає довжину заданого масиву
 * @param symbols приймає унікальні символи
 * @param sizeOut приймає розмір результуючого масиву
 */
void getsymbols(char* strIn, int sizeIn, char* symbols, int sizeOut);

/**
 *
 * Функція отримує кількість повторів кожного елементу
 * @param strIn приймає заданий масив
 * @param sizeIn приймає довжину заданого масиву
 * @param elements приймає масив унікальних елементів
 * @param elCounts приймає кількість унікальних елементів
 * @param sizeOut приймає довжину результуючого масиву
 */
void getSymbolsCounts(char* strIn, int sizeIn, char* elements, int* elCounts, int sizeOut);

/**
 * Функція ініцолізує результуючий масив
 * @param arr приймає заданий масив
 * @param size приймає довжину заданого масиву
 */
void fillZeros(int* arr, int size);

/**
 *
 * Функція вираховує та записує в масив частоту появи кожного елементу
 * @param elCounts
 * @param elFreaqs
 * @param size
 * @param totalCount
 */
void getSymbolsFrequencies(int* elCounts, double* elFreaqs, int size, int totalCount);
