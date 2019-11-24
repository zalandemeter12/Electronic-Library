#include "records.h"
#include "../lists/lists.h"
#include "../econio/econio.h"
#include "../utils/utils.h"

#include "../debugmalloc/debugmalloc.h"

bool addRecord(list recordList){
    printHeader("Add meg az adatokat: Szerző|Cím|Műfaj|Kidási_év formában!    Visszalépéshez hagyd üresen és nyomj ENTER-t.");
    /* Bekéri a hozzáadni kívánt könyv adatait. */
    char recordLine[118];
    char author[31]; char title[51]; char genre[31]; int year;

    econio_normalmode();
    econio_textbackground(8), econio_textcolor(7);
    econio_gotoxy(8,47); printf("$  ");
    econio_gotoxy(10,47);

    if (scanf("%[^\n]",recordLine) == 1 && strcmp(recordLine,"\n") != 0){
        sscanf(recordLine,"%[^|]|%[^|]|%[^|]|%d",author,title,genre,&year);
        listElement *tempElement = newElement();
        if (tempElement == NULL) {
            perror("Error: ");
            printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");
            return false;
        }

        strcpy(tempElement->author, author);
        strcpy(tempElement->title,title);
        strcpy(tempElement->genre,genre);
        tempElement->year = year;

        /* Az így kapott listaelemet hozzáfűzi a lista végéhez. */
        appendElementLast(recordList,tempElement);
    }

    printFromTo(recordList,0,10,-1,8,31);
    econio_rawmode();
    printBox(0,46,162,3,8);
    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");
    return true;
}

bool modifyRecord(list recordList){
    bool success = false;
    int key; int index = 0; int elementIndex = 0; bool quit = false; listElement * moving;
    printFromTo(recordList,0,10,0,8,31);
    printHeader("Kiválasztás: ↑ ↓    Módosítás: ENTER    Visszalépés: ESC");
    while (!quit){
        key = econio_getch();
        switch (key) {
            /* Arrow Down */
            case -21:
                if (index != 10) {
                    if (getNth(recordList,elementIndex) != recordList.last->previous){
                        index++; elementIndex++;
                        printFromTo(recordList,elementIndex-index,elementIndex-index+10,index,8,31);
                    }
                } else {
                    if (getNth(recordList,elementIndex) != recordList.last->previous){
                        elementIndex++;
                        printFromTo(recordList,elementIndex-10,elementIndex,index,8,31);
                    }
                }
                break;
            /* Arrow Up */
            case -20:
                if (index != 0) {
                    if (elementIndex > 0){
                        index--; elementIndex--;
                        printFromTo(recordList,elementIndex-index,elementIndex-index+10,index,8,31);
                    }
                } else {
                    if (elementIndex > 0){
                        elementIndex--;
                        printFromTo(recordList,elementIndex,elementIndex+10,index,8,31);
                    }
                }
                break;
            /* ENTER */
            case 10:
                success = modifyElement(getNth(recordList,elementIndex));
                printFromTo(recordList,0,10,-1,8,31);
                econio_rawmode();
                printBox(0,46,162,3,8);
                quit = true;
                break;
            /* ESC */
            case 27:
                printFromTo(recordList,0,10,-1,8,31);
                quit = true;
                break;
        }
    }
    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");
    return success;
}

bool removeRecord(list recordList){
    bool success = false; listElement *toRemove;
    int key; int index = 0; int elementIndex = 0; bool quit = false; listElement * moving;
    printFromTo(recordList,0,10,0,8,31);
    printHeader("Kiválasztás: ↑ ↓    Törlés: ENTER    Visszalépés: ESC");
    while (!quit){
        key = econio_getch();
        switch (key) {
            /* Arrow down */
            case -21:
                if (index != 10) {
                    if (getNth(recordList,elementIndex) != recordList.last->previous){
                        index++; elementIndex++;
                        printFromTo(recordList,elementIndex-index,elementIndex-index+10,index,8,31);
                    }
                } else {
                    if (getNth(recordList,elementIndex) != recordList.last->previous){
                        elementIndex++;
                        printFromTo(recordList,elementIndex-10,elementIndex,index,8,31);
                    }
                }
                break;
            /* Arrow Up */
            case -20:
                if (index != 0) {
                    if (elementIndex > 0){
                        index--; elementIndex--;
                        printFromTo(recordList,elementIndex-index,elementIndex-index+10,index,8,31);
                    }
                } else {
                    if (elementIndex > 0){
                        elementIndex--;
                        printFromTo(recordList,elementIndex,elementIndex+10,index,8,31);
                    }
                }
                break;
                /* ENTER */
            case 10:
                toRemove = getNth(recordList,elementIndex);
                if (toRemove != NULL)
                    success = removeElement(toRemove);
                printFromTo(recordList,0,10,-1,8,31);
                econio_rawmode();
                printBox(0,46,162,3,8);
                quit = true;
                break;
                /* ESC */
            case 27:
                printFromTo(recordList,0,10,-1,8,31);
                quit = true;
                break;
        }
    }
    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");
    return success;
}

