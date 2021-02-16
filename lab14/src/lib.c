/*
 * @file lib.c
 * @brief Файл з реалізацією функцій
 *
 * @author Belchynska K.
 * @date 20-dec-2020
 * @version 1.0
 */

#include"lib.h"


int countOfUniqueElements(char* arr, int size) {
    int count = 0;
    int i = 0;
    int k = 0;
    char* arrTemp = (char*)malloc(size * sizeof(char));
    strncpy(arrTemp, arr, 1);

    for (i = 0; i < size + 1; i++) {
        char value = *(arr + i);
        bool check = checker(arrTemp, k, value);
        for (int j = i + 1; j < size + 1; j++) {
            if (check == false) {
                *(arrTemp + k) = value;
                count++;
                k++;
                break;
            }
        }
    }
    free(arrTemp);
    return count;
}

bool checker(char* arr, int currentIndex, char value) {
    bool flag = false;
    for (int i = 0; i < currentIndex; i++) {
        if (*(arr + i) == value) {
            flag = true;
        }
    }
    return flag;
}

void getSymbols(char* strIn, int sizeIn, char* symbols, int sizeOut) {
    int i;
    int k = 0;
    for (i = 0; i < sizeIn + 1; i++) {
        char value = *(strIn + i);
        bool check = checker(symbols, k, value);
        for (int j = i + 1; j <= sizeIn; j++) {
            if (check == false) {
                *(symbols + k) = value;
                k++;
                break;
            }
        }
    }
    *(symbols + k) = '\0';
}

void getSymbolsCounts(char* strIn, int sizeIn, char* elements, int* elCounts, int sizeOut) {

    for (int i = 0; i < sizeOut; i++) {
        //char value = *(elements + i);
        for (int j = 0; j < sizeIn; j++) {
            if (*(elements + i) == *(strIn + j)) {
                *(elCounts + i) += 1;
            }
        }
    }
}

void fillZeros(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = 0;
    }
}

void getSymbolsFrequencies(int* elCounts, float* elFreaqs, int size, int totalCount) {
    for (int i = 0; i < size; i++) {
        int current = *(elCounts + i);
        *(elFreaqs + i) = (float) current / (float) totalCount;
    }
}
void writeToFile(FILE* f, char* filename, float* arr, int size) {
    f = fopen(filename, "w");
    if (f == NULL) {
        printf("Неможливо відкрити файл через: %s", strerror(errno));
        exit(1);
    }
    printf("Частота: ");
    for (int i = 0; i < size; i++) {
        printf("%f\n", *(arr + i));
    }

    for (int i = 0; i < size; i++) {
        fprintf(f, "%f, ", *(arr + i));
    }
    fclose(f);
}

int getFileLength(FILE* file) {
    int count = 0;
    while (!feof(file)) {
        fgetc(file);
        count++;
    }
    count--;
    printf("Filesize: %d \n", count);

    fclose(file);
    return count;
}

void readFromFile(char* filename, char* pText, int bufSize) {

    FILE* f = fopen(filename, "r");



    if (f == NULL) {
        printf("Неможливо відкрити файл через: %s", strerror(errno));
        exit(1);
    }

    for (ssize_t i = 0; i < bufSize; i++) {
        fscanf(f, "%s", pText + i);
    }


}

/*void getTree(char* dirName) {
    DIR *d;
    d = opendir(dirName);
    if (d == NULL) {
        printf("Неможливо відкрити файл через: %s", strerror(errno));
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        printf("- %s\n", dirName);

        struct stat statbuf;
        stat(dirName, &statbuf);

        if (S_ISDIR(statbuf.st_mode))
            getTree(dirName);
    }



    closedir(d);



}*/

/*int getFileVolume(char *dirName) {
    FILE *d;
    d = fopen(dirName, "r");
    //readdir(d);
    if (d == NULL) {
        printf("Неможливо відкрити файл через: %s", strerror(errno));
        exit(1);
    }
    seekdir(d, SEEK_END);
    long count = ftell(d);
    printf("Filesize: %ld \n", count);
    fclose(d);

}*/

void listdir(const char *name, int indent) {
    int count = 0;
    DIR *dir;
    struct dirent *entry;
    struct stat stbuf;

    if (!(dir = opendir(name)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            printf("%*s[%s]\n", indent, "", entry->d_name);
            listdir(path, indent + 2);
            count+= stbuf.st_size;
            printf("Size of directory: %d\n", count);
        } else {
            printf("%*s- %s\n", indent, "", entry->d_name);

        }
    }
    closedir(dir);
}