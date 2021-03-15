#include "lib.h"
#include <stdbool.h>

bool testInsert() {
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
    return result;
}

bool test_delete_array(){
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
    return result;

}
int main(){
    bool result = true;
    result &= testInsert();
    result &= test_delete_array();
    if (result){
        printf("All test succeed!\n");
    } else {
        printf("Some tests are failed");
    }
    return result ? 0:1;
}