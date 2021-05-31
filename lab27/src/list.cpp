#include "list.h"
#include "data.h"

Instrument& List:: getInstrument(size_t index){
    return *instrument[index];
}


void List::addInstrument(Instrument * instrument) {

    Instrument** new_arr = new Instrument*[this->count + 1];

    for (int i = 0; i < this->count; ++i) {


    }
    new_arr[count] = dynamic_cast<Violin *>(instrument);
    //cout << *instrument << endl;
    delete this->instrument;
    this->instrument = new_arr;
    this->count++;
}

//void List:: removeInstrument(size_t pos) {
//    getInstrument(pos);
//    cout << "Delete element from list:" << endl;
//    if(instrument == dynamic_cast<Violin*>(instrument)) {}
//    Instrument** new_array = new Instrument*[this->count - 1];
//    //List::getInstrument(pos);
//    if (this->count == 0) return; // nothing to delete
//    if (pos >= this->count) {
//        pos = this->count - 1;
//    }
//    //this->instrument[0] = dynamic_cast<Violin *>(instrument);
//    for (int i = 0; i < pos; ++i) {
//        new_array[i] = dynamic_cast<Violin*>(this->instrument[i]);
//    }
//    for (int i = pos; i < count - 1; ++i) {
//        new_array[i] = dynamic_cast<Violin*>(this->instrument[i + 1]);
//    }
//    //for (int i = 0; i < count - 1; ++i) {
//        //cout << this->instrument;
//    //}
//
//    //delete[] this->instrument;
//    //this->instrument = new_array;
//    this->count--;
//
//}
//
void List::readFromFile(string &fileName, Instrument * instrument) {
    std::ifstream fin;
    fin.open(fileName);

    while (!fin.eof()) {
        instrument->readElementFromFile(fin);
        //if(instrument == dynamic_cast<Violin*>(instrument)) {

            if (instrument->getYear() != 0){
                addInstrument(instrument);
                cout << *instrument << endl;
            }
            //removeInstrument(1);
        //} else if (dynamic_cast<Contrabass*>(instrument)) {


        //}

    }
    fin.close();
}



void List::showInstrument(Instrument * instrument) {
    for (int i = 0; i < this->count; ++i) {
        if (instrument == dynamic_cast<Violin*>(instrument)){
            Violin violin;
            cout << instrument[i] << endl;
        } else if (instrument == dynamic_cast<Contrabass*>(instrument)){
            Contrabass contrabass;
            cout << *instrument << endl;
        }

    }
}
