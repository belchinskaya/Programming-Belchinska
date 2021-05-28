#include "list.h"
#include "data.h"

Instrument& List:: getInstrument(size_t index){
    return *instrument[index];
}


void List::addInstrument(Instrument& instrument) {

    Instrument** new_arr = new Instrument*[this->count + 1];

    for (int i = 0; i < this->count; ++i) {

        new_arr[i + 1] = this->instrument[i];
    }
    new_arr[0] = &instrument;
    //delete this->instrument;
    //this->instrument = new_arr;
    this->count++;
    //return **new_arr;
}

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

void List::readFromFile(string &fileName, Instrument &instrument) {
    std::ifstream fin;
    fin.open(fileName);

    while (!fin.eof()) {
        Instrument *instrument1;

        //violin.readFromFileViolin(fin);
        instrument1->readElementFromFile(fin);
        if (instrument1->getYear() != 0){
            addInstrument(*instrument1);
        }
    }
    fin.close();
}
void List::readFromFile(string &fileName, Violin& violin) {
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




void List::showInstrument(Violin& violin) {
    for (int i = 0; i < this->count; ++i) {
        cout << violin << endl;
    }
}
