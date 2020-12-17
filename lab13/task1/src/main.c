#include "lib.h"

int main() {
    char phrase[] = "Yeey, last lab work in this term";

    char * p_string = phrase;
    p_string = strtok(p_string, " ");

    int countWords = 0;
    countWords = getWordCount(p_string, ' ');
    char ** stringIn = (char**) malloc(countWords + 1 * sizeof(char*));
    int i = 0;
    *(stringIn + i) = (char*) malloc(strlen(p_string) * sizeof(char));
    strcpy(*(stringIn + i), p_string);
    i++;
    int count = 0;
    while (p_string != NULL) {
        count += strlen(p_string);
        p_string = stringIn;
        p_string = strtok(p_string + count, " ");

        if (p_string == NULL) {
            break;
        }
        *(stringIn + i) = (char *) malloc(strlen(p_string) + 1 * sizeof(char));
        strcpy(*(stringIn + i), p_string);
        i++;
    }




    free(stringIn);
    return 0;
}
