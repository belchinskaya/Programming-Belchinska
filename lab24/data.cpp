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
    printf("%d\n", this->weight);
}

void Instrument::print() const{
    //printf("%15s\n", this->firm);
    //printf("%15s", this->type);
    printf("%d", this->year);
    printf("%f", this->size);
    bow.print();
}