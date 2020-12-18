#include "lib.h"
int main() {
    char* textIn = "123, fdk, 34, 45 4";
    char * textOut = (char*) malloc(strlen(textIn) * sizeof(char));
    getNum(textIn, textOut);
    return 0;
}
