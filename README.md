A játékosok kezelésére létrehoztuk a Player nevű osztályt. Az osztály konstruktora három változót vár bemenetül, amik a következők: Name, hp (health point) és dmg (damage). 
Az osztály rendelkezik GetName, GetHp, GetDmg és SetInjury metódussal.
Az első három metódus visszaadja a játékos nevét, életerejét vagy sebzését, az SetInjury-vel pedig lényegében megtudjuk sebezni a játékosunk, az életerejéből egy X értéket von le.
A Main függvényen belül elsőként dinamikusan lefoglaltunk két helyet a játékosoknak player1 és player2 név alatt, majd a konstruktorokban beállítottuk a játékosok adataikat. 
Magára a csata levezénylésére létrehoztuk a Fight metódust, ami kettő Player-re mutató pointert vár. 
A metóduson belül egy while ciklus helyezkedik el, ami addig fut míg a „fip/Fight in progress” változó értéke igaz. 
A while cikluson belül egy if ág helyezkedik el, amelyben oda-vissza támadják egymást a játékosok a SetInjury metódus meghívásával. 
Maga a SetInjury az ellenfél dmg értékét kapja meg. Abban az esetben, ha az egyik játékos élete 0 értéket vesz fel, ezt a CheckHp metódus ellenőrzi, akkor a fip változó értéke hamis lesz és a játéknak vége. 
A PrintAllStatus a játékosok adatait (Name, hp és dmg) írja ki a konzolra. 
