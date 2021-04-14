/**
 * @mainpage
 * # Основное задание: [3 балла из 10]
 * @brief Дан массив эллипсов, который заполняется случайными данными. Создать функцию, которая находит эллипс максимальной площади.
 */
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>



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
/**
 * Generate random values for ellipse
 * @param ellipse
 * @return
 */
struct Ellipse*generateRandEllipse(struct Ellipse* ellipse){
    ellipse->center.x = rand() % 100 - 20;
    ellipse->center.y = rand() % 100 - 20;
    ellipse->radius1 = rand() % 50 + 1;
    ellipse->radius2 = rand() % 50 + 1;

}

/**
 * Find ellips' area
 * @param ellipse
 * @return
 */
float area(struct Ellipse * ellipse) {
     float area  = ellipse->radius1 * ellipse->radius2 * PI;
    return area;
}

/**
 * Find max ellips area
 * @param ellipse
 * @return
 */
struct Ellipse*MaxArea(struct Ellipse ** ellipse){
    for (int i = 0; i < N; i++) {
        //struct Instrument* item = *(instruments + i);
        for (int j = 0; j < N - 1; j++) {
            float n1 = area(*(ellipse + j));
            float n2 = area(*(ellipse + j + 1));
            if ( n1 < n2) {
                struct Ellipse *temp = *(ellipse + j);
                *(ellipse + j) = *(ellipse + j + 1);
                *(ellipse + j + 1) = temp;
            }
        }

    }
    printf("%f", area(*(ellipse)));
    return *ellipse;
}

/**
 * Find the smallest ellipse area
 * @param ellipse
 * @return
 */
struct Ellipse* MinArea(struct Ellipse ** ellipse){
    for (int i = 0; i < N; i++) {
        //struct Instrument* item = *(instruments + i);
        for (int j = 0; j < N - 1; j++) {
            float n1 = area(*(ellipse + j));
            float n2 = area(*(ellipse + j + 1));
            if ( n1 > n2) {
                struct Ellipse *temp = *(ellipse + j);
                *(ellipse + j) = *(ellipse + j + 1);
                *(ellipse + j + 1) = temp;
            }
        }

    }
    printf("%f", area(*(ellipse)));
    return *ellipse;
}

/**
 * fill array with random ellipses
 * @param ellipse
 * @param container
 */
void fillEllipse(struct Ellipse ** ellipse, struct Container * container){
    struct Ellipse ** el = malloc(((container->size + 1) * sizeof(struct Ellipse*)));
 //   for (int i = 0; ; ++i) {
//        *(el + i) = malloc(((container->size + 1) * sizeof(struct Ellipse)));
 //   }
    float n = 0;

    while ( n < 100) {
        int i = 0;
        memcpy(el, generateRandEllipse(*(ellipse + i)), sizeof(struct Ellipse));

        n += area(*(el));
        if(n >= 150){
            break;
        }
        i++;
    }


}


int main() {
    srand(time(NULL));
    struct Ellipse ** ellipse = malloc(N * sizeof(struct Ellipse*));
    for (int i = 0; i < N; i++){
        *(ellipse + i) = malloc(sizeof (struct Ellipse));
        generateRandEllipse(*(ellipse + i));
        area(*(ellipse + i));
    }
    struct Container * con = malloc(sizeof(struct Container));
    fillEllipse(ellipse, con);


    MaxArea(ellipse);
    MinArea(ellipse);

    free(ellipse);
    return 0;
}

