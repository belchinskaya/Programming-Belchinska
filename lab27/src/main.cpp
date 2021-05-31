/**
 * @mainpage
 * # Індивідуальне завдання
 * @brief Модернізувати попередню роботу шляхом:
 * • базовий клас зробити абстрактним. Додати абстрактні методи;
 * • розроблені класи-списки поєднуються до одного класу таким чином, щоб він міг
 * працювати як з базовим класом, так і з його спадкоємцями. При цьому серед полів
 * класу-списку повинен бути лише один масив, що містить усі типи класів ієєрархії.
 * Оновити методи, що працюють з цим масивом;
 * • у функціях базового класу та класів-спадкоємців обов’язкове використання ключових слів final
 * та override.
 * @date 27-may-2021
 * @version 1.0
 */

#include "list.h"
/**
 * @file main.cpp
 * @brief Головний файл з викликом функцій,
 * виділенням пам'яті для динамічних масивів та заданням вхідного тексту.
 *
 *
 * @author Belchynska K.
 * @date 27-may-2021
 * @version 1.0
 */

/**
 * Головна функція.
 *
 * - Додавання елементів в список інструментів
 * - Додавання елементів в список скрипок
 * - Додавання елементів в список контрабасів
 * - Вивід на екран списків
 * - Видалення елементу зі списку
 *
 * @return 0 при успішному завершенні програми
 */
int main() {
    string fileName = "/home/kate/Стільниця/instruments.txt";

    //list->writeInFile("/home/kate/Стільниця/instrumentsOut.txt");
    Instrument *instrument;
    List * list = new List();
    //list->readFromFile(fileName, *instrument);
    string violinFileName = "/home/kate/Стільниця/ViolinIn.txt";
    string contrabassFileName = "/home/kate/Стільниця/ContrabassIn.txt";
    Violin * violin = new Violin();
    list->readFromFile(violinFileName, new Violin());
    list->readFromFile(contrabassFileName, new Contrabass());


    delete list;

    return 0;
}


