#include "lib.h"
#include <stdbool.h>
#define INSTRUMENT_COUNT_TEST 3

bool test_sortByYear() {
    bool result = true;

    struct Instrument ** instrument = malloc(INSTRUMENT_COUNT_TEST * sizeof(struct Instrument* ));
    for (int i = 0; i < 200; i++) {
        *(instrument + i) = malloc(sizeof(struct Instrument));

    }
    strcpy((*(instrument + 0))->type, "Acoustic");
    strcpy((*(instrument + 0))->firm, "Stenor");
    (*(instrument + 0))->year = 1800;
    (*(instrument + 0))->size = 0.25f;
    (*(instrument + 0))->bow.weight = 800;
    (*(instrument + 0))->bow.material = PERNAMBUCO;

    strcpy((*(instrument + 1))->type, "Acoustic");
    strcpy((*(instrument + 1))->firm, "Yamaha");
    (*(instrument + 1))->year = 1902;
    (*(instrument + 1))->size = 1.0f;
    (*(instrument + 1))->bow.weight = 1500;
    (*(instrument + 1))->bow.material = FIBERGLASS;

    strcpy((*(instrument + 2))->type, "Classic");
    strcpy((*(instrument + 2))->firm, "Cecilio");
    (*(instrument + 2))->year = 1824;
    (*(instrument + 2))->size = 0.5f;
    (*(instrument + 2))->bow.weight = 1000;
    (*(instrument + 2))->bow.material = BT;

//            {"Acoustic", "Stenor", 1800, 0.25f, (800, PERNAMBUCO)},
//            {"Acoustic", "Yamaha", 1902, 1.0f, {1500, FIBERGLASS}},
//            {"Classic", "Cecilio", 1824, 0.5f, {1000, BT}}
//    };

    struct Instrument ** expected = malloc(INSTRUMENT_COUNT_TEST * sizeof(struct Instrument* ));
    for (int i = 0; i < 200; i++) {
        *(expected + i) = malloc(sizeof(struct Instrument));

    }

            //{"Acoustic", "Stenor", 1800, 0.25f, {800, PERNAMBUCO}},
            //{"Acoustic", "Yamaha", 1902, 1.0f, {1500, FIBERGLASS}},
            //{"Classic", "Cecilio", 1824, 0.5f, {1000, BT}}

    strcpy((*(expected + 0))->type, "Acoustic");
    strcpy((*(expected + 0))->firm, "Stenor");
    (*(expected + 0))->year = 1800;
    (*(expected + 0))->size = 0.25f;
    (*(expected + 0))->bow.weight = 800;
    (*(expected + 0))->bow.material = PERNAMBUCO;

    strcpy((*(expected + 1))->type, "Classic");
    strcpy((*(expected + 1))->firm, "Cecilio");
    (*(expected + 1))->year = 1824;
    (*(expected + 1))->size = 0.5f;
    (*(expected + 1))->bow.weight = 1000;
    (*(expected + 1))->bow.material = BT;

    strcpy((*(expected + 2))->type, "Acoustic");
    strcpy((*(expected + 2))->firm, "Yamaha");
    (*(expected + 2))->year = 1902;
    (*(expected + 2))->size = 1.0f;
    (*(expected + 2))->bow.weight = 1500;
    (*(expected + 2))->bow.material = FIBERGLASS;

    struct Instrument** actual = sortByYear(instrument);

    printf("Actual instrument: \n");
    for (int j = 0; j < INSTRUMENT_COUNT_TEST; j++) {
        struct Instrument* item = *(actual + j);
        printf("\tType: %s\n", item->type);
        printf("\tPosition: %s\n", item->firm);
        printf("\tProduction Year: %d\n", item->year);
        printf("\tSize: %f\n", item->size);
        printf("\tBow weight: %d\n", item->bow.weight);
        switch (item->bow.material) {
            case BT: printf("\tBow material: Brazilian Tree\n\n");
                break;
            case PERNAMBUCO: printf("\tBow material: Pernambuco\n\n");
                break;
            case FIBERGLASS: printf("\tBow material: Fiberglass\n\n");
                break;
        }

    }


    for (int j = 0; j < INSTRUMENT_COUNT_TEST; j++) {
        if (strcmp((*(instrument + j))->type, (*(expected + j))->type) != 0 || strcmp((*(instrument + j))->firm, (*(expected + j))->firm) != 0 || (*(expected + j))->year != (*(instrument + j))->year) {
            result = false;
        } else {
            result =  true;
        }

    }
    free(instrument);
    return result;
}

bool test_printTheOldestInstrument(){
    bool success = true;
    struct Instrument ** instrument = malloc(INSTRUMENT_COUNT * sizeof(struct Instrument* ));
    for (int i = 0; i < 200; i++) {
        *(instrument + i) = malloc(sizeof(struct Instrument));

    }


    strcpy((*(instrument + 0))->type, "Acoustic");
    strcpy((*(instrument + 0))->firm, "Stenor");
    (*(instrument + 0))->year = 1800;
    (*(instrument + 0))->size = 0.25f;
    (*(instrument + 0))->bow.weight = 800;
    (*(instrument + 0))->bow.material = PERNAMBUCO;

    strcpy((*(instrument + 1))->type, "Acoustic");
    strcpy((*(instrument + 1))->firm, "Yamaha");
    (*(instrument + 1))->year = 1902;
    (*(instrument + 1))->size = 1.0f;
    (*(instrument + 1))->bow.weight = 1500;
    (*(instrument + 1))->bow.material = FIBERGLASS;

    strcpy((*(instrument + 2))->type, "Classic");
    strcpy((*(instrument + 2))->firm, "Cecilio");
    (*(instrument + 2))->year = 1824;
    (*(instrument + 2))->size = 0.5f;
    (*(instrument + 2))->bow.weight = 1000;
    (*(instrument + 2))->bow.material = BT;

    struct Instrument expected = {"Acoustic", "Yamaha", 1902, 1.0f, {1500, BT}};

    struct Instrument* actual = printTheOldestInstrument(instrument);

        if (expected.year != (actual->year)) {
            printf("expected:\n \t%s\n \t%s\n \t%d\n but actual is\n \t%s\n \t%s\n \t%d\n", expected.type, expected.firm, expected.year, actual->type, actual->firm, actual->year);
            success = false;

        } else {
            success = true;
        }



    return success;
}


int main() {
    bool result = true;

    result &= test_sortByYear();
    result &= test_printTheOldestInstrument();

    if (result) {
        printf("Congratulations! All tests succeed!\n");
    } else {
        printf("Some tests failed. Check logs, fix errors and try again\n");
    }
    return result ? 0 : 1;


}

