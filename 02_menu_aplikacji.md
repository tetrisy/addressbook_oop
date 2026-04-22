# Zadanie 02 - Menu aplikacji

## Poziom: ⭐ Łatwy

## Opis zadania

Stwórz menu główne aplikacji książki adresowej:
1. Funkcję `wyswietlMenu()` pokazującą opcje
2. Pętlę główną obsługującą wybór użytkownika
3. Obsługę opcji 0 kończącej program

Menu powinno zawierać opcje:
- 1. Dodaj kontakt
- 2. Wyświetl wszystkie
- 3. Wyszukaj
- 4. Edytuj
- 5. Usuń
- 0. Wyjście

Na razie wystarczą funkcje zastępcze wypisujące nazwę wybranej opcji.

## Oczekiwane wyjście (przykład)

```
=== KSIĄŻKA ADRESOWA ===
1. Dodaj kontakt
2. Wyświetl wszystkie
3. Wyszukaj kontakt
4. Edytuj kontakt
5. Usuń kontakt
0. Wyjście
Wybór: 1
[Dodawanie kontaktu...]

=== KSIĄŻKA ADRESOWA ===
...
Wybór: 0
Do widzenia!
```

---

## Wskazówka 1
Użyj pętli `while (true)` lub `do-while` dla menu głównego.

---

## Wskazówka 2
Użyj `switch` do obsługi wyboru użytkownika.

---

## Wskazówka 3
Po `cin >> wybor;` dodaj `cin.ignore();` aby wyczyścić bufor.

---

## Wskazówka 4
```cpp
switch (wybor) {
    case 1: /* kod */ break;
    case 0: return 0;  // lub dzialaj = false;
    default: cout << "Błąd!"; break;
}
```

---

## Wskazówka 5 (Rozwiązanie)

```cpp
#include <iostream>
using namespace std;

void wyswietlMenu() {
    cout << endl;
    cout << "=== KSIĄŻKA ADRESOWA ===" << endl;
    cout << "1. Dodaj kontakt" << endl;
    cout << "2. Wyświetl wszystkie" << endl;
    cout << "3. Wyszukaj kontakt" << endl;
    cout << "4. Edytuj kontakt" << endl;
    cout << "5. Usuń kontakt" << endl;
    cout << "0. Wyjście" << endl;
    cout << "Wybór: ";
}

int main() {
    int wybor;
    
    while (true) {
        wyswietlMenu();
        cin >> wybor;
        cin.ignore();
        
        switch (wybor) {
            case 1: cout << "[Dodawanie kontaktu...]" << endl; break;
            case 2: cout << "[Wyświetlanie...]" << endl; break;
            case 3: cout << "[Wyszukiwanie...]" << endl; break;
            case 4: cout << "[Edycja...]" << endl; break;
            case 5: cout << "[Usuwanie...]" << endl; break;
            case 0: 
                cout << "Do widzenia!" << endl;
                return 0;
            default:
                cout << "Nieznana opcja!" << endl;
        }
    }
    
    return 0;
}
```
