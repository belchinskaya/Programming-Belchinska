#include "lib.h"
#include <stdbool.h>

bool testInsert() {
    bool result = true;
    char arr1[] = "abracadabra";
    char arr2[] = "Text2";
    char expected[]= "abrText2acadabra";
    char actual[17];
    size_t pos = 3;


    strcpy(actual, insert(arr1, arr2, 3));

    if (strcmp(actual, expected) == 0){
        result = true;
        printf("Expected array: %s\n", expected);
        printf("Actual array: %s\n", actual);
    } else {
        result = false;
        printf("Expected array: %s\n", expected);
        printf("Actual array: %s\n", actual);
    }
    return result;
}

bool test_delete_array(){
    
}
int main(){
    bool result = true;
    result &= testInsert();
    if (result){
        printf("All test succeed!\n");
    } else {
        printf("Some tests are failed");
    }
    return result ? 0:1;
}