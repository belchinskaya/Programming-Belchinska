#pragma once
#include <stdlib.h>
#include <time.h>

#define N 8

void fillArrIn(int* arrIn, int lenIn);
int findMaxPositiveSequence(int* arrIn, int lenIn, int* lenOut);
void fillArrayResult (int* arrIn, int start, int* arrResult, int lenOut);