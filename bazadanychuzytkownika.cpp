#include "bazadanychuzytkownika.h"
#include <iostream>
#include <string>
#include "uzytkownik.h"
#include <fstream>
#include "Adres.h"
#include "uzytkownik.h"
using namespace std;

BazaUzytkownikow::BazaUzytkownikow() : rozmiar(0), pojemnosc(10) {
    uzytkownicy = new Uzytkownik[pojemnosc];
}

BazaUzytkownikow::~BazaUzytkownikow() {
    delete[] uzytkownicy;
}

void BazaUzytkownikow::dodajUzytkownika(const Uzytkownik& nowyUzytkownik) {
    if (rozmiar == pojemnosc) {
        pojemnosc *= 2;
        Uzytkownik* nowaTablica = new Uzytkownik[pojemnosc];
        for (int i = 0; i < rozmiar; i++) {
            nowaTablica[i] = uzytkownicy[i];
        }
        delete[] uzytkownicy;
        uzytkownicy = nowaTablica;
    }
    uzytkownicy[rozmiar] = nowyUzytkownik;
    rozmiar++;
}

Uzytkownik* BazaUzytkownikow::znajdzUzytkownika(const string& nazwaUzytkownika) {
    for (int i = 0; i < rozmiar; i++) {
        if (uzytkownicy[i].getNazwaUzytkownika() == nazwaUzytkownika) {
            return &uzytkownicy[i];

        }
    }
    return nullptr;
}
void BazaUzytkownikow::zarejestrujUzytkownika(const string& nazwaUzytkownika, const string& haslo, const string& rola, 
                                                   const string& imie, const string& nazwisko, const Adres& adres) {
    string zahashowaneHaslo = Uzytkownik::zahashujHaslo(haslo);
    Uzytkownik nowyUzytkownik(nazwaUzytkownika, zahashowaneHaslo, rola, imie, nazwisko, adres);
    dodajUzytkownika(nowyUzytkownik);
    
    cout<<"Uzytkownik zarejestrowany"<<endl;
    zapiszUzytkownikowDoPliku("uzytkownicy.txt");
}


void BazaUzytkownikow::zapiszUzytkownikowDoPliku(const string& plikNazwa) {
    ofstream plik(plikNazwa.c_str());
    if (!plik.is_open()) {
        cerr << "Nie można otworzyć pliku do zapisu." << endl;
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
             << uzytkownicy[i].getAdres().numerDomu <<endl;
             
    }
    cout<<"Uzytkownik zapisany"<<endl;
    plik.close();
 
    
}


void BazaUzytkownikow::wczytajUzytkownikowZPliku(const string& plikNazwa) {
    ifstream plik(plikNazwa);
    if (plik.is_open()) {
         if (uzytkownicy != nullptr) {
            delete[] uzytkownicy;
            uzytkownicy = nullptr;
            rozmiar = 0;
        }

        // rozmiar początkowy tablicy
        int poczatkowyRozmiar = 10;
        uzytkownicy = new Uzytkownik[poczatkowyRozmiar];
        int liczbaUzytkownikow = 0;

        while (!plik.eof()) {
            string nazwaUzytkownika, ZahashowaneHaslo, rola, imie, nazwisko;
            string ulica, miasto, kodPocztowy, numerDomu;
            plik >> nazwaUzytkownika >> ZahashowaneHaslo >> rola >> imie >> nazwisko
                 >> ulica >> miasto >> kodPocztowy >> numerDomu;

            if (!plik.fail() && !nazwaUzytkownika.empty()) {
                Adres adres(ulica, miasto, kodPocztowy, numerDomu);
                if (liczbaUzytkownikow == poczatkowyRozmiar) {
                    // zwiekszenie rozmiaru tablicy gdy jest pelna
                    poczatkowyRozmiar *= 2;
                    Uzytkownik* nowaTablica = new Uzytkownik[poczatkowyRozmiar];
                    for (int i = 0; i < liczbaUzytkownikow; i++) {
                        nowaTablica[i] = uzytkownicy[i];
                    }
                    delete[] uzytkownicy;
                    uzytkownicy = nowaTablica;
                }
                uzytkownicy[liczbaUzytkownikow++] = Uzytkownik(nazwaUzytkownika, ZahashowaneHaslo, rola, imie, nazwisko, adres);
            }
        }

        rozmiar = liczbaUzytkownikow;
        plik.close();
       cout << "Dane uzytkownikow wczytane" << endl;
    } else {
        cout << "Nie mozna otworzyc pliku" << endl;
    }
}


