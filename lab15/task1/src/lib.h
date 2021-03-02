/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 *
 * @author Belchynska K.
 * @date 02-march-2021
 * @version 1.0
 */
#pragma one
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define INSTRUMENT_COUNT 6
/**
 *  Функція читає вхідні дані з файлу
 * @param i приймає вказівник на вказівники структури інструментів
 * @return вказівник на структуру елементів
 */
struct Instrument* readFromFile(struct Instrument** i);

//long fileSize(FILE * file);
/**
 * Структура інструментів, включає до себе тип інструменту, фірму та рік виготовленя
 */
struct Instrument {
    char type[15];
    char firm[15];
    int year;
};




//struct Instrument* printInstrument(struct Instrument** instrument);

/**
 * Функція сортує інструменти за роком виготовлення
 * @param instruments
 * @return вказівник на структури інструментів
 */
struct Instrument* sortByYear(struct Instrument** instruments);

/**
 *
 * @param instrument
 * @return вказівник на структури інструментів
 */
struct Instrument* printTheOldestInstrument(struct Instrument** instrument);

/**
 * Функція записує у файл  відсортовані елементи
 * @param instrument
 * @return вказівник на структури інструментів
 */
struct Instrument* writeInFile(struct Instrument** instrument);

/**
 * Функція записує у бінарний файл  відсортовані елементи
 * @param instrument
 * @return 
 */
void writeToBinaryFile(struct Instrument** instrument);