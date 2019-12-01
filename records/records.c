#include "records.h"
#include "../lists/lists.h"
#include "../econio/econio.h"
#include "../utils/utils.h"

#include "../debugmalloc/debugmalloc.h"

bool addRecord(list *recordList){
    char recordLine[118] = "<NULL>";
    char author[31] = "<NULL>";
    char title[51] = "<NULL>";
    char genre[31] = "<NULL>";
    int year = 0;

    printHeader("Add meg az adatokat: Szerző|Cím|Műfaj|Kidási_év formában!    Visszalépéshez hagyd üresen és nyomj ENTER-t.");
    econio_normalmode();
    econio_textbackground(COL_DARKGRAY), econio_textcolor(COL_LIGHTGRAY);
    econio_gotoxy(8,47); printf("$  ");
    econio_gotoxy(10,47);

    /* Bekéri a hozzáadni kívánt könyv adatait. */

    if (scanf("%[^\n]",recordLine) == 1){
        getchar();
        sscanf(recordLine,"%[^|]|%[^|]|%[^|]|%d",author,title,genre,&year);

        listElement *tempElement = newElement();
        if (tempElement == NULL) {
            perror("Error: ");
            printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");
            return false;
        }

        /* Elmenti az adatokat egy listaelembe. */
        strcpy(tempElement->author, author);
        strcpy(tempElement->title,title);
        strcpy(tempElement->genre,genre);
        tempElement->year = year;

        /* Ellenőrzi a jóváhagyást. */
        if (confirmAction(tempElement)){
            /* Az így kapott listaelemet hozzáfűzi a lista végéhez. */
            appendElementFirst(recordList,tempElement);
        } else free(tempElement);
    }

    printFromTo(recordList,0,10,-1,8,31);
    econio_rawmode();
    printBox(0,46,162,3,COL_DARKGRAY);
    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");
    return true;
}

bool modifyRecord(list *recordList){
    int key;
    int index = 0;
    int elementIndex = 0;
    bool quit = false;
    bool success = false;

    printFromTo(recordList,0,10,0,8,31);
    printHeader("Kiválasztás: ↑ ↓    Módosítás: ENTER    Visszalépés: ESC");

    while (!quit){
        key = econio_getch();
        switch (key) {
            case KEY_DOWN:
                /* Ha a kijelölt elem nem a megjelenített 11 elem utolsó eleme. */
                if (index != 10) {
                    /* Ha a kijelölt elem nem a lista utlosó eleme. */
                    if (getNth(recordList,elementIndex) != recordList->last->previous){
                        index++; elementIndex++;
                        printFromTo(recordList,elementIndex-index,elementIndex-index+10,index,8,31);
                    }
                } else {
                    /* Ha a kijelölt elem nem a lista utlosó eleme. */
                    if (getNth(recordList,elementIndex) != recordList->last->previous){
                        elementIndex++;
                        printFromTo(recordList,elementIndex-10,elementIndex,index,8,31);
                    }
                }
                break;
            case KEY_UP:
                /* Ha a kijelölt elem nem a megjelenített 11 elem első eleme. */
                if (index != 0) {
                    /* Ha a kijelölt elem nem a lista első eleme. */
                    if (elementIndex > 0){
                        index--; elementIndex--;
                        printFromTo(recordList,elementIndex-index,elementIndex-index+10,index,8,31);
                    }
                } else {
                    /* Ha a kijelölt elem nem a lista első eleme. */
                    if (elementIndex > 0){
                        elementIndex--;
                        printFromTo(recordList,elementIndex,elementIndex+10,index,8,31);
                    }
                }
                break;
            case KEY_ENTER:
                success = modifyElement(getNth(recordList,elementIndex));
                printFromTo(recordList,0,10,-1,8,31);
                printBox(0,46,162,3,COL_DARKGRAY);
                quit = true;
                break;
            case KEY_ESCAPE:
                printFromTo(recordList,0,10,-1,8,31);
                quit = true;
                break;
            default:
                break;
        }
    }

    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");
    return success;
}

bool removeRecord(list *recordList){
    int key;
    int index = 0;
    int elementIndex = 0;
    bool quit = false;
    bool success = false;

    printFromTo(recordList,0,10,0,8,31);
    printHeader("Kiválasztás: ↑ ↓    Törlés: ENTER    Visszalépés: ESC");

    while (!quit){
        key = econio_getch();
        switch (key) {
            case KEY_DOWN:
                /* Ha a kijelölt elem nem a megjelenített 11 elem utolsó eleme. */
                if (index != 10) {
                    /* Ha a kijelölt elem nem a lista utlosó eleme. */
                    if (getNth(recordList,elementIndex) != recordList->last->previous){
                        index++; elementIndex++;
                        printFromTo(recordList,elementIndex-index,elementIndex-index+10,index,8,31);
                    }
                } else {
                    /* Ha a kijelölt elem nem a lista utlosó eleme. */
                    if (getNth(recordList,elementIndex) != recordList->last->previous){
                        elementIndex++;
                        printFromTo(recordList,elementIndex-10,elementIndex,index,8,31);
                    }
                }
                break;
            case KEY_UP:
                /* Ha a kijelölt elem nem a megjelenített 11 elem első eleme. */
                if (index != 0) {
                    /* Ha a kijelölt elem nem a lista első eleme. */
                    if (elementIndex > 0){
                        index--; elementIndex--;
                        printFromTo(recordList,elementIndex-index,elementIndex-index+10,index,8,31);
                    }
                } else {
                    /* Ha a kijelölt elem nem a lista első eleme. */
                    if (elementIndex > 0){
                        elementIndex--;
                        printFromTo(recordList,elementIndex,elementIndex+10,index,8,31);
                    }
                }
                break;
            case KEY_ENTER:
                success = removeElement(getNth(recordList,elementIndex));
                printFromTo(recordList,0,10,-1,8,31);
                printBox(0,46,162,3,COL_DARKGRAY);
                quit = true;
                break;
            case KEY_ESCAPE:
                printFromTo(recordList,0,10,-1,8,31);
                quit = true;
                break;
            default:
                break;
        }
    }

    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");
    return success;
}

