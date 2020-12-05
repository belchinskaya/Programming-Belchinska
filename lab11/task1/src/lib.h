#pragma once
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 10

void fillArrayIn(int* arr);
int countDuplicatingElements(int* arr, int len);
bool checker(int* arr, int currentIndex, int value);
void writeDupElToResult(int* arrIn, int lenIn, int* arrOut, int lenOut);
void writeCountsToResult(int* arrIn, int lenIn, int* arrOut, int lenOut);
