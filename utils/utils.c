#include "utils.h"
#include "../econio/econio.h"

#include "../debugmalloc/debugmalloc.h"

void econioInit(){
    econio_set_title("Elektronikus Könyvtár");
    econio_textbackground(0);
    econio_clrscr();
    econio_rawmode();
    econio_kbhit();

    printBanner();
    /* MENU */
    printBox(0,15,162,9,8);

    /* RECORD BOX */
    printBox(0,25,162,20,8);

    /* RECORD HEADER*/
    printBox(8,27,146,13,15);

    /* RECORD HEADINGS*/
    econio_textcolor(0); econio_textbackground(15);
    econio_gotoxy(8+4,28); printf("Szerző");
    econio_gotoxy(8+42,28); printf("Cím");
    econio_gotoxy(8+100,28); printf("Műfaj");
    econio_gotoxy(8+138,28); printf("Év");

    printBox(80,17,74,5,7);

    /* COMMAND LINE */ printBox(0,46,162,3,8);
}

void econioExit(){
    econio_textbackground(16);
    econio_textcolor(16);
    econio_normalmode();
    econio_clrscr();
    econio_gotoxy(0,0);
}

void printBox(int x, int y, int w, int h, int color){
    econio_textbackground(color);
    econio_textcolor(color);
    for (int i = 0; i < h ; ++i) {
        for (int j = 0; j < w; ++j) {
            econio_gotoxy(x+j,y+i); printf("█");
        }
    }
    econio_flush();
    econio_textbackground(16);
    econio_textcolor(16);
    econio_gotoxy(0,0);
}

void printBanner(){
    econio_textbackground(  1);
    econio_textcolor(7);
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
    econio_flush();
}

void printHeader(char * info){
    printBox(0,11,162,3,7);
    econio_textcolor(0);
    econio_textbackground(7);
    econio_gotoxy(0,12);printf("\t%s", info);
    econio_flush();
}

void dataSplit(char *recordLine, listElement *thisElement){

    char *token;
    /* Kicseréli a sor vége karaktert sztring lezáró nullára. */
    if((token = strchr(recordLine, '\n')) != NULL) *token = '\0';

    /* Felbontja a rekordsort 4 különféle adattípusra és beleírja a listaelembe. */
    if((token = strtok(recordLine, "|")) != NULL){
        strcpy(thisElement->author,token);
        int counter = 0;
        while((token = strtok(NULL, "|")) != NULL){
            if (counter == 0) strcpy(thisElement->title,token);
            if (counter == 1) strcpy(thisElement->genre,token);
            if (counter == 2) {
                /* Átkonvertálja a kapott sztringet egy integerré. Nem kezeli az ebből adódó hibákat. */
                int num = atoi(token);
                thisElement->year = num;
            }
            counter++;
        }
    }
}

void printRecord(listElement *thisElement, int x, int y, int bgcolor){
    printBox(x,y,146,1,bgcolor);
    econio_textbackground(bgcolor);
    econio_textcolor(0);
    econio_gotoxy(x+4,y); printf("%s",thisElement->author);
    econio_gotoxy(x+42,y); printf("%s",thisElement->title);
    econio_gotoxy(x+100,y); printf("%s",thisElement->genre);
    econio_gotoxy(x+138,y); printf("%d",thisElement->year);
}

void printFromTo(list thisList, int from, int to, int selected, int x, int y) {
    printBox(8,30,146,13,7);
    int counter = 0; int index = 0;
    listElement *moving = thisList.first->next;
    while (moving != thisList.last && counter <= to){
        if (counter >= from && counter <= to) {
            if (index == selected)
                printRecord(moving,x,y+index,15);
            else printRecord(moving,x,y+index,7);
            index++;
        }
        moving = moving->next;
        counter++;
    }
    econio_flush();
}