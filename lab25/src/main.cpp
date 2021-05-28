/**
 * @mainpage
 * # Індивідуальне завдання
 * @brief Поширити попередню лабораторну роботу таким чином:
 *
 * • у базовому класі та класі/класах-спадкоємцях перевантажити:
 *
 * • оператор присвоювання;
 *
 * • оператор порівняння (на вибір: ==, <, >, >=, <=, !=);
 *
 * • оператор введення / виведення;
 *
 * • у класі-списку перевантажити:
 *
 * • оператор індексування ([]);
 *
 * • введення / виведення з акцентом роботи, у тому числі з файлами. При цьому продовжувати використовувати регулярні вирази для валідації введених даних.
 *
 * @date 28-may-2021
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
 * @date 17-march-2021
 * @version 1.0
 */

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - додавання елемента до списку
 * - вивід списку на екран
 * - видалення елемента зі списку
 * - знаходження елемента фірми Yamaha
 * @return 0 при успішному завершенні програми
 */
int main() {

    List * list = new List();
    std::cout << "From file" << std:: endl;
    std::string fileName = "/home/kate/Стільниця/instruments.txt";
    list->readFromFile(fileName);

    //list->showInstrument();
    list->writeInFile("/home/kate/Стільниця/instrumentsOut.txt");
    std::cout << "end" << std::endl;

    Instrument instrument;
  ///  instrument = list->getInstrument(3);
    list->removeInstrument(3);
    list->showInstrument();
    std::string name = "Yamaha";
    list->findTheOldestInstr(name);
    Instrument i;
    std::string str = "Classic,Yamaha,1805,0.5f";
    i.getInstrumentFromString(str);

    //list->addInstrument(i);
    //list->showInstrument();
    delete list;

    return 0;
}
