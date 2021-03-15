/**
 * @mainpage
 * # Індивідуальне завдання
 * @brief З розділу “Розрахункове завдання / Індивідуальні завдання”
 * взяти прикладну галузь стосовно номеру варіанту за попередньо-визначеною формулою. Створити структуру, що відображає “базовий клас” число символів у тексті).
 *
 * @author Belchynska K.
 * @date 02-march-2021
 * @version 1.0
 */
#include "lib.h"

/**
 * @file main.c
 * @brief Головний файл з викликом функцій,
 * виділенням пам'яті для динамічних масивів та заданням вхідного тексту.
 *
 *
 * @author Belchynska K.
 * @date 02-march-2021
 * @version 1.0
 */

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - виділення пам'яті для структури інструментів
 * - зчитування інформації з файлу
 * - виклик функції для сортування інструментів за роком випуску
 * - виклик функції для виведеня на екран найстаршої скрипки фірми Yamaha
 * - виклик функції для запису результату у файл
 * - виклик функції для запису результату у бінарний файл
 * - звільнення пам'яті для структури інструментів
 *
 * @return 0 при успішному завершенні програми
 */
int main() {
    //FILE * file = fopen("/home/kate/Programming-Belchynska/lab15/InstrumentsOut.txt", "r");
    struct Instrument ** instruments = malloc(INSTRUMENT_COUNT * sizeof(struct Instrument* ));
    for (int i = 0; i < 200; i++) {
        *(instruments + i) = malloc(sizeof(struct Instrument));
    }
//    struct Bow ** bows = malloc(6 * sizeof(struct Bow ));
//    for (int i = 0; i < 200; i++) {
//        *(bows + i) = malloc(sizeof(struct Bow));
//    }
    //struct Bow* bow1 = malloc(sizeof(struct Bow));

    readFromFile(instruments);
    sortByYear(instruments);
    //printInstrument(instruments, bows);
    printTheOldestInstrument(instruments);
    writeInFile(instruments);
    writeToBinaryFile(instruments);
    readFromBinary( instruments);



    free(instruments);
    //free(bow1);

    return 0;
}


