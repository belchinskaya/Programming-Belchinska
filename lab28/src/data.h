#pragma once
#include <cstdio>
#include <ctime>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <iomanip>
using std::string;
using std::cout;
using std::cin;
using std::endl;

string scanFileNameIn();
int* getIndex(int arr[], int num) noexcept(false);
int readFromFileN1( std::ifstream &f) noexcept(false);
int readFromFileN2( std::ifstream &f) noexcept(false);
int readFromFileArray( std::ifstream &f, int n1, int n2) noexcept(false);
//int sum(int arrSum, int num);
float average(int arr, int num);
string scanFileNameOut();
void writeResult(float result[], int num, std::ofstream &fout);