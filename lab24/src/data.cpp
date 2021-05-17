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
    std::cout << "Type: " << this->type << std::endl;
    std::cout << "Firm: " << this->firm << std::endl;

    std::cout << "Production year: " << this->year << std::endl;
    std::cout << "Instrument`s size: " << this->size << std::endl;
    bow.print();
}

void Instrument:: printTheOldestInstrument(char &name){
    if (this->firm == &name){
        print();
    }

}

void Bow::readFromFileBow(std::ifstream &f) {
     int a;
     f >> this->weight;
     f >> a;
     this->material = (Material) a;

}
void Instrument::readElementFromFile(std::ifstream &f) {
    f >> this->type;
    f >> this->firm;
    f >> this->year;
    f >> this->size;
    bow.readFromFileBow(f);
 }

 void Bow::writeInFileBow(std::ofstream &f) {
     f << "Bow weight: " << this->weight << std::endl;
     switch (this->material) {
         case BT: f << "Bow material: Brazilian Tree" << std::endl << std::endl;
             break;
         case PERNAMBUCO: f << "Bow material: Pernambuco" << std::endl << std::endl;
             break;
         case FIBERGLASS: f << "Bow material: Fiberglass" << std::endl << std::endl;
     }
 }

 void Instrument::writeInFileInstr(std::ofstream &f) {
     f << "Type: " << this->type << std::endl;
     f << "Firm: " << this->firm << std::endl;
     f << "Production year: " << this->year << std::endl;
     f << "Instrument`s size: " << this->size << std::endl;
     bow.writeInFileBow(f);
 }
Bow& Bow::getBowFromString() {

    std::string str = "300,2";
    std::stringstream ss(str);
    Bow bow;
    std::string token;
    std::stringstream tempSS3;
    int a;

    std::stringstream tempSS;
    std::getline(ss, token, ',');
    tempSS << token;
    tempSS >> bow.weight;

    std::stringstream tempSS4;
    std::getline(ss, token, ',');
    tempSS4 << token;
    tempSS4 >> a;
    bow.material = (Material) a;
    return bow;
 }
Instrument& Instrument::getInstrumentFromString(std::string& str) {

   //std::string  str = "Classic,Yamaha,1805,0.5f";
    std::stringstream ss(str);
    Instrument instrument;
    std::string token;
    std::getline(ss, token, ',');
    instrument.type = token;
    std::getline(ss, token, ',');
    instrument.firm = token;

    std::stringstream tempSS;
    std::getline(ss, token, ',');
    tempSS << token;
    tempSS >> instrument.year;

    std::stringstream tempSS2;
    std::getline(ss, token, ',');
    tempSS2 << token;
    tempSS2 >> instrument.size;


     instrument.bow = bow.getBowFromString();

     instrument.print();
     return instrument;
 }
std::string& Instrument::getFirm() {
    return this->firm;
}

int Instrument::getYear() const {
    return this->year;
}

std::string& Instrument::getType() {
    return this->type;
}

float Instrument::getSize() const {
    return this->size;
}