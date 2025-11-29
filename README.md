
### 1. Uruchamianie programu (`main.cpp`)

1. Otworzyć projekt w Visual Studio.
2. W Solution Explorer kliknąć PPM na `main.cpp`.
3. Wybrać "Include in Build", jeśli był wyłączony.
4. W pliku `test.cpp` kliknąć "Exclude from Build", żeby nie było podwójnego `main`.
5. Ustawić projekt jako StartUp Project (jeśli nie jest).
6. Odpalić program.

Program posortuje dwie tablice i wypisze wynik w konsoli.

---

### 2. Uruchamianie testów Google Test
1. W Solution Explorer wyłączyć kompilację `main.cpp`  
   (PPM → Exclude from Build).
2. Włączyć kompilację `test.cpp`  
   (PPM → Include in Build).
3. Upewnić się, że projekt typu „Google Test” jest ustawiony jako StartUp Project.
4. Otworzyć **Test Explorer**:  
   `Test → Test Explorer` lub po prostu odplić program (F5).

Wszystkie 13 testów powinno przejść poprawnie.

---

## Co testują testy?

W `test.cpp` znajdują się przypadki sprawdzające:

- tablica już posortowana
- tablica posortowana odwrotnie
- losowe liczby
- liczby ujemne
- liczby dodatnie i ujemne
- pusty vector
- jeden element
- duplikaty
- ujemne + duplikaty
- mix ujemne/dodatnie/duplikaty
- dwa elementy już posortowane
- duża tablica (100+ elementów)
- duża tablica mieszana

Wszystkie testy powinny zakończyć się na zielono.
