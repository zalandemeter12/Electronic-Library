#include "definitions.h"
#include "lists/lists.h"
#include "database/database.h"
#include "menus/menus.h"
#include "utils/utils.h"

#include "debugmalloc/debugmalloc.h"

int main() {

    econioInit();

    /* Létrehoz egy listát és betölti a "database.txt"
     * fájlban tárolt adatokat. */
    list recordList = createList();
    loadDatabase(recordList);

    /* Megnyitja a program menüjét vezérlő függvényt. */
    mainMenu(recordList);

    /* Törli a program által használt listát és felszabadítja az
     * általa foglalt memóriaterületeket. */
    removeList(recordList);


    econioExit();
    return 0;
}