#include "lib.h"

void getNum(char* strIn, char* textOut) {
    char * pStrIn = strIn;
    //strOut[50] = {0};
    for (int i = 0; i < strlen(strIn); i++) {
        if (isdigit(*(pStrIn + i)) != 0) {
            //char temp = *(pStrIn + i);
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

