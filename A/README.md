# System Zarządzania Strunami i Koralikami

Projekt symuluje zarządzanie strunami, koralikami i powiązaniami między nimi. Program umożliwia manipulowanie obiektami koralików i strun, w tym dodawanie, usuwanie i modyfikowanie powiązań między nimi. Symuluje biologiczny koncept struktur molekularnych, gdzie struny reprezentują nici DNA, koraliki to poszczególne nukleotydy, a powiązania to połączenia między nimi.

## Funkcje

- **Dodawanie i Usuwanie Koralików**: Możliwość dodawania nowych koralików do struny lub usuwania istniejących.
- **Dodawanie i Usuwanie Powiązań**: Możliwość tworzenia lub usuwania powiązań między koralikami na podstawie identyfikatorów strun.
- **Modyfikowanie Powiązań**: Powiązania między koralikami mogą być modyfikowane, co pozwala na symulowanie dynamicznych zmian w interakcjach między strunami i koralikami.
- **Zarządzanie Strunami**: Możliwość zarządzania wieloma strunami, gdzie każda struna może mieć wiele koralików, a każdy koralik może mieć powiązania do innych koralików.
- **Wyświetlanie Danych**: System umożliwia wyświetlanie obecnych strun, koralików i powiązań w strukturze.

## Opis Kodu

Kod zarządza trzema głównymi strukturami: **Struna**, **Koralik** i **Powiązanie**.

### Struktura Struny
- Reprezentuje strunę, zawierającą:
  - `id1`, `id2`, `id3`: Identyfikatory struny.
  - Referencję do pierwszego koralika (`f_bead`), który może być pierwszym koralikiem w liście koralików przypisanych do tej struny.
  - Wskaźnik na kolejne struny (`next_strand`).

### Struktura Koralika
- Reprezentuje pojedynczy koralik, zawierający:
  - `id`: Identyfikator koralika.
  - Wskaźnik na kolejne koraliki w ramach tej samej struny (`next_bead`).
  - Wskaźnik na powiązania (`link_from`), które reprezentują połączenia z innymi koralikami.

### Struktura Powiązania
- Reprezentuje połączenie pomiędzy dwoma koralikami, zawierające:
  - `strand_id1`, `strand_id2`, `strand_id3`: Identyfikatory strun, do których należy powiązanie.
  - `to_bead_id`: Identyfikator koralika, z którym powiązanie jest związane.
  - Wskaźnik na kolejne powiązania (`next_link`).

## Instrukcja Obsługi

Program operuje na komendach wprowadzanych przez użytkownika. Dostępne operacje to:

- **Dodawanie Koralików (A)**: Pozwala dodać nowy koralik do wybranej struny.
- **Usuwanie Koralików (D)**: Umożliwia usunięcie wybranego koralika.
- **Modyfikowanie Powiązań (M)**: Pozwala na modyfikowanie istniejących powiązań między koralikami.
- **Usuwanie Powiązań (R)**: Umożliwia usunięcie wybranego powiązania między koralikami.
- **Wyświetlanie Struktury (P)**: Pokazuje obecny stan strun, koralików i powiązań.

## Przykłady Komend

1. **Dodawanie Koralika**:
   - Komenda: `A`
   - Wprowadź identyfikator koralika oraz identyfikatory struny, do której ma zostać dodany.

2. **Usuwanie Koralika**:
   - Komenda: `D`
   - Wprowadź identyfikator koralika oraz identyfikatory struny, z której ma zostać usunięty.

3. **Modyfikowanie Powiązań**:
   - Komenda: `M`
   - Wprowadź identyfikatory strun i koralików, aby zmodyfikować istniejące powiązania.

4. **Usuwanie Powiązań**:
   - Komenda: `R`
   - Wprowadź identyfikatory powiązania, które ma zostać usunięte.

5. **Wyświetlanie Struktury**:
   - Komenda: `P`
   - Wyświetli obecną strukturę strun, koralików i powiązań.
