# Zadanie 05 - Edycja i usuwanie kontaktów

## Poziom: ⭐⭐⭐ Trudny

## Opis zadania

Dodaj funkcje edycji i usuwania kontaktów:

**Edycja:**
1. Wyświetl listę kontaktów z numerami
2. Użytkownik wybiera numer do edycji
3. Dla każdego pola pokazuj aktualną wartość
4. Puste wejście = bez zmian, nowy tekst = zmiana

**Usuwanie:**
1. Wyświetl listę kontaktów
2. Użytkownik wybiera numer do usunięcia
3. Potwierdź usunięcie (t/n)
4. Usuń kontakt z vectora

## Oczekiwane wyjście (przykład)

```
--- Edycja kontaktu ---
Wybierz numer: 1
Imię [Jan]: 
Nazwisko [Kowalski]: Kowalczyk
Telefon [123-456-789]: 111-222-333
Email [jan@email.pl]: 
Zaktualizowano kontakt!

--- Usuwanie kontaktu ---
Wybierz numer: 2
Usunąć Anna Nowak? (t/n): t
Kontakt usunięty!
```

---

## Wskazówka 1
Sprawdź zakres numeru: `if (numer < 1 || numer > kontakty.size())`

---

## Wskazówka 2
Do edycji: wczytaj do zmiennej tymczasowej, jeśli niepusta - nadpisz.
```cpp
string temp;
getline(cin, temp);
if (!temp.empty()) k.imie = temp;
```

---

## Wskazówka 3
Usuwanie z vectora: `kontakty.erase(kontakty.begin() + (numer - 1));`

---

## Wskazówka 4
Potwierdzenie: `char potwierdzenie; cin >> potwierdzenie;`

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

void edytujKontakt(vector<Kontakt>& kontakty) {
    if (kontakty.empty()) { cout << "Brak kontaktów." << endl; return; }
    
    // Wyświetl listę
    for (size_t i = 0; i < kontakty.size(); i++) {
        cout << (i+1) << ". " << kontakty[i].imie << " " 
             << kontakty[i].nazwisko << endl;
    }
    
    cout << "Wybierz numer: ";
    int nr; cin >> nr; cin.ignore();
    
    if (nr < 1 || nr > (int)kontakty.size()) {
        cout << "Błędny numer!" << endl; return;
    }
    
    Kontakt& k = kontakty[nr - 1];
    string temp;
    
    cout << "Imię [" << k.imie << "]: "; getline(cin, temp);
    if (!temp.empty()) k.imie = temp;
    
    cout << "Nazwisko [" << k.nazwisko << "]: "; getline(cin, temp);
    if (!temp.empty()) k.nazwisko = temp;
    
    cout << "Telefon [" << k.telefon << "]: "; getline(cin, temp);
    if (!temp.empty()) k.telefon = temp;
    
    cout << "Email [" << k.email << "]: "; getline(cin, temp);
    if (!temp.empty()) k.email = temp;
    
    cout << "Zaktualizowano!" << endl;
}

void usunKontakt(vector<Kontakt>& kontakty) {
    if (kontakty.empty()) { cout << "Brak kontaktów." << endl; return; }
    
    for (size_t i = 0; i < kontakty.size(); i++) {
        cout << (i+1) << ". " << kontakty[i].imie << " " 
             << kontakty[i].nazwisko << endl;
    }
    
    cout << "Wybierz numer: ";
    int nr; cin >> nr; cin.ignore();
    
    if (nr < 1 || nr > (int)kontakty.size()) {
        cout << "Błędny numer!" << endl; return;
    }
    
    cout << "Usunąć " << kontakty[nr-1].imie << " " 
         << kontakty[nr-1].nazwisko << "? (t/n): ";
    char p; cin >> p; cin.ignore();
    
    if (p == 't' || p == 'T') {
        kontakty.erase(kontakty.begin() + (nr - 1));
        cout << "Usunięto!" << endl;
    } else {
        cout << "Anulowano." << endl;
    }
}

int main() {
    vector<Kontakt> kontakty = {
        {"Jan", "Kowalski", "123", "jan@email.pl"},
        {"Anna", "Nowak", "456", "anna@email.pl"}
    };
    
    edytujKontakt(kontakty);
    usunKontakt(kontakty);
    
    return 0;
}
```
