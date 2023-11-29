#include <iostream>
#include "RejestrCzytelnikow.h"

int main(){
RejestrCzytelnikow rejestr;

// Wczytywanie danych z pliku (jeśli dostępny)
Czytelnik::wczytajMaxIDZPliku("czytelnicy_max_id.txt");
rejestr.wczytajZPliku("czytelnicy.txt");

// Działania użytkownika
char wybor;
do {
std::cout << "1. Zarejestruj czytelnika\n";
std::cout << "2. Wyświetl szczegóły czytelnika\n";
std::cout << "3. Wyświetl wszystkich czytelników\n";
std::cout << "4. Zapisz dane do pliku\n";
std::cout << "5. Wyjdź\n";
std::cout << "Wybór: ";
std::cin >> wybor;
std::cin.ignore(); // Ignorowanie znaku nowej linii po wczytaniu liczby

switch (wybor) {
case '1': {
std::cout << "Podaj dane czytelnika:\n";
std::cout << "Imię: ";
std::string imie;
std::getline(std::cin, imie);

std::cout << "Nazwisko: ";
std::string nazwisko;
std::getline(std::cin, nazwisko);

std::cout << "Adres:\n";
Adres adres;

std::cout << "Ulica: ";
std::getline(std::cin, adres.ulica);

std::cout << "Numer domu/mieszkania: ";
std::getline(std::cin, adres.numerDomu);

std::cout << "Miasto: ";
std::getline(std::cin, adres.miasto);

// Wprowadź kod pocztowy i sprawdź jego format
do {
std::cout << "Kod pocztowy (xx-xxx): ";
std::getline(std::cin, adres.kodPocztowy);
} while (!Adres::czyPoprawnyFormatKoduPocztowego(adres.kodPocztowy));

Czytelnik nowyCzytelnik(rejestr.generujID(), imie, nazwisko, adres);
rejestr.zarejestrujCzytelnika(nowyCzytelnik);
rejestr.zapiszDoPliku("czytelnicy.txt");
Czytelnik::zapiszMaxIDDoPliku("czytelnicy_max_id.txt");
break;
}
case '2': {
std::cout << "Podaj ID czytelnika: ";
std::string id;
std::getline(std::cin, id);
rejestr.wyswietlSzczegolyCzytelnika(id);
break;
}
case '3':
rejestr.wyswietlWszystkichCzytelnikow();
break;
case '4':
rejestr.zapiszDoPliku("czytelnicy.txt");
Czytelnik::zapiszMaxIDDoPliku("czytelnicy_max_id.txt");
break;
case '5':
std::cout << "Do widzenia!\n";
break;
default:
std::cout << "Niepoprawny wybór.\n";
}
} while (wybor != '5');

return 0;
}