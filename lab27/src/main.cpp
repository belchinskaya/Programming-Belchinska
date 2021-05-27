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
    //List * list = new List;
    //cout << "From file" << std:: endl;
    //string fileName = "/home/kate/Стільниця/instruments.txt";
    //list->readFromFile(fileName);
    //list->showInstrument();
    //list->writeInFile("/home/kate/Стільниця/instrumentsOut.txt");
    //cout << "end" << endl;
    //Instrument instrument;
    //list->removeInstrument(3);
    //list->showInstrument();
    //std::string name = "Yamaha";
    //list->findTheOldestInstr(name);

    ViolinList * violinList = new ViolinList();
    string violinFileName = "/home/kate/Стільниця/ViolinIn.txt";
    violinList->readFromFile(violinFileName);
    violinList->showInstrument();
    //Violin violin("t", "f", 100, 1.0f, Bow(10,BT), true, false, SOLO);
    //violinList->addViolin(violin);
    violinList->removeInstrument(0);
    violinList ->showInstrument();
    cout << "end violin list" << endl << endl << "Contrabass" << endl;

    ContrabassList * contrabassList = new ContrabassList();
    string contrabassFileName = "/home/kate/Стільниця/ContrabassIn.txt";
    contrabassList->readFromFile(contrabassFileName);
    contrabassList->showInstrument();
    contrabassList->removeInstrument(1);
    contrabassList ->showInstrument();

    //delete list;
    delete violinList;
    delete contrabassList;
    return 0;
}


