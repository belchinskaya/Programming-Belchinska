#include "list.h"
#include <stdbool.h>
#define INSTRUMENT_COUNT_TEST 3
bool test_sortByYear() {
    bool result = true;
    struct Container container_test = {NULL, 0, NULL};
    container_test.head = malloc(sizeof(struct ElementCapsule));
    struct Instrument expected = {"Acoustic", "Yamaha", 1902, 1.0f, 1500, FIBERGLASS};
    struct ElementCapsule* actual = findByCriterion(&container_test);
    if (strcmp(actual->instrument.firm, expected.firm) == 0) {
        result = true;
    }
    return result;
}

int main() {
    bool result = true;

    result &= test_sortByYear();


    if (result) {
        printf("Congratulations! All tests succeed!\n");
    } else {
        printf("Some tests failed. Check logs, fix errors and try again\n");
    }
    return result ? 0 : 1;


}