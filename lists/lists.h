#ifndef LISTS_H
#define LISTS_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../definitions.h"

/* Létrehoz egy duplán láncolt strázsás listát és visszatér vele. A lista tartalmazza a benne tárolt elemeket határoló
 * strázsákra mutató pointereket. */
list *createList();

/* Felszabadítja a paraméterként kapott lista által lefoglalt memória területeket, törli a listát. */
void removeList(list *thisList);

/* Létrehoz egy új listaelemet, lefoglalja az ehhez szükséges memóriaterületeket és visszatér az új elemre mutató
 * pointerrel. Ha nem tudott memóriát foglalni NULL pointerrel tér vissza. */
listElement *newElement();

/* Létrehoz egy új listaelemet és a paraméterként átvett listaelem adatait átmásolja ide, visszatér az új listaelemre
 * mutató pointerrel. Ha nem tudott memóriát foglalni NULL pointerrel tér vissza. Ha a paraméterként átvett listaelemre
 * mutató pointer NULL pointer, NULL pointerrel tér vissza. */
listElement *copyElement(listElement *sourceElement);

/* A paraméterként kapott listaelemet hozzáfűzi a szintén paraméterként kapott lista elejéhez. */
void appendElementFirst(list *thisList, listElement *thisElement);

/* A paraméterként kapott listaelemet hozzáfűzi a szintén paraméterként kapott lista végéhez. */
void appendElementLast(list *thisList, listElement *thisElement);

/* Végig iterál a listán és visszatér a paraméterként átvett indexű elemre mutató pointerrel. Ha a kapott index túl nagy
 * NULL pointerrel tér vissza. */
listElement *getNth(list *thisList, int index);

/* Bekéri a felhasználótól a megváltoztatni kívánt adatokat, majd a felhasználó jóváhagyása után módosítja a
 * paraméterként kapott listaelem adatait. Hamis értékkel tér vissza ha a paraméterként kapott listaelemre mutató
 * pointer NULL pointer. */
bool modifyElement(listElement *thisElement);

/* Kifűzi a listából a paraméterként kapott listaelemet és felszabadítja az általa foglalt memóriaterületet. Ha a kapott
 * pointer NULL pointer, hamis értékkel tér vissza. Ha a felhasználó nem hagyja jóvá a törlést akkor is hamis értékkel
 * tér vissza.*/
bool removeElement(listElement *thisElement);

#endif //LISTS_H
