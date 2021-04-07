#include "list.h"
#include "data.h"
struct ElementCapsule *get_element_by_pos(struct Container* container, size_t pos){
    struct ElementCapsule * walker = container->head;
    for (int i = 0; i < pos; i++){
        walker = walker->next;

    }

    return walker;
}
//void insertEl(struct Container *container, size_t pos, struct Instrument** instrument){
//    struct Instrument** new_array = malloc((container->size + 1) * sizeof(struct Instrument*));
//    for (int i = 0; i < INSTRUMENT_COUNT; i++){
//        *(new_array + i) = get_element_by_pos();
//    }
//}
void insertEl(struct Container * container, size_t pos, struct Instrument * instrument) {
    if (pos > container->size) {
        pos = container->size;
    }
    struct ElementCapsule *walker = get_element_by_pos(container, pos);

     struct ElementCapsule *temp_insert = malloc(sizeof(struct ElementCapsule));
     memcpy(&temp_insert->instrument, instrument, sizeof(struct ElementCapsule));

    walker->next->previous = temp_insert;

    temp_insert->next = walker->next;
    temp_insert->previous = walker;
    walker->next = temp_insert;
    container->size++;

}
struct ElementCapsule* getInstrumentList(struct Container * container) {
    FILE * file = fopen("/home/kate/Programming-Belchynska/lab18/instruments.txt", "r");
    //readFromFile(instrument);
    if (file == NULL) {
        printf("can't open because: %s", strerror(errno));
        exit(1);
    }
    for (int j = 0; j < INSTRUMENT_COUNT; j++) {
        struct Instrument item;
        fscanf(file, "%s %s %d %f", item.type, item.firm, &(item.year), &(item.size));
        fscanf(file, "%d", &item.bow.weight);
        fscanf(file, "%d", &item.bow.material);
        insertEl(container, j, &item);
    }

    fclose(file);
}



struct ElementCapsule* sortByYearList(struct Container *container) {
    struct ElementCapsule *walker = container->head;
    walker = walker->next;

    //struct Instrument* item = *(instruments + i);
    struct Instrument *item = malloc(INSTRUMENT_COUNT * sizeof(struct Instrument *));
    //for (int i = 0; i < INSTRUMENT_COUNT; i++) {
    //struct Instrument* item = *(instruments + i);
    for (int j = 0; j < INSTRUMENT_COUNT; j++) {
        walker = container->head;
        walker = walker->next;
        while (walker->next != NULL) {

            if (walker->instrument.year > walker->next->instrument.year) {
                *item = walker->instrument;
                walker->instrument = walker->next->instrument;
                walker->next->instrument = *item;
            }
            //printf("\n%s\n", walker->instrument.type);
            walker = walker->next;

        }
    }

    showArray(container);

    //return &walker->instrument;
}

struct ElementCapsule* writeInFileList(struct Container *container){
    FILE * file = fopen("/home/kate/Programming-Belchynska/lab18/instrumentsOutLists.txt", "w");
    struct ElementCapsule* walker = container->head;
    walker = walker->next;

    while (walker != NULL) {
        int j = 0;
        fprintf(file,"\t%s\n", walker->instrument.type);
        fprintf(file,"\t%s\n", walker->instrument.firm);
        fprintf(file,"\t%d\n", walker->instrument.year);
        fprintf(file,"\t%f\n", walker->instrument.size);
        fprintf(file,"\t%d\n", walker->instrument.bow.weight);
        switch (walker->instrument.bow.material) {
            case BT: fprintf(file,"\tBow material: Brazilian Tree\n\n");
                break;
            case PERNAMBUCO: fprintf(file,"\tBow material: Pernambuco\n\n");
                break;
            case FIBERGLASS: fprintf(file,"\tBow material: Fiberglass\n\n");
                break;
        }
        walker = walker->next;

    }
}

