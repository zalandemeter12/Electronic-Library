#include "definitions.h"
#include "lists/lists.h"
#include "database/database.h"
#include "menus/menus.h"
#include "econico/econio.h"
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
    econio_gotoxy(8,28); printf("    %-30s         %-50s         %-30s         %-4s", "Szerző", "Cím", "Műfaj", "Év");
    printBox(8,30,146,13,7);
    listElement *moving = recordList.first->next;
    int c = 0;
    while (moving != recordList.last && c<11){
        if (c%2 == 0) printRecord(moving,8,31+c,7);
        else printRecord(moving,8,31+c,7);
        moving = moving->next;
        c++;
    }
    printBox(0,46,162,3,8);



    mainMenu(0);

    /* Törli a program által használt listát és felszabadítja az általa foglalt memóriaterületeket. */
    removeList(recordList);

    econio_textbackground(16);
    econio_textcolor(16);
    econio_clrscr();
    econio_gotoxy(0,0);
    return 0;
}