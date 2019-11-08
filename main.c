#include "definitions.h"

int main() {
    list recordList = createList();
    loadDatabase(recordList);

    saveDatabase(recordList);

    removeList(recordList);
}