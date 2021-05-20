/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 *
 * @author Belchynska K.
 * @date 17-march-2021
 * @version 1.0
 */
#pragma once
#include <cstdio>
#include <ctime>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <regex.h>
#include <iostream>
#include <fstream>
#include <sstream>

//long fileSize(FILE * file);


enum Material {BT = 1, PERNAMBUCO = 2, FIBERGLASS = 3};
//static char material[3][20] = {"Brazilian Tree", "Pernambuco", "Fiberglass"};

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
    int getWeight() const{
        return weight;
    }
    Material getMat() const{
        return material;
    }
    virtual ~Bow(){

    }


    void setMat(Material material){
        Bow::material = material;
    }
    void setWeight(int weight) {
        Bow::weight = weight;
    }

    //void print() const;
    friend std::istream& operator>> (std::istream &input, Bow& bow);
    void readFromFileBow(std::ifstream &f);
    //void writeInFileBow(std::ofstream &f);
    Bow& getBowFromString();

};

/**
 * Структура інструментів, включає до себе тип інструменту, фірму та рік виготовленя
 */
class Instrument {
    std::string type;
    std::string firm;
    int year;
    float size;
    Bow bow;
public:
Instrument(): type(), firm(), year(0), size(0), bow(0, BT){

}
Instrument(const char t[15], const char f[15], const int year, const float size, const Bow& bow ): year(year), size(size), bow(bow){
    type = t;
    firm = f;
}
Instrument(const Instrument& copy): year(copy.year), size(copy.size), bow(copy.bow){
    type = copy.type;
    firm = copy.firm;
}

    //void print() const;
    void readElementFromFile(std::ifstream &f);
    void writeInFileInstr(std::ofstream &f) const;

    void printTheOldestInstrument(std::string& name);
    Instrument& getInstrumentFromString(std::string& str);
    std::string& getFirm();
    int getYear() const;
    std::string& getType();
    float getSize() const;



    bool operator == (const std::string& name) const {
        return this->firm == name;
    }

    bool operator != (const Instrument& other) const {
        return !(this->firm == other.firm);
    }
    friend std::istream& operator>> (std::istream &input, Instrument& instrument);
    friend std::ostream& operator<< (std::ostream &output, const Instrument& instrument);

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

