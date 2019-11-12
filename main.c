#include "definitions.h"
#include "lists/lists.h"
#include "database/database.h"
#include "menus/menus.h"
#include "econico/econio.h"
#include "utils/utils.h"

#include "debugmalloc/debugmalloc.h"

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    #include <windows.h>
#endif


int main() {
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    fullscreen();
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    econio_textbackground(4);
    econio_textcolor(15);
    econio_textbackground(4);
    econio_textcolor(15);
    econio_set_title("Elektronikus Könyvtár");

    /* Létrehoz egy listát és betölti a "database.txt" fájlban tárolt adatokat. */
    list recordList = createList();
    loadDatabase(recordList);

    menu();

    /* Törli a program által használt listát és felszabadítja az általa foglalt memóriaterületeket. */
    removeList(recordList);
    return 0;
}