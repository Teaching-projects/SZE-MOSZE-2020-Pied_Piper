# SZE-MOSZE-2020-Pied_Piper
## Rövid leirás: 
A következő program egy Role-playing játék harcát szimulálja le. A kód bementül kettő json formátumú fájlt vár, amiből képes beolvasni a két harcos adatit. A bemeneti adatokat a purseUnit() nevü függvény dolgozza fel, ami bementül egy stringet és egy vector-vár. A vector azért szükséges, mert abba tárolja az adatokat a megfelelő továbbadásra. Ezen a adatokat a Character osztály két változója kapja meg. A Character osztály a játékosokért felelős. 
Minden játékos rendelkezik egy névvel, egy Health Pointal és egy Damage-el. Ezeket a Character osztály konstruktora állítja be. Mivel az osztály ezen adattagjai privátok, ezért az osztályban létrehoztunk getter függvényeket, amikkel ezeket le tudjuk kérdezni biztonságosan.
** Az osztály legfontosabb függvényei a következőek: **
- Az isDead() függvényel letudjuk kérdezni, hogy a karakterünk halott-e
- Az injure(int) függvényünkel sebzést tudunk bevinni a karakterünknek, ezt általában az ellenfél getDamage() függvényének átadásával tudjuk elérni,
- Az utolsó függvényük pedig az attack(), ami egy Character-t vár bemenetül és annak injure() függvényét hivja meg. 
A Main-ben ezen kivül létezik még kettő függvény, amikkel a harcot tudjuk leszimulálni. Az egyik függvény a logCharacterParameters(Character &, Character&), amivel az éppen küzdő játékosok adatait tudjuk kiírni, a mások függvény pedig a game(Character&, Character&), ami a játék levezényléséért felelős. 
