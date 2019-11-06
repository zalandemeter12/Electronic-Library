#include <stdio.h>
#include "records/records.h"
#include "database/database.h"
#include "menus/menus.h"

int main() {
    loadDatabase();
    menu();
}