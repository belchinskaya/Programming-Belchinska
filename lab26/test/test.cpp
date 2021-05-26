#include "list.h"
bool test_getInstrumentFromString(){
    bool result = true;
    Instrument expected("Acoustic", "Stenor", 1985, 1.5f, Bow(300, PERNAMBUCO));
    std::cout << "Actual instrument: " << std::endl;
    std::string expectedStr = "Acoustic,Stenor,1985,1.5f";
    Instrument actual = actual.getInstrumentFromString(expectedStr);
    if (actual == expected) {
        result = true;
    } else {
        result = false;
    }

    std::cout << "Expected instrument: " << std::endl;
    std::cout << expected;


    return result;
}
int main() {

    bool result = true;
    result &= test_getInstrumentFromString();
    if (result){
        printf("Test succeed!\n");
    } else {

    }
    return result ? 0 : 1;
}
