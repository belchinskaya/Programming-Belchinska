#include "lib.h"
int main() {
    char* text = "abrakadabra";

    char* result = (char*)malloc(strlen(text) * 2 * sizeof(char));
    writeTextInResult(text, result);
    writeFrequency(text, result);

    return 0;
}
