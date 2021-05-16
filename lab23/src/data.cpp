#include "data.h"

/**
 * @file data.cpp
 * @brief Файл з реалізацією функцій класу інструменту
 *
 * @author Belchynska K.
 * @date 08-may-2021
 * @version 1.0
 */


 void Bow::print() const{
     printf("Bow weight: %d\n\n", this->weight);
}

void Instrument::print() const{
    printf("Firm: %s\n", this->firm);
    printf("Type: %s\n", this->type);
    printf("Production year: %d\n", this->year);
    printf("Instrument`s size: %f\n", this->size);
    bow.print();
}

void Instrument:: printTheOldestInstrument(char* name){
    if (strcmp(this->firm, name)==0){
        print();

    }

}

int Instrument::getYear() const {
    return this->year;
}

char * Instrument::getType() {
    return this->type;
}

char * Instrument::getFirm() {
     return this->firm;
}
float Instrument::getSize() const {
     return this->size;
 }