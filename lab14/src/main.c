/**
 * @mainpage
 * # Індивідуальне завдання
 * @brief **Вирахувати**  для тексту частотну таблицю:
 * для кожного символу визначити його частоту появи у тексті (число таких символів у тексті ділене на загальне число символів у тексті).
 *
 * @author Belchynska K.
 * @date 20-dec-2020
 * @version 1.0
 */



/**
 * @file main.c
 * @brief Головний файл з викликом функцій,
 * виділенням пам'яті для динамічних масивів та заданням вхідного тексту.
 *
 *
 * @author Belchynska K.
 * @date 20-dec-2020
 * @version 1.0
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - завдання вхідного тексту
 * - виклик функції для обчислювання довжини вхідного тексту
 * - виклик функції для знаходженя кількості унікальних (неповторюваних) елементів
 * - звільнення пам'яті для масиву заповнення унікальними символами
 * - звільнення пам'яті для запису частоти з з'явлення кожного символу
 * - виклик функції для заповнення масиву унікальними символами
 * - виклик функції для заповнення масиву частотою виявлення кожного символу
 *
 * @return 0 при успішному завершенні програми
 */


int main() {


    char* filenameIn = (char*)malloc(100 * sizeof(char));
    char* filenameOut = (char*)malloc(100 * sizeof(char));

    char* pText = (char*)malloc(10000 * sizeof(char));

    printf("Введіть назву файлу для вирахування частоти: \n" );
    scanf("%s", filenameIn);
    printf("Введіть назву файлу для запису результату: \n" );
    scanf("%s", filenameOut);

    //readFromFile(filenameIn, pText, 100);
//
    FILE *file = fopen(filenameIn, "r");
    int textLength = getFileLength(file);
    readFromFile(filenameIn, pText, textLength);
    int uniqueElCount = countOfUniqueElements(pText, textLength);

    char* symbols = (char*) malloc ((uniqueElCount + 1) * sizeof(char));
    int* symbolsCounts = (int*) malloc (uniqueElCount * sizeof(int));
    float* symbolsFrequency = (float*) malloc (uniqueElCount * sizeof(float));




    fillZeros(symbolsCounts, uniqueElCount);
    getSymbols(pText, textLength, symbols, uniqueElCount);
    getSymbolsCounts(pText, textLength, symbols, symbolsCounts, uniqueElCount);
    getSymbolsFrequencies(symbolsCounts, symbolsFrequency, uniqueElCount, textLength);



    writeToFile(file, filenameOut, symbolsFrequency, uniqueElCount);
    char* dirName = (char*)  malloc (100 * sizeof(char));
    printf("Введіть назву файлу для зчитування: \n");
    scanf("%s", dirName);
    listdir(dirName, 0);

//
    free(pText);
    free(symbols);
    free(symbolsCounts);
    free(symbolsFrequency);
    free(filenameIn);
    free(filenameOut);
    free(dirName);
    return 0;
}

