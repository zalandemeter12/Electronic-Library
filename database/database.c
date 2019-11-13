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
            char line[30+50+30+4+3+1]; fgets(line,118,fp);

            /* Beolvassa a fájl rekordokat tartalmazó sorait*/
            for (int recordIndex = 0; recordIndex < recordNumber; recordIndex++) {
                fgets(line, 118, fp);

                /* Létrehoz egy új listaelemet */
                listElement *tempElement = newElement();

                /* A rekordsor adatait beolvassa ebbe a listaelembe.*/
                dataSplit(line,tempElement);

                /* Hozzáfűzi az így kapott elemet a lista végéhez. */
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
        /* A létrehozott fájl első sorába elmenti a tárolt rekordok számát. */
        fprintf(fp,"%d\n",*recordList.elementNumber);

        /* A tárolt rekordokat fájlba írja a megfelelő formátum szerint.
         * [    szerző|cím|műfaj|kiadási_év     ] */
        listElement *moving = recordList.first->next;
        while (moving != recordList.last){
            fprintf(fp,"%s|%s|%s|%d\n",moving->author,moving->title,moving->genre,moving->year);
            moving = moving->next;
        }

        fclose(fp);
        return true;
    }

    /* Ha a fájl létrehozása során hibába ütközik, hamis értékkel tér vissza. */
    else{
        fclose(fp);
        return false;
    }
}

void printDatabase(list recordList){
    /* Végig iterál a lista összes elemén és formázva kiírja őket a kijelzőre. */
    listElement *moving = recordList.first->next;
    while (moving != recordList.last){
        printRecord(moving);
        moving = moving->next;
    }
}
