#include "data.h"
string scanFileNameIn() {
    string fileName;
    cout << "Enter file name to open" << endl;
    cin >> fileName;


    return fileName;
}
int readFromFileN1( std::ifstream &f) noexcept(false) {
    int n1;
    try {
        f >> n1;
        if (n1 <= 0) {
            throw std::exception();
        }
        cout << "Value can be array length" << endl;
    } catch (std::exception &exception) {
        cout << "Value can't be an array length!" << endl;
    }


    return n1;
}
int readFromFileN2( std::ifstream &f) noexcept(false) {
    int n2;
    f >> n2;
    return n2;
}

int readFromFileArray( std::ifstream &f, int n1, int n2) noexcept(false) {

    int arr[n1][n2];
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            f >> arr[i][j];
            return arr[i][j];
        }
    }
}

float average(int arr, int num) {
    float result = 0;
    result = (float)arr / (float)num;
    return result;
}

int* getIndex(int arr[], int num) noexcept(false){
    for (int i = 0; i < num; ++i) {
        return &arr[i];
    }
}

string scanFileNameOut() {
    string fileOut;
    cout << "Enter file name to write results" << endl;
    cin >> fileOut;
    return fileOut;
}

void writeResult(float result[], int num, std::ofstream &fout){
    fout << "Average of array's numbers" << endl;
    for (int i = 0; i < num; ++i) {
        fout << result[i] << ", ";
    }
}