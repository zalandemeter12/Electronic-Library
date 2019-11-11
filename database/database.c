#include "database.h"
#include "../utils/utils.h"
#include "../lists/lists.h"

#include "../debugmalloc/debugmalloc.h"

bool loadDatabase(list recordList){
    FILE* fp = fopen("../database/database.txt","rt");
    if (fp != NULL) {
        /* A fájl első sorából beolvassa, hogy hány rekordot tárol a fájl. */
        int recordNumber; fscanf(fp, "%d",&recordNumber);

        if (recordNumber != 0){
            /* Eldobja az első sort. */
            char line[50+50+50+4+3+1]; fgets(line,158,fp);

            /* Beolvassa a fájl rekordokat tartalmazó sorait*/
            for (int recordIndex = 0; recordIndex < recordNumber; recordIndex++) {
                fgets(line, 158, fp);
                listElement *tempElement = newElement();
                dataSplit(line,tempElement);
                appendElementLast(recordList, tempElement);
            }
        }
        fclose(fp);
        return true;
    }

        /* Ha a fájl megnyitása során hibába ütközik, hamis értékkel tér vissza. */
    else{
        fclose(fp);
        return false;
    }
}

bool saveDatabase(list recordList){
    FILE* fp = fopen("../database/database.txt","wt");
    if (fp != NULL) {
        fprintf(fp,"%d\n",*recordList.elementNumber);

        listElement *moving = recordList.first->next;
        while (moving != recordList.last){
            fprintf(fp,"%s|%s|%s|%d\n",moving->author,moving->title,moving->genre,moving->year);
            moving = moving->next;
        }

        fclose(fp);
        return true;
    }

    else{
        fclose(fp);
        return false;
    }
}

void printDatabase(list recordList){
    listElement *moving = recordList.first->next;
    while (moving != recordList.last){
        printRecord(moving);
        moving = moving->next;
    }
}
