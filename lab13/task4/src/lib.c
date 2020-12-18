#include "lib.h"

void getNum(char* strIn, char* strOut) {
    char * pStrIn = strIn;
    for (int i = 0; i < strlen(strIn); i++) {
        if (isdigit(*(pStrIn + i)) != 0) {
            strcat(strOut, *(pStrIn + i));
        } else {
            strcat(strOut, ",");
            strcat(strOut, " ");
            break;
        }
    }
    free(strIn);
    free(pStrIn);
}

