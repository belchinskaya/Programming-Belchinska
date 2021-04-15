/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 *
 * @author Belchynska K.
 * @date 17-march-2021
 * @version 1.0
 */
#pragma once
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#define INSTRUMENT_COUNT 6



//struct TestElement{
//    int id;
 //   char data[30];
//};






//long fileSize(FILE * file);


enum Material {BT = 1, PERNAMBUCO = 2, FIBERGLASS = 3};
//static char material[3][20] = {"Brazilian Tree", "Pernambuco", "Fiberglass"};

struct Bow {
    int weight;
    enum Material material;
};

/**
 * Структура інструментів, включає до себе тип інструменту, фірму та рік виготовленя
 */
struct Instrument {
    char type[15];
    char firm[15];
    int year;
    float size;
    struct Bow bow;

};

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


/**
 * Функція записує у бінарний файл  відсортовані елементи
 * @param instrument
* @return
 */
void writeToBinaryFile(struct Instrument** instrument);

/**
 * Функція читає дані з бінарного файлу та виводить їх на екран
 * @param instrument вказівник на масив вказівників на кожен інструмент
 */
void readFromBinary(struct Instrument** instrument);

void print_result(int return_value);

