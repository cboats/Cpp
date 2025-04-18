# Operacje na Zbiorach Bitowych

Ten projekt implementuje podstawowe i zaawansowane operacje na zbiorach reprezentowanych w formie bitowej. Każdy zbiór to liczba całkowita, w której poszczególne bity oznaczają obecność lub brak elementu.

## Autor

Aleksandra Prodziewicz

## Opis funkcjonalności

Program udostępnia następujące operacje:

### Operacje podstawowe:
- `Emptiness(zbior)` – sprawdza, czy zbiór jest pusty.
- `Nonempty(zbior)` – sprawdza, czy zbiór nie jest pusty.
- `Insert(ciag, *zbior)` – wstawia elementy zakodowane jako ciąg binarny do zbioru.
- `Erase(ciag, *zbior)` – usuwa elementy z ciągu binarnego ze zbioru.
- `Print(zbior, *wynik)` – wypisuje elementy zbioru jako ciąg binarny (np. `00001 00010 ...`).
- `Cardinality(zbior)` – zwraca liczbę elementów w zbiorze.
- `Emplace(ciag, *zbior)` – resetuje zbiór i wstawia nowe elementy.

### Operacje sprawdzające:
- `Member(ciag, zbior)` – sprawdza, czy dany element znajduje się w zbiorze.
- `Equality(zbior1, zbior2)` – sprawdza równość dwóch zbiorów.
- `Inclusion(zbior1, zbior2)` – sprawdza, czy zbiór1 jest podzbiorem zbioru2.
- `Disjoint(zbior1, zbior2)` – sprawdza, czy zbiory są rozłączne.
- `Conjunctive(zbior1, zbior2)` – sprawdza, czy zbiory mają wspólne elementy.

### Operacje na zbiorach:
- `Union(z1, z2, *z3)` – suma zbiorów.
- `Intersection(z1, z2, *z3)` – część wspólna.
- `Symmetric(z1, z2, *z3)` – różnica symetryczna.
- `Difference(z1, z2, *z3)` – różnica zbiorów.

### Porównywanie zbiorów:
- `LessThen(z1, z2)` – czy z1 ma mniej elementów niż z2 (lub mniejsze wartości przy równości).
- `LessEqual(z1, z2)` – mniej lub równo.
- `GreatEqual(z1, z2)` – więcej lub równo.
- `GreatThen(z1, z2)` – więcej niż.

## Reprezentacja danych

- Zbiory reprezentowane są jako 32-bitowe liczby całkowite.
- Elementy zbioru kodowane są binarnie jako ciągi pięciobitowe (np. `00000` do `11111`, czyli liczby 0–31).

## Przykład użycia

```cpp
int zbior = 0;
Insert("00001 00010 00011", &zbior);
char wynik[100];
Print(zbior, wynik);
// wynik: "00001 00010 00011"
