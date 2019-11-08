#include "../definitions.h"

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
                    int num = atoi(token);
                    thisElement->year = num;
                }
                counter++;
            }
        }
}

void printRecord(listElement *thisElement){
    printf("|%-50s|\t|%-50s|\t|%-50s|\t|%-4d|\n",thisElement->author,thisElement->title,thisElement->genre,thisElement->year);
}