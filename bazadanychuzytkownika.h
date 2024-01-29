#include <iostream>
#include <string>
#include "uzytkownik.h"
#include "Adres.h"
#include <fstream>
using namespace std;
//Kod Huberta
class BazaUzytkownikow{
public:
    BazaUzytkownikow();
    ~BazaUzytkownikow();
    void dodajUzytkownika(const Uzytkownik& nowyUzytkownik);
    void usunUzytkownika(const string& nazwaUzytkownika);
    Uzytkownik* znajdzUzytkownika(const string& nazwaUzytkownika);
    void zarejestrujUzytkownika(const string& nazwaUzytkownika, const string& haslo, const string& rola,
                                const string& imie, const string& nazwisko, const Adres& adres);

    void zapiszUzytkownikowDoPliku(const string& plikNazwa) ;
    void wczytajUzytkownikowZPliku(const string& plikNazwa);
    void wyswietlWszystkichUzytkownikow();
    void wyswietlSzczegolyUzytkownika(const string& nazwaUzytkownika);
    void zapiszWypozyczoneKsiazki();// Kod Bartka
private:
    Uzytkownik* uzytkownicy;
    int rozmiar;
    int pojemnosc;


};
