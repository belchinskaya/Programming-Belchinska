#include "data.h"
#define INSTRUMENT_COUNT 6
/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 02-march-2021
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

void Instrument:: printTheOldestInstrument(char &name){
    if (strcmp(this->firm, &name)==0){
        print();
    }

}