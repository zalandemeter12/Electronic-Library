#include "menus.h"
#include "../econico/econio.h"

#include "../debugmalloc/debugmalloc.h"

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    #include <windows.h>
#endif

void printMenu (char **menuElements, int elementNumber, int selectedIndex, int x, int y){
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    for (int index = 0; index < elementNumber; index++) {
        econio_gotoxy(x, y+index);
        if (index == selectedIndex){
            econio_textbackground(15);
            econio_textcolor(4);
        }
        else {
            econio_textbackground(4);
            econio_textcolor(15);
        }
        printf("[%d] %s", index+1,menuElements[index]);
    }

    econio_textbackground(4);
    econio_textcolor(4);
    econio_gotoxy(0,0);
}

void menu(){

    /*
▒█▀▀▀ █░░ █▀▀ █░█ ▀▀█▀▀ █▀▀█ █▀▀█ █▀▀▄ ░▀░ █░█ █░░█ █▀▀
▒█▀▀▀ █░░ █▀▀ █▀▄ ░░█░░ █▄▄▀ █░░█ █░░█ ▀█▀ █▀▄ █░░█ ▀▀█
▒█▄▄▄ ▀▀▀ ▀▀▀ ▀░▀ ░░▀░░ ▀░▀▀ ▀▀▀▀ ▀░░▀ ▀▀▀ ▀░▀ ░▀▀▀ ▀▀▀
                                   ▄
            ░▀░▀                  ▀
▒█░▄▀ █▀▀█ █▀▀▄ █░░█ ▀█░█▀ ▀▀█▀▀ █▀▀█ █▀▀█
▒█▀▄░ █░░█ █░░█ █▄▄█ ░█▄█░ ░░█░░ █▄▄█ █▄▄▀
▒█░▒█ ▀▀▀▀ ▀░░▀ ▄▄▄█ ░░▀░░ ░░▀░░ ▀░░▀ ▀░▀▀

     */

    econio_rawmode();
    econio_kbhit();

    char *menuElements[] = {"Rekord menü", "Adatbázis menü", "Kilépés"};


    printMenu(menuElements, 3, 0, 0, 0);

    int key; int index = 0;
    while ((key = econio_getch()) != 10){
        switch (key) {
            case -21:
                if (index != 2) index++;
                econio_clrscr();
                printMenu(menuElements, 3, index, 0, 0);
                econio_flush();
                break;
            case -20:
                if (index != 0) index--;
                econio_clrscr();
                printMenu(menuElements, 3, index, 0, 0);
                econio_flush();
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