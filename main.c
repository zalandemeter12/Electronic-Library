#include "definitions.h"
#include "lists/lists.h"
#include "database/database.h"

#include "debugmalloc/debugmalloc.h"

#ifdef _WIN32
    #include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
#endif


    list recordList = createList();

    loadDatabase(recordList);

    printDatabase(recordList);

    saveDatabase(recordList);

    removeList(recordList);

    system("pause");

    return 0;
}