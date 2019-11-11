#ifndef NAGYHAZI_DATABASE_H
#define NAGYHAZI_DATABASE_H

#include "../definitions.h"

/* Betölti a "database.txt" fájlból az elmentett rekordokat és a program által kezelhető
 * láncolt listává alakítja őket.*/
bool loadDatabase(list recordList);

/* A program által az aktuális időpillanatban tárolt adatokat elmenti a "database.txt" fájlba */
bool saveDatabase(list recordList);
void searchDatabase(list recordList, searchCondition condition);
void printDatabase(list recordList);

#endif //NAGYHAZI_DATABASE_H
