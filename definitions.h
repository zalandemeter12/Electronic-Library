#ifndef NAGYHAZI_DEFINITIONS_H
#define NAGYHAZI_DEFINITIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Duplán láncolt lista elemet definiál, ami tartalmazza egy könyv
 * adatait (szerző, cím, műfaj, kiadási év). */
typedef struct listElement {
    char *author;
    char *title;
    char *genre;
    int year;
    struct listElement *next, *previous;
} listElement;

/* Definiál egy láncolt listát. Tartalmazza a lista első és utolsó
 * elemnére mutató pointert, és a lista elemszámára mutató pointert.*/
typedef struct list {
    int *elementNumber;
    listElement *first, *last;
} list;

/* Definiálja az adatbázis keresésénél használható keresési feltételeket. */
typedef enum searchCondition{
    author, title, genre, year
} searchCondition;

#endif //NAGYHAZI_DEFINITIONS_H
