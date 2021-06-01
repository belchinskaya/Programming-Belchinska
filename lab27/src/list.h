#include "data.h"
#include <cstddef>
#include <string>



#pragma once
/**
 * Список інструментів
 */
class List {
    int count;
    Instrument **instrument;

public:
    List() : count(0) {

    }

    List(const List &copy) : count(copy.count) {
        instrument = new Instrument *[count];
    }


    virtual void readFromFile(string& fileName, Instrument * instrument);


    virtual Instrument &getInstrument(size_t index);

    void addInstrument(Instrument * instrument1, int pos);

    virtual void removeInstrument(size_t pos);


    virtual void showInstrument() ;


    virtual ~List() {
        //for (int i = 0; i < count; ++i) {
        //    delete instrument[i];
        //}
        //delete[] instrument;
    }

    Instrument& operator[](size_t i) const {

        if (i < count)  {  //throw std::exception(“index out of range”)
            return *instrument[i];
        }
    }



};
