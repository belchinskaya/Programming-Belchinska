#include "list.h"
#include "data.h"

/**
 * @file list.cpp
 * @brief Файл з реалізацією функцій для списку інструментів
 *
 * @author Belchynska K.
 * @date 08-may-2021
 * @version 1.0
 */


Instrument& List:: getInstrument(size_t index){
    return *instrument[index];
}

void List:: addInstrument(Instrument& instrument){
    Instrument** new_array = new Instrument*[this->count + 1];

    for (int i = 0; i < this->count; ++i) {
        new_array[i + 1] = this->instrument[i];
    }
    new_array[0] = new Instrument(instrument);

    delete this->instrument;
    this->instrument = new_array;
    this->count++;
}
void List:: removeInstrument(size_t pos) {
    printf("Delete element from list:\n");
    Instrument** new_array = new Instrument*[this->count - 1];
    List::getInstrument(pos);
    if (this->count == 0) return; // nothing to delete
    //for (int i = 0; i < this->count; ++i) {
    //    new_array[i - 1] = this->instrument[i];
    //}
    for (int i = 0; i < pos; ++i) {
        new_array[i] = this->instrument[i];
    }
    for (int i = pos; i < count - 1; ++i) {
        new_array[i] = this->instrument[i + 1];
    }

    if (pos >= this->count) {
        pos = this->count - 1;
    }
    delete this->instrument;
    this->instrument = new_array;
    this->count--;

}
Instrument* List::findTheOldestInstr(char * name) {

    printf("Instrument firm Yamaha\n");

    for (int i = 0; i < this->count; ++i) {
        //getInstrument(i);

        if (strcmp(instrument[i]->getFirm(), name) == 0) {
            instrument[i]->print();
            return instrument[i];
        }
    }

}

void List:: showInstrument() {

    for (int i = 0; i < this->count; ++i) {
        instrument[i]->print();
    }
}