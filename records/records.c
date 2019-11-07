#include "records.h"

listElement *newElement(){
    listElement *newElement  = (struct listElement*) malloc(sizeof(struct listElement));
    char* author =(char*) malloc(51 * sizeof(char));
    char* title =(char*) malloc(51 * sizeof(char));
    char* genre =(char*) malloc(51 * sizeof(char));
    newElement->author = author;
    newElement->title = title;
    newElement->genre = genre;
    if (newElement != NULL) return newElement;
    else return NULL;
}

void appendElementFirst(list *thisList, listElement *thisElement){
    thisElement->previous = thisList->first;
    thisElement->next = thisList->first->next;
    thisList->first->next->previous = thisElement;
    thisList->first->next = thisElement;
    thisList->elementNumber++;
}

void appendElementLast(list *thisList, listElement * thisElement){
    thisElement->next = thisList->last;
    thisElement->previous = thisList->last->previous;
    thisList->last->previous->next = thisElement;
    thisList->last->previous = thisElement;
    thisList->elementNumber++;
}

bool modifyElement(list *thisList, listElement * thisElement){

}

bool removeElement(list *thisList, listElement * thisElement){

}