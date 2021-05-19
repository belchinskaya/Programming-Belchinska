#include "data.h"
#include <cstddef>
#include <string>



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
    //std::string fileName = "/home/kate/Programming-Belchynska/lab24/instruments.txt";
    void readFromFile(std::string fileName);
    void writeInFile(std::string outputFile);
    Instrument& getInstrument(size_t index);
    void addInstrument(Instrument& instrument);
    void removeInstrument(size_t pos);
    void showInstrument();
    void findTheOldestInstr(char &name);



    virtual ~List(){
        for (int i = 0; i < count; ++i) {
            delete instrument[i];
        }
        delete[] instrument;
    }
};




