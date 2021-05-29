#include "data.h"

int main() {
    ///home/kate/Стільниця/lab28.txt

    string fileName;
    try {
        fileName =  scanFileNameIn();
    } catch (std::exception &e) {
        cout << "ERROR: " << e.what();
    }
    

    std::ifstream fin;

    try {
        fin.open(fileName);
        cout << "File for reading information is open!" << endl;
    } catch (const std::exception& exception) {
        cout << exception.what() << endl;
        cout << "Can not open the file!" << endl;
    }
    try {
        if (!fin.is_open()) {
            throw fileName;
        }
    }
    catch(string filename) {
        cout << "Can't open file with this name "<< fileName << endl;
    }
    int  num1 = readFromFileN1(fin);
    try {
        if (num1 <= 0) {
            throw std::exception();
        }
        cout << "Value can be array length" << endl;
    } catch (std::exception &exception) {
        cout << "Value can't be an array length!" << endl;
    }
    int num2 = readFromFileN2(fin);

    int arr[num1][num2];

    int sum[num1];
    int suma = 0;
    for (int i = 0; i < num1; ++i) {
        getIndex(arr[i], num1);
        suma = 0;
        for (int j = 0; j < num2; ++j) {

            arr[i][j] = readFromFileArray(fin, num1, num2);
            suma += arr[i][j];
            //cout << arr[i][j] << " ";
        }
        sum[i] = suma;
    }
    fin.close();
    float averageArr[num1];
    for (int i = 0; i < num1; ++i) {
        averageArr[i] = average(sum[i], num1);
        cout << averageArr[i] << " " << endl;
    }
    string fileOut = scanFileNameOut();
    std::ofstream fout;
    try {
        fout.open(fileOut);
        cout << "File for result is open!" << endl;
    } catch (const std::exception& exception) {
        cout << exception.what() << endl;
        cout << "Can not open the file! " << exception.what() << endl;
    }


    writeResult(averageArr, num1, fout);
    fout.close();
    return 0;
}

