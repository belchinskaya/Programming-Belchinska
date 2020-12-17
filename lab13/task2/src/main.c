#include "lib.h"
int main() {
    char surname[] = "Бібік, Акулібаба, Зажерило, Бібік, Черепок, Чупилко, Гаврик, Шжопов,  Шмонько, Гаврик";
    char *p_surname = surname;

    int comaCount = getComaCount(surname);

    int temp1 = comaCount + 1;
    char ** strIn = (char**) malloc(temp1 * sizeof(char*));

    p_surname = strtok(p_surname, ",");
    int i = 0;
    *(strIn + i) = (char*) malloc(strlen(p_surname) + 1 * sizeof(char));
    strcpy(*(strIn + i), p_surname);
    i++;

    int count = 0;
    while (p_surname != NULL) {
      count += strlen(p_surname) + 1;
      p_surname = surname;
      p_surname = strtok(p_surname + count, ",");
      if (p_surname == NULL) {
          break;
      }
      *(strIn + i) = (char*)malloc(strlen(p_surname) + 1 * sizeof(char));
      strcpy(*(strIn + i), p_surname);
      i++;
    }
    sortSequence(strIn, count);
    deleteRepeat(strIn, count);

    free(strIn);
    return 0;
}
