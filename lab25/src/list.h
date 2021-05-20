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




