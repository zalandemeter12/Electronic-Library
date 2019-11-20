#include "database.h"
#include "../lists/lists.h"
#include "../econio/econio.h"
#include "../utils/utils.h"

#include "../debugmalloc/debugmalloc.h"


bool loadDatabase(list recordList) {
    FILE *fp;
    fp = fopen("../database/database.txt", "rt");

    /* Ha a fájl megnyitása során hibába ütközik, hamis értékkel tér vissza. */
    if (fp == NULL){
        perror("Error: ");
        return false;
    }

    /* Beolvassa a fájl sorait lokális változókba, majd ezeket elmenti
     * a létrehozott listaelembe és hozzáfűzi a lista végéhez. */
    char author[31]; char title[51]; char genre[31]; int year;
    while (fscanf(fp," %[^|]|%[^|]|%[^|]|%d",author,title,genre,&year) != EOF) {
        listElement *tempElement = newElement();
        strcpy(tempElement->author, author);
        strcpy(tempElement->title, title);
        strcpy(tempElement->genre, genre);
        tempElement->year = year;
        appendElementLast(recordList, tempElement);
    }

    fclose(fp);
    return true;
}

bool saveDatabase(list recordList){
    FILE* fp = fopen("../database/database.txt","wt");

    /* Ha a fájl létrehozása során hibába ütközik, hamis értékkel tér vissza. */
    if (fp == NULL){
        perror("Error: ");
        return false;
    }

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

void printDatabase(list recordList){
    int key; int index = 0; int elementIndex = 0; int counter = 0; bool quit = false; listElement * moving;
    while (!quit){
        key = econio_getch();
        switch (key) {
            case -21:
                if (index != 10) {

                } else {

                }
                break;
            case -20:
                if (index != 0) {

                } else {

                }
                break;
            case 10:
                break;
            case 27:
                quit = true;
                break;
        }
    }
}
