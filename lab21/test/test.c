#include "../src/list.h"
#include <stdbool.h>
#define INSTRUMENT_COUNT_TEST 3
#include <sys/time.h>
long  currentTimeMillis() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1000 + time.tv_usec / 1000;
}

bool test_findByCriterion() {
    //printf("%s\n", __FUNCTION__ );
#ifdef DEBUG
    long  start = currentTimeMillis();
#endif

    bool result = false;
    struct Container container_test = {NULL, 0, NULL};
    container_test.head = malloc(sizeof(struct ElementCapsule));
    container_test.head->previous = NULL;

    container_test.tail = malloc(sizeof(struct ElementCapsule));
    container_test.tail->next = NULL;
    container_test.head->next = container_test.tail;
    container_test.tail->previous = container_test.head;
    container_test.size = 0;
    getInstrumentList(&container_test);
    struct Instrument expected = {"Acoustic", "Yamaha", 1902, 1.0f, 1500, FIBERGLASS};
    struct ElementCapsule* actual = findByCriterion(&container_test);

    if (strcmp(actual->instrument.firm, expected.firm) == 0) {
        result = true;
    }



#ifdef DEBUG
    long end = currentTimeMillis();
    printf("Total time of %s: %d milliseconds\n", __FUNCTION__ , end - start);
#endif
    return result;
}
bool testInsert() {
    //printf("%s\n", __FUNCTION__ );
#ifdef DEBUG
    long  start = currentTimeMillis();
#endif
    bool result = true;
    char arr1[] = "abracadabra";
    char arr2[] = "Text2";
    char expected[]= "abrText2acadabra";
    char actual[17];


    strcpy(actual, insert(arr1, arr2, 3));

    if (strcmp(actual, expected) == 0){
        result = true;
        printf("\nExpected array for function testInsert: %s\n", expected);
        printf("Actual array for function testInsert: %s\n\n", actual);
    } else {
        result = false;
        printf("Expected array for function testInsert: %s\n", expected);
        printf("Actual array for function testInsert: %s\n\n", actual);
    }
    //printf("%s\n", __FUNCTION__ );
#ifdef DEBUG
    long  end = currentTimeMillis();
    printf("Total time %s: %d milliseconds\n", __FUNCTION__ , end - start);
#endif

    return result;
}

bool test_delete_array(){
    //printf("%s\n", __FUNCTION__ );
#ifdef DEBUG
    long start = currentTimeMillis();
#endif
    bool result = true;
    char arr1[] = "testForDelete";
    char expected[]= "testDelete";
    char actual[11];
    strcpy(actual, delete_array(arr1, 4, 7));
    if (strcmp(actual, expected) == 0){
        result = true;
        printf("Expected array for function delete_array: %s\n", expected);
        printf("Actual array for function delete_array: %s\n\n", actual);
    } else {
        result = false;
        printf("Expected array for function delete_array: %s\n", expected);
        printf("Actual array for function delete_array: %s\n\n", actual);
    }
#ifdef DEBUG
    long  end = currentTimeMillis();
    printf("Total time %s : %d milliseconds\n", __FUNCTION__ , end - start);
#endif

    return result;

}
int main() {
#ifdef DEBUG
    long start = currentTimeMillis();
#endif

    bool result = true;

    result &= test_findByCriterion();
    result &= test_delete_array();
    result &= testInsert();

    if (result) {
        printf("Congratulations! All tests succeed!\n");
    } else {
        printf("Some tests failed. Check logs, fix errors and try again\n");
    }
#ifdef DEBUG
    long  end = currentTimeMillis();
    printf("\nTotal time %s: %d milliseconds\n", __PRETTY_FUNCTION__ , end - start);
#endif

    return result ? 0 : 1;


}