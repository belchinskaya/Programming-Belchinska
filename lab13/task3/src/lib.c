#include "lib.h"

float getFrequency(char* in, char sym) {
    float countSymbol = 0;
    char * p_text = in;
    while (p_text = strchr(p_text, sym) != NULL) {
        countSymbol++;
        p_text++;
    }
    return countSymbol;
    free(p_text);
}

void writeTextInResult(char* in, char* reslt) {
    char * p_string = in;
    int n = 2 * strlen(in);
    for (int i = 0; i < n; i + 2) {
        for (int j; j < strlen(in); j++) {
            *(reslt + i) = *(p_string + j);
        }
    }
    free(p_string);
}

void writeFrequency(char* in, char* reslt) {
    char * p_str = in;
    int n = 2 * strlen(in);
    for (int i = 1; i < n; i + 2) {
        for (int j = 0; j < strlen(in); j++) {
            *(reslt + i) = getFrequency(in, *(p_str + j)) / strlen(in);
        }
    }
    free(p_str);
}