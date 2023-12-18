#include <iostream>
#include <fstream>
#include "katalog.h"
#include "ksiazka.h"
#include "Czytelnik.h"
#include "Adres.h"
#include "RejestrCzytelnikow.h"
#include "wypozyczanie.h"

int main() {
    setlocale(LC_CTYPE, "Polish");
    Katalog katalog;

    // Wczytywanie danych z pliku ksiazki.txt
    ifstream plik("ksiazki.txt");
    if (plik.is_open()) {
        string tytul, autor, isbn, rok;
        while (plik >> tytul >> autor >> isbn >> rok) {
            Ksiazka ksiazka(tytul, autor, isbn, rok);
            katalog.dodaj_ksiazke(ksiazka);
        }
        plik.close();
    } else {
        cout << "Nie można otworzyć pliku ksiazki.txt\n";
        return 1;
    }

    //część Huberta:
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
                string szukana_fraza;
                cout << "Podaj frazę do wyszukania: ";
                cin >> szukana_fraza;

                vector<Ksiazka> znalezione_ksiazki = katalog.szukaj_ksiazki(szukana_fraza);

                // Wyświetlanie znalezionej książki z informacją o wypożyczeniu
                for (const Ksiazka &ksiazka : znalezione_ksiazki) {
                    cout << ksiazka.wez_tytul() << " autorstwa " << ksiazka.wez_autor() << " (" << ksiazka.wez_isbn() << ") Rok: " << ksiazka.wez_rok_publikacji() << " - " << (ksiazka.czy_wypozyczona() ? "Wypożyczona" : "Dostępna") << endl;
                }
                break;
            }

            case '7': {
                Wypozyczanie wypozyczanie;
                cout << "Wypożyczanie książek:\n";
                cout << "Podaj ID ksiazki do wypozyczenia: ";
                string id;
                getline(cin, id);
                wypozyczanie.wypozyczKsiazke(katalog, id);
                break;
            }

            case '8':
                std::cout << "Do widzenia!\n";
                break;
            default:
                std::cout << "Niepoprawny wybór.\n";
        }
    } while (wybor != '8');
}
