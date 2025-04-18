# Arena Battle Simulation

Projekt jest symulacją walki w arenie, gdzie różne typy graczy (człowiek, bestia, berserker) walczą ze sobą na śmierć i życie. Gra wykorzystuje klasy i obiekty w języku C++ do modelowania postaci, areny oraz mechanizmu walki.

## Opis klas:

### 1. **PLAYER_CLASS**
Jest to klasa bazowa dla wszystkich typów graczy. Zawiera wspólne atrybuty i metody, takie jak:
- `id` – identyfikator gracza,
- `maxHealth` – maksymalne zdrowie,
- `currHealth` – bieżące zdrowie,
- `damage` – zadawane obrażenia,
- `agility` – zwinność,
- `defense` – obrona.

Metody takie jak `getRemainingHealth()`, `takeDamage()`, `applyWinnerReward()`, `cure()` są zadeklarowane w tej klasie i nadpisane w klasach pochodnych.

### 2. **CAESAR_CLASS**
Klasa odpowiedzialna za zarządzanie przebiegiem walki. W jej ramach znajduje się metoda `judgeDeathOfLife()`, która sprawdza, czy gracz powinien umrzeć w wyniku odniesionych obrażeń.

### 3. **ARENA_CLASS**
Klasa ta zarządza pojedynkiem pomiędzy dwoma graczami. Odpowiada za kolejność ataków, obliczanie obrażeń oraz stosowanie nagród dla zwycięzców.

### 4. **HUMAN_CLASS**
Klasa reprezentująca gracza-człowieka, dziedzicząca po `PLAYER_CLASS`. Zawiera logikę dotyczącą przyjmowania obrażeń oraz stosowania nagród zwycięzcy (np. zwiększenie obrażeń i zwinności).

### 5. **BEAST_CLASS**
Klasa reprezentująca bestię, także dziedzicząca po `PLAYER_CLASS`. Zawiera specyficzną logikę przyjmowania obrażeń, zależną od zwinności bestii, oraz specjalne zachowanie przy niskim poziomie zdrowia (zwiększone obrażenia).

### 6. **BERSERKER_CLASS**
Klasa reprezentująca wojownika-berserkera, który łączy cechy zarówno człowieka, jak i bestii. W zależności od poziomu zdrowia postać może zmieniać tryb działania – od człowieka do bestii. Zawiera logikę dotyczącą przyjmowania obrażeń i zwiększania obrażeń oraz zwinności.

### 7. **SQUAD_CLASS**
Klasa reprezentująca drużynę graczy. Umożliwia dodawanie graczy do drużyny, sortowanie graczy po ich parametrach oraz zarządzanie ich zdrowiem, obrażeniami i nagrodami.
