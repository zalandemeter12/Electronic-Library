#ifndef NAGYHAZI_UTILS_H
#define NAGYHAZI_UTILS_H

#include "../definitions.h"

/* Egy paraméterként átvett karaktertömböt feldarabol 4 adattípusra (szerző, cím, műfaj, kiadási év).
 * A karaktertömb formátuma [    szerző|cím|műfaj|kiadási_év     ]
 * Az így kapott adatokat elmenti a paraméterként átvett lista elembe megfelelő értékeibe.*/
void dataSplit(char *recordLine, listElement *thisElement);

/* Kiírja egy paraméterként átvett lista elem adatait megfelelően formázva.*/
void printRecord(listElement *thisElement);

#endif //NAGYHAZI_UTILS_H
