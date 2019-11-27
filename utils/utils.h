#ifndef UTILS_H
#define UTILS_H

#include "../definitions.h"

/* Létrehozza a felhasználói felület megjelenítését és beállítja a megnyíló ablakot. */
void econioInit();

/* Törli a program felhasználói felületét is visszaállítja a terminál alapértelmezett tulajdonságait. */
void econioExit();

/* Kirajzol egy ablakot a paraméterként kapott x,y koordináta, a kapott hosszúság, magasság és a kapott szín szerint. Az
 * x,y koordináta az ablak bal felső sarkának koordinátája, a szín az econio könyvtár által definiált színeket jellemző
 * egész szám. */
void printBox(int x, int y, int w, int h, int color);

/* Kirajzolja a könyvtár tetején lévő banner-t egy előre definiált helyen, a képernyő tetején. */
void printBanner();

/* A paraméterként kapott sztring alapján egy információs fejlécet rajzol ki egy előre definiált helyen, a banner alatt. */
void printHeader(char *info);

/* Kiírja egy paraméterként átvett lista elem adatait a paraméterként átvett koordinátán megfelelően formázva.
 * Paraméterként megkapja a kiírás háttérszínét. A szín az econio könyvtár által definiált színeket jellemző egész szám. */
void printRecord(listElement *thisElement, int x, int y, int bgcolor);

/* Kiírja az adatbázis rekordjait egy eleje indextől egy vége indexig, paraméterként kapott koordinátán. A paraméterként
 * kapott kiválasztott elem indexén megjelenő elem háttérszíne előre definiáltan más, mint a többi rekord háttérszíne.*/
void printFromTo(list *thisList, int from, int to, int selected, int x, int y);

/* Kiírja a paraméterként kapott listaelemet a bemeneti sor helyén. És megkérdezi a felhasználót, hogy jóváhagyja-e az
 * adatot. ENTER leütésekor igaz értékkel tér vissza, ESC leütésekor hamis értékkel tér vissza. Mindaddig amíg a két
 * billentyű közül valamelyiket be nem olvassa a függvény addig nem tér vissza. */
bool confirmAction(listElement *thisElement);

#endif //UTILS_H
