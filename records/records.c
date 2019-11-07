#include "records.h"

listElement *newElement(){
    listElement *newElement  = (struct listElement*) malloc(sizeof(struct listElement));
    if (newElement != NULL) return newElement;
    else return NULL;
}

void appendElementFirst(list *thisList, listElement *thisElement){
    thisElement->previous = thisList->first;
    thisElement->next = thisList->first->next;
    thisList->first->next = thisElement;
}

void appendElementLast(list *thisList, listElement * thisElement){
    thisElement->next = thisList->last;
    thisElement->previous = thisList->last->previous;
    thisList->last->previous = thisElement;
}

bool modifyElement(list *thisList, listElement * thisElement){

}

bool removeElement(list *thisList, listElement * thisElement){

}