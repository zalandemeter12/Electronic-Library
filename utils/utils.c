#include "utils.h"

#include "../debugmalloc/debugmalloc.h"
#include "../econio/econio.h"

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
    econio_textbackground(bgcolor);
    econio_textcolor(0);
    econio_gotoxy(x+4,y); printf("%s",thisElement->author);
    econio_gotoxy(x+42,y); printf("%s",thisElement->title);
    econio_gotoxy(x+100,y); printf("%s",thisElement->genre);
    econio_gotoxy(x+138,y); printf("%d",thisElement->year);
}