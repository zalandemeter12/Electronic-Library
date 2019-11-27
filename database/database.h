#ifndef DATABASE_H
#define DATABASE_H

#include "../definitions.h"

/* Betölti a "database.txt" fájlból az elmentett rekordokat és a paraméterként átvett lista végére fűzi őket. Ha a fájl
 * megnyitása során hibába ütközik, hamis értékkel tér vissza. Ha a beolvasott elemeknek nem tud memóriát foglalni hamis
 * értékkel tér vissza. Sikeres beolvasás esetén igaz értékkel tér vissza. */
bool loadDatabase(list *recordList);

/* Aktuális időpillanatban a paraméterként kapott lista változó által tárolt adatokat elmenti a "database.txt" fájlba.
 * A tárolt rekordokat fájlba írja a megfelelő formátum szerint: szerző|cím|műfaj|kiadási_év
 * Ha a fájl megnyitása során hibába ütközik, hamis értékkel tér vissza. */
bool saveDatabase(list *recordList);

/* Kilistázza a paraméterként kapott lista összes elemét egy görgethető listában. A görgetést a fel - le nyilakkal
 * leütésével végezheti a felhasználó. Az ESC gomb megynomására a függvény visszatér. A megjelenítésért egy ciklus felel,
 * ami minden futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a megfelelő függvényeket. */
void printDatabase(list *recordList);

/* Keresést hajt végre egy paraméterként kapott keresési feltétel alapján a szintén paraméterként kapott listában és
 * kiírja az így talált adatokat egy görgethető listában. */
void searchDatabase(list *recordList, searchCondition condition);

#endif //DATABASE_H
