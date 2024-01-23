#include <iostream>
#include <fstream>
#include "katalog.h"
#include "ksiazka.h"
#include "Czytelnik.h"
#include "Adres.h"
#include "RejestrCzytelnikow.h"
#include "wypozyczanie.h"
#include "uzytkownik.h"
#include "bazadanychuzytkownika.h"

int main() {
    setlocale(LC_CTYPE, "Polish");
    Katalog katalog;
    katalog.wczytajKsiazkiZPliku("ksiazki.txt");

    //część Huberta:
    RejestrCzytelnikow rejestr;

    // Wczytywanie danych z pliku (jeśli dostępny)
    Czytelnik::wczytajMaxIDZPliku("czytelnicy_max_id.txt");
    rejestr.wczytajZPliku("czytelnicy.txt");

BazaUzytkownikow bazaDanychUzytkownika;
 bazaDanychUzytkownika.wczytajUzytkownikowZPliku("uzytkownicy.txt");
std::string opcja;
std::cout << "Czy chcesz się zalogować (l) czy zarejestrować (r)? ";
std::cin >> opcja;

std::string nazwaUzytkownika;
std::string haslo;
std::string kodUwierzytelniajacy;
std::string rola;
if (opcja == "r") {
    std::string imie;
    std::string nazwisko;
    std::string ulica;
    std::string numerDomu;
    std::string kodPocztowy;
    std::string miasto;
    std::cout << "Podaj imię: ";
    std::cin >> imie;
    std::cout << "Podaj nazwisko: ";
    std::cin >> nazwisko;
    std::cout << "Podaj ulicę: ";
    std::cin >> ulica;
    std::cout << "Podaj numer domu: ";
    std::cin >> numerDomu;
    do{
        std::cout << "Podaj kod pocztowy: ";
        std::cin >> kodPocztowy;
        if(!Adres::czyPoprawnyFormatKoduPocztowego(kodPocztowy)){
            std::cout << "Niepoprawny format kodu pocztowego. Spróbuj ponownie.\n";
        }
    } while(!Adres::czyPoprawnyFormatKoduPocztowego(kodPocztowy));
    // std::cout << "Podaj kod pocztowy: ";
    // std::cin >> kodPocztowy;
    std::cout << "Podaj miasto: ";
    std::cin >> miasto;
    Adres adres(ulica, numerDomu, kodPocztowy, miasto);
    std::cout << "Podaj nazwę użytkownika: ";
    std::cin >> nazwaUzytkownika;
    std::cout << "Podaj hasło: ";
    std::cin >> haslo;
    do{
    std::cout << "Podaj rolę (czytelnik/bibliotekarz): ";
    std::cin >> rola;
    } while (rola != "czytelnik" && rola != "bibliotekarz");
    if (rola == "bibliotekarz") {
    std::cout << "Podaj kod uwierzytelniający dla bibliotekarza: ";
    std::cin >> kodUwierzytelniajacy;
    if (kodUwierzytelniajacy != "1111") { 
        std::cout << "Niepoprawny kod uwierzytelniający. Nie możesz się zarejestrować jako bibliotekarz.\n";   
        rola="czytelnik"; 
    }
    // std::cout << "Podaj rolę (czytelnik/bibliotekarz): ";
    // std::cin >> rola;
    bazaDanychUzytkownika.zarejestrujUzytkownika(nazwaUzytkownika, haslo, rola, imie, nazwisko, adres);
   // bazaDanychUzytkownika.zapiszUzytkownikowDoPliku("uzytkownicy.txt");
} else if (opcja == "l") {
    // Zaloguj użytkownika
    std::cout << "Podaj nazwę użytkownika: ";
    std::cin >> nazwaUzytkownika;
    std::cout << "Podaj hasło: ";
    std::cin >> haslo;

    Uzytkownik* uzytkownik = bazaDanychUzytkownika.znajdzUzytkownika(nazwaUzytkownika);
    if (uzytkownik != nullptr && uzytkownik->sprawdzHaslo(haslo)) {
        std::cout << "Logowanie pomyślne.\n";
        if (uzytkownik->getRola() == "czytelnik") {
            // Wyświetl menu dla czytelnika
        } else if (uzytkownik->getRola() == "bibliotekarz") {
            // Wyświetl menu dla bibliotekarza
        }
    } else {
        std::cout << "Logowanie nieudane.\n";
    }
} else {
    std::cout << "Niepoprawna opcja.\n";
}

 bazaDanychUzytkownika.zapiszUzytkownikowDoPliku("uzytkownicy.txt");

    // Działania użytkownika
    char wybor;
    do {
        std::cout << "1. Zarejestruj czytelnika\n";
        std::cout << "2. Wyświetl szczegóły czytelnika\n";
        std::cout << "3. Wyświetl wszystkich czytelników\n";
        std::cout << "4. Usuń czytelnika.\n";
        std::cout << "5. Zapisz dane do pliku\n";
        std::cout << "6. Szukanie ksiazek\n";
        std::cout << "7. Wypozyczanie ksiazke (WERSJA ALPHA)\n";
        std::cout << "8. Wyjdź\n";
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
            case '4': {
                std::cout << "Podaj ID czytelnika do usunięcia: ";
                std::string id;
                std::getline(std::cin, id);
                rejestr.usunCzytelnika(id);
                rejestr.zapiszDoPliku("czytelnicy.txt");
                Czytelnik::zapiszMaxIDDoPliku("czytelnicy_max_id.txt");
                break;
            }
            case '5':
                rejestr.zapiszDoPliku("czytelnicy.txt");
                Czytelnik::zapiszMaxIDDoPliku("czytelnicy_max_id.txt");
                break;


case '6': {
    std::string szukana_fraza;
    std::cout << "Podaj frazę do wyszukania: ";
    std::getline(std::cin, szukana_fraza);

    int liczbaZnalezionych;
    Ksiazka** znalezioneKsiazki = katalog.wyszukajKsiazki(szukana_fraza, liczbaZnalezionych);

    if (liczbaZnalezionych > 0) {
        std::cout << "Znalezione książki:\n";
        for (int i = 0; i < liczbaZnalezionych; ++i) {
            std::cout << i + 1 << ". Tytuł: " << znalezioneKsiazki[i]->wez_tytul() << ", Autor: "
                      << znalezioneKsiazki[i]->wez_autor() << ", ISBN: " << znalezioneKsiazki[i]->wez_isbn()
                      << ", Rok publikacji: " << znalezioneKsiazki[i]->wez_rok_publikacji() << "\n";
        }
    } else {
        std::cout << "Brak pasujących książek.\n";
    }
}

            case '8':
                std::cout << "Do widzenia!\n";
                break;
            default:
                std::cout << "Niepoprawny wybór.\n";
        }
    } while (wybor != '8');
}
    return 0;
}
