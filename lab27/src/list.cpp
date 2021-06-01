#include "list.h"
#include "data.h"

Instrument& List:: getInstrument(size_t index){
    return *instrument[index];
}


void List::addInstrument(Instrument * instrument1, int pos) {

    Instrument** new_arr = new Instrument*[this->count + 1];
    new_arr[0] = instrument1;
    for (int i = 0; i < count ; ++i) {
        Instrument* in(instrument[i]);
        //instrument[i] = &getInstrument(i);
        new_arr[i + 1] = in;
    }

    delete this->instrument;
    this->instrument = new_arr;
    this->count++;

}

void List:: removeInstrument(size_t pos) {
    getInstrument(pos);
    cout << "Delete element from list:" << endl;

    Instrument** new_array = new Instrument*[this->count - 1];
    //getInstrument(pos);
    if (this->count == 0) return; // nothing to delete
    if (pos >= this->count) {
        pos = this->count - 1;
    }
    for (int i = 0; i < count - 1; ++i) {
        new_array[i] = instrument[i];
    }
    for (int i = 0; i < pos; ++i) {
        Instrument* in(instrument[i]);
        new_array[i] = in;
    }
    pos++;
    for (int i = pos; i < count; ++i) {
        Instrument* in(instrument[i]);
        new_array[i] = in;
    }
    for (int i = 0; i < count - 1; ++i) {
        Instrument* in(instrument[i]);
       //showInstrument(in);
    }

    delete[] this->instrument;
    this->instrument = new_array;
    this->count--;

}

void List::readFromFile(string &fileName, Instrument * instrument) {
    std::ifstream fin;
    fin.open(fileName);
    int k = 0;
    while (!fin.eof()) {
        instrument->readElementFromFile(fin);
        //if(instrument == dynamic_cast<Violin*>(instrument)) {
        if (instrument->getYear() != 0){

            addInstrument(instrument, k);
            k++;
        }
    }
    fin.close();
}



void List::showInstrument() {
    for (int i = 0; i < count; ++i) {
        Instrument* in(instrument[i]);
        //if (in == dynamic_cast<Violin*>(instrument[i])) {
            //cout << in[i] << endl;
            in->print();
        //}
        //for (int i = 0; i < this->count; ++i) {
        //    cout << *instrument[i];
//
        //}

    }


}
