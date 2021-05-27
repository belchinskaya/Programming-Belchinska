#include "list.h"
#include "data.h"

Instrument& List:: getInstrument(size_t index){
    return *instrument[index];
}

//void List:: addInstrument(Instrument& instrument){
//
//    Instrument** new_array = new Instrument*[this->count + 1];
//
//    for (int i = 0; i < this->count; ++i) {
//        getInstrument(i);
//        new_array[i + 1] = this->instrument[i];
//    }
//    new_array[0] = new Instrument(instrument);
//    delete this->instrument;
//    this->instrument = new_array;
//    this->count++;
//}
void List:: removeInstrument(size_t pos) {
    getInstrument(pos);
    std::cout << "Delete element from list:" <<std::endl;
    Instrument** new_array = new Instrument*[this->count - 1];
    List::getInstrument(pos);
    if (this->count == 0) return; // nothing to delete
    if (pos >= this->count) {
        pos = this->count - 1;
    }
    for (int i = 0; i < pos; ++i) {
        new_array[i] = this->instrument[i];
    }
    for (int i = pos; i < count - 1; ++i) {
        new_array[i] = this->instrument[i + 1];
    }

    //delete[] this->instrument;
    //this->instrument = new_array;
    this->count--;

}

void List:: showInstrument() {
    //getInstrument(0);

    for (int i = 0; i < this->count; ++i) {
        instrument[i]->print();

    }
}

//void List::readFromFile(std::string fileName) {
//    std::ifstream fin;
//    fin.open(fileName);
//
//    while (!fin.eof()) {
//
//
//        instrument->readElementFromFile(fin);
//        if (instrument.getFirm() != ""){
//            addInstrument(instrument);
//        }
//    }
//    fin.close();
//}
void ViolinList::readFromFile(string& fileName) {
    std::ifstream fin;
    fin.open(fileName);

    while (!fin.eof()) {
        Violin violin;

        violin.readFromFileViolin(fin);
        if (violin.getYear() != 0){
            addInstrument(violin);
        }
    }
    fin.close();
}
void ContrabassList::readFromFile(string &fileName) {
    std::ifstream fin;
    fin.open(fileName);

    while (!fin.eof()) {
        Contrabass contrabass;

        contrabass.readFromFileContrabass(fin);
        if (contrabass.getYear() != 0){
            addInstrument(contrabass);
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

void ViolinList::addInstrument(Violin &violin) {

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


void ViolinList::showInstrument() {
    for (int i = 0; i < this->num; ++i) {
        cout << *violins[i] << endl;
    }
}

void ViolinList::removeInstrument(size_t pos) {
    std::cout << "Delete element from list:" <<std::endl;
    Violin** new_array = new Violin*[this->num];
    //List::getInstrument(pos);
    if (this->num == 0) return;
    if (pos >= this->num) {
        pos = this->num - 1;
    }
    for (int i = 0; i < pos; ++i) {
        new_array[i] = this->violins[i];
    }
    for (int i = pos; i < num - 1; ++i) {
        new_array[i] = this->violins[i + 1];
    }

    delete[] this->violins;
    this->violins = new_array;
    this->num--;
}

void ContrabassList::addInstrument(Contrabass &contrabass) {

    Contrabass** newArr = new Contrabass*[this->size + 1];

    for (int i = 0; i < this->size; ++i) {
        newArr[i + 1] = this->contrabasses[i];
    }
    newArr[0] = new Contrabass(contrabass);
    delete this->contrabasses;
    this->contrabasses = newArr;
    this->size++;
}
void ContrabassList::removeInstrument(size_t pos) {
    std::cout << "Delete element from list:" <<std::endl;
    Contrabass** new_array = new Contrabass*[this->size];
    //List::getInstrument(pos);
    if (this->size == 0) return;

    for (int i = 0; i < pos; ++i) {
        new_array[i] = this->contrabasses[i];
    }
    for (int i = pos; i < size - 1; ++i) {
        new_array[i] = this->contrabasses[i + 1];
    }
    // delete instrument[]
    if (pos >= this->size) {
        pos = this->size - 1;
    }
    delete[] this->contrabasses;
    this->contrabasses = new_array;
    this->size--;
}

void  ContrabassList::showInstrument() {
    for (int i = 0; i < this->size; ++i) {
        cout << *contrabasses[i] << endl;
    }
}

