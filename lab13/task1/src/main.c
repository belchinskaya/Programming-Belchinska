/**
 * @mainpage
 * # Індивідуальне завдання
 * @brief **Визначити**, скільки у тексті слів
 * (без використання ітерації по кожному символу у циклу). Видати всі слова за абеткою.
 *
 * @author Belchynska K.
 * @date 19-dec-2020
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Головний файл з викликом функцій,
 * виділенням пам'яті для динамічних масивів та заданням вхідного тексту.
 *
 * @author Belchynska K.
 * @date 19-dec-2020
 * @version 1.0
 */
#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - задання тексту для виконання завдання {@link phrase}
 * - виклик функції, яка обчислює кількість слів {@link getWordCount}
 * - звільнення пам'яті для масиву вказівників на масив вазівників {@link stringIn}
 * - звільнення пам'яті для масиву вказівників на строки та заповнення строк словами із заданого тексту
 * - виклик функції сортування слів за алфавітом {@link sortWord}
 * - звільнення пам'яті для викорастоного динамічного масиву
 * @return успішний код повернення з програми (0)
 */
int main() {
    char phrase[] = "Yeey, last lab work in this term";

    char * p_string = phrase;


    int countWords = 0;
    countWords = getWordCount(p_string, ' ');
    int len = 0;
    char ** stringIn = (char**) malloc(countWords * sizeof(char*));
    for (int i = 0; i < countWords; i++) {
        char *temp = strtok(p_string + len, " ");
        len += strlen(temp) + 1;
        *(stringIn + i) = (char*) malloc(10 * sizeof(char));
        strcpy(*(stringIn + i), temp);
    }
    sortWord(stringIn, countWords);

    for (int i = 0; i < countWords; i++) {
        free(*(stringIn + i));
    }
    free(stringIn);
    return 0;
}
