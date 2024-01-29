#include "bazadanychuzytkownika.h"
#include <iostream>
#include <string>
#include "uzytkownik.h"
#include <fstream>
#include "Adres.h"
#include "uzytkownik.h"
using namespace std;
//kod Huberta
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
void BazaUzytkownikow::usunUzytkownika(const string& nazwaUzytkownika) {
    int indeksDoUsuniecia = -1;
    for (int i = 0; i < rozmiar; ++i) {
        if (uzytkownicy[i].getNazwaUzytkownika() == nazwaUzytkownika) {
            indeksDoUsuniecia = i;
            break;
        }
    }
    if (indeksDoUsuniecia != -1) {
        for (int i = indeksDoUsuniecia; i < rozmiar - 1; ++i) {
            uzytkownicy[i] = uzytkownicy[i + 1];
        }
        rozmiar--;
        cout << "Uzytkownik usuniety" << endl;
        zapiszUzytkownikowDoPliku("uzytkownicy.txt");
    } else {
        cout << "Uzytkownik nie istnieje" << endl;
    }
}

Uzytkownik* BazaUzytkownikow::znajdzUzytkownika(const string& nazwaUzytkownika) {
    for (int i = 0; i < rozmiar; i++) {
        if (uzytkownicy[i].getNazwaUzytkownika() == nazwaUzytkownika) {
            return &uzytkownicy[i];

        }
    }
    return nullptr;
}
void BazaUzytkownikow::wyswietlWszystkichUzytkownikow() {
    for (int i = 0; i < rozmiar; ++i) {
        cout << "Uzytkownik " << i+1 << ":\n";
        cout << "Nazwa uzytkownika: " << uzytkownicy[i].getNazwaUzytkownika() << "\n";
        cout << "Rola: " << uzytkownicy[i].getRola() << "\n";
        cout << "Imie: " << uzytkownicy[i].getImie() << "\n";
        cout << "Nazwisko: " << uzytkownicy[i].getNazwisko() << "\n";
        cout << "------------------------\n";
    }
}
void BazaUzytkownikow::wyswietlSzczegolyUzytkownika(const string& nazwaUzytkownika) {
    for (int i = 0; i < rozmiar; ++i) {
        if (uzytkownicy[i].getNazwaUzytkownika() == nazwaUzytkownika) {
            cout << "Nazwa uzytkownika: " << uzytkownicy[i].getNazwaUzytkownika() << "\n";
            cout << "Rola: " << uzytkownicy[i].getRola() << "\n";
            cout << "Imie: " << uzytkownicy[i].getImie() << "\n";
            cout << "Nazwisko: " << uzytkownicy[i].getNazwisko() << "\n";
            cout << "Adres: " << uzytkownicy[i].getAdres().ulica << "\n";
            cout << "Adres: " << uzytkownicy[i].getAdres().miasto << "\n";
            cout << "Adres: " << uzytkownicy[i].getAdres().kodPocztowy<< "\n";
            cout << "Adres: " << uzytkownicy[i].getAdres().numerDomu << "\n";
            return;
        }
    }
    cout << "Nie znaleziono użytkownika o nazwie " << nazwaUzytkownika << ".\n";
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
    plik.close();
     
}



//Wypozacznie Bartek
void BazaUzytkownikow::zapiszWypozyczoneKsiazki()
{
    ofstream plik("wypozyczone.txt");


    for(int i=0; i<rozmiar; i++)
    {
        plik << uzytkownicy[i].getNazwaUzytkownika()<< ":";
        for(int j=0; j<5; j++)
            if(uzytkownicy[i].wypozyczone_ksiazki[j] != "")
                plik << " " << uzytkownicy[i].wypozyczone_ksiazki[j];
        plik << endl;
    }

    plik.close();
}

//Dalsza czesc Huberta

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


