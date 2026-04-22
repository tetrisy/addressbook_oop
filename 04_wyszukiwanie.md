# Zadanie 04 - Wyszukiwanie kontaktów

## Poziom: ⭐⭐ Średni

## Opis zadania

Dodaj funkcję wyszukiwania kontaktów po frazie:
1. Użytkownik podaje frazę do wyszukania
2. Program znajduje wszystkie kontakty, gdzie fraza występuje w imieniu, nazwisku lub telefonie
3. Wyświetlane są pasujące wyniki

Wyszukiwanie powinno być niewrażliwe na wielkość liter (dla imienia i nazwiska).

## Oczekiwane wyjście (przykład)

```
Wyszukaj: kowalski

Znaleziono 2 kontakt(ów):
1. Jan Kowalski | Tel: 123-456-789
2. Anna Kowalska | Tel: 987-654-321

Wyszukaj: xyz
Nie znaleziono kontaktów.
```

---

## Wskazówka 1
Użyj `string::find()` do sprawdzenia czy fraza jest w tekście. Zwraca `string::npos` jeśli nie znaleziono.

---

## Wskazówka 2
Do porównania bez wielkości liter, zamień oba teksty na małe litery przed porównaniem.

---

## Wskazówka 3
```cpp
string naMale(string s) {
    for (char& c : s) c = tolower(c);
    return s;
}
```

---

## Wskazówka 4
```cpp
if (naMale(k.imie).find(naMale(fraza)) != string::npos ||
    naMale(k.nazwisko).find(naMale(fraza)) != string::npos) {
    // znaleziono
}
```

---

## Wskazówka 5 (Rozwiązanie)

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Kontakt {
    string imie, nazwisko, telefon;
};

string naMale(string s) {
    for (char& c : s) c = tolower(c);
    return s;
}

void wyszukaj(const vector<Kontakt>& kontakty) {
    string fraza;
    cout << "Wyszukaj: ";
    getline(cin, fraza);
    
    vector<int> wyniki;
    string frazaMala = naMale(fraza);
    
    for (size_t i = 0; i < kontakty.size(); i++) {
        if (naMale(kontakty[i].imie).find(frazaMala) != string::npos ||
            naMale(kontakty[i].nazwisko).find(frazaMala) != string::npos ||
            kontakty[i].telefon.find(fraza) != string::npos) {
            wyniki.push_back(i);
        }
    }
    
    if (wyniki.empty()) {
        cout << "Nie znaleziono kontaktów." << endl;
        return;
    }
    
    cout << "Znaleziono " << wyniki.size() << " kontakt(ów):" << endl;
    for (int idx : wyniki) {
        cout << (idx+1) << ". " << kontakty[idx].imie << " " 
             << kontakty[idx].nazwisko 
             << " | Tel: " << kontakty[idx].telefon << endl;
    }
}

int main() {
    vector<Kontakt> kontakty = {
        {"Jan", "Kowalski", "123-456-789"},
        {"Anna", "Kowalska", "987-654-321"},
        {"Piotr", "Nowak", "555-123-456"}
    };
    
    wyszukaj(kontakty);
    return 0;
}
```
