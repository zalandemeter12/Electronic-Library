# ELEKTRONIKUS KÖNYVTÁR

## Felhasználói dokumentáció

## Programozói dokumentáció

### ADATSZERKEZET

A program adatszerkezetét egy rendezetlen duplán láncolt strázsás listával valósítottam meg. Azért választottam ezt az adatszerkezetet, mert könnyen módosítható a benne tárolt elemek száma. Mivel a program fő célja egy könyvtár létrehozása, ezért számíthatunk rá, hogy az elemek gyakran bővülnek, frissülnek. A könyvtárnak szükséges funckiója, hogy többféle keresési feltétellel keresést tudjunk benne végezni, amit ezzel az adatszerkezettel gyorsan valósíthatunk meg. Továbbá, ha később igény lenne a könyvtár rendezését kezelő funkcióra, azt is könnyedén implementálni lehetne a programban.

### FÁJLSZERKEZET

 - main.c  
 - definitions.h  
 - README.md  
 - /database  
   - database.c  
   - database.h  
- /lists  
   - lists.c  
   - lists.h  
- /records  
   - records.c  
   - records.h  
- /menus  
   - menus.c  
   - menus.h  
- /utils  
   - utils.c  
   - utils.h

### DEFINITIONS.H

> Láncolt lista elemet definiál, ami tartalmazza egy könyv adatait
> `(szerző, cím, műfaj, kiadási év)`. A szerző maximum 30 karakter, a cím
> maximum 50 karakter, a műfaj maximum 30 karakter lehet.

    typedef  struct  listElement {
	    char  author[31];
    	char  title[51];
    	char  genre[31];
    	int year;
    	struct  listElement  *next, *previous;
    } listElement;

> Definiál egy duplán láncolt listát. Tartalmazza a lista első és utolsó
> elemnére mutató pointert.

    typedef  struct  list {
    	    listElement *first, *last;
    } list;

> Definiálja az adatbázis keresésénél használható keresési feltételeket.

    typedef  enum  searchCondition{
    	author, title, genre, year
    } searchCondition;

### DATABASE/DATABASE.H

> Betölti a "database.txt" fájlból az elmentett rekordokat és a
> paraméterként átvett lista végére fűzi őket. Ha a fájl megnyitása
> során hibába ütközik, hamis értékkel tér vissza. Ha a beolvasott
> elemeknek nem tud memóriát foglalni hamis értékkel tér vissza. Sikeres
> beolvasás esetén igaz értékkel tér vissza.

    bool  loadDatabase(list  *recordList);

> Aktuális időpillanatban a paraméterként kapott lista változó által
> tárolt adatokat elmenti a "database.txt" fájlba. A tárolt rekordokat
> fájlba írja a megfelelő formátum szerint: `szerző|cím|műfaj|kiadási_év`
> Ha a fájl megnyitása során hibába ütközik, hamis értékkel tér vissza.

    bool  saveDatabase(list  *recordList);

> Kilistázza a paraméterként kapott lista összes elemét egy görgethető
> listában. A görgetést a fel - le nyilakkal leütésével végezheti a
> felhasználó. Az ESC gomb megynomására a függvény visszatér. A
> megjelenítésért egy ciklus felel ami minden futásakor beolvassa a
> leütött billentyűt és ez alapján hívja meg a megfelelő függvényeket.

    void  printDatabase(list  *recordList);

> Keresést hajt végre egy paraméterként kapott keresési feltétel alapján
> a szintén paraméterként kapott listában és kiírja az így talált
> adatokat egy görgethető listában.

    void  searchDatabase(list  *recordList, searchCondition  condition);

### LISTS/LIST.H

> Létrehoz egy duplán láncolt strázsás listát és visszatér vele. A lista
> tartalmazza a benne tárolt elemeket határoló strázsákra mutató
> pointereket.

    list  *createList();

> Felszabadítja a paraméterként kapott lista által lefoglalt memória
> területeket, törli a listát.

    void  removeList(list  *thisList);

