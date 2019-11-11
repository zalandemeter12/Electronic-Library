#include "definitions.h"
#include "lists/lists.h"
#include "database/database.h"

#include "debugmalloc/debugmalloc.h"

#ifdef _WIN32
    #include <windows.h>
#endif

int main() {

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
#endif
    /* Létrehoz egy listát és betölti a "database.txt" fájlban tárolt adatokat. */
    list recordList = createList();
    loadDatabase(recordList);

    printDatabase(recordList);

    saveDatabase(recordList);

    /* Törli a program által használt listát és felszabadítja az általa foglalt memóriaterületeket. */
    removeList(recordList);

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    system("pause");
#endif

    return 0;
}