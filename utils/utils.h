#ifndef NAGYHAZI_UTILS_H
#define NAGYHAZI_UTILS_H

#include "../definitions.h"

/* Létrehozza a felhasználói felület megjelenítését
* és beállítja a megnyíló ablakot. */
void econioInit();

/* Törli a program felhasználói felületét is visszaállítja a
* terminál alapértelmezett tulajdonságait. */
void econioExit();

void printBox(int x, int y, int w, int h, int color);

void printBanner();
void printHeader(char *info);

/* Egy paraméterként átvett karaktertömböt feldarabol 4 adattípusra (szerző, cím, műfaj, kiadási év).
 * A karaktertömb formátuma [    szerző|cím|műfaj|kiadási_év     ]
 * Az így kapott adatokat elmenti a paraméterként átvett lista elembe megfelelő értékeibe.*/
void dataSplit(char *recordLine, listElement *thisElement);

/* Kiírja egy paraméterként átvett lista elem adatait megfelelően formázva.*/
void printRecord(listElement *thisElement, int x, int y, int bgcolor);

void printFromTo(list thisList, int from, int to, int selected, int x, int y);

bool confirmAction(listElement *thisElement);

#endif //NAGYHAZI_UTILS_H
