#ifndef DEFINITIONS_H
#define DEFINITIONS_H

/* Láncolt lista elemet definiál, ami tartalmazza egy könyv adatait (szerző, cím, műfaj, kiadási év). A szerző
 * maximum 30 karakter, a cím maximum 50 karakter, a műfaj maximum 30 karakter lehet. */
typedef struct listElement {
    char author[31];
    char title[51];
    char genre[31];
    int year;
    struct listElement *next, *previous;
} listElement;

/* Definiál egy duplán láncolt listát. Tartalmazza a lista első és utolsó elemnére mutató pointert. */
typedef struct list {
    listElement *first, *last;
} list;

/* Definiálja az adatbázis keresésénél használható keresési feltételeket. */
typedef enum searchCondition{
    author, title, genre, year
} searchCondition;

#endif //NAGYHAZI_DEFINITIONS_H
