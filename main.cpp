#include <iostream>
#include <fstream>
#include "katalog.h"
#include "ksiazka.h"
//#include "Czytelnik.h"
#include "Adres.h"
//#include "RejestrCzytelnikow.h"
#include "wypozyczanie.h"
#include "uzytkownik.h"
#include "bazadanychuzytkownika.h"
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Polish");
    Katalog katalog;
    katalog.wczytajKsiazkiZPliku("ksiazki.txt");

    //część Huberta:
    //RejestrCzytelnikow rejestr;

    // Wczytywanie danych z pliku (jeśli dostępny)
   // Czytelnik::wczytajMaxIDZPliku("czytelnicy_max_id.txt");
   // rejestr.wczytajZPliku("czytelnicy.txt");

BazaUzytkownikow bazaDanychUzytkownika;
 bazaDanychUzytkownika.wczytajUzytkownikowZPliku("uzytkownicy.txt");
string opcja;
cout << "Czy chcesz się zalogować (l) czy zarejestrować (r)? ";
cin >> opcja;

string nazwaUzytkownika;
string haslo;
string kodUwierzytelniajacy;
string rola;
if (opcja == "r") {
    string imie;
    string nazwisko;
    string ulica;
    string numerDomu;
    string kodPocztowy;
    string miasto;
    cout << "Podaj imię: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj ulicę: ";
    cin >> ulica;
    cout << "Podaj numer domu: ";
    cin >> numerDomu;
    do{
        cout << "Podaj kod pocztowy: ";
        cin >> kodPocztowy;
        if(!Adres::czyPoprawnyFormatKoduPocztowego(kodPocztowy)){
            cout << "Niepoprawny format kodu pocztowego. Spróbuj ponownie.\n";
        }
    } while(!Adres::czyPoprawnyFormatKoduPocztowego(kodPocztowy));
    // cout << "Podaj kod pocztowy: ";
    // cin >> kodPocztowy;
    cout << "Podaj miasto: ";
    cin >> miasto;
    Adres adres(ulica, numerDomu, kodPocztowy, miasto);
    cout << "Podaj nazwę użytkownika: ";
    cin >> nazwaUzytkownika;
    cout << "Podaj hasło: ";
    cin >> haslo;
    do{
    cout << "Podaj rolę (czytelnik/bibliotekarz): ";
    cin >> rola;
    } while (rola != "czytelnik" && rola != "bibliotekarz");
    if (rola == "bibliotekarz") {
    cout << "Podaj kod uwierzytelniający dla bibliotekarza: ";
    cin >> kodUwierzytelniajacy;
    if (kodUwierzytelniajacy != "1111") { 
        cout << "Niepoprawny kod uwierzytelniający. Nie możesz się zarejestrować jako bibliotekarz.\n";   
        rola="czytelnik"; 
        }
}   
    bazaDanychUzytkownika.zarejestrujUzytkownika(nazwaUzytkownika, haslo, rola, imie, nazwisko, adres);
   // bazaDanychUzytkownika.zapiszUzytkownikowDoPliku("uzytkownicy.txt");
} else if (opcja == "l") {
    // Zaloguj użytkownika
    cout << "Podaj nazwę użytkownika: ";
    cin >> nazwaUzytkownika;
    cout << "Podaj hasło: ";
    cin >> haslo;

Uzytkownik* uzytkownik = bazaDanychUzytkownika.znajdzUzytkownika(nazwaUzytkownika);
    if (uzytkownik != nullptr) {
    string zahashowaneWprowadzoneHaslo = uzytkownik->zahashujHaslo(haslo);
    if (uzytkownik->sprawdzHaslo(zahashowaneWprowadzoneHaslo)) {
        cout << "Logowanie pomyślne.\n";
        if (uzytkownik->getRola() == "czytelnik") {
            // Wyświetl menu dla czytelnika
            char wybor;
            do{
            cout << "1. Wyszukaj książkę\n";
            cout << "2. Wyjdz\n";
            cin>>wybor;
            switch(wybor){
                case '1':{
                    string szukana_fraza;
                    cout << "Podaj frazę do wyszukania: ";
                    cin >> szukana_fraza;

                    int liczbaZnalezionych;
                    Ksiazka** znalezioneKsiazki = katalog.wyszukajKsiazki(szukana_fraza, liczbaZnalezionych);

                    if (liczbaZnalezionych > 0) {
                        cout << "Znalezione książki:\n";
                        for (int i = 0; i < liczbaZnalezionych; ++i) {
                            cout << i + 1 << ". Tytuł: " << znalezioneKsiazki[i]->wez_tytul() << ", Autor: "
                                  << znalezioneKsiazki[i]->wez_autor() << ", ISBN: " << znalezioneKsiazki[i]->wez_isbn()
                                  << ", Rok publikacji: " << znalezioneKsiazki[i]->wez_rok_publikacji() << "\n";
                        }
                    } else {
                        cout << "Brak pasujących książek.\n";
                    }
                    break;
                }
                case '2':{
                    cout << "Do widzenia!\n";
                    break;
                }
                default:
                    cout << "Niepoprawny wybór.\n";
            }
                


            }while (wybor != '2');}
            
        } else if (uzytkownik->getRola() == "bibliotekarz") {
            // Wyświetl menu dla bibliotekarza
        }
    } else {
        cout << "Logowanie nieudane.\n";
    }
    } else {
    cout << "Nie znaleziono użytkownika.\n";
  
    }

 bazaDanychUzytkownika.zapiszUzytkownikowDoPliku("uzytkownicy.txt");

}  
   
   
   
    // Działania użytkownika
