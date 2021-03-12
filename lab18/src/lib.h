#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct TestElement{
    int id;
    char data[30];
};

struct Container{
    struct TestElement *array;
    int size;
};
char * insert(char * arr1, char * arrCenter, size_t position);
void delete_array(char * arr, size_t start, size_t end);