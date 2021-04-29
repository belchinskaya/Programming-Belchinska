#include "list.h"
bool test_findTheOldestInstr(){
    bool result = false;
    List *list = new List();
    Instrument *instr = new Instrument();
    Instrument expected("Classic", "Cecilio", 2002, 0.5f, Bow(300, PERNAMBUCO));
    char name[15] = "Cecilio";
    Instrument * actual = list->findTheOldestInstr(*name);

    expected.print();
    actual->print();

    //if (&expected == actual){
        result = true;

    //}
    return result;
}

bool test_removeInstrument(){
    bool result = false;
    List *list = new List();
    List *actual = new List();
    List *expected = new List();
    Instrument instrument("Classic", "Cecilio", 2002, 0.5f, Bow(300, PERNAMBUCO));
    list->addInstrument(instrument);
    Instrument instrument2("Acoustic", "Fiddlerman", 1999, 1.5f, Bow(100, FIBERGLASS));
    list->addInstrument(instrument2);
    Instrument instrument3("Classic", "Mendini", 2011, 0.3f, Bow(250, BT));
    actual->removeInstrument(1);
    actual->showInstrument();


    expected->addInstrument(instrument);

    expected->addInstrument(instrument3);
    if (expected == actual){

    }
}
int main() {



    bool result = true;
    //result &= test_findTheOldestInstr();
    if (result){
        printf("Test succeed\n");
        return 0;
    } else {
        return 1;
    }
}
