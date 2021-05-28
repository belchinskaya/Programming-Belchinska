#include "data.h"
#define INSTRUMENT_COUNT 6
/**
 * @file lib.cpp
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 02-march-2021
 * @version 1.0
 */



void Instrument:: printTheOldestInstrument(std::string& name){
    bool result = true;
    result  = this->firm == name;
    if (result){
        std::cout << *this;
    }

}

void Bow::readFromFileBow(std::ifstream &f) {
    f >> *this;
}
void Instrument::readElementFromFile(std::ifstream &f) {
    f >> *this;
    bow.readFromFileBow(f);
}

void Instrument::writeInFileInstr(std::ofstream &f) const{
   f << *this;
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
    std::cout << "Instrument from string:" << std::endl;
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

     std::cout << instrument;
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

std::ostream& operator<< (std::ostream &output, const Instrument& instrument) {

    output << "Type: " << instrument.type << std::endl;
    output << "Firm: " << instrument.firm << std::endl;
    output << "Production year: " << instrument.year << std::endl;
    output << "Instrument`s size: " << instrument.size << std::endl;

    output << "Bow weight: " << instrument.bow.getWeight() << std::endl;
    switch (instrument.bow.getMat()) {
        case BT: output << "Bow material: Brazilian Tree" << std::endl << std::endl;
            break;
        case PERNAMBUCO: output << "Bow material: Pernambuco" << std::endl << std::endl;
            break;
        case FIBERGLASS: output << "Bow material: Fiberglass" << std::endl << std::endl;
    }
    return output;
}

std::istream& operator>> (std::istream &input, Bow& bow){
    int a;
    input >> bow.weight;
    input >> a;
    bow.material = (Material) a;
    return input;
}

std::istream& operator>> (std::istream &input, Instrument& instrument){
    input >> instrument.type;
    input >> instrument.firm;
    input >> instrument.year;
    input >> instrument.size;
    //bow.readFromFileBow(f);


    return input;
}