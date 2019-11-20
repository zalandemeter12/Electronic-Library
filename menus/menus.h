#ifndef NAGYHAZI_MENUS_H
#define NAGYHAZI_MENUS_H

#include "../definitions.h"


void printMenu (char **menuElements, int elementNumber, int selectedIndex, int x, int y);

void mainMenu(list recordList);
void recordMenu(list recordList);
void databaseMenu(list recordList);
void searchMenu(list recordList);

#endif //NAGYHAZI_MENUS_H
