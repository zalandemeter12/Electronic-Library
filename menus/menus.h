#ifndef MENUS_H
#define MENUS_H

#include <stdbool.h>
#include "../definitions.h"

/* Megjeleníti a paraméterként kapott sztringek tömbjét menüként. Szükséges paramétere a kilistázni kívánt menüpontok
 * száma, az aktuálisan kijelölt menüpont indexe és a megjelenítendő menű bal felső sarkának x,y koordinátája. */
void printMenu (char **menuElements, int elementNumber, int selectedIndex, int x, int y);

/* Megjeleníti a főmenüt. Lehetővéteszi a menüpontok kiválasztását a fel le nyilakkal. A menüpont megnyitását az ENTER
 * lenyomásával teheti a felhasználó. A kiválasztott menüpont (rekord menü, adatbázis menü) újabb almenük függvényét hívja
 * meg. A kilépés menüpont kiválasztásakor a vüggvény visszatér. A menü megjelenítéséért egy ciklus felel, ami minden
 * futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a megfelelő függvényeket. */
void mainMenu(list *recordList);

/* Megjeleníti a rekord menüt. Lehetővéteszi a menüpontok kiválasztását a fel le nyilakkal. A menüpont megnyitását az
 * ENTER lenyomásával teheti a felhasználó. A hozzáadás/törlés/módosítás kiválasztása esetén a függvény meghívja az
 * ezekért a feladatokért felelős függvényeket. A vissza választásakor vagy az ESC leütésekor a függvény visszatér a
 * főmenübe. A menü megjelenítéséért egy ciklus felel, ami minden futásakor beolvassa a leütött billentyűt és ez alapján
 * hívja meg a megfelelő függvényeket. */
void recordMenu(list *recordList);

/* Megjeleníti az adatbázis menüt. Lehetővéteszi a menüpontok kiválasztását a fel le nyilakkal. A menüpont megnyitását
 * az ENTER lenyomásával teheti a felhasználó. A keresés/kilistázás/mentés kiválasztása esetén a függvény meghívja az
 * ezekért a feladatokért felelős függvényeket. A vissza választásakor vagy az ESC leütésekor a függvény visszatér a
 * főmenübe. A menü megjelenítéséért egy ciklus felel, ami minden futásakor beolvassa a leütött billentyűt és ez alapján
 * hívja meg a megfelelő függvényeket. */
void databaseMenu(list *recordList);

/* Megjeleníti a keresés menüt. Lehetővéteszi a menüpontok kiválasztását a fel le nyilakkal. A menüpont megnyitását az
 * ENTER lenyomásával teheti a felhasználó. A különböző keresések kiválasztása esetén a függvény meghívja az ezekért a
 * feladatokért felelős függvényeket. A vissza választásakor vagy az ESC leütésekor a függvény visszatér az adatbázis
 * menübe. A menü megjelenítéséért egy ciklus felel, ami minden futásakor beolvassa a leütött billentyűt és ez alapján
 * hívja meg a megfelelő függvényeket. */
void searchMenu(list *recordList);

#endif //MENUS_H
