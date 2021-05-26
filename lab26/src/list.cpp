#include "list.h"
#include "data.h"
#define INSTRUMENT_COUNT 6

Instrument& List:: getInstrument(size_t index){
    return *instrument[index];
}

void List:: addInstrument(Instrument& instrument){

    Instrument** new_array = new Instrument*[this->count + 1];

    for (int i = 0; i < this->count; ++i) {
        //this->operator[](i);
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
        cout << *instrument[i];
        cout << endl;
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


void ViolinList::addViolin(Violin &violin) {

    Violin** new_arr = new Violin*[this->num + 1];

    for (int i = 0; i < this->num; ++i) {
        //this->operator[](i);
        new_arr[i + 1] = this->violins[i];
    }
    new_arr[0] = new Violin(violin);
    //this->instrument[0]("Acoustic", "Stenor", 1985, 1.5f, Bow(300, PERNAMBUCO));
    delete this->violins;
    this->violins = new_arr;
    this->num++;
}

void ViolinList:: showViolin() {
    //getInstrument(0);
    for (int i = 0; i < this->num; ++i) {
        //std::cout << violins[i];
         std::cout << violins[i] << endl;
    }
}

void ViolinList::removeViolin(size_t pos) {
    std::cout << "Delete element from list:" <<std::endl;
    Violin** new_array = new Violin*[this->num - 1];
    //List::getInstrument(pos);
    if (this->num == 0) return; // nothing to delete

    for (int i = 0; i < pos; ++i) {
        new_array[i] = this->violins[i];
    }
    for (int i = pos; i < num - 1; ++i) {
        new_array[i] = this->violins[i + 1];
    }
    // delete instrument[]
    if (pos >= this->num) {
        pos = this->num - 1;
    }
    delete[] this->violins;
    this->violins = new_array;
    this->num--;
}