> Létrehoz egy új listaelemet, lefoglalja az ehhez szükséges
> memóriaterületeket és visszatér az új elemre mutató pointerrel. Ha nem
> tudott memóriát foglalni NULL pointerrel tér vissza.

    listElement  *newElement();

> Létrehoz egy új listaelemet és a paraméterként átvett listaelem
> adatait átmásolja ide, visszatér az új listaelemre  mutató pointerrel.
> Ha nem tudott memóriát foglalni NULL pointerrel tér vissza. Ha a
> paraméterként átvett listaelemre mutató pointer NULL pointer, NULL
> pointerrel tér vissza.

    listElement  *copyElement(listElement  *sourceElement);  

> A paraméterként kapott listaelemet hozzáfűzi a szintén paraméterként
> kapott lista elejéhez.

    void  appendElementFirst(list  *thisList, listElement  *thisElement);

> A paraméterként kapott listaelemet hozzáfűzi a szintén paraméterként
> kapott lista végéhez.

    void  appendElementLast(list  *thisList, listElement  *thisElement);

> Végig iterál a listán és visszatér a paraméterként átvett indexű
> elemre mutató pointerrel. Ha a kapott index túl nagy NULL pointerrel
> tér vissza.

    listElement  *getNth(list  *thisList, int  index);

> Bekéri a felhasználótól a megváltoztatni kívánt adatokat, majd a
> felhasználó jóváhagyása után módosítja a paraméterként kapott
> listaelem adatait. Hamis értékkel tér vissza ha a paraméterként kapott
> listaelemre mutató pointer NULL pointer.

    bool  modifyElement(listElement  *thisElement);

> Kifűzi a listából a paraméterként kapott listaelemet és felszabadítja
> az általa foglalt memóriaterületet. Ha a kapott pointer NULL pointer,
> hamis értékkel tér vissza. Ha a felhasználó nem hagyja jóvá a törlést
> akkor is hamis értékkel tér vissza.

    bool  removeElement(listElement  *thisElement);

### RECORDS/RECORDS.H

> Bekéri a felhasználótól egy könyv adatait, majd hozzáfűzi az így
> létrehozott listaelemet a paraméterként kapott lista elejéhez. Ha nem
> tud memóriát foglalni az új elemnek hamis értékkel tér vissza,
> különben igazzal.

    bool  addRecord(list  *recordList);

> Megjeleníti egy görgethető listában az adatbázis elemeit. ENTER
> leütésével a felhasználó kiválaszthat egy adatot. A kiválasztott
> adatra meghívja az adatot módosító függvényt, majd visszatér. ESC
> leütésére a függvény visszatér. A megjelenítésért egy ciklus felel ami
> minden futásakor beolvassa a leütött billentyűt és ez alapján hívja
> meg a megfelelő függvényeket.

    bool  modifyRecord(list  *recordList);

> Megjeleníti egy görgethető listában az adatbázis elemeit. ENTER
> leütésével a felhasználó kiválaszthat egy adatot. A kiválasztott
> adatra meghívja az adatot törlő függvényt, majd visszatér. ESC
> leütésére a függvény visszatér. A megjelenítésért egy ciklus felel ami
> minden futásakor beolvassa a leütött billentyűt és ez alapján hívja
> meg a megfelelő függvényeket.

    bool  removeRecord(list  *recordList);

### MENUS/MENUS.H

> Megjeleníti a paraméterként kapott sztringek tömbjét menüként.
> Szükséges paramétere a kilistázni kívánt menüpontok száma, az
> aktuálisan kijelölt menüpont indexe és a megjelenítendő menű bal felső
> sarkának x,y koordinátája.

    void  printMenu (char  **menuElements, int  elementNumber, int  selectedIndex, int  x, int  y);

> Megjeleníti a főmenüt. Lehetővéteszi a menüpontok kiválasztását a fel
> le nyilakkal. A menüpont megnyitását az ENTER lenyomásával teheti a
> felhasználó. A kiválasztott menüpont (rekord menü, adatbázis menü)
> újabb almenük függvényét hívja meg. A kilépés menüpont kiválasztásakor
> a vüggvény visszatér. A menü megjelenítéséért egy ciklus felel, ami
> minden futásakor beolvassa a leütött billentyűt és ez alapján hívja
> meg a megfelelő függvényeket.

    void  mainMenu(list  *recordList);

