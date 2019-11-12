#include "utils.h"

#include "../debugmalloc/debugmalloc.h"

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    #include <windows.h>
#endif

void fullscreen(){
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
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

void printRecord(listElement *thisElement){
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
#endif
    printf("|%-50s|\t|%-50s|\t|%-50s|\t|%-4d|\n",thisElement->author,thisElement->title,thisElement->genre,thisElement->year);
}