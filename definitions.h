#ifndef NAGYHAZI_DEFINITIONS_H
#define NAGYHAZI_DEFINITIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



typedef struct listElement {


    struct listElement *next, *previous;
} listElement;



typedef struct List {
    listElement *first;
    listElement *last;
} list;



#endif //NAGYHAZI_DEFINITIONS_H
