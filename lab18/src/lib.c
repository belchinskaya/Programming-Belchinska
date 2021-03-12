#include "lib.h"
char * insert(char * arr1, char * arrCenter, size_t position) {
    char *new_array = malloc((strlen(arr1) + 1) * sizeof(char ));
    if (position > strlen(arr1)) {
        position = strlen(arr1);
    }
    for (int i = 0; i < strlen(arr1); i++) {
        if (position == i) {
            memcpy(new_array, arr1, position * sizeof(char));
            memcpy(new_array + position, arrCenter, strlen(arrCenter) * sizeof(char));
            memcpy(new_array + position + strlen(arrCenter), arr1 + position, strlen(arr1) - position);
            *(new_array + strlen(new_array)) = '\0';
            break;
        }
    }
    return new_array;
    //free(arr1);
}

void delete_array(char * arr, size_t start, size_t end) {
    if ((end - start) == 0) {
        return; // nothing to delete
    }
    char * new_array = malloc((strlen(arr) - 1) * sizeof(char ));
    if (start >= strlen(arr)) {
        start = strlen(arr) - 1;
    }
    memcpy(new_array, arr, start * sizeof(char ));
    memcpy(new_array + start, arr + end, (strlen(arr) - (end - start)) * sizeof(struct TestElement));
    *(new_array + strlen(new_array)) = '\0';
    //free(arr);;
}