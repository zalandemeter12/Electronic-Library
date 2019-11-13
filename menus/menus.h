#ifndef NAGYHAZI_MENUS_H
#define NAGYHAZI_MENUS_H

#include "../definitions.h"


void printMenu (char **menuElements, int elementNumber, int selectedIndex, int x, int y);

void mainMenu();
void recordMenu();
void databaseMenu();
void searchMenu();

#endif //NAGYHAZI_MENUS_H
