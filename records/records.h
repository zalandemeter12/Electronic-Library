#ifndef NAGYHAZI_RECORDS_H
#define NAGYHAZI_RECORDS_H

#include "../definitions.h"

listElement *newElement();
bool modifyElement(list *thisList, listElement *thisElement);
bool removeElement(list *thisList, listElement *thisElement);
void appendElementFirst(list *thisList, listElement *thisElement);
void appendElementLast(list *thisList, listElement *thisElement);

#endif //NAGYHAZI_RECORDS_H
