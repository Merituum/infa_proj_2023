#include <iostream>
#include <string>
#include "uzytkownik.h"
#include "Adres.h"
#include <fstream>
using namespace std;
class BazaUzytkownikow{
private:
    Uzytkownik* uzytkownicy;
    int rozmiar;
    int pojemnosc;
public:
    BazaUzytkownikow();
    ~BazaUzytkownikow();
    void dodajUzytkownika(const Uzytkownik& nowyUzytkownik);
    Uzytkownik* znajdzUzytkownika(const string& nazwaUzytkownika);
    void zarejestrujUzytkownika(const string& nazwaUzytkownika, const string& haslo, const string& rola,
                                const string& imie, const string& nazwisko, const Adres& adres);

    void zapiszUzytkownikowDoPliku(const string& plikNazwa) ;
    void wczytajUzytkownikowZPliku(const string& plikNazwa);


   

};
