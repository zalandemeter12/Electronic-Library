#include "definitions.h"
#include "lists/lists.h"
#include "database/database.h"
#include "menus/menus.h"
#include "econico/econio.h"
#include "utils/utils.h"

#include "debugmalloc/debugmalloc.h"

int main() {
    econio_set_title("Elektronikus Könyvtár");
    econio_clrscr();

    /* Létrehoz egy listát és betölti a "database.txt" fájlban tárolt adatokat. */
    list recordList = createList();
    loadDatabase(recordList);

    mainMenu();

    /* Törli a program által használt listát és felszabadítja az általa foglalt memóriaterületeket. */
    removeList(recordList);

    econio_textbackground(16);
    econio_textcolor(16);
    econio_clrscr();
    econio_gotoxy(0,0);
    return 0;
}