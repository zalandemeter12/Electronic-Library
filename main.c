#include "definitions.h"
#include "lists/lists.h"
#include "database/database.h"
#include "menus/menus.h"
#include "utils/utils.h"

#include "debugmalloc/debugmalloc.h"

int main() {

    econioInit();

    list recordList = createList();
    loadDatabase(recordList);

    mainMenu(recordList);

    removeList(recordList);

    econioExit();

    debugmalloc_log_file("../debugmalloc/debugmalloc-memlog.txt");
    debugmalloc_atexit_dump();

    return 0;
}