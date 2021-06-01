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
#include <stdbool.h>
#define INSTRUMENT_COUNT 6

enum Material {BT = 1, PERNAMBUCO = 2, FIBERGLASS = 3};

struct Bow {
    int weight;
    enum Material material;
};

/**
 * Структура інструментів, включає до себе тип інструменту, фірму та рік виготовленя
 */
struct Instrument {
    //char type[15];
    char firm[15];
    int year;
    float size;
    //struct Bow bow;

};

struct Instrument* readFromFile(FILE * fileIn);

void writeInFile(FILE * fileOut, struct Instrument* instruments);
void printDoubleWordInstrument(struct Instrument * instruments);
bool isValidInstrument(struct Instrument * instruments);


