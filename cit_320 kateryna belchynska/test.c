//#include "data.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


#define N 15
#define PI 3.14

struct Point {
    int x;
    int y;
};
struct Ellipse {
    struct Point center;
    size_t radius1;
    size_t radius2;
};

struct Container {
    struct Ellipse *ellipse;
    int size;
};
float area(struct Ellipse * ellipse) {
    float area  = ellipse->radius1 * ellipse->radius2 * PI;
    return area;
}

bool test_area() {
    bool result = true;
    struct Ellipse ellipse = {{1, 2}, 3, 5};
    float  exp = 47.1f;
    float actual = area(&ellipse);
    if(exp == actual) {
        result = true;
    } else {
        result = false;
    }
    return result;
}
int main() {
    bool result = test_area();
    if(result == true){
        printf("Test succeed\n");
    } else {
        printf("Test failed\n");
    }
    return result ? 0 : 1;
}