void addElement(struct Container *container, size_t pos, struct Instrument ** instrument){
    if (pos > container->size) {
        pos = container->size;
    }
    struct ElementCapsule *walker = get_element_by_pos(container, pos);

    struct ElementCapsule *temp_insert = malloc(sizeof(struct ElementCapsule));
    memcpy(&temp_insert->instrument, *(instrument + 0), sizeof(struct Instrument));

    walker->next->previous = temp_insert;

    temp_insert->next = walker->next;
    temp_insert->previous = walker;
    walker->next = temp_insert;
    container->size++;

    showArray(container);

    //return walker;
}
void  deleteElementNext(struct Container *container, size_t pos){
    if(container->size == 0) return;
    if (pos >= container->size) pos = container->size - 1;

    struct ElementCapsule *walker = get_element_by_pos(container, pos);
    struct ElementCapsule *toDelete = walker->next;

    walker->next = toDelete->next;
    //walker->previous = toDeletePrev->previous;
    walker->previous = walker->next->previous;
    toDelete = NULL;

    free(toDelete);

    container->size--;

}
void showArray(struct Container* container){
    struct ElementCapsule* walker = container->head;
    walker= walker->next;

    while (walker->next != NULL) {
        printf("\tType: %s\n", walker->instrument.type);
        printf("\tFirm: %s\n", walker->instrument.firm);
        printf("\tYear: %d\n", walker->instrument.year);
        printf("\tSize: %f\n", walker->instrument.size);
        printf("\tBow Weight: %d\n", walker->instrument.bow.weight);
        switch (walker->instrument.bow.material) {
            case BT: printf("\tBow material: Brazilian Tree\n\n");
                break;
            case PERNAMBUCO: printf("\tBow material: Pernambuco\n\n");
                break;
            case FIBERGLASS: printf("\tBow material: Fiberglass\n\n");
                break;
        }
        walker = walker->next;

    }
}

void showList(struct Container* container){
    struct ElementCapsule* walker = container->tail;
    walker = walker->previous;
    while (walker->previous != NULL) {
        printf("\tType: %s\n", walker->instrument.type);
        printf("\tFirm: %s\n", walker->instrument.firm);
        printf("\tYear: %d\n", walker->instrument.year);
        printf("\tSize: %f\n\n", walker->instrument.size);
        walker = walker->previous;

    }
}
struct ElementCapsule* findByCriterion(struct Container * container){
    char seekInstrument[10] = "Yamaha";
    struct ElementCapsule* walker = container->head;
    walker = walker->next;
    while (walker->next != NULL) {
        if (strcmp(seekInstrument, walker->instrument.firm) == 0) {
            printf("\tType: %s\n", walker->instrument.type);
            printf("\tFirm: %s\n", walker->instrument.firm);
            printf("\tYear: %d\n", walker->instrument.year);
            printf("\tSize: %f\n", walker->instrument.size);
            printf("\tBow Weight: %d\n", walker->instrument.bow.weight);
            switch (walker->instrument.bow.material) {
                case BT:
                    printf("\tBow material: Brazilian Tree\n\n");
                    break;
                case PERNAMBUCO:
                    printf("\tBow material: Pernambuco\n\n");
                    break;
                case FIBERGLASS:
                    printf("\tBow material: Fiberglass\n\n");
                    break;
            }
            break;
        }
        walker = walker->next;
    }
    return walker;
}
void dialog(struct Container *container, struct Instrument ** instrument){
    int num = 0;
    printf("Press:\n 1 - to sort instruments,\n 2 - to write list in file,\n 3 - to delete element,\n 4 - to write additional element,\n 5 - find element by criterion\n 6 - to write list in reverse order\n");
    scanf("%d", &num);
    int n = 0;

    switch (num) {
        case 1:
            sortByYearList(container);
            dialog(container, instrument);
            //showArray(container);
            break;
        case 2: writeInFileList(container);
            //dialog(container, instrument);
            break;
        case 3: printf("Print position to delete new element: \n");
            scanf("%d", &n);
            deleteElementNext(container, n);
            showArray(container);
            dialog(container, instrument);
            break;
        case 4:  printf("Print position for adding new element: \n");
            //scanf("%d", &n);
            addElement(container, 0, instrument);
            //showArray(container);
            dialog(container, instrument);
            break;
        case 5: findByCriterion(container);
            dialog(container, instrument);

            break;
        case 6: showList(container);
            dialog(container, instrument);
            break;
        default: printf("\nYou enter incorrect number\n");
            dialog(container, instrument);
    }

}

void cleanUp(struct Container * container){
    while (container->size > 0) {
        deleteElementNext(container,0);
    }
}