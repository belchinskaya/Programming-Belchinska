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
 * Вставка одного масиву у другий в задану позицію
 * @param arr1 масив, в який вписують
 * @param arrCenter масив, який вписують
 * @param position позиція, з якої вписують
 * @return
 */
//char * insert(char * arr1, char * arrCenter, size_t position);

/**
 * Видалення ділянки масиву заданого розміру
 * @param arr вхідний масив
 * @param start з якого елемента видаляти
 * @param end по який елемент видаляти
 * @return
 */
//char * delete_array(char * arr, size_t start, size_t end);

//struct Instrument* printInstrument(struct Instrument** instrument);
/**
 *  Функція читає вхідні дані з файлу
 * @param i приймає вказівник на вказівники структури інструментів
 * @return вказівник на структуру елементів
 */
struct Instrument* readFromFile(struct Instrument **i);

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
struct Instrument *writeInFile(struct Instrument **instrument);

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

/**
 * Скопіювати елемент з масиву інструментів
 * @param pInstrument вказівник на масив вказівників на кожен інструмент
 * @param bow
 * @param material
 */
void copyStructElement(struct Instrument** pInstrument, enum Material* material);

/**
 * Видалити елемент з масиву інструментів
 * @param pInstrument
 * @param bow
 * @param material
 */
void deleteStructElement(struct Instrument** pInstrument, enum Material* material);