//     char wybor;
//     do {
//         // std::cout << "1. Zarejestruj czytelnika\n";
//         // std::cout << "2. Wyświetl szczegóły czytelnika\n";
//         // std::cout << "3. Wyświetl wszystkich czytelników\n";
//         // std::cout << "4. Usuń czytelnika.\n";
//         // std::cout << "5. Zapisz dane do pliku\n";
//         // std::cout << "6. Szukanie ksiazek\n";
//         // std::cout << "7. Wypozyczanie ksiazke (WERSJA ALPHA)\n";
//         // std::cout << "8. Wyjdź\n";
//         // std::cout << "Wybór: ";
//         // std::cin >> wybor;
//         // std::cin.ignore(); // Ignorowanie znaku nowej linii po wczytaniu liczby

//         // switch (wybor) {
//         //     case '1': {
//         //         std::cout << "Podaj dane czytelnika:\n";
//         //         std::cout << "Imię: ";
//         //         std::string imie;
//         //         std::getline(std::cin, imie);

//         //         std::cout << "Nazwisko: ";
//         //         std::string nazwisko;
//         //         std::getline(std::cin, nazwisko);

//         //         std::cout << "Adres:\n";
//         //         Adres adres;

//         //         std::cout << "Ulica: ";
//         //         std::getline(std::cin, adres.ulica);

//         //         std::cout << "Numer domu/mieszkania: ";
//         //         std::getline(std::cin, adres.numerDomu);

//         //         std::cout << "Miasto: ";
//         //         std::getline(std::cin, adres.miasto);

//         //         // Wprowadź kod pocztowy i sprawdź jego format
//         //         do {
//         //             std::cout << "Kod pocztowy (xx-xxx): ";
//         //             std::getline(std::cin, adres.kodPocztowy);
//         //         } while (!Adres::czyPoprawnyFormatKoduPocztowego(adres.kodPocztowy));

//         //         Czytelnik nowyCzytelnik(rejestr.generujID(), imie, nazwisko, adres);
//         //         rejestr.zarejestrujCzytelnika(nowyCzytelnik);
//         //         rejestr.zapiszDoPliku("czytelnicy.txt");
//         //         Czytelnik::zapiszMaxIDDoPliku("czytelnicy_max_id.txt");
//         //         break;
//         //     }
//         //     case '2': {
//         //         std::cout << "Podaj ID czytelnika: ";
//         //         std::string id;
//         //         std::getline(std::cin, id);
//         //         rejestr.wyswietlSzczegolyCzytelnika(id);
//         //         break;
//         //     }
//         //     case '3':
//         //         rejestr.wyswietlWszystkichCzytelnikow();
//         //         break;
//         //     case '4': {
//         //         std::cout << "Podaj ID czytelnika do usunięcia: ";
//         //         std::string id;
//         //         std::getline(std::cin, id);
//         //         rejestr.usunCzytelnika(id);
//         //         rejestr.zapiszDoPliku("czytelnicy.txt");
//         //         Czytelnik::zapiszMaxIDDoPliku("czytelnicy_max_id.txt");
//         //         break;
//         //     }
//         //     case '5':
//         //         rejestr.zapiszDoPliku("czytelnicy.txt");
//         //         Czytelnik::zapiszMaxIDDoPliku("czytelnicy_max_id.txt");
//         //         break;


// case '6': {
//     std::string szukana_fraza;
//     std::cout << "Podaj frazę do wyszukania: ";
//     std::getline(std::cin, szukana_fraza);

//     int liczbaZnalezionych;
//     Ksiazka** znalezioneKsiazki = katalog.wyszukajKsiazki(szukana_fraza, liczbaZnalezionych);

//     if (liczbaZnalezionych > 0) {
//         std::cout << "Znalezione książki:\n";
//         for (int i = 0; i < liczbaZnalezionych; ++i) {
//             std::cout << i + 1 << ". Tytuł: " << znalezioneKsiazki[i]->wez_tytul() << ", Autor: "
//                       << znalezioneKsiazki[i]->wez_autor() << ", ISBN: " << znalezioneKsiazki[i]->wez_isbn()
//                       << ", Rok publikacji: " << znalezioneKsiazki[i]->wez_rok_publikacji() << "\n";
//         }
//     } else {
//         std::cout << "Brak pasujących książek.\n";
//     }
// }

//             case '8':
//                 cout << "Do widzenia!\n";
//                 break;
//             default:
//                 cout << "Niepoprawny wybór.\n";
//         }
//     } while (wybor != '8');
// }

  
