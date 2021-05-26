#include "data.h"
#include <cstddef>
#include <string>



#pragma once
class List {
    Instrument **instrument;
    int count;
public:
    List() : count(0) {

    }

    List(const List &copy) : count(copy.count) {
        instrument = new Instrument *[count];
        for (int i = 0; i < count; ++i) {
            instrument[i] = new Instrument(*copy.instrument[i]);
        }
    }

    //std::string fileName = "/home/kate/Programming-Belchynska/lab24/instruments.txt";
    void readFromFile(std::string fileName);

    void writeInFile(std::string outputFile);

    Instrument &getInstrument(size_t index);

    void addInstrument(Instrument &instrument);

    void removeInstrument(size_t pos);

    void showInstrument();

    void findTheOldestInstr(std::string &name);


    virtual ~List() {
        for (int i = 0; i < count; ++i) {
            delete instrument[i];
        }
        delete[] instrument;
    }

    Instrument& operator[](size_t i) const {

        if (i < count)  {  //throw std::exception(“index out of range”)
            return *instrument[i];
        }
    }

    List& operator = (const List& other) {
        if (this == &other) { // 0) проверка на самоприсваивание
            return *this;
        }
        delete [] instrument;	                     // 1) clear current dat//

        count = other.count;

        instrument = new Instrument *[count];
        for (int i = 0; i < count; ++i) {
            instrument[i] = new Instrument[count];
        } // 2) create new data



        for (int i = 0; i < count; i++) { // 3) fill data

            instrument[i] = other.instrument[i];

        }

        return *this;
    }

};

class ViolinList {
    Violin **violins;
    int num;
public:
    ViolinList() : num(0) {

    }

    ViolinList(const ViolinList &copy) : num(copy.num) {
        violins = new Violin *[num];
        for (int i = 0; i < num; ++i) {
            violins[i] = new Violin(*copy.violins[i]);
        }

    }

    void addViolin(Violin &violin);

    void removeViolin(size_t pos);

    void showViolin();
    virtual ~ViolinList() {
        for (int i = 0; i < num; ++i) {
            delete violins[i];
        }
        delete[] violins;
    }

};

class ContrabassList {

    Contrabass **contrabasses;
    int size;
public:
    ContrabassList() : size(0) {

    }

    ContrabassList(const ContrabassList &copy) : size(copy.size) {
        contrabasses = new Contrabass *[size];
        for (int i = 0; i < size; ++i) {
            contrabasses[i] = new Contrabass(*copy.contrabasses[i]);
        }

    }
    void addContrabass(Contrabass &contrabass);

    void removeContrabass(size_t pos);

    void showContrabass();
};
