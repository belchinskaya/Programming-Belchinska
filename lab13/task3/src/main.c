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

    char text[] = "abbcccddddaaabbbb";
    char* pText = text;

    int textLength = countTextLength(pText);
    int uniqueElCount = countOfUniqueElements(pText, textLength);

    char* symbols = (char*) malloc ((uniqueElCount + 1) * sizeof(char));
    int* symbolsCounts = (int*) malloc (uniqueElCount * sizeof(int));
    double* symbolsFrequency = (double*) malloc (uniqueElCount * sizeof(double));
    fillZeros(symbolsCounts, uniqueElCount);

    getsymbols(pText, textLength, symbols, uniqueElCount);
    getSymbolsCounts(pText, textLength, symbols, symbolsCounts, uniqueElCount);
    getSymbolsFrequencies(symbolsCounts, symbolsFrequency, uniqueElCount, textLength);





    free(pText);
    free(symbols);
    free(symbolsCounts);
    free(symbolsFrequency);
    return 0;
}

