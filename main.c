#include "definitions.h"
#include "lists/lists.h"
#include "database/database.h"
#include "menus/menus.h"
#include "econio/econio.h"
#include "utils/utils.h"

#include "debugmalloc/debugmalloc.h"

int main() {
    econio_set_title("Elektronikus Könyvtár");
    econio_textbackground(0);
    econio_clrscr();

    /* Létrehoz egy listát és betölti a "database.txt" fájlban tárolt adatokat. */
    list recordList = createList();
    loadDatabase(recordList);

    econio_rawmode();
    econio_kbhit();
    printBanner();
    printBox(0,15,162,9,8);
    printBox(0,25,162,20,8);
    printBox(8,27,146,13,15);

    econio_textcolor(0); econio_textbackground(15);
    econio_gotoxy(8+4,28); printf("Szerző");
    econio_gotoxy(8+42,28); printf("Cím");
    econio_gotoxy(8+100,28); printf("Műfaj");
    econio_gotoxy(8+138,28); printf("Év");

    printFromTo(recordList,0,10,-1,8,31);

    /* SHELL */ printBox(0,46,162,3,8);



    mainMenu(recordList);

    /* Törli a program által használt listát és felszabadítja az általa foglalt memóriaterületeket. */
    removeList(recordList);

    econio_textbackground(16);
    econio_textcolor(16);
    econio_normalmode();
    econio_clrscr();
    econio_gotoxy(0,0);
    return 0;
}