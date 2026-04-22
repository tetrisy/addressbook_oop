# Zadanie 01 - Struktura Kontakt

## Poziom: ⭐ Łatwy

## Opis zadania

Zaprojektuj i zaimplementuj strukturę `Kontakt` przechowującą dane osoby:
- imię (string)
- nazwisko (string)
- telefon (string)
- email (string)
- ulica (string)
- miasto (string)

Utwórz również funkcję `wyswietlKontakt()` wyświetlającą wszystkie dane kontaktu.

W `main()` utwórz 2 przykładowe kontakty i wyświetl je.

## Oczekiwane wyjście

```
=== Kontakt 1 ===
Imię:     Jan
Nazwisko: Kowalski
Telefon:  123-456-789
Email:    jan@email.pl
Ulica:    ul. Główna 10
Miasto:   Warszawa

=== Kontakt 2 ===
Imię:     Anna
Nazwisko: Nowak
Telefon:  987-654-321
Email:    anna@email.pl
Ulica:    ul. Parkowa 5
Miasto:   Kraków
```

---

## Wskazówka 1
Struktura definiowana jest słowem kluczowym `struct` przed `main()`.

---

## Wskazówka 2
```cpp
struct Kontakt {
    string imie;
    string nazwisko;
    // ... pozostałe pola
};
```

---

## Wskazówka 3
Funkcja wyświetlająca powinna przyjmować kontakt przez const referencję: `void wyswietlKontakt(const Kontakt& k)`.

---

## Wskazówka 4
Dostęp do pól: `k.imie`, `k.nazwisko`, itd.

---

## Wskazówka 5 (Rozwiązanie)

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Kontakt {
    string imie;
    string nazwisko;
    string telefon;
    string email;
    string ulica;
    string miasto;
};

void wyswietlKontakt(const Kontakt& k) {
    cout << "Imię:     " << k.imie << endl;
    cout << "Nazwisko: " << k.nazwisko << endl;
    cout << "Telefon:  " << k.telefon << endl;
    cout << "Email:    " << k.email << endl;
    cout << "Ulica:    " << k.ulica << endl;
    cout << "Miasto:   " << k.miasto << endl;
}

int main() {
    Kontakt k1 = {"Jan", "Kowalski", "123-456-789", 
                  "jan@email.pl", "ul. Główna 10", "Warszawa"};
    Kontakt k2 = {"Anna", "Nowak", "987-654-321", 
                  "anna@email.pl", "ul. Parkowa 5", "Kraków"};
    
    cout << "=== Kontakt 1 ===" << endl;
    wyswietlKontakt(k1);
    cout << endl;
    
    cout << "=== Kontakt 2 ===" << endl;
    wyswietlKontakt(k2);
    
    return 0;
}
```
