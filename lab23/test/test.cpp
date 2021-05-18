#include "list.h"
bool test_findTheOldestInstr(){
    bool result = false;
    List *list = new List();

    Instrument instrument("Classic", "Cecilio", 2002, 0.5f, Bow(300, PERNAMBUCO));
    list->addInstrument(instrument);
    Instrument instrument2("Acoustic", "Fiddlerman", 1999, 1.5f, Bow(100, FIBERGLASS));
    list->addInstrument(instrument2);
    Instrument instrument3("Classic", "Mendini", 2011, 0.3f, Bow(250, BT));
    list->addInstrument(instrument3);


    Instrument expected("Classic", "Cecilio", 2002, 0.5f, Bow(300, PERNAMBUCO));
    char name[15] = "Cecilio";

    Instrument actual;
    actual = *list->findTheOldestInstr(name);

    expected.print();
    actual.print();

    if (strcmp(expected.getFirm(), actual.getFirm()) == 0){
        result = true;
    } else {
        result = false;
    }
    delete list;
    return result;
}

bool test_removeInstrument(){
    bool result = false;
    List *list = new List();
    List *expected = new List();

    Instrument instrument("Classic", "Cecilio", 2002, 0.5f, Bow(300, PERNAMBUCO));
    list->addInstrument(instrument);
    Instrument instrument2("Acoustic", "Fiddlerman", 1999, 1.5f, Bow(100, FIBERGLASS));
    list->addInstrument(instrument2);
    Instrument instrument3("Classic", "Mendini", 2011, 0.3f, Bow(250, BT));
    list->addInstrument(instrument3);

    list->removeInstrument(1);

    expected->addInstrument(instrument);
    expected->addInstrument(instrument3);

    if (list->getInstrument(0).getYear() != expected->getInstrument(0).getYear() && list->getInstrument(1).getYear() != expected->getInstrument(1).getYear()){
        result = false;
    } else {
        result = true;
    }
    delete list;
    delete expected;
    return result;
}
int main() {
    bool result = true;
    result &= test_removeInstrument();
    result &= test_findTheOldestInstr();
    if (result){
        printf("Test succeed!\n");

    } else {
        printf ("Some tests are failed\n");

    }
    return result ? 0 : 1;
}
