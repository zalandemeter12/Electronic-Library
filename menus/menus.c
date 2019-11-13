#include "menus.h"
#include "../econico/econio.h"
#include "../utils/utils.h"

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
        econio_gotoxy(x, y+index); printf("\t%s",menuElements[index]);
    }
    econio_textbackground(0);
    econio_textcolor(15);
    econio_gotoxy(0,0);
}

void mainMenu(){
    econio_rawmode();
    econio_rawmode();
    econio_kbhit();
    printBanner();
    printHeader("Menüpont kiválasztása: ↑ ↓ \tMenüpont megnyitása: ENTER");
    printBox(0,15,138,7,8);

    char *menuElements[] = {"    Rekord menü    ", "    Adatbázis menü    ", "    Kilépés    "};
    printMenu(menuElements, 3, 0, 0, 17);

    int key; int index = 0;
    while ((key = econio_getch()) != 10){
        switch (key) {
            case -21:
                if (index != 2) index++;
                printMenu(menuElements, 3, index, 0, 17);
                break;
            case -20:
                if (index != 0) index--;
                printMenu(menuElements, 3, index, 0, 17);
                break;
        }
    }
    switch (index) {
        case 1:

            break;
        case 2:

            break;
        case 3:
            break;
    }
}