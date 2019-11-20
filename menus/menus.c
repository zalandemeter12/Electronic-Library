#include "menus.h"
#include "../econio/econio.h"
#include "../utils/utils.h"
#include "../records/records.h"
#include "../database/database.h"

#include "../debugmalloc/debugmalloc.h"


void printMenu (char **menuElements, int elementNumber, int selectedIndex, int x, int y){
    for (int index = 0; index < elementNumber; index++) {
        econio_textbackground(8);
        if (index == selectedIndex){
            econio_textbackground(7);
            econio_textcolor(0);
        }
        else {
            econio_textbackground(8);
            econio_textcolor(7);
        }
        econio_gotoxy(x, y+index); printf("%s",menuElements[index]);
    }
    econio_textbackground(0);
    econio_textcolor(15);
    econio_gotoxy(0,0);
}

void mainMenu(list recordList){
    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER");

    char *menuElements[] = {" Rekord menü    ", " Adatbázis menü ", " Kilépés        "};
    printMenu(menuElements, 3, 0, 8, 17);

    int key; int index = 0; bool quit = false;
    while (!quit){
        key = econio_getch();
        switch (key) {
            case -21:
                if (index != 2) index++;
                printMenu(menuElements, 3, index, 8, 17);
                break;
            case -20:
                if (index != 0) index--;
                printMenu(menuElements, 3, index, 8, 17);
                break;
            case 10:
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
                }
                break;
        }
    }

}

void recordMenu(list recordList){
    printHeader("Menüpont kiválasztása: ↑ ↓ \tMenüpont megnyitása: ENTER");

    char *menuElements[] = {" Hozzáadás ", " Törlés    ", " Módosítás ", " Vissza    "};
    printMenu(menuElements, 4, 0, 32, 17);

    int key; int index = 0; bool quit = false;
    while (!quit){
        key = econio_getch();
        switch (key) {
            case -21:
                if (index != 3) index++;
                printMenu(menuElements, 4, index, 32, 17);
                break;
            case -20:
                if (index != 0) index--;
                printMenu(menuElements, 4, index, 32, 17);
                break;
            case 10:
                switch (index) {
                    case 0:
                        addRecord(recordList);
                        break;
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        printBox(32,17,11,4,8);
                        quit = true;
                        break;
                }
                break;
        }
    }
}

void databaseMenu(list recordList){
    printHeader("Menüpont kiválasztása: ↑ ↓ \tMenüpont megnyitása: ENTER");

    char *menuElements[] = {" Keresés    ", " Kilistázás ", " Mentés     ", " Vissza     "};
    printMenu(menuElements, 4, 0, 32, 17);

    int key; int index = 0; bool quit = false;
    while (!quit){
        key = econio_getch();
        switch (key) {
            case -21:
                if (index != 3) index++;
                printMenu(menuElements, 4, index, 32, 17);
                break;
            case -20:
                if (index != 0) index--;
                printMenu(menuElements, 4, index, 32, 17);
                break;
            case 10:
                switch (index) {
                    case 0:
                        searchMenu(recordList);
                        break;
                    case 1:
                        printDatabase(recordList);
                        break;
                    case 2:
                        saveDatabase(recordList);
                        printBox(32,17,12,4,8);
                        quit = true;
                        break;
                    case 3:
                        printBox(32,17,12,4,8);
                        quit = true;
                        break;
                }
                break;
        }
    }
}

void searchMenu(list recordList){
    printHeader("Menüpont kiválasztása: ↑ ↓ \tMenüpont megnyitása: ENTER");

    char *menuElements[] = {" Szerző alapján     ", " Cím alapján        ", " Műfaj alapján      ", " Kiadási év alapján ", " Vissza             "};
    printMenu(menuElements, 5, 0, 52, 17);

    int key; int index = 0; bool quit = false;
    while (!quit){
        key = econio_getch();
        switch (key) {
            case -21:
                if (index != 4) index++;
                printMenu(menuElements, 5, index, 52, 17);
                break;
            case -20:
                if (index != 0) index--;
                printMenu(menuElements, 5, index, 52, 17);
                break;
            case 10:
                switch (index) {
                    case 0:
                        break;
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        printBox(52,17,20,5,8);
                        quit = true;
                        break;
                }
                break;
        }
    }

}