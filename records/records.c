#include "records.h"
#include "../lists/lists.h"
#include "../econio/econio.h"
#include "../menus/menus.h"
#include "../utils/utils.h"

#include "../debugmalloc/debugmalloc.h"

bool addRecord(list thisList){


    /* Bekéri a hozzáadni kívánt könyv adatait. */
    char author[31]; char title[51]; char genre[31]; int year = -1;

    econio_normalmode();
    econio_textbackground(8), econio_textcolor(7);
    econio_gotoxy(8,47); printf("$  ");
    econio_gotoxy(10,47);

    if (scanf("%[^|]|%[^|]|%[^|]|%d%*c",author,title,genre,&year) == 4){
        listElement *tempElement = newElement();
        if (tempElement == NULL) {
            perror("Error: ");
            return false;
        }

        strcpy(tempElement->author, author);
        strcpy(tempElement->title,title);
        strcpy(tempElement->genre,genre);
        tempElement->year = year;

        /* Az így kapott listaelemet hozzáfűzi a lista végéhez. */
        appendElementLast(thisList,tempElement);
    }

    econio_rawmode();
    printBox(0,46,162,3,8);
    return true;
}

bool modifyRecord(listElement *thisElement){
    if (thisElement == NULL) return false;
    char recordLine[158];
    scanf("%s",recordLine);
    dataSplit(recordLine,thisElement);
    return true;
}

bool removeRecord(listElement *thisElement){
    if (thisElement == NULL) return false;
    thisElement->previous->next = thisElement->next;
    thisElement->next->previous = thisElement->previous;
    return true;
}

