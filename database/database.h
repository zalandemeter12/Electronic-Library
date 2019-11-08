#ifndef NAGYHAZI_DATABASE_H
#define NAGYHAZI_DATABASE_H

#include "../definitions.h"

bool loadDatabase(list recordList);
bool saveDatabase(list recordList);
void searchDatabase(list recordList, searchCondition condition)
void printDatabase(list recordList);

#endif //NAGYHAZI_DATABASE_H
