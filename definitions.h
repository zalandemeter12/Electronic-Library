#ifndef NAGYHAZI_DEFINITIONS_H
#define NAGYHAZI_DEFINITIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct listElement {
    char *author;
    char *title;
    char *genre;
    int year;
    struct listElement *next, *previous;
} listElement;

typedef struct list {
    int *elementNumber;
    listElement *first, *last;
} list;

typedef enum searchCondition{
    author, title, genre, year
} searchCondition;


#endif //NAGYHAZI_DEFINITIONS_H
