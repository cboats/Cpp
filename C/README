# Big Number Operations

## Opis

Program implementuje operacje na dużych liczbach, które są reprezentowane jako ciągi znaków (stringi). Obsługuje operacje dodawania, odejmowania i mnożenia na liczbach o dowolnej wielkości. Został zaprojektowany, aby radzić sobie z liczbami, które są zbyt duże, aby zmieściły się w standardowych typach liczbowych dostępnych w C++.

Program obsługuje także:
- Operacje na liczbach dodatnich i ujemnych.
- Usuwanie zbędnych zer wiodących.
- Reprezentowanie wyników w postaci poprawnych ciągów znaków.

## Funkcje

### 1. `reverse_string`

Funkcja rekurencyjnie odwraca ciąg znaków.

**Argumenty:**
- `string& s`: ciąg znaków, który ma zostać odwrócony.
- `int n`: długość ciągu.
- `int r = 0`: zmienna pomocnicza do rekurencji (domyślnie 0).

### 2. `make_pretty`

Funkcja usuwa zbędne zera wiodące z liczby reprezentowanej jako ciąg znaków.

**Argumenty:**
- `Number* s`: wskaźnik na strukturę zawierającą liczbę w formie ciągu znaków.
- `int n`: długość liczby.

### 3. `is_bigger`

Funkcja porównuje dwie liczby reprezentowane jako ciągi znaków i zwraca:
- 1, jeśli pierwsza liczba jest większa.
- 2, jeśli druga liczba jest większa.
- 0, jeśli liczby są równe.

**Argumenty:**
- `string one`: pierwsza liczba.
- `string two`: druga liczba.
- `int n1`: długość pierwszej liczby.
- `int n2`: długość drugiej liczby.
- `int i = 0`: indeks pomocniczy do rekurencji (domyślnie 0).

### 4. `add_string`

Funkcja dodaje dwie liczby reprezentowane jako ciągi znaków.

**Argumenty:**
- `Number* one`: pierwsza liczba.
- `Number* three`: druga liczba.
- `Number* temp`: zmienna pomocnicza do przechowywania wyniku.
- `int n`: długość liczby.

### 5. `sub_string`

Funkcja odejmuje jedną liczbę od drugiej, reprezentowaną jako ciągi znaków.

**Argumenty:**
- `Number* one`: pierwsza liczba.
- `Number* three`: druga liczba.
- `Number* temp`: zmienna pomocnicza do przechowywania wyniku.
- `int n`: długość liczby.

### 6. `determine_string`

Funkcja określa wynik operacji matematycznych (dodawanie lub odejmowanie) na dwóch liczbach reprezentowanych jako ciągi znaków i zapisuje wynik w strukturze `Number`.

**Argumenty:**
- `Number* one`: pierwsza liczba.
- `Number* three`: druga liczba.

### 7. `sign_combine`

Funkcja przetwarza znak liczby (dodatni lub ujemny) i dostosowuje reprezentację liczby.

**Argumenty:**
- `Number* t`: wskaźnik na strukturę liczby.

### 8. `adding`

Funkcja rekurencyjnie dodaje kilka liczb, przekazywanych jako argumenty, do wyniku, który jest reprezentowany jako ciąg znaków.

**Argumenty:**
- `int amount`: liczba liczb do dodania.
- `const string* s`: tablica stringów reprezentujących liczby.
- `Number* tp`: wskaźnik na zmienną, w której zostanie zapisany wynik.
- `int repeat = 1`: zmienna pomocnicza (domyślnie 1).

### 9. `Sum`

Funkcja dodaje wszystkie liczby przekazane jako argumenty i zwraca wynik w postaci ciągu znaków.

**Argumenty:**
- `int amount`: liczba liczb do dodania.
- `const string* st`: tablica stringów reprezentujących liczby.

### 10. `mult_this`

Funkcja mnoży liczbę reprezentowaną jako ciąg znaków przez pojedynczą cyfrę.

**Argumenty:**
- `Number* ed`: wskaźnik na liczbę.
- `Number* to`: wskaźnik na wynik.
- `int xmult`: liczba, przez którą mnożymy.
- `int n_ed`: długość liczby.
- `int repeat = 0`: zmienna pomocnicza (domyślnie 0).
- `int added = 0`: zmienna pomocnicza dla dodania do wyniku (domyślnie 0).

### 11. `mult_string`

Funkcja mnoży dwie liczby reprezentowane jako ciągi znaków.

**Argumenty:**
- `Number* ed`: pierwsza liczba.
- `Number* ing`: druga liczba.
- `Number* nu`: zmienna pomocnicza przechowująca wynik.
- `int n_ed`: długość pierwszej liczby.
- `int n_ing`: długość drugiej liczby.
- `int rep = 0`: zmienna pomocnicza (domyślnie 0).

### 12. `multing`

Funkcja rekurencyjnie mnoży zestaw liczb.

**Argumenty:**
- `int amount`: liczba liczb do pomnożenia.
- `const string* st`: tablica stringów reprezentujących liczby.
- `Number* an`: wskaźnik na zmienną przechowującą wynik.
- `int repeat = 1`: zmienna pomocnicza (domyślnie 1).

### 13. `Mult`

Funkcja mnoży wszystkie liczby przekazane jako argumenty i zwraca wynik w postaci ciągu znaków.

**Argumenty:**
- `int amount`: liczba liczb do pomnożenia.
- `const string* st`: tablica stringów reprezentujących liczby.

### 14. `Operation`

Funkcja wykonuje operację matematyczną (dodawanie, odejmowanie, mnożenie) na zadanych liczbach, przy użyciu odpowiedniej funkcji.

**Argumenty:**
- `string(*func)(int, const string*)`: funkcja operacji (np. dodawanie, odejmowanie, mnożenie).
- `int amount`: liczba liczb do operacji.
- `const string* st`: tablica stringów reprezentujących liczby.

## Przykład użycia

### Dodawanie:

```cpp
string result = Sum(3, "123", "456", "789");
cout << result << endl;  // Wypisuje wynik dodawania: "1368"
