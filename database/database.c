#include "database.h"
#include "../lists/lists.h"
#include "../econio/econio.h"
#include "../utils/utils.h"

#include "../debugmalloc/debugmalloc.h"


bool loadDatabase(list recordList) {
    FILE *fp;
    fp = fopen("../database/database.txt", "rt");

    /* Ha a fájl megnyitása során hibába ütközik, hamis értékkel tér vissza. */
    if (fp == NULL){
        perror("Error: ");
        return false;
    }

    /* Beolvassa a fájl sorait lokális változókba, majd ezeket elmenti
     * a létrehozott listaelembe és hozzáfűzi a lista végéhez. */
    char author[31]; char title[51]; char genre[31]; int year;
    while (fscanf(fp," %[^|]|%[^|]|%[^|]|%d",author,title,genre,&year) != EOF) {
        listElement *tempElement = newElement();
        strcpy(tempElement->author, author);
        strcpy(tempElement->title, title);
        strcpy(tempElement->genre, genre);
        tempElement->year = year;
        appendElementLast(recordList, tempElement);
    }

    fclose(fp);
    return true;
}

bool saveDatabase(list recordList){
    FILE* fp = fopen("../database/database.txt","wt");

    /* Ha a fájl létrehozása során hibába ütközik, hamis értékkel tér vissza. */
    if (fp == NULL){
        perror("Error: ");
        return false;
    }

    /* A tárolt rekordokat fájlba írja a megfelelő formátum szerint.
     * [    szerző|cím|műfaj|kiadási_év     ] */
    listElement *moving = recordList.first->next;
    while (moving != recordList.last){
        fprintf(fp,"%s|%s|%s|%d\n",moving->author,moving->title,moving->genre,moving->year);
        moving = moving->next;
    }

    fclose(fp);
    return true;
}

void printDatabase(list recordList){
    int key; int index = 0; int elementIndex = 0; bool quit = false; listElement * moving;
    printFromTo(recordList,0,10,0,8,31);
    printHeader("Görgetés: ↑ ↓    Visszalépés: ESC");
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
            /* ESC */
            case 27:
                printFromTo(recordList,0,10,-1,8,31);
                printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");
                quit = true;
                break;
        }
    }
}
