#include "database.h"
#include "../records/records.h"

list createList(){
    list newList;
    listSentinel *first = (struct listSentinel *) malloc(sizeof(struct listSentinel));
    listSentinel *last = (struct listSentinel *) malloc(sizeof(struct listSentinel));
    first->next = last; first->previous = NULL;
    last->next = NULL; last->previous = first;
    newList.first = first;
    newList.last = last;
    newList.elementNumber = 0;
    return newList;
}

bool loadDatabase(list *recordList){
    FILE* fp = fopen("database.txt","rt");
    if (fp != NULL) {

        /* A fájl első sorából beolvassa, hogy hány rekordot tárol a fájl. */
        fscanf(fp, "%d",&recordList->elementNumber);

        if (recordList->elementNumber != 0){
            /* Eldobja az első sort. */
            char line[50+50+50+4+3+1]; fgets(line,158,fp);

            /* Betölti a rekordokat a listába. */
            for (int recordIndex = 0; recordIndex < recordList->elementNumber; recordIndex++) {
                fgets(line, 158, fp);
                listElement *tempElement = newElement();
                char *token;

                /* Kicseréli a sor vége karaktert sztring lezáró nullára. */
                if((token = strchr(line, '\n')) != NULL) *token = '\0';

                /* Felbontja a rekordsort 4 különféle adattípusra. */
                if((token = strtok(line, "|")) != NULL){
                    strcpy(tempElement->author,token);
                    int counter = 0;
                    while((token = strtok(NULL, "|")) != NULL){
                        if (counter == 0) strcpy(tempElement->title,token);
                        if (counter == 1) strcpy(tempElement->genre,token);
                        if (counter == 2) {
                            int num = atoi(token);
                            tempElement->year = num;
                        }
                        counter++;
                    }
                }
                /* A létrehozott record változót a lista végére fűzi. */
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
