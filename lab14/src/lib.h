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
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
/**
 *
 * Функція для обчислення довжини заданого масиву
 *
 * @param arr приймає заданий масив
 * @return довжину масиву
 */
int getFileLength(FILE* file);

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
void getSymbols(char* strIn, int sizeIn, char* symbols, int sizeOut);

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
 * Функція ініціолізує результуючий масив
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
void getSymbolsFrequencies(int* elCounts, float* elFreaqs, int size, int totalCount);

int getFileLength();

void readFromFile(char* filename, char* pText, int bufSize);
void writeToFile(FILE* f, char* filename, float* arr, int size);

void listdir(const char *name, int indent);
