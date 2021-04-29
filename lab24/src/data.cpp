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
     std::cout << "Bow weight: " << this->weight << std::endl;
    switch (this->material) {
        case BT: std::cout << "Bow material: Brazilian Tree" << std::endl << std::endl;
            break;
        case PERNAMBUCO: std::cout << "Bow material: Pernambuco" << std::endl << std::endl;
            break;
        case FIBERGLASS: std::cout << "Bow material: Fiberglass" << std::endl << std::endl;
    }
}

void Instrument::print() const{
    std::cout << "Firm: " << this->firm << std::endl;
    std::cout << "Type: " << this->type << std::endl;
    std::cout << "Production year: " << this->year << std::endl;
    std::cout << "Instrument`s size: " << this->size << std::endl;
    bow.print();
}

void Instrument:: printTheOldestInstrument(char &name){
    if (this->firm == &name){
        print();
    }

}

void Bow::readFromFileBow(std:: string &filename) {
    std::ifstream fin;
    //fin.open(filename);
    fin >> this->weight;

 }
void Instrument::readElementFromFile(std:: string &filename) {
    std::ifstream fin;
    //fin.open(filename);
    std::getline(fin, this->type);
    std::getline(fin, this->firm);
    fin >> this->year >> this->size;
    bow.readFromFileBow(filename);
    //fin.close();
 }

 void Bow::writeInFileBow(std::string outputFile) {
     std::ofstream fout;
     fout << this->weight << std::endl;
 }

 void Instrument::writeInFileInstr(std::string outputFile) {
     bow.writeInFileBow(outputFile);
 }