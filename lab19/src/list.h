#include "data.h"
struct ElementCapsule {
    struct ElementCapsule *prev;
    struct Instrument instrument;
    struct ElementCapsule *next;
};

struct  Container{
    struct ElementCapsule *head;
    int size;
};
struct ElementCapsule *get_element_by_pos(struct Container* container, size_t pos);

void insertEl(struct Container * container, size_t pos, struct Instrument * instrument);

struct ElementCapsule* getInstrumentList(struct Container * container);

void showArray(struct Container* container);

struct ElementCapsule* sortByYearList(struct Container *container);

struct ElementCapsule* writeInFileList(struct Container *container);

void addElement(struct Container *container, size_t pos, struct Instrument ** instrument);

void  deleteElementNext(struct Container *container, size_t pos);

void findByCriterion(struct Container * container);

void dialog(struct Container *container, struct Instrument ** instrument);
void cleanUp(struct Container * container);