#include "lists.h"

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

