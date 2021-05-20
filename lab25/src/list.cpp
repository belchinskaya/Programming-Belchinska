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
    new_array[0] = new Instrument(instrument);
    //this->instrument[0]("Acoustic", "Stenor", 1985, 1.5f, Bow(300, PERNAMBUCO));
    delete this->instrument;
    this->instrument = new_array;
    this->count++;
}
void List:: removeInstrument(size_t pos) {
    std::cout << "Delete element from list:" <<std::endl;
    Instrument** new_array = new Instrument*[this->count - 1];
    List::getInstrument(pos);
    if (this->count == 0) return; // nothing to delete

    for (int i = 0; i < pos; ++i) {
        new_array[i] = this->instrument[i];
    }
    for (int i = pos; i < count - 1; ++i) {
        new_array[i] = this->instrument[i + 1];
    }
   // delete instrument[]
    if (pos >= this->count) {
        pos = this->count - 1;
    }
    delete[] this->instrument;
    this->instrument = new_array;
    this->count--;

}
void List::findTheOldestInstr(std::string& name) {
    printf("Instrument firm Yamaha\n");

    for (int i = 0; i < this->count; ++i) {
        getInstrument(i);
        instrument[i]->printTheOldestInstrument(name);

    }
}

void List:: showInstrument() {
    //getInstrument(0);
    for (int i = 0; i < this->count; ++i) {
        std::cout << *instrument[i];
    }
}

void List::readFromFile(std::string fileName) {
    std::ifstream fin;
    fin.open(fileName);

    while (!fin.eof()) {
        Instrument instrument;

        instrument.readElementFromFile(fin);
        //fin >> instrument;
        std::cout << std::endl << std::endl;
        if (instrument.getFirm() != ""){
            addInstrument(instrument);
            std::cout << instrument;
        }
    }
    fin.close();
}

void List::writeInFile(std::string outputFile) {
    std::ofstream fout;
    fout.open(outputFile);
    for (int i = 0; i < count; ++i) {
        fout << *instrument[i];
    }
    fout.close();
}



