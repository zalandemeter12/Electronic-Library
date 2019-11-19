#ifndef NAGYHAZI_MENUS_H
#define NAGYHAZI_MENUS_H

#include "../definitions.h"


void printMenu (char **menuElements, int elementNumber, int selectedIndex, int x, int y);

void mainMenu(list recordList, int selected);
void recordMenu(list recordList, int selected);
void databaseMenu(list recordList, int selected);
void searchMenu(list recordList, int selected);

#endif //NAGYHAZI_MENUS_H
