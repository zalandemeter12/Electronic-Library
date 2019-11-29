#include "menus.h"
#include "../econio/econio.h"
#include "../utils/utils.h"
#include "../records/records.h"
#include "../database/database.h"

#include "../debugmalloc/debugmalloc.h"

void printMenu (char **menuElements, int elementNumber, int selectedIndex, int x, int y){
    for (int index = 0; index < elementNumber; index++) {
        /* Beállítja a kiírt menüpont háttér és betűszínét aszerint, hogy melyik van kiválasztva. */
        if (index == selectedIndex){
            econio_textbackground(COL_LIGHTGRAY); econio_textcolor(COL_BLACK);
        } else{
            econio_textbackground(COL_DARKGRAY); econio_textcolor(COL_LIGHTGRAY);
        }

        /* Kiírja az adott menüpontot. */
        econio_gotoxy(x, y+index); printf("%s",menuElements[index]);
    }
}

void mainMenu(list *recordList){
    int key;
    int index = 0;
    bool quit = false;

    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER");
    printFromTo(recordList,0,10,-1,8,31);

    char *menuElements[] = {" Rekord menü    ", " Adatbázis menü ", " Kilépés        "};
    printMenu(menuElements, 3, 0, 8, 17);

    /* Amíg a quit változó értékét igazra nem állítja a felhasznnáló, addig a ciklus minden futásakor beolvassa a
     * leütött billentyűt és kiértékeli azt. */
    while (!quit){
        key = econio_getch();
        switch (key) {
            case KEY_DOWN:
                /* Megnöveli a kijelölt elem indexét és kiírja az ehhez megfelelő menüt. */
                if (index != 2) index++;
                printMenu(menuElements, 3, index, 8, 17);
                break;
            case KEY_UP:
                /* Lecsökkenti a kijelölt elem indexét és kiírja az ehhez megfelelő menüt. */
                if (index != 0) index--;
                printMenu(menuElements, 3, index, 8, 17);
                break;
            case KEY_ENTER:
                /* Az aktuális index alapján meghívja a megfelelő függvényt, vagy igazra állítja a quit értékét. */
                switch (index) {
                    case 0:
                        recordMenu(recordList);
                        break;
                    case 1:
                        databaseMenu(recordList);
                        break;
                    case 2:
                        quit = true;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

}

void recordMenu(list *recordList){
    int key;
    int index = 0;
    bool quit = false;

    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");

    char *menuElements[] = {" Hozzáadás ", " Törlés    ", " Módosítás ", " Vissza    "};
    printMenu(menuElements, 4, 0, 32, 17);

    /* Amíg a quit változó értékét igazra nem állítja a felhasznnáló, addig a ciklus minden futásakor beolvassa a
     * leütött billentyűt és kiértékeli azt. */
    while (!quit){
        key = econio_getch();
        switch (key) {
            case KEY_DOWN:
                /* Megnöveli a kijelölt elem indexét és kiírja az ehhez megfelelő menüt. */
                if (index != 3) index++;
                printMenu(menuElements, 4, index, 32, 17);
                break;
            case KEY_UP:
                /* Lecsökkenti a kijelölt elem indexét és kiírja az ehhez megfelelő menüt. */
                if (index != 0) index--;
                printMenu(menuElements, 4, index, 32, 17);
                break;
            case KEY_ENTER:
                /* Az aktuális index alapján meghívja a megfelelő függvényt, vagy igazra állítja a quit értékét. */
                switch (index) {
                    case 0:
                        addRecord(recordList);
                        break;
                    case 1:
                        /* Ha nem üres a rekordokat tartalmazó lista meghívja a megfelelő függvényt. */
                        if (recordList->first->next != recordList->last)
                            removeRecord(recordList);
                        break;
                    case 2:
                        /* Ha nem üres a rekordokat tartalmazó lista meghívja a megfelelő függvényt. */
                        if (recordList->first->next != recordList->last)
                            modifyRecord(recordList);
                        break;
                    case 3:
                        printBox(32,17,11,4,COL_DARKGRAY);
                        quit = true;
                        break;
                    default:
                        break;
                }
                break;
            case KEY_ESCAPE:
                /* Igazra állítja a quit értékét ami miatt vissza fog térni a függvény. */
                printBox(32,17,11,4,COL_DARKGRAY);
                quit = true;
                break;
            default:
                break;
        }
    }
    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER");
}

void databaseMenu(list *recordList){
    int key;
    int index = 0;
    bool quit = false;

    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER     Visszalépés: ESC");

    char *menuElements[] = {" Keresés    ", " Kilistázás ", " Mentés     ", " Vissza     "};
    printMenu(menuElements, 4, 0, 32, 17);

    /* Amíg a quit változó értékét igazra nem állítja a felhasznnáló, addig a ciklus minden futásakor beolvassa a
     * leütött billentyűt és kiértékeli azt. */
    while (!quit){
        key = econio_getch();
        switch (key) {
            case KEY_DOWN:
                if (index != 3) index++;
                printMenu(menuElements, 4, index, 32, 17);
                break;
            case KEY_UP:
                if (index != 0) index--;
                printMenu(menuElements, 4, index, 32, 17);
                break;
            case KEY_ENTER:
                /* Az aktuális index alapján meghívja a megfelelő függvényt, vagy igazra állítja a quit értékét. */
                switch (index) {
                    case 0:
                        searchMenu(recordList);
                        break;
                    case 1:
                        printDatabase(recordList);
                        break;
                    case 2:
                        saveDatabase(recordList);
                        printBox(32,17,12,4,COL_DARKGRAY);
                        quit = true;
                        break;
                    case 3:
                        printBox(32,17,12,4,COL_DARKGRAY);
                        quit = true;
                        break;
                    default:
                        break;
                }
                break;
            case KEY_ESCAPE:
                /* Igazra állítja a quit értékét ami miatt vissza fog térni a függvény. */
                printBox(32,17,12,4,COL_DARKGRAY);
                quit = true;
                break;
            default:
                break;
        }
    }
    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER");
}

void searchMenu(list *recordList){
    int key;
    int index = 0;
    bool quit = false;

    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER     Visszalépés: ESC");

    char *menuElements[] = {" Szerző alapján     ", " Cím alapján        ", " Műfaj alapján      ", " Kiadási év alapján ", " Vissza             "};
    printMenu(menuElements, 5, 0, 52, 17);

    /* Amíg a quit változó értékét igazra nem állítja a felhasznnáló, addig a ciklus minden futásakor beolvassa a
     * leütött billentyűt és kiértékeli azt. */
    while (!quit){
        key = econio_getch();
        switch (key) {
            case KEY_DOWN:
                if (index != 4) index++;
                printMenu(menuElements, 5, index, 52, 17);
                break;
            case KEY_UP:
                if (index != 0) index--;
                printMenu(menuElements, 5, index, 52, 17);
                break;
            case KEY_ENTER:
                /* Az aktuális index alapján meghívja a megfelelő függvényt, vagy igazra állítja a quit értékét. */
                switch (index) {
                    case 0:
                        searchDatabase(recordList,author);
                        break;
                    case 1:
                        searchDatabase(recordList,title);
                        break;
                    case 2:
                        searchDatabase(recordList,genre);
                        break;
                    case 3:
                        searchDatabase(recordList,year);
                        break;
                    case 4:
                        printBox(52,17,20,5,COL_DARKGRAY);
                        quit = true;
                        break;
                    default:
                        break;
                }
                break;
            case KEY_ESCAPE:
                /* Igazra állítja a quit értékét ami miatt vissza fog térni a függvény. */
                printBox(52,17,20,5,COL_DARKGRAY);
                quit = true;
                break;
            default:
                break;
        }
    }
}