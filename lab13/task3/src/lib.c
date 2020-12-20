#include "lib.h"

float getFrequency(char* in, char sym) {
    float countSymbol = 0;
    char * p_text = in;
    while (p_text = strchr(p_text, sym) != NULL) {
        countSymbol++;
        p_text++;
    }
    free(p_text);
    free(in);
    return countSymbol;

}

void writeTextInResult(char* in, char* text_out) {
    char * p_string = in;
    for (int i = 0; i < strlen(text_out); i++) {

        for (int j; j < strlen(in); j++) {
            *(reslt + i) = '\0';
            i++;
            *(reslt + i) = *(p_string + j);
        }
    }
    free(in);
    free(reslt);
    free(p_string);
}

void writeFrequency(char* in, char* reslt) {
    char * p_str = in;
    
    for (int i = 0; i < strlen(reslt); i++) {
        i++;
        for (int j = 0; j < strlen(in); j++) {
            *(reslt + i) = getFrequency(in, (float)*(p_str + j)) / strlen(in);
        }
    }

    free(p_str);
}