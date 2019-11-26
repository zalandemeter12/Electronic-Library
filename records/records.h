#ifndef NAGYHAZI_RECORDS_H
#define NAGYHAZI_RECORDS_H

#include "../definitions.h"

/* Bekéri a felhasználótól egy könyv adatait, majd hozzáfűzi az így létrehozott listaelemet a paraméterként kapott lista
 * elejéhez. Ha nem tud memóriát foglalni az új elemnek hamis értékkel tér vissza, különben igazzal. */
bool addRecord(list recordList);

/* Megjeleníti egy görgethető listában az adatbázis elemeit. ENTER leütésével a felhasználó kiválaszthat egy adatot.
 * A kiválasztott adatra meghívja az adatot módosító függvényt, majd visszatér. ESC leütésére a függvény visszatér. A
 * megjelenítésért egy ciklus felel ami minden futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a
 * megfelelő függvényeket. */
bool modifyRecord(list recordList);

/* Megjeleníti egy görgethető listában az adatbázis elemeit. ENTER leütésével a felhasználó kiválaszthat egy adatot.
 * A kiválasztott adatra meghívja az adatot törlő függvényt, majd visszatér. ESC leütésére a függvény visszatér. A
 * megjelenítésért egy ciklus felel ami minden futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a
 * megfelelő függvényeket. */
bool removeRecord(list recordList);


#endif //NAGYHAZI_RECORDS_H
