# Drzewo Wyszukiwań Binarnego (BST) w C++

## Opis
Ten projekt implementuje strukturę danych typu Drzewo Wyszukiwań Binarnego (BST) w języku C++. Klasa BST wspiera podstawowe operacje, takie jak dodawanie, usuwanie, wyszukiwanie oraz różne metody przejścia przez drzewo. Drzewo może być przeszukiwane w różnych porządkach: pre-order, in-order, post-order oraz level-order.

## Funkcjonalności
- **Dodawanie**: Dodaje węzeł z podanym kluczem i danymi do drzewa.
- **Usuwanie**: Usuwa węzeł z drzewa na podstawie podanego klucza.
- **Wyszukiwanie**: Znajduje węzeł z określonym kluczem.
- **Przejścia przez drzewo**:
  - Pre-order
  - In-order
  - Post-order
  - Level-order
- **Obliczanie wysokości**: Oblicza wysokość drzewa.

## Klasy
### `BST`
Ta klasa reprezentuje Drzewo Wyszukiwań Binarnego (BST) z następującymi funkcjami:

### Publiczne metody:
- **Insert(KEY_TYPE key, DATA_TYPE data)**: Dodaje węzeł z podanym `key` i `data` do drzewa.
- **Delete(KEY_TYPE key)**: Usuwa węzeł z drzewa na podstawie podanego `key`.
- **Search(KEY_TYPE key)**: Wyszukuje węzeł z określonym `key` i zwraca związane z nim dane.
- **PreOrder()**: Przechodzi przez drzewo w porządku pre-order (korzeń, lewy, prawy).
- **InOrder()**: Przechodzi przez drzewo w porządku in-order (lewy, korzeń, prawy).
- **PostOrder()**: Przechodzi przez drzewo w porządku post-order (lewy, prawy, korzeń).
- **LevelOrder()**: Przechodzi przez drzewo poziomami.
- **Height()**: Zwraca wysokość drzewa.

### Składowe danych:
- **root**: Korzeń drzewa.

### Prywatne metody:
- **preorder(Node* currNode)**: Pomocnicza metoda do przejścia przez drzewo w porządku pre-order.
- **inorder(Node* currNode)**: Pomocnicza metoda do przejścia przez drzewo w porządku in-order.
- **postorder(Node* currNode)**: Pomocnicza metoda do przejścia przez drzewo w porządku post-order.
- **currLevel(Node* currNode, int level)**: Pomocnicza metoda do przejścia przez drzewo poziomami.
- **cHeight(Node* currNode)**: Pomocnicza metoda do obliczania wysokości drzewa rekurencyjnie.

## Przykład użycia

```cpp
#include "BST.h"

int main() {
    BST<int, string> tree;

    tree.Insert(50, "Korzeń");
    tree.Insert(30, "Lewy potomek");
    tree.Insert(70, "Prawy potomek");
    tree.Insert(20, "Lewy potomek lewego potomka");
    tree.Insert(40, "Prawy potomek lewego potomka");

    cout << "Przejście PreOrder: ";
    tree.PreOrder();  // Wynik: 50Korzeń 30Lewy potomek 20Lewy potomek lewego potomka 40Prawy potomek lewego potomka 70Prawy potomek

    cout << "\nPrzejście InOrder: ";
    tree.InOrder();  // Wynik: 20Lewy potomek lewego potomka 30Lewy potomek 40Prawy potomek lewego potomka 50Korzeń 70Prawy potomek

    cout << "\nPrzejście PostOrder: ";
    tree.PostOrder();  // Wynik: 20Lewy potomek lewego potomka 40Prawy potomek lewego potomka 30Lewy potomek 70Prawy potomek 50Korzeń

    cout << "\nPrzejście LevelOrder: ";
    tree.LevelOrder();  // Wynik: 50Korzeń 30Lewy potomek 70Prawy potomek 20Lewy potomek lewego potomka 40Prawy potomek lewego potomka

    cout << "\nWysokość drzewa: " << tree.Height();  // Wynik: 2

    cout << "\nWyszukiwanie węzła z kluczem 40: ";
    auto result = tree.Search(40);
    if (result) {
        cout << *result;  // Wynik: Prawy potomek lewego potomka
    } else {
        cout << "Węzeł nie znaleziony!";
    }

    cout << "\nUsuwanie węzła z kluczem 30: ";
    tree.Delete(30);  // Węzeł z kluczem 30 usunięty
    tree.InOrder();  // Wynik: 20Lewy potomek lewego potomka 40Prawy potomek lewego potomka 50Korzeń 70Prawy potomek
}
