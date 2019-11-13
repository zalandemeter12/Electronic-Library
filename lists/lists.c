#include "lists.h"

#include "../debugmalloc/debugmalloc.h"

list createList(){
    list newList;

    /* Memóriát foglal a lista adatainak, létrehozza a listát határoló strázsákat. */
    listElement *first = (struct listElement *) malloc(sizeof(struct listElement));
    listElement *last = (struct listElement *) malloc(sizeof(struct listElement));
    int *elementNumber = (int*) malloc(sizeof(int));

    /* Az így kapott pointereket elmenti az új lista struktúrába. */
    newList.first = first;
    newList.last = last;
    newList.elementNumber = elementNumber;
    *newList.elementNumber = 0;

    /* A strázsák következő és előző pointereit beállítja úgy,
     * hogy a strázsák egymásra mutassanak. */
    first->next = last; first->previous = NULL;
    last->next = NULL; last->previous = first;
    return newList;
}

void removeList(list thisList){
    /* Végigmegy a lista összes nem strázsa elemén és meghívja rá a freeRecord() függvényt. */
    listElement *moving = thisList.first->next;
    listElement *next;
    while (moving != thisList.last) {
        next = moving->next;
        freeElement(moving);
        moving = next;
    }

    /* Felszabadítja a lista adatait tartalmazó memóriaterületeket. */
    free(thisList.first);
    free(thisList.last);
    free(thisList.elementNumber);
}

listElement *newElement(){
    /* Memóriát foglal a listaelemet tartalmazó struktúrának. */
    listElement *newElement  = (struct listElement*) malloc(sizeof(struct listElement));
    if (newElement == NULL) return NULL;
    /* Memóriát foglal a könyv adatait tartalmazó karaktertömbök számára. */
    char* author =(char*) malloc(31 * sizeof(char));
    char* title =(char*) malloc(51 * sizeof(char));
    char* genre =(char*) malloc(31 * sizeof(char));

    /* Az így kapott pointereket elmenti a struktúrába. */
    newElement->author = author;
    newElement->title = title;
    newElement->genre = genre;
    return newElement;
}

void freeElement(listElement *thisElement){
    /* Felszabadítja a listaelem karaktertömbök által foglalt memóriaterületeket. */
    free(thisElement->author);
    free(thisElement->title);
    free(thisElement->genre);
    free(thisElement);
}

void appendElementFirst(list thisList, listElement *thisElement){
    /* Beállítja a megfelelő elemek előző és következő pointereit. */
    thisElement->previous = thisList.first;
    thisElement->next = thisList.first->next;
    thisList.first->next->previous = thisElement;
    thisList.first->next = thisElement;

    /* Megnöveli a lista elemszámát eggyel*/
    *thisList.elementNumber = *thisList.elementNumber + 1;
}

void appendElementLast(list thisList, listElement * thisElement){
    /* Beállítja a megfelelő elemek előző és következő pointereit. */
    thisElement->next = thisList.last;
    thisElement->previous = thisList.last->previous;
    thisList.last->previous->next = thisElement;
    thisList.last->previous = thisElement;

    /* Megnöveli a lista elemszámát eggyel*/
    *thisList.elementNumber = *thisList.elementNumber + 1;
}

