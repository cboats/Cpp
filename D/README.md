# Symulacja Ogrodu

Ten projekt symuluje system **drzew**, **gałęzi**, **owoców** i **ogrodów**, skupiając się na operacjach takich jak wzrost, zbiór, przycinanie i klonowanie. Symulacja przedstawia ogród, w którym można sadzić i zarządzać wieloma drzewami, z których każde ma swoje gałęzie i owoce. Można również przeprowadzać operacje takie jak wzrost, zanik, cięcie i klonowanie drzew lub gałęzi.

## Klasy

Symulacja jest podzielona na trzy główne klasy: `GARDEN_CLASS`, `WOOD_CLASS` i `BRANCH_CLASS`. Poniżej znajduje się krótki opis każdej z nich:

### 1. `BRANCH_CLASS`

Klasa `BRANCH_CLASS` reprezentuje gałęzie drzewa. Zawiera różne właściwości, takie jak długość, całkowita liczba owoców oraz waga owoców. Można wykonywać operacje, takie jak:

- **Wzrost**: Gałąź rośnie w czasie, dodając owoce i zwiększając swoją długość.
- **Zanik**: Gałąź zanika w czasie, zmniejszając długość i usuwając owoce.
- **Zbiór**: Można zebrać owoce z gałęzi, które spełniają minimalne wymaganie wagowe.
- **Cięcie**: Gałąź może zostać przycięta do określonej długości.

#### Główne metody:

- `growthBranch()`: Zwiększa długość gałęzi i dodaje nowe owoce.
- `fadeBranch()`: Zmniejsza długość gałęzi i zanika owoce.
- `harvestBranch(unsigned int minimalWeight)`: Zbiera owoce z gałęzi, które spełniają wymaganie minimalnej wagi.
- `cutBranch(unsigned int newLength)`: Przycina gałąź do określonej długości.
- `getFruitPointer(unsigned int fruitOnLength)`: Zwraca wskaźnik do owocu na określonej długości gałęzi.

### 2. `WOOD_CLASS`

Klasa `WOOD_CLASS` reprezentuje drzewo. Każde drzewo zawiera wiele gałęzi, a także umożliwia wykonywanie operacji na drzewie, takich jak wzrost, zanik, zbiór i cięcie. Klasa `WOOD_CLASS` pozwala zarządzać kolekcją gałęzi i klonować istniejące gałęzie.

#### Główne metody:

- `growthWood()`: Zwiększa wysokość drzewa i rośnie gałęzie.
- `fadeWood()`: Zmniejsza wysokość drzewa i zanika gałęzie.
- `harvestWood(unsigned int minimalWeight)`: Zbiera owoce z gałęzi drzewa, które spełniają minimalne wymaganie wagowe.
- `cutWood(unsigned int newHeight)`: Przycina drzewo do określonej wysokości.
- `cloneBranch(BRANCH_CLASS *toClone)`: Klonuje istniejącą gałąź i dodaje ją do drzewa.

### 3. `GARDEN_CLASS`

Klasa `GARDEN_CLASS` reprezentuje ogród, który zawiera wiele drzew. Możesz sadzić nowe drzewa, usuwać istniejące, klonować je oraz przeprowadzać operacje na wszystkich drzewach w ogrodzie, takie jak wzrost, zanik, zbiór i klonowanie.

#### Główne metody:

- `plantWood()`: Sadzi nowe drzewo w ogrodzie.
- `extractWood(unsigned int toExtractId)`: Usuwa drzewo z ogrodu na podstawie jego identyfikatora.
- `harvestGarden(unsigned int minimalWeight)`: Zbiera owoce z wszystkich drzew w ogrodzie, które spełniają wymaganie minimalnej wagi.
- `growGarden()`: Sprawia, że wszystkie drzewa w ogrodzie rosną.
- `fadeGarden()`: Sprawia, że wszystkie drzewa w ogrodzie zanikają.

## Jak używać

1. **Klonowanie drzewa i gałęzi**:
   - Można klonować gałęzie i dodawać je do innych drzew.
   - Można klonować całe drzewa w ogrodzie.

2. **Zarządzanie ogrodem**:
   - Można sadzić nowe drzewa.
   - Można usunąć drzewa.
   - Można sprawić, by drzewa rosły lub zanikały.

3. **Zbiory**:
   - Zbieraj owoce z gałęzi i drzew, które spełniają określone wymagania wagowe.

## Przykład użycia

```cpp
int main() {
    GARDEN_CLASS garden;
    WOOD_CLASS tree1, tree2;
    
    // Sadzenie drzew w ogrodzie
    garden.plantWood(&tree1);
    garden.plantWood(&tree2);

    // Rozwój drzew
    tree1.growthWood();
    tree2.growthWood();

    // Zbiory
    garden.harvestGarden(10); // Zbiera owoce o wadze powyżej 10

    // Przycinanie drzewa
    tree1.cutWood(5);

    // Klonowanie gałęzi
    BRANCH_CLASS *branch = new BRANCH_CLASS();
    tree1.cloneBranch(branch);
    
    return 0;
}
