#include "lists.h"
#include "../econio/econio.h"
#include "../utils/utils.h"

#include "../debugmalloc/debugmalloc.h"

list createList(){
    list newList;

    /* Memóriát foglal a lista adatainak, létrehozza a listát határoló strázsákat. */
    listElement *first = (struct listElement *) malloc(sizeof(struct listElement));
    listElement *last = (struct listElement *) malloc(sizeof(struct listElement));

    /* Az így kapott pointereket elmenti az új lista struktúrába. */
    newList.first = first;
    newList.last = last;

    /* A strázsák következő és előző pointereit beállítja úgy,
     * hogy a strázsák egymásra mutassanak. */
    first->next = last; first->previous = NULL;
    last->next = NULL; last->previous = first;
    return newList;
}

void removeList(list thisList){
    /* Végigmegy a lista összes nem strázsa elemén és meghívja rá a free() függvényt. */
    listElement *moving = thisList.first->next;
    listElement *next;
    while (moving != thisList.last) {
        next = moving->next;
        free(moving);
        moving = next;
    }

    /* Felszabadítja a lista adatait tartalmazó memóriaterületeket. */
    free(thisList.first);
    free(thisList.last);
}

listElement *newElement(){
    /* Memóriát foglal a listaelemet tartalmazó struktúrának. */
    listElement *newElement  = (struct listElement*) malloc(sizeof(struct listElement));
    if (newElement == NULL) return NULL;
    return newElement;
}

void appendElementFirst(list thisList, listElement *thisElement){
    /* Beállítja a megfelelő elemek előző és következő pointereit. */
    thisElement->previous = thisList.first;
    thisElement->next = thisList.first->next;
    thisList.first->next->previous = thisElement;
    thisList.first->next = thisElement;
}

void appendElementLast(list thisList, listElement * thisElement){
    /* Beállítja a megfelelő elemek előző és következő pointereit. */
    thisElement->next = thisList.last;
    thisElement->previous = thisList.last->previous;
    thisList.last->previous->next = thisElement;
    thisList.last->previous = thisElement;
}

listElement *getNth(list thisList, int index){
    int counter = 0;
    listElement *moving = thisList.first->next;
    while (moving != thisList.last && counter < index){
        moving = moving->next;
        counter++;
    }
    if (moving == thisList.last) return  NULL;
    return moving;
}

bool modifyElement(listElement *thisElement){
    printHeader("Add meg az adatokat: Szerző|Cím|Műfaj|Kidási_év formában!    Visszalépéshez hagyd üresen és nyomj ENTER-t.");
    if (thisElement == NULL) {
        return false;
    }
    char recordLine[118];
    /* Bekéri a hozzáadni kívánt könyv adatait. */
    char author[31]; char title[51]; char genre[31]; int year;

    econio_normalmode();
    econio_textbackground(8), econio_textcolor(7);
    econio_gotoxy(8,47); printf("$  ");
    econio_gotoxy(10,47);

    if (scanf("%[^\n]",recordLine) == 1 && strcmp(recordLine,"\n") != 0){
        sscanf(recordLine,"%[^|]|%[^|]|%[^|]|%d",author,title,genre,&year);
        strcpy(thisElement->author, author);
        strcpy(thisElement->title,title);
        strcpy(thisElement->genre,genre);
        thisElement->year = year;
    }
    return true;
}

bool removeElement(listElement *thisElement){
    if (thisElement == NULL) return false;
    thisElement->previous->next = thisElement->next;
    thisElement->next->previous = thisElement->previous;
    free(thisElement);
    return true;
}

