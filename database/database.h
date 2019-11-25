#ifndef NAGYHAZI_DATABASE_H
#define NAGYHAZI_DATABASE_H

#include "../definitions.h"

/* Betölti a "database.txt" fájlból az elmentett rekordokat és a
 * paraméterként átvett lista végére fűzi őket.*/
bool loadDatabase(list recordList);

/* Aktuális időpillanatban a paraméterként kapott listában
 * tárolt adatokat elmenti a "database.txt" fájlba */
bool saveDatabase(list recordList);

/* Kilistázza, megjeleníti a paraméterként kapott lista összes elemét.*/
void printDatabase(list recordList);

/* Keresést hajt végre egy paraméterként kapott keresési feltétel alapján
 * a szintén paraméterként kapott listában és kiírja az így talált adatokat.*/
void searchDatabase(list recordList, searchCondition condition);

#endif //NAGYHAZI_DATABASE_H
