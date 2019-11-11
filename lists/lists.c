#include "lists.h"

#include "../debugmalloc/debugmalloc.h"

list createList(){
    list newList;
    listElement *first = (struct listElement *) malloc(sizeof(struct listElement));
    listElement *last = (struct listElement *) malloc(sizeof(struct listElement));
    int *elementNumber = (int*) malloc(sizeof(int));
    first->next = last; first->previous = NULL;
    last->next = NULL; last->previous = first;
    newList.first = first;
    newList.last = last;
    newList.elementNumber = elementNumber;
    *newList.elementNumber = 0;
    return newList;
}

void removeList(list thisList){
    listElement *moving = thisList.first->next;
    listElement *next;
    while (moving != thisList.last) {
        next = moving->next;
        freeElement(moving);
        moving = next;
    }
    free(thisList.first);
    free(thisList.last);
    free(thisList.elementNumber);
}

listElement *newElement(){
    listElement *newElement  = (struct listElement*) malloc(sizeof(struct listElement));
    if (newElement == NULL) return NULL;
    char* author =(char*) malloc(51 * sizeof(char));
    char* title =(char*) malloc(51 * sizeof(char));
    char* genre =(char*) malloc(51 * sizeof(char));
    newElement->author = author;
    newElement->title = title;
    newElement->genre = genre;
    return newElement;
}

void freeElement(listElement *thisElement){
    free(thisElement->author);
    free(thisElement->title);
    free(thisElement->genre);
    free(thisElement);
}

void appendElementFirst(list thisList, listElement *thisElement){
    thisElement->previous = thisList.first;
    thisElement->next = thisList.first->next;
    thisList.first->next->previous = thisElement;
    thisList.first->next = thisElement;
    *thisList.elementNumber = *thisList.elementNumber + 1;
}

void appendElementLast(list thisList, listElement * thisElement){
    thisElement->next = thisList.last;
    thisElement->previous = thisList.last->previous;
    thisList.last->previous->next = thisElement;
    thisList.last->previous = thisElement;
    *thisList.elementNumber = *thisList.elementNumber + 1;
}

