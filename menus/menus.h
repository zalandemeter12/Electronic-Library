#ifndef NAGYHAZI_MENUS_H
#define NAGYHAZI_MENUS_H

#include "../definitions.h"


void printMenu (char **menuElements, int elementNumber, int selectedIndex, int x, int y);

void mainMenu(int selected);
void recordMenu(int selected);
void databaseMenu(int selected);
void searchMenu(int selected);

#endif //NAGYHAZI_MENUS_H
