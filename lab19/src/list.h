#include "data.h"
#include <stddef.h>
#include <strings.h>
#pragma once
struct ElementCapsule{
    struct ElementCapsule *previous;
    struct Instrument instrument;
    struct ElementCapsule *next;
};

struct Container{
    struct ElementCapsule *head;
    int size;
    struct ElementCapsule *tail;
};
struct ElementCapsule *get_element_by_pos(struct Container* container, size_t pos);

struct ElementCapsule* getInstrumentList(struct Container * container);

void insertEl(struct Container * container, size_t pos, struct Instrument* instrument);

struct ElementCapsule* writeInFileList(struct Container *container);

struct ElementCapsule* sortByYearList(struct Container *container);

//struct ElementCapsule* addElement(struct Container * container, size_t pos, struct Instrument** instrument);

void showArray(struct Container* container);

void showList(struct Container* container);

void deleteElementNext(struct Container *container, size_t pos);

void addElement(struct Container *container, size_t pos, struct Instrument ** instrument);

void findByCriterion(struct Container * container);

void cleanUp(struct Container * container);

void dialog(struct Container *container, struct Instrument ** instrument);


