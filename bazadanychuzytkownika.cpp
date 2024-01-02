#include "bazadanychuzytkownika.h"
#include <iostream>
#include <string>
#include "uzytkownik.h"
#include <fstream>
#include "Adres.h"
#include "uzytkownik.h"

BazaUzytkownikow::BazaUzytkownikow() : rozmiar(0), pojemnosc(10) {
    uzytkownicy = new Uzytkownik[pojemnosc];
}

BazaUzytkownikow::~BazaUzytkownikow() {
    delete[] uzytkownicy;
}

void BazaUzytkownikow::dodajUzytkownika(const Uzytkownik& uzytkownik) {
    if (rozmiar == pojemnosc) {
        pojemnosc *= 2;
        Uzytkownik* nowiUzytkownicy = new Uzytkownik[pojemnosc];
        for (int i = 0; i < rozmiar; i++) {
            nowiUzytkownicy[i] = uzytkownicy[i];
        }
        delete[] uzytkownicy;
        uzytkownicy = nowiUzytkownicy;
    }
    uzytkownicy[rozmiar] = uzytkownik;
    rozmiar++;
}

Uzytkownik* BazaUzytkownikow::znajdzUzytkownika(const std::string& nazwaUzytkownika) {
    for (int i = 0; i < rozmiar; i++) {
        if (uzytkownicy[i].getNazwaUzytkownika() == nazwaUzytkownika) {
            return &uzytkownicy[i];

        }
    }
    return nullptr;
}

void BazaUzytkownikow::zarejestrujUzytkownika(const std::string& nazwaUzytkownika, const std::string& haslo, const std::string& rola, 
                                                   const std::string& imie, const std::string& nazwisko, const Adres& adres) {
    Uzytkownik nowyUzytkownik(nazwaUzytkownika, haslo, rola, imie, nazwisko, adres);
    Uzytkownik zhashujHaslo(std::string&haslo);
    dodajUzytkownika(nowyUzytkownik);
    std::cout<<"Uzytkownik zarejestrowany"<<std::endl;
                                                   }
void BazaUzytkownikow::zapiszUzytkownikowDoPliku(const std::string& plikNazwa) {
    std::ofstream plik(plikNazwa.c_str());
    if (!plik.is_open()) {
        std::cerr << "Nie można otworzyć pliku do zapisu." << std::endl;
        return;
    }
    for (int i = 0; i < rozmiar; ++i) {
        // Zapisywanie danych użytkownika
        plik << uzytkownicy[i].getNazwaUzytkownika() << " "
             << uzytkownicy[i].getZahashowaneHaslo() << " " // zapisywanie zahashowanego hasla
             << uzytkownicy[i].getRola() << " "
             << uzytkownicy[i].getImie() << " "
             << uzytkownicy[i].getNazwisko() << " "
             // Zapisywanie adresu
             << uzytkownicy[i].getAdres().ulica << " "
             << uzytkownicy[i].getAdres().miasto << " "
             << uzytkownicy[i].getAdres().kodPocztowy << " "
             << uzytkownicy[i].getAdres().numerDomu << std::endl;
             std::cout<<"Uzytkownik zapisany"<<std::endl;
             plik.close();
    }
    //plik.close();
 
    
}
void BazaUzytkownikow::wczytajUzytkownikowZPliku(const std::string& plikNazwa) {
    std::ifstream plik(plikNazwa);
    if (plik.is_open()) {
        // Najpierw sprawdź, czy tablica już istnieje, i ją wyczyść
        if (uzytkownicy != nullptr) {
            delete[] uzytkownicy;
            uzytkownicy = nullptr;
            rozmiar = 0;
        }

        // Ustal rozmiar początkowy tablicy
        int poczatkowyRozmiar = 10;
        uzytkownicy = new Uzytkownik[poczatkowyRozmiar];
        int liczbaUzytkownikow = 0;

        while (!plik.eof()) {
            std::string nazwaUzytkownika, haslo, rola, imie, nazwisko;
            std::string ulica, miasto, kodPocztowy, numerDomu;
            plik >> nazwaUzytkownika >> haslo >> rola >> imie >> nazwisko
                 >> ulica >> miasto >> kodPocztowy >> numerDomu;

            if (!plik.fail() && !nazwaUzytkownika.empty()) {
                Adres adres(ulica, miasto, kodPocztowy, numerDomu);
                if (liczbaUzytkownikow == poczatkowyRozmiar) {
                    // Zwiększ rozmiar tablicy, gdy jest pełna
                    poczatkowyRozmiar *= 2;
                    Uzytkownik* nowaTablica = new Uzytkownik[poczatkowyRozmiar];
                    for (int i = 0; i < liczbaUzytkownikow; i++) {
                        nowaTablica[i] = uzytkownicy[i];
                    }
                    delete[] uzytkownicy;
                    uzytkownicy = nowaTablica;
                }
                uzytkownicy[liczbaUzytkownikow++] = Uzytkownik(nazwaUzytkownika, haslo, rola, imie, nazwisko, adres);
            }
        }

        rozmiar = liczbaUzytkownikow;
        plik.close();
        std::cout << "Dane uzytkownikow wczytane" << std::endl;
    } else {
        std::cout << "Nie mozna otworzyc pliku" << std::endl;
    }
}


// void BazaUzytkownikow::wczytajUzytkownikowZPliku(const std::string& plikNazwa) {
//     std::ifstream plik(plikNazwa);
//     if(plik.is_open()){
//         delete[] uzytkownicy;
//         uzytkownicy = new Uzytkownik[rozmiar];
//         while(!plik.eof()){
//             std::string nazwaUzytkownika, haslo, rola, imie, nazwisko;
//             std::string ulica, miasto, kodPocztowy, numerDomu;
//             plik >> nazwaUzytkownika >> haslo >> rola >> imie >> nazwisko
//                 >> ulica >> miasto >> kodPocztowy >> numerDomu;
//             if(!nazwaUzytkownika.empty() && !haslo.empty() && !rola.empty() && !imie.empty() && !nazwisko.empty() && !ulica.empty() && !miasto.empty() && !kodPocztowy.empty() && !numerDomu.empty()){
//                 Adres adres(ulica, miasto, kodPocztowy, numerDomu);
//                 Uzytkownik* nowaTablica=new Uzytkownik[rozmiar+1];
//                 std::copy(uzytkownicy, uzytkownicy+rozmiar, nowaTablica);
//                 nowaTablica[rozmiar]=Uzytkownik(nazwaUzytkownika, haslo, rola, imie, nazwisko, adres);
//                 delete[] uzytkownicy;  //usuniecie starej tablicy
//                 uzytkownicy=nowaTablica; //przypisanie nowej tablicy
//                 rozmiar++;
//                 std::cout<<"Dane uzytkownikow wczytane"<<std::endl;
//             }
            
//     }
//     plik.close();
//     }else{
//         std::cout<<"Nie mozna otworzyc pliku"<<std::endl;
//     }

// }