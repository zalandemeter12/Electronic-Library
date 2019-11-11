#ifndef NAGYHAZI_LISTS_H
#define NAGYHAZI_LISTS_H

#include "../definitions.h"

/* Létrehoz egy duplán láncolt strázsás listát és visszatér vele.*/
list createList();

/* Felszabadítja a paraméterként kapott lista által lefoglalt
 * memória területeket, törli a listát.*/
void removeList(list thisList);

/* Létrehoz egy új listaelemet, lefoglalja az ehhez szükséges
 * memóriaterületeket és visszatér az új elemre mutató pointerrel. */
listElement *newElement();

/* Felszabadítja a paraméterként kapott listaelem által foglalt
 * memóriaterületeket.*/
void freeElement(listElement *thisElement);

/* A paraméterként kapott listaelemet hozzáfűzi a szintén
 * paraméterként kapott lista elejéhez. */
void appendElementFirst(list thisList, listElement *thisElement);

/* A paraméterként kapott listaelemet hozzáfűzi a szintén
 * paraméterként kapott lista végéhez. */
void appendElementLast(list thisList, listElement *thisElement);


#endif //NAGYHAZI_LISTS_H
