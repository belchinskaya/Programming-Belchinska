#include <stdbool.h>
#include "data.h"
bool test_isValidInstrument() {
    struct Instrument instrument = {"Abra cadabra", 1805, 0.5f};
    bool actual = false;
    bool expected = true;
    bool result = true;
    actual = isValidInstrument (&instrument);
    if (actual == expected) {
        return result;
    } else {
        return !result;
    }
}
int main() {
    bool result = true;
    result &= test_isValidInstrument();
    if (result) {
        printf("Test sucseed!\n");
    } else {
        printf("Test failed!\n");
    }
    return result ? 0 : 1;
}
