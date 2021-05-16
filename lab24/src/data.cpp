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
     std::cout << "Bow weight: " << this->weight << std::endl;
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
void  Bow::getBowFromString() {
    std::stringstream input;
    input.str("300 2");
    Bow bow;
    int a;
    input >> bow.weight >> a;
    bow.material = (Material) a;
 }
void Instrument::getInstrumentFromString() {
     std::stringstream input;
     input.str("Classic Yamaha 1805 0.5f");
     Instrument instrument;
     input >> instrument.type >> instrument.firm >> instrument.year >> instrument.size;
     bow.getBowFromString();

     //print();
     //std::istringst// ream ss(input);
     std::string token;

  // std::getline(ss, token, ',');
  // token = instrument.type;
  // std::getline(ss, token, ',');
  // token = instrument.firm;
  // std::cout << instrument.firm;

  //hile(std::getline(ss, token, ',')) {
  //   int i = 0;
  //   std::cout << token << '\n';
  //   switch (i) {
  //       case 0: instrument.type = token;
  //           break;;
  //       case 1: instrument.firm = token;
  //           break;
  //      // case 3: instrument.year = token;

  //   }



 }