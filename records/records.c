#include "records.h"
#include "../lists/lists.h"
#include "../utils/utils.h"

#include "../debugmalloc/debugmalloc.h"

bool addRecord(list thisList){
    listElement *tempElement = newElement();
    if (tempElement == NULL) return false;

    /* Bekéri a hozzáadni kívánt könyv adatait. */
    char recordLine[158];
    scanf("%s",recordLine);

    /* Részekre bontja a kapott rekordsort és az adatokat
     * elmenti az új listaelembe. */
    dataSplit(recordLine,tempElement);

    /* Az így kapott listaelemet hozzáfűzi a lista végéhez. */
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

