/**
 * @mainpage
 * # Індивідуальне завдання
 * @brief Модернізувати попередню роботу шляхом:
 * * додавання класів-спадкоємців з розділу “Розрахункове завдання / Індивідуальні завдання”,
 * котрі будуть поширювати функціонал “базового класу” відповідно до базового класу;
 * * додавання ще класу–списку для кожного класу-спадкоємцю,
 * що буде керувати лише елементами стосовно класу-спадкоємця;
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
    //List * list = new List();
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
    //Instrument i;
    //std::string str = "Classic,Yamaha,1805,0.5f";
    //i.getInstrumentFromString(str);

    ViolinList * violinList = new ViolinList();
    string violinFileName = "/home/kate/Стільниця/ViolinIn.txt";
    violinList->readFromFileViolinList(violinFileName);
    violinList->showViolin();
    //Violin violin("t", "f", 100, 1.0f, Bow(10,BT), true, false, SOLO);
    //violinList->addViolin(violin);
    violinList->removeViolin(0);
    violinList ->showViolin();
    cout << "end violin list" << endl << endl << "Contrabass" << endl;

    ContrabassList * contrabassList = new ContrabassList();
    string contrabassFileName = "/home/kate/Стільниця/ContrabassIn.txt";
    contrabassList->readFromFileContrabassList(contrabassFileName);
    contrabassList->showContrabass();
    contrabassList->removeContrabass(1);
    contrabassList ->showContrabass();

    //delete list;
    delete violinList;
    delete contrabassList;
    return 0;
}
