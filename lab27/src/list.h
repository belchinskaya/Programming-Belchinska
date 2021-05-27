#include "data.h"
#include <cstddef>
#include <string>



#pragma once
/**
 * Список інструментів
 */
class List {
    int count;
    Instrument *instrument[];

public:
    List() : count(0) {

    }

    List(const List &copy) : count(copy.count) {
        //instrument = new Instrument [count];
        //for (int i = 0; i < count; ++i) {
        //   instrument[i] = new Instrument(*copy.instrument[i]);
        //}
    }
    virtual void readFromFile(string& fileName);

    void writeInFile(string outputFile);

    virtual Instrument &getInstrument(size_t index);

    virtual void addInstrument();

    virtual void removeInstrument(size_t pos);

    virtual void showInstrument();



    virtual ~List() {
        for (int i = 0; i < count; ++i) {
            delete instrument[i];
        }
        //delete[] instrument;
    }

    Instrument& operator[](size_t i) const {

        if (i < count)  {  //throw std::exception(“index out of range”)
            return *instrument[i];
        }
    }



};

/**
 * Список скрипок
 */
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

    void addInstrument(Violin &violin);
    void readFromFile(string& fileName);
    void removeInstrument(size_t pos);

    void showInstrument();
    virtual ~ViolinList() {
        for (int i = 0; i < num; ++i) {
            delete violins[i];
        }
        delete[] violins;
    }

};

/**
 * Список контрабасів
 */
class ContrabassList {
    Contrabass **contrabasses;
    int size;
public:
    ContrabassList() : size(0) {

    }
    void readFromFile(string& fileName);
    ContrabassList(const ContrabassList &copy) : size(copy.size) {
        contrabasses = new Contrabass *[size];
        for (int i = 0; i < size; ++i) {
            contrabasses[i] = new Contrabass(*copy.contrabasses[i]);
        }

    }
    void addInstrument(Contrabass &contrabass);

    void removeInstrument(size_t pos);

    void showInstrument();
    virtual ~ContrabassList() {
        for (int i = 0; i < size; ++i) {
            delete contrabasses[i];
        }
        delete[] contrabasses;
    }
};
