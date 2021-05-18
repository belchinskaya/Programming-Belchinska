#include "data.h"
#include <cstddef>
#include <strings.h>

/**
 * @file list.h
 * @brief Файл з прототипами функцій списку
 *
 * @author Belchynska K.
 * @date 08-may-2021
 * @version 1.0
 */

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
    Instrument* findTheOldestInstr(char * name);


    virtual ~List(){
        for (int i = 0; i < count; ++i) {
            delete instrument[i];
        }
        delete instrument;
    }
};




