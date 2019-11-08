#include "../definitions.h"

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

void searchDatabase(list recordList, searchCondition condition) {
    /*
    for (int recordIndex = 0; recordIndex < recordNumber; recordIndex++) {
        switch (condition) {
            case author:
                if (strstr(database[recordIndex].author,term) != NULL) printRecord(database[recordIndex]); break;
            case title:
                if (strstr(database[recordIndex].title,term) != NULL) printRecord(database[recordIndex]); break;
            case genre:
                if (strstr(database[recordIndex].genre,term) != NULL) printRecord(database[recordIndex]); break;
            case year:
                if (*database[recordIndex].year == atoi(term)) printRecord(database[recordIndex]); break;
        }
    }
    */
    listElement *moving = recordList.first->next;
    while (moving != recordList.last){
        printf("|%-50s|\t|%-50s|\t|%-50s|\t|%-4d|\n",moving->author,moving->title,moving->genre,moving->year);
        moving = moving->next;
    }
}

void printDatabase(list recordList){
    listElement *moving = recordList.first->next;
    while (moving != recordList.last){
        printRecord(moving);
        moving = moving->next;
    }
}
