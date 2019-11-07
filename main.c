#include "records/records.h"
#include "database/database.h"
#include "menus/menus.h"

int main() {
    list recordList = createList();
    loadDatabase(&recordList);
    listElement *i = recordList.first->next;
    while (i != recordList.last){
        printf("%s\n",i->author);
        i = i->next;
    }
}