#include "data.h"
#include <cstddef>
#include <strings.h>

#pragma once
class List{
    Instrument** instrument;
    size_t count;
public:List():  count(0){

    }
    List(const List& copy):  count(copy.count){
        instrument = new Instrument*[count];
        for (int i = 0; i < count; ++i) {
            instrument[i]= new Instrument(*copy.instrument[i]);
        }
    }

    Instrument& getInstrument(size_t index);
    void addInstrument(Instrument& instrument);
    void removeInstrument(size_t pos);
    void showInstrument();
    void findTheOldestInstr(char name[15]);

//add distruct
    virtual ~List(){
        for (int i = 0; i < count; ++i) {
            delete instrument[i];
        }
        delete instrument;
    }
};





