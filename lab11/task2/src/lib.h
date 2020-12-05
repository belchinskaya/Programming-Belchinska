#pragma once
#include <stdlib.h>
#include <time.h>

#define N 5

void fillArrIn(int* arrIn, int lenIn);
int getPositiveSequence(int* arrIn, int* arrResult, int lenIn);
void fillArrayResult (int* arrIn, int lenIn, int* arrResult, int sum);
int checkSum(int lenIn, int* arrResult);
