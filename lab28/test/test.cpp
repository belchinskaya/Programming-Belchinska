#include "data.h"
bool test_average() {
    bool result = false;
    float expected = 1.5;
    float  actual = average(6, 4);
    cout <<"Actual result is: " << actual << endl;
    cout << "And expected result is: " << expected << endl;
    if (expected == actual) {
        result = true;
    }
    return result;
}
int main() {
    bool result = true;
    result &= test_average();
    if (result) {
        cout << "Test succeed!" << endl;
    } else {
        cout << "Test failed" << endl;
    }
    return result ? 0 : 1;
}