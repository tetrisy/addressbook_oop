# Zadanie 03 - Dodawanie i lista kontaktów

## Poziom: ⭐⭐ Średni

## Opis zadania

Rozbuduj aplikację o funkcjonalność dodawania i wyświetlania kontaktów:
1. Użyj `vector<Kontakt>` do przechowywania kontaktów
2. Funkcja `dodajKontakt()` - wczytuje dane od użytkownika i dodaje do vectora
3. Funkcja `wyswietlWszystkie()` - pokazuje listę wszystkich kontaktów

Pamiętaj o obsłudze pustej listy kontaktów.

## Oczekiwane wyjście (przykład)

```
Wybór: 2
Brak kontaktów.

Wybór: 1
--- Dodawanie kontaktu ---
Imię: Jan
Nazwisko: Kowalski
Telefon: 123456789
Email: jan@email.pl
Kontakt dodany!

Wybór: 2
--- Lista kontaktów (1) ---
1. Jan Kowalski
   Tel: 123456789
   Email: jan@email.pl
```

---

## Wskazówka 1
Dołącz `#include <vector>` i zadeklaruj wektor globalnie lub przekazuj przez referencję.

---

## Wskazówka 2
Użyj `getline(cin, zmienna)` do wczytywania pełnych linii tekstu.

---

## Wskazówka 3
Dodawanie do vectora: `kontakty.push_back(nowyKontakt);`

---

## Wskazówka 4
Sprawdzenie pustej listy: `if (kontakty.empty())` lub `if (kontakty.size() == 0)`

---

## Wskazówka 5 (Rozwiązanie)

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Kontakt {
    string imie, nazwisko, telefon, email;
};

void dodajKontakt(vector<Kontakt>& kontakty) {
    Kontakt k;
    cout << "--- Dodawanie kontaktu ---" << endl;
    cout << "Imię: "; getline(cin, k.imie);
    cout << "Nazwisko: "; getline(cin, k.nazwisko);
    cout << "Telefon: "; getline(cin, k.telefon);
    cout << "Email: "; getline(cin, k.email);
    kontakty.push_back(k);
    cout << "Kontakt dodany!" << endl;
}

void wyswietlWszystkie(const vector<Kontakt>& kontakty) {
    if (kontakty.empty()) {
        cout << "Brak kontaktów." << endl;
        return;
    }
    cout << "--- Lista kontaktów (" << kontakty.size() << ") ---" << endl;
    for (size_t i = 0; i < kontakty.size(); i++) {
        cout << (i+1) << ". " << kontakty[i].imie << " " 
             << kontakty[i].nazwisko << endl;
        cout << "   Tel: " << kontakty[i].telefon 
             << " | Email: " << kontakty[i].email << endl;
    }
}

int main() {
    vector<Kontakt> kontakty;
    int wybor;
    
    while (true) {
        cout << "\n1.Dodaj 2.Lista 0.Wyjście: ";
        cin >> wybor; cin.ignore();
        
        switch (wybor) {
            case 1: dodajKontakt(kontakty); break;
            case 2: wyswietlWszystkie(kontakty); break;
            case 0: return 0;
        }
    }
}
```
