#ifndef NAGYHAZI_RECORDS_H
#define NAGYHAZI_RECORDS_H

#include "../definitions.h"

/* Bekéri a felhasználótól egy könyv adatait, majd hozzáfűzi az így
 * létrehozott listaelemet a paraméterként kapott lista végéhez.
 * Igaz értékkel tér vissza ha a művelet sikeres, különben hamissal.*/
bool addRecord(list thisList);

/* */
bool modifyRecord(listElement *thisElement);

/* */
bool removeRecord(listElement *thisElement);


#endif //NAGYHAZI_RECORDS_H
