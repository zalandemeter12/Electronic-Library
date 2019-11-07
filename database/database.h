#ifndef NAGYHAZI_DATABASE_H
#define NAGYHAZI_DATABASE_H

#include "../definitions.h"

list createList();
bool saveDatabase(list *records);
bool loadDatabase(list *records);
void searchDatabase(list *records);

#endif //NAGYHAZI_DATABASE_H
