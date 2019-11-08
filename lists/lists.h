#ifndef NAGYHAZI_LISTS_H
#define NAGYHAZI_LISTS_H

#include "../definitions.h"

list createList();
void removeList(list thisList);

listElement *newElement();
void freeElement(listElement *thisElement);

void appendElementFirst(list thisList, listElement *thisElement);
void appendElementLast(list thisList, listElement *thisElement);


#endif //NAGYHAZI_LISTS_H
