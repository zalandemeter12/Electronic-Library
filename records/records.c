#include "../definitions.h"

bool addRecord(list thisList){
    listElement *tempElement = newElement();
    if (tempElement == NULL) return false;
    char recordLine[158];
    scanf("%s",recordLine);
    dataSplit(recordLine,tempElement);
    appendElementLast(thisList,tempElement);
    return true;
}

bool modifyRecord(listElement *thisElement){
    if (thisElement == NULL) return false;
    char recordLine[158];
    scanf("%s",recordLine);
    dataSplit(recordLine,thisElement);
    return true;
}

bool removeRecord(listElement *thisElement){
    if (thisElement == NULL) return false;
    thisElement->previous->next = thisElement->next;
    thisElement->next->previous = thisElement->previous;
    freeElement(thisElement);
    return true;
}