> Megjeleníti a rekord menüt. Lehetővéteszi a menüpontok kiválasztását a
> fel le nyilakkal. A menüpont megnyitását az ENTER lenyomásával teheti
> a felhasználó. A hozzáadás/törlés/módosítás kiválasztása esetén a
> függvény meghívja az ezekért a feladatokért felelős függvényeket. A
> vissza választásakor vagy az ESC leütésekor a függvény visszatér a
> főmenübe. A menü megjelenítéséért egy ciklus felel, ami minden
> futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a
> megfelelő függvényeket.

    void  recordMenu(list  *recordList);

> Megjeleníti az adatbázis menüt. Lehetővéteszi a menüpontok
> kiválasztását a fel le nyilakkal. A menüpont megnyitását az ENTER
> lenyomásával teheti a felhasználó. A keresés/kilistázás/mentés
> kiválasztása esetén a függvény meghívja az ezekért a feladatokért
> felelős függvényeket. A vissza választásakor vagy az ESC leütésekor a
> függvény visszatér a főmenübe. A menü megjelenítéséért egy ciklus
> felel, ami minden futásakor beolvassa a leütött billentyűt és ez
> alapján hívja meg a megfelelő függvényeket.

    void  databaseMenu(list  *recordList);

> Megjeleníti a keresés menüt. Lehetővéteszi a menüpontok kiválasztását
> a fel le nyilakkal. A menüpont megnyitását az ENTER lenyomásával
> teheti a felhasználó. A különböző keresések kiválasztása esetén a
> függvény meghívja az ezekért a feladatokért felelős függvényeket. A
> vissza választásakor vagy az ESC leütésekor a függvény visszatér az
> adatbázis menübe. A menü megjelenítéséért egy ciklus felel, ami minden
> futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a
> megfelelő függvényeket.

    void  searchMenu(list  *recordList);

### UTILS/UTILS.H

> Létrehozza a felhasználói felület megjelenítését és beállítja a
> megnyíló ablakot.

    void econioInit(); 

> Törli a program felhasználói felületét is visszaállítja a terminál
> alapértelmezett tulajdonságait.

    void econioExit();  

> Kirajzol egy ablakot a paraméterként kapott x,y koordináta, a kapott
> hosszúság, magasság és a kapott szín szerint. Az x,y koordináta az
> ablak bal felső sarkának koordinátája, a szín az econio könyvtár által
> definiált színeket jellemző egész szám.

    void printBox(int x, int y, int w, int h, int color);

> Kirajzolja a könyvtár tetején lévő banner-t egy előre definiált
> helyen, a képernyő tetején.

    void printBanner();

> A paraméterként kapott sztring alapján egy információs fejlécet rajzol
> ki egy előre definiált helyen, a banner alatt.

    void printHeader(char *info);  

> Kiírja egy paraméterként átvett lista elem adatait a paraméterként
> átvett koordinátán megfelelően formázva.   Paraméterként megkapja a
> kiírás háttérszínét. A szín az econio könyvtár által definiált
> színeket jellemző egész szám.

    void printRecord(listElement *thisElement, int x, int y, int bgcolor);  

> Kiírja az adatbázis rekordjait egy eleje indextől egy vége indexig,
> paraméterként kapott koordinátán. A paraméterként  kapott kiválasztott
> elem indexén megjelenő elem háttérszíne előre definiáltan más, mint a
> többi rekord háttérszíne.

    void printFromTo(list *thisList, int from, int to, int selected, int x, int y);  

> Kiírja a paraméterként kapott listaelemet a bemeneti sor helyén. És
> megkérdezi a felhasználót, hogy jóváhagyja-e az adatot. ENTER
> leütésekor igaz értékkel tér vissza, ESC leütésekor hamis értékkel tér
> vissza. Mindaddig amíg a két billentyű közül valamelyiket be nem
> olvassa a függvény addig nem tér vissza.

    confirmAction(listElement *thisElement);
