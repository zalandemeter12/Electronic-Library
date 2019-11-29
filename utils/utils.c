#include "utils.h"
#include "../econio/econio.h"

#include "../debugmalloc/debugmalloc.h"

void econioInit(){
    econio_set_title("Elektronikus Könyvtár");
    econio_textbackground(COL_BLACK);
    econio_clrscr();
    econio_rawmode();
    econio_kbhit();

    printBanner();
    /* MENÜ */
    printBox(0,15,162,9,COL_DARKGRAY);

    /* REKORD DOBOZ */
    printBox(0,25,162,20,COL_DARKGRAY);

    /* REKORD HEADER*/
    printBox(8,27,146,13,COL_WHITE);

    /* REKORD HEADING*/
    econio_textcolor(COL_BLACK); econio_textbackground(COL_WHITE);
    econio_gotoxy(8+4,28); printf("Szerző");
    econio_gotoxy(8+42,28); printf("Cím");
    econio_gotoxy(8+100,28); printf("Műfaj");
    econio_gotoxy(8+138,28); printf("Év");

    /* INPUT SOR */
    printBox(0,46,162,3,COL_DARKGRAY);
}

void econioExit(){
    econio_textbackground(COL_RESET);
    econio_textcolor(COL_RESET);
    econio_normalmode();
    econio_clrscr();
    econio_gotoxy(0,0);
}

void printBox(int x, int y, int w, int h, int color){
    econio_textbackground(color); econio_textcolor(color);

    for (int i = 0; i < h ; ++i) {
        for (int j = 0; j < w; ++j) {
            econio_gotoxy(x+j,y+i); printf("█");
        }
    }
}

void printBanner(){
    econio_textbackground(COL_BLUE); econio_textcolor(COL_LIGHTGRAY);
    econio_gotoxy(0,0); printf("▒░░░░░░░░░░▒░░░░░░░░░░▒                                                                                                           ▒▒▒▒▒▒▒▒▒▒░▒▒▒▒▒▒▒▒▒▒░▒▒▒▒▒▒▒▒▒▒");
    econio_gotoxy(0,1); printf("▒▒░░░░░░░░░▒▒░░░░░░░░░▒▒                           ▒█▀▀▀ █░░ █▀▀ █░█ ▀▀█▀▀ █▀▀█ █▀▀█ █▀▀▄ ░▀░ █░█ █░░█ █▀▀                         ▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒");
    econio_gotoxy(0,2); printf("▒▒▒░░░░░░░░▒▒▒░░░░░░░░▒▒▒                          ▒█▀▀▀ █░░ █▀▀ █▀▄ ░░█░░ █▄▄▀ █░░█ █░░█ ▀█▀ █▀▄ █░░█ ▀▀█                          ▒▒▒▒▒▒▒▒░░░▒▒▒▒▒▒▒▒░░░▒▒▒▒▒▒▒▒");
    econio_gotoxy(0,3); printf("▒▒▒▒░░░░░░░▒▒▒▒░░░░░░░▒▒▒▒                         ▒█▄▄▄ ▀▀▀ ▀▀▀ ▀░▀ ░░▀░░ ▀░▀▀ ▀▀▀▀ ▀░░▀ ▀▀▀ ▀░▀ ░▀▀▀ ▀▀▀                           ▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒▒");
    econio_gotoxy(0,4); printf("▒▒▒▒▒░░░░░░▒▒▒▒▒░░░░░░▒▒▒▒▒                                                                       ▄                                   ▒▒▒▒▒▒░░░░░▒▒▒▒▒▒░░░░░▒▒▒▒▒▒");
    econio_gotoxy(0,5); printf("▒▒▒▒▒▒░░░░░▒▒▒▒▒▒░░░░░▒▒▒▒▒▒                                        ░▀░▀                        ░▀                                     ▒▒▒▒▒░░░░░░▒▒▒▒▒░░░░░░▒▒▒▒▒");
    econio_gotoxy(0,6); printf("▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒▒                                 ▒█░▄▀ █▀▀█ █▀▀▄ █░░█ ▀█░█▀ ▀▀█▀▀ █▀▀█ █▀▀█                                ▒▒▒▒░░░░░░░▒▒▒▒░░░░░░░▒▒▒▒");
    econio_gotoxy(0,7); printf("▒▒▒▒▒▒▒▒░░░▒▒▒▒▒▒▒▒░░░▒▒▒▒▒▒▒▒                                ▒█▀▄░ █░░█ █░░█ █▄▄█ ░█▄█░ ░░█░░ █▄▄█ █▄▄▀                                 ▒▒▒░░░░░░░░▒▒▒░░░░░░░░▒▒▒");
    econio_gotoxy(0,8); printf("▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒                               ▒█░▒█ ▀▀▀▀ ▀░░▀ ▄▄▄█ ░░▀░░ ░░▀░░ ▀░░▀ ▀░▀▀                                  ▒▒░░░░░░░░░▒▒░░░░░░░░░▒▒");
    econio_gotoxy(0,9); printf("▒▒▒▒▒▒▒▒▒▒░▒▒▒▒▒▒▒▒▒▒░▒▒▒▒▒▒▒▒▒▒                                                                                                           ▒░░░░░░░░░░▒░░░░░░░░░░▒");
}

void printHeader(char * info){
    printBox(0,11,162,3,COL_LIGHTGRAY);
    econio_textcolor(COL_BLACK); econio_textbackground(COL_LIGHTGRAY);
    econio_gotoxy(0,12);printf("\t%s", info);
}

void printRecord(listElement *thisElement, int x, int y, int bgcolor){
    /* Törli a kiírandó listaelem helyén szereplő adatokat. */
    printBox(x,y,146,1,bgcolor);
    econio_textbackground(bgcolor); econio_textcolor(COL_BLACK);

    /* Kiírja a listaelem adatait. */
    econio_gotoxy(x+4,y); printf("%s",thisElement->author);
    econio_gotoxy(x+42,y); printf("%s",thisElement->title);
    econio_gotoxy(x+100,y); printf("%s",thisElement->genre);
    econio_gotoxy(x+138,y); printf("%d",thisElement->year);
}

void printFromTo(list *thisList, int from, int to, int selected, int x, int y) {
    printBox(8,30,146,13,COL_LIGHTGRAY);

    int counter = 0;
    int index = 0;

    listElement *moving = thisList->first->next;
    while (moving != thisList->last && counter <= to){
        if (counter >= from && counter <= to) {
            if (index == selected)
                printRecord(moving,x,y+index,COL_WHITE);
            else printRecord(moving,x,y+index,COL_LIGHTGRAY);
            index++;
        }
        moving = moving->next;
        counter++;
    }
}

bool confirmAction(listElement *thisElement){
    printBox(0,47,146,1,COL_DARKGRAY);
    printHeader("Jóváhagyás: ENTER    Mégsem: ESC");

    /* Kiírja a jóváhagyni kívánt rekord adatait az input sorba. */
    econio_textbackground(COL_DARKGRAY); econio_textcolor(COL_LIGHTGRAY);
    econio_gotoxy(8+4,47); printf("%s",thisElement->author);
    econio_gotoxy(8+42,47); printf("%s",thisElement->title);
    econio_gotoxy(8+100,47); printf("%s",thisElement->genre);
    econio_gotoxy(8+138,47); printf("%d",thisElement->year);

    econio_rawmode();
    econio_kbhit();

    /* Vár a jóváhagyásra, vagy az elutasításra. */
    while (true){
        int key = econio_getch();
        switch (key) {
            case KEY_ENTER: return true;
            /* ESC */
            case KEY_ESCAPE: return false;
            default: break;
        }
    }
}