#include "data.h"
/**
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 02-march-2021
 * @version 1.0
 */


void Bow::readFromFileBow(std::ifstream &f) {
    f >> *this;
}
void Instrument::readElementFromFile(std::ifstream &f) {
    f >> *this;
    bow.readFromFileBow(f);
}
void Violin::readElementFromFile(std::ifstream &f) {
    Instrument::readElementFromFile(f);
    f >> this->hasBridge;
    f >> this->hasChinRest;
    int a;
    f >> a;
    this->violinType = (ViolinType) a;
}
void Contrabass::readElementFromFile(std::ifstream &f) {
    Instrument::readElementFromFile(f);
    f >> this->hasExtraString;
    f >> this->endpinLength;
}
void Instrument::writeInFileInstr(std::ofstream &f) const{
    f << *this;
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
    //instrument.bow.readFromFileBow(f);


    return input;
}
std::ostream& operator<< (std::ostream &output, const Violin& violin) {
    switch (violin.getVType()) {
        case SOLO: output << "Solo" << std::endl ;
            break;
        case ORCHESTRAL: output << "Orchestral" << std::endl;
            break;
        case UNIVERSAL: output << "Universal" << std::endl ;
    }
    return output;
}


string Instrument::getInfo() const {
    std::stringstream ss;
    ss << "Type: " << type << endl;
    ss << "Firm: " << firm << endl;
    ss << "Production year: " << year << endl;
    ss << "Instrument`s size: " << size << endl;

    ss << "Bow weight: " << bow.getWeight() << endl;
    switch (bow.getMat()) {
        case BT: ss << "Bow material: Brazilian Tree" << endl;
            break;
        case PERNAMBUCO: ss << "Bow material: Pernambuco" << endl;
            break;
        case FIBERGLASS: ss << "Bow material: Fiberglass" << endl;
    }
    ss << endl;

    return ss.str();
}

string Violin::getInfo() const{
    std::stringstream ss;
    ss << Instrument::getInfo();
    ss << "Violin's characteristics: " << std::endl;
    switch (this->violinType) {
        case SOLO: ss << "Violin Type: Solo" << endl;
            break;
        case ORCHESTRAL: ss << "Violin Type: Orchestral" << endl;
            break;
        case UNIVERSAL: ss << "Violin Type: Universal" << endl;
    }
    if (this->hasBridge) {
        ss << "Has Bridge: Yes" << std::endl;
    } else{
        ss << "Has Bridge: No" << std::endl;
    }
    if (this->hasChinRest) {
        ss << "Has Chin Rest: Yes" << std::endl;
    } else {
        ss << "Has Chin Rest: No" << std::endl;
    }
    ss<<endl;
    return ss.str();
}

string Contrabass::getInfo() const {
    std::stringstream ss;
    ss << Instrument::getInfo();
    ss << "Double Bass's characteristics: " << std::endl;
    if (this->hasExtraString) {
        ss << "Has Extra String: Yes" << std::endl;
    } else{
        ss << "Has Extra String: No" << std::endl;
    }
    ss << "Endipil Length: " << this->endpinLength << endl;
    ss<<endl;
    return ss.str();
}
void Instrument::print() {
    cout << getInfo();
}
void Violin::print() {
    cout << getInfo();
}
void Contrabass::print() {
    cout << getInfo();
}


