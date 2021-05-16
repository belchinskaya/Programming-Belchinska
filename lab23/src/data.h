/**
 * @file data.h
 * @brief Файл з прототипами функцій
 *
 * @author Belchynska K.
 * @date 08-may-2021
 * @version 1.0
 */
#pragma once
#include <cstdio>
#include <ctime>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <regex.h>



/**
 * Перерахування матеріалу смичку інструментів
 */
enum Material {BT = 1, PERNAMBUCO = 2, FIBERGLASS = 3};
//static char material[3][20] = {"Brazilian Tree", "Pernambuco", "Fiberglass"};

/**
 * клас смичку та його функції
 */
class Bow {
    int weight;
    enum Material material;
public:
    Bow(): weight(0), material(){

    }
    Bow(int w, Material m): weight(w), material(m){

    }
    Bow(const Bow& copy ): weight(copy.weight), material(copy.material){

    }
    virtual ~Bow(){

    }

    int getWeight() const{
        return weight;
    }
    Material getMat() const{
        return material;
    }
    void setMat(Material material){
        Bow::material = material;
    }
    void setWeight(int weight) {
        Bow::weight = weight;
    }

    void print() const;
};

/**
 * Структура інструментів, включає до себе тип інструменту, фірму та рік виготовленя
 */
class Instrument {
    char type[15];
    char firm[15];
    int year;
    float size;
    Bow bow;
public:
Instrument(): type(), firm(), year(0), size(0), bow(0, BT){

}
Instrument(const char t[15], const char f[15], const int year, const float size, const Bow& bow ): year(year), size(size), bow(bow){
    strcpy(type, t);
    strcpy(firm, f);
}
Instrument(const Instrument& copy): year(copy.year), size(copy.size), bow(copy.bow){
    strcpy(type, copy.type);
    strcpy(firm, copy.firm);
}

    void print() const;
    int getYear() const;
    char * getType();
    char * getFirm();
    float getSize() const;

/**
 *
 * @param instrument
 * @return вказівник на структури інструментів
 */
    void printTheOldestInstrument(char* name);
//add distruct
    virtual ~Instrument(){

    }
};




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

void print_result(int return_value);

