#include "database.h"
#include "../lists/lists.h"
#include "../econio/econio.h"
#include "../utils/utils.h"

#include "../debugmalloc/debugmalloc.h"


bool loadDatabase(list *recordList) {
    FILE *fp;
    fp = fopen("database/database.txt", "rt");

    if (fp == NULL){
        perror("Error: ");
        return false;
    }

    char author[31];
    char title[51];
    char genre[31];
    int year;

    /* Beolvassa a fájl sorait a létrehozott változókba. */
    while (fscanf(fp," %[^|]|%[^|]|%[^|]|%d",author,title,genre,&year) != EOF) {
        listElement *tempElement = newElement();
        if (tempElement == NULL) return false;

        /* A beolvasott adatokat elmenti a létrehozott listaelembe*/
        strcpy(tempElement->author, author);
        strcpy(tempElement->title, title);
        strcpy(tempElement->genre, genre);
        tempElement->year = year;

        /* Az így kapott listaelemet hozzáfűzi az adatbázis elejéhez. */
        appendElementLast(recordList, tempElement);
    }

    fclose(fp);
    return true;
}

bool saveDatabase(list *recordList){
    FILE* fp = fopen("database/database.txt","wt");

    if (fp == NULL){
        perror("Error: ");
        return false;
    }

    /* Végig iterál a listán és minden rekordot kiír a fájlba. */
    listElement *moving = recordList->first->next;
    while (moving != recordList->last){
        fprintf(fp,"%s|%s|%s|%d\n",moving->author,moving->title,moving->genre,moving->year);
        moving = moving->next;
    }

    fclose(fp);
    return true;
}

void printDatabase(list *recordList){
    int key;
    int index = 0;
    int elementIndex = 0;
    bool quit = false;

    printFromTo(recordList,0,10,0,8,31);
    printHeader("Görgetés: ↑ ↓    Visszalépés: ESC");

    /* Amíg a felhasználó nem lép ki a ciklusból addig beolvassa és kiértékeli a leütött billentyűket. */
    while (!quit){
        key = econio_getch();
        switch (key) {
            /* LEFELE NYÍL */
            case -21:
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
            /* FELFELE NYÍL */
            case -20:
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
            /* ESC */
            case 27:
                printFromTo(recordList,0,10,-1,8,31);
                quit = true;
                break;
            default:
                break;
        }
    }
    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER    Visszalépés: ESC");
}

void searchDatabase(list *recordList, searchCondition condition){
    char searchString[51];
    int searchYear;

    printHeader("Add meg a keresni kívánt kifejezést!    Visszalépéshez hagyd üresen és nyomj ENTER-t.");

    econio_normalmode();
    econio_textbackground(8); econio_textcolor(7);
    econio_gotoxy(8,47); printf("$  ");
    econio_gotoxy(10,47);

    int inputSuccess = scanf("%[^\n]",searchString);

    list *searchList = createList();
    listElement *tempElement;

    /* Ha a keresett adat nem ürs, akkor végrehajtja a keresést. */
    if (inputSuccess == 1){
        econio_rawmode();

        /* Végig iterál a lista összes elemén és ellenőrzi a keresési feltételt, ha a feltétel teljesül, hozzáadja a
         * keresett elemekből álló listához. */
        listElement *moving = recordList->first->next;
        while (moving != recordList->last){
            switch (condition) {
                case author:
                    if (strstr(moving->author,searchString) != NULL){
                        tempElement = copyElement(moving);
                        appendElementLast(searchList,tempElement);
                    }
                    break;
                case title:
                    if (strstr(moving->title,searchString) != NULL){
                        tempElement = copyElement(moving);
                        appendElementLast(searchList,tempElement);
                    }
                    break;
                case genre:
                    if (strstr(moving->genre,searchString) != NULL){
                        tempElement = copyElement(moving);
                        appendElementLast(searchList,tempElement);
                    }
                    break;
                case year:
                    /* Ha év alapján keres a felhasználó a beolvasott sztringből egész számot olvas ki. */
                    sscanf(searchString,"%d",&searchYear);
                    if (moving->year == searchYear){
                        tempElement = copyElement(moving);
                        appendElementLast(searchList,tempElement);
                    }
                    break;
                default:
                    break;
            }
            moving = moving->next;
        }

        /* Kiírja a megtalált adatokat egy görgethető listában. */
        printDatabase(searchList);
        printFromTo(recordList,0,10,-1,8,31);
    }

    econio_rawmode();
    printBox(0,46,162,3,8);
    printHeader("Menüpont kiválasztása: ↑ ↓    Menüpont megnyitása: ENTER     Visszalépés: ESC");
    removeList(searchList);
}
