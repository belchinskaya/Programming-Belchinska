/**
 * @mainpage
 * # Індивідуальне завдання
 * @brief Текст - це перелік прізвищ студентів через кому.
 * **Видалити** з тексту усі дублікати.
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
 * - обчислення кількості слів {@link temp1}
 * - звільнення пам'яті для масиву вказівників на масив вазівників {@link strIn}
 * - звільнення пам'яті для масиву вказівників на строки та заповнення строк словами із заданого тексту
 * - виклик функції {@link sortSequence}
 * - виклик функції {@link deleteRepeat}
 * - звільнення пам'яті для викорастоного динамічного масиву
 * @return успішний код повернення з програми (0)
 */
int main() {
    char surname[] = "Бібік, Акулібаба, Зажерило, Бібік, Черепок, Чупилко, Гаврик, Шжопов,  Шмонько, Гаврик";
    char *p_surname = surname;

    int comaCount = getComaCount(surname);

    int temp1 = comaCount + 1;
    int count = 0;
    char ** strIn = (char**) malloc(temp1 * sizeof(char*));
    for (int i = 0; i < temp1; i++) {
        char *tempSurname = strtok(p_surname + count, ",");
        count += strlen(tempSurname) + 1;
        *(strIn + i) = (char*) malloc((strlen(tempSurname) + 1) * sizeof(char));
        strcpy(*(strIn + i), tempSurname);
        if (tempSurname == NULL) {
            break;
        }
    }

    sortSequence(strIn, count);
    deleteRepeat(strIn, count);

    for (int i = 0; i < temp1; i++) {
        free(*(strIn + i));
    }
    free(strIn);
    return 0;
}
