#include "records/records.h"
#include "database/database.h"
#include "menus/menus.h"

int main() {
    list recordList = createList();
    loadDatabase(&recordList);
}