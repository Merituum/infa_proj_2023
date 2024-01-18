#include <iostream>
#include <string>
#include "uzytkownik.h"
#include "Adres.h"
#include <fstream>

class BazaUzytkownikow:public Adres {
private:
    Uzytkownik* uzytkownicy;
    int rozmiar;
    int pojemnosc;
public:
    BazaUzytkownikow();
    ~BazaUzytkownikow();
    void dodajUzytkownika(const Uzytkownik& nowyUzytkownik);
    Uzytkownik* znajdzUzytkownika(const std::string& nazwaUzytkownika);
    void zarejestrujUzytkownika(const std::string& nazwaUzytkownika, const std::string& haslo, const std::string& rola,
                                const std::string& imie, const std::string& nazwisko, const Adres& adres);

    void zapiszUzytkownikowDoPliku(const std::string& plikNazwa) ;
    void wczytajUzytkownikowZPliku(const std::string& plikNazwa);


   

};
