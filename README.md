![by Demeter Zalán](https://i.imgur.com/xeWQjTO.png)  

## FELHASZNÁLÓI DOKUMENTÁCIÓ  

### A PROGRAM CÉLJA  
  
A feladat egy elektronikus könyvtár készítése, amely képes eltárolni könyvek adatait. A program képes kell legyen új rekordok létrehozására, törlésére és módosítására. A programban végre kell tudjunk hajtani keresést a könyvek szerzője címe kiadási éve és műfaja alapján. A program szükséges funkciója még, hogy képes legyen az adatbázist fájlba menteni, és be is tölteni azt.  
  
### A PROGRAM HASZNÁLATA  

#### Áttekintés

A program futtatásakor automatikusan betöltődik az adatbázis egy szöveges fájlból. A felhasználó ezek után a könyvtár menüjét látja. A menüben szerepel a rekord hozzáadása, törlése, módosítása, a rekordok közötti keresés (tartalmazva a különféle keresési fajtákat) az adatbázis kilistázása és az adatbázis mentése funkció.   
  
A menüpontok kiválasztása billentyűzeten történik (a fel és le - nyilak, ENTER és ESC billentyűk használatával), nem lehet a menüpontokra egérrel kattintani. Minden funkció használata után lehetőség van visszatérni a főmenübe aminek módjáról a fejléc ad információt.  
  
#### Funkciók

Törlés és módosítás esetén először megjelenik minden adat egy görgethető listában, amiben kiválszthatjuk a szerkeszteni kívánt rekordot, ezután a program bekéri a könyv adatait. Hozzáadás esetében a görgethető lista nem jelenik meg csak az adatokat kell megadjuk. A program kiírja az aktuálisan kezelt adatot és lehetőséget kínál a főmenübe lépésre. Ilyenkor frissül az adatbázis, de fájlba csak akkor mentődnek el a változtatások, hogyha erre külön parancs érkezik. 
  
Amennyiben keresést hajt végre a felhasználó a program bekéri a keresett kifejezést és kilistázza az adott feltételek alapján talált rekordokat egy görgethető listában. A keresés feltételei: szerző alapján való keresésnél a program ellenőrzi, hogy melyik rekordok szerző adatában található meg a keresett szó (hasonlóan működik a többi keresési típus esetében is, de a kiadási év alapján való keresés pontos egyezést keres).   
  
Az adatbázis kilistázása funkció esetén az összes eltárolt rekord megjelenítésre kerül egy görgethető listában.  
  
### A PROGRAM KI és BE-MENETE  
  
A database mappában található database.txt szolgál az adatbázis fájljainak eltárolására. A program minden futásakor betölti az ebben a fájlban található, könyvekhez tartozó adatokat. A program automatikusan nem menti a könyvtárban végrehajtott módosításokat. Amennyiben menteni szeretnénk ki kell választani az adatbázis menüpontot és azon belül a mentés alpontot.  
  
A rekordok egyes adatait egy `|` karakter választja el a fájlban. Az adatbázist tartalmazó fájl egy rekordjának szerkezete: `rekordok_száma szerző|cím|műfaj|kiadási_év`. A program nem vállalkozik az adatok közötti elválasztójel és a hibásan megadott adatok miatt felmerülő hibák kezelésére.  
    
## PROGRAMOZÓI DOKUMENTÁCIÓ  

### A FORDÍTÁS LÉPÉSEI  
  
A program linux operációs rendszerre lett optimalizálva, ezért windows rendszeren nem fog megfelelően megjelenni. A program a fordításához semmilyen különleges lépést nem igényel. A szabványos könyvtárakon kívül, csak a tantárgy honlap ([https://infoc.eet.bme.hu/](https://infoc.eet.bme.hu/)) által biztosított a megjelenítésért felelős econio, és a memóriaszivárgásokat kereső debugmalloc könyvtárakat használja.   
  
A program fordítása linux rendszeren:  

    gcc main.c econio/econio.c econio/econio.h debugmalloc/debugmalloc.h debugmalloc/debugmalloc-impl.h records/records.c records/records.h database/database.c database/database.h menus/menus.c menus/menus.h definitions.h lists/lists.c lists/lists.h utils/utils.c utils/utils.h -o ElectronicLibrary  

A program futtatása:  

    ./ElectronicLibrary

### MEMÓRIASZIVÁRGÁS ELLENŐRZÉS

Ha a programban memóriaszivárgás van, akkor a program futásának végén a debugmalloc mappában készül egy debugmalloc-memlog.txt fájl, amiben megtekinthetjük a szivárgásról készült összefoglalást. Ezért a tárgyhonlap által biztosított debugmalloc könyvtár felel.

Ha bővebb áttekintést szeretnénk, a programot ellenőrizhetjük a Valgrind Memcheck nevű alkalmazással:

    valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s
  
### ADATSZERKEZET    
 A programban fontos, hogy gyorsan tudjunk hozzáadni és eltávolítani elemeket, viszont a keresés nem időkritikus, ezért a program adatszerkezetét egy rendezetlen duplán láncolt strázsás lista adja. Jelenleg nincsen szükség az elemek rendezésére, de a későbbiekben, ha igény van rá könnyen implementálható egy rendező algoritmus.  
    
### FÁJLSZERKEZET    

- main.c      
- definitions.h      
- README.md      
- database/ database.c , database.h , database.txt  
- lists/ lists.c , lists.h      
- records/ records.c , records.h      
- menus/ menus.c , menus.h      
- utils/ utils.c , utils.h    
- econio/ econio.c , econio.h  
- debugmalloc / debugmalloc.h , debugmalloc-impl.h  
  
  
### DEFINITIONS.H
#### A program függvényei által használt struktúrák és felsorolt lista definícióit tartalmazza.  
 
> Láncolt lista elemet definiál, ami tartalmazza egy könyv adatait `(szerző, cím, műfaj, kiadási év)`. A szerző maximum 30 karakter, a cím maximum 50 karakter, a műfaj maximum 30 karakter lehet.    
    
    typedef  struct  listElement {    
       char  author[31];    
       char  title[51];    
       char  genre[31];    
       int year;    
       struct  listElement  *next, *previous;    
    } listElement;    
 
> Definiál egy duplán láncolt listát. Tartalmazza a lista első és utolsó elemnére mutató pointert.    
    
    typedef  struct  list {    
           listElement *first, *last;    
    } list;    
 
> Definiálja az adatbázis keresésénél használható keresési feltételeket.    
    
    typedef  enum  searchCondition{    
       author, title, genre, year    
    } searchCondition;    
 
### DATABASE/DATABASE.H 
#### A program adatbázisát kezelő függvényeket tartalmazza (betöltés, mentés, kiírás, keresés).    

> Betölti a "database.txt" fájlból az elmentett rekordokat és a paraméterként átvett lista végére fűzi őket. Ha a fájl megnyitása során hibába ütközik, hamis értékkel tér vissza. Ha a beolvasott elemeknek nem tud memóriát foglalni hamis értékkel tér vissza. Sikeres beolvasás esetén igaz értékkel tér vissza.    
    
    bool  loadDatabase(list  *recordList);    

> Aktuális időpillanatban a paraméterként kapott lista változó által tárolt adatokat elmenti a "database.txt" fájlba. A tárolt rekordokat fájlba írja a megfelelő formátum szerint: `szerző|cím|műfaj|kiadási_év Ha a fájl megnyitása során hibába ütközik, hamis értékkel tér vissza.    
    
    bool  saveDatabase(list  *recordList);    

> Kilistázza a paraméterként kapott lista összes elemét egy görgethető listában. A görgetést a fel - le nyilakkal leütésével végezheti a felhasználó. Az ESC gomb megynomására a függvény visszatér. A megjelenítésért egy ciklus felel ami minden futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a megfelelő függvényeket.    
    
    void  printDatabase(list  *recordList);    

> Keresést hajt végre egy paraméterként kapott keresési feltétel alapján a szintén paraméterként kapott listában és kiírja az így talált adatokat egy görgethető listában.    
    
    void  searchDatabase(list  *recordList, searchCondition  condition);    

### LISTS/LIST.H 
#### A duplán láncolt strázsás listát kezelő függvényeket tartalmazza.  
  
> Létrehoz egy duplán láncolt strázsás listát és visszatér vele. A lista tartalmazza a benne tárolt elemeket határoló strázsákra mutató pointereket.    
    
    list  *createList();    

> Felszabadítja a paraméterként kapott lista által lefoglalt memória területeket, törli a listát.    
    
    void  removeList(list  *thisList);    

> Létrehoz egy új listaelemet, lefoglalja az ehhez szükséges memóriaterületeket és visszatér az új elemre mutató pointerrel. Ha nem tudott memóriát foglalni NULL pointerrel tér vissza.    
    
    listElement  *newElement();    

> Létrehoz egy új listaelemet és a paraméterként átvett listaelem adatait átmásolja ide, visszatér az új listaelemre mutató pointerrel. Ha nem tudott memóriát foglalni NULL pointerrel tér vissza. Ha a paraméterként átvett listaelemre mutató pointer NULL pointer, NULL pointerrel tér vissza.    
    
    listElement  *copyElement(listElement  *sourceElement);      

> A paraméterként kapott listaelemet hozzáfűzi a szintén paraméterként kapott lista elejéhez.    
    
    void  appendElementFirst(list  *thisList, listElement  *thisElement);    

> A paraméterként kapott listaelemet hozzáfűzi a szintén paraméterként kapott lista végéhez.    
    
    void  appendElementLast(list  *thisList, listElement  *thisElement);    

> Végig iterál a listán és visszatér a paraméterként átvett indexű elemre mutató pointerrel. Ha a kapott index túl nagy NULL pointerrel tér vissza.    
    
    listElement  *getNth(list  *thisList, int  index);    

> Bekéri a felhasználótól a megváltoztatni kívánt adatokat, majd a felhasználó jóváhagyása után módosítja a paraméterként kapott listaelem adatait. Hamis értékkel tér vissza ha a paraméterként kapott listaelemre mutató pointer NULL pointer.    
    
    bool  modifyElement(listElement  *thisElement);    

> Kifűzi a listából a paraméterként kapott listaelemet és felszabadítja az általa foglalt memóriaterületet. Ha a kapott pointer NULL pointer, hamis értékkel tér vissza. Ha a felhasználó nem hagyja jóvá a törlést akkor is hamis értékkel tér vissza.    
    
    bool  removeElement(listElement  *thisElement);    
 
### RECORDS/RECORDS.H 
#### Az adatbázis rekordjainak kezeléséért felelős függvényeket tartalmazza.  

> Bekéri a felhasználótól egy könyv adatait, majd hozzáfűzi az így létrehozott listaelemet a paraméterként kapott lista elejéhez. Ha nem tud memóriát foglalni az új elemnek hamis értékkel tér vissza, különben igazzal.    
    
    bool  addRecord(list  *recordList);    

> Megjeleníti egy görgethető listában az adatbázis elemeit. ENTER leütésével a felhasználó kiválaszthat egy adatot. A kiválasztott adatra meghívja az adatot módosító függvényt, majd visszatér. ESC leütésére a függvény visszatér. A megjelenítésért egy ciklus felel ami minden futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a megfelelő függvényeket.    
    
    bool  modifyRecord(list  *recordList);    

> Megjeleníti egy görgethető listában az adatbázis elemeit. ENTER leütésével a felhasználó kiválaszthat egy adatot. A kiválasztott adatra meghívja az adatot törlő függvényt, majd visszatér. ESC leütésére a függvény visszatér. A megjelenítésért egy ciklus felel ami minden futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a megfelelő függvényeket.    
    
    bool  removeRecord(list  *recordList);    
 
### MENUS/MENUS.H 
#### Az adatbázist vezérlő menüket megvalósító függvényeket tartalmazza. 

> Megjeleníti a paraméterként kapott sztringek tömbjét menüként. Szükséges paramétere a kilistázni kívánt menüpontok száma, az aktuálisan kijelölt menüpont indexe és a megjelenítendő menű bal felső sarkának x,y koordinátája.    
    
    void  printMenu (char  **menuElements, int  elementNumber, int  selectedIndex, int  x, int  y);    

> Megjeleníti a főmenüt. Lehetővéteszi a menüpontok kiválasztását a fel le nyilakkal. A menüpont megnyitását az ENTER lenyomásával teheti a felhasználó. A kiválasztott menüpont (rekord menü, adatbázis menü) újabb almenük függvényét hívja meg. A kilépés menüpont kiválasztásakor a vüggvény visszatér. A menü megjelenítéséért egy ciklus felel, ami minden futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a megfelelő függvényeket.    
    
    void  mainMenu(list  *recordList);    

> Megjeleníti a rekord menüt. Lehetővéteszi a menüpontok kiválasztását a fel le nyilakkal. A menüpont megnyitását az ENTER lenyomásával teheti a felhasználó. A hozzáadás/törlés/módosítás kiválasztása esetén a függvény meghívja az ezekért a feladatokért felelős függvényeket. A vissza választásakor vagy az ESC leütésekor a függvény visszatér a főmenübe. A menü megjelenítéséért egy ciklus felel, ami minden futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a megfelelő függvényeket.    
    
    void  recordMenu(list  *recordList);    

> Megjeleníti az adatbázis menüt. Lehetővéteszi a menüpontok kiválasztását a fel le nyilakkal. A menüpont megnyitását az ENTER lenyomásával teheti a felhasználó. A keresés/kilistázás/mentés kiválasztása esetén a függvény meghívja az ezekért a feladatokért felelős függvényeket. A vissza választásakor vagy az ESC leütésekor a függvény visszatér a főmenübe. A menü megjelenítéséért egy ciklus felel, ami minden futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a megfelelő függvényeket.    
    
    void  databaseMenu(list  *recordList);    

> Megjeleníti a keresés menüt. Lehetővéteszi a menüpontok kiválasztását a fel le nyilakkal. A menüpont megnyitását az ENTER lenyomásával teheti a felhasználó. A különböző keresések kiválasztása esetén a függvény meghívja az ezekért a feladatokért felelős függvényeket. A vissza választásakor vagy az ESC leütésekor a függvény visszatér az adatbázis menübe. A menü megjelenítéséért egy ciklus felel, ami minden futásakor beolvassa a leütött billentyűt és ez alapján hívja meg a megfelelő függvényeket.    
    
    void  searchMenu(list  *recordList);    

### UTILS/UTILS.H 
#### A megjelenítést segítő és egyéb segédfüggvényeket tartalmaz. 

> Létrehozza a felhasználói felület megjelenítését és beállítja a megnyíló ablakot.    
    
    void econioInit();     

> Törli a program felhasználói felületét is visszaállítja a terminál alapértelmezett tulajdonságait.    
    
    void econioExit();      

> Kirajzol egy ablakot a paraméterként kapott x,y koordináta, a kapott hosszúság, magasság és a kapott szín szerint. Az x,y koordináta az ablak bal felső sarkának koordinátája, a szín az econio könyvtár által definiált színeket jellemző egész szám.    
    
    void printBox(int x, int y, int w, int h, int color);    

> Kirajzolja a könyvtár tetején lévő banner-t egy előre definiált helyen, a képernyő tetején.    
    
    void printBanner();    

> A paraméterként kapott sztring alapján egy információs fejlécet rajzol ki egy előre definiált helyen, a banner alatt.    
    
    void printHeader(char *info);      

> Kiírja egy paraméterként átvett lista elem adatait a paraméterként átvett koordinátán megfelelően formázva.   Paraméterként megkapja a kiírás háttérszínét. A szín az econio könyvtár által definiált színeket jellemző egész szám.    
   
    void printRecord(listElement *thisElement, int x, int y, int bgcolor);      

> Kiírja az adatbázis rekordjait egy eleje indextől egy vége indexig, paraméterként kapott koordinátán. A paraméterként  kapott kiválasztott elem indexén megjelenő elem háttérszíne előre definiáltan más, mint a többi rekord háttérszíne.    
    
    void printFromTo(list *thisList, int from, int to, int selected, int x, int y);      

> Kiírja a paraméterként kapott listaelemet a bemeneti sor helyén. És megkérdezi a felhasználót, hogy jóváhagyja-e az adatot. ENTER leütésekor igaz értékkel tér vissza, ESC leütésekor hamis értékkel tér vissza. Mindaddig amíg a két billentyű közül valamelyiket be nem olvassa a függvény addig nem tér vissza.    
    
    confirmAction(listElement *thisElement);
