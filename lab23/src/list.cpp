#include "list.h"
#include "data.h"
#define INSTRUMENT_COUNT 6

Instrument& List:: getInstrument(size_t index){
    return *instrument[index];
}

void List:: addInstrument(Instrument& instrument){
    Instrument** new_array = new Instrument*[this->count + 1];

    for (int i = 0; i < this->count; ++i) {
        new_array[i + 1] = this->instrument[i];
    }
    new_array[count] = new Instrument(instrument);

    delete this->instrument;
    this->instrument = new_array;
    this->count++;
}

void List:: showInstrument() {

    for (int i = 0; i < this->count; ++i) {
        instrument[i]->print();
    }
}