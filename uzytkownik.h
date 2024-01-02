#include <iostream>
#include <string>
#include "Adres.h"

#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

class Uzytkownik :public Adres {
private:
    std::string nazwaUzytkownika;
    std::string haslo;
    std::string rola; // "czytelnik" lub "bibliotekarz"
    std::string imie;
    std::string nazwisko;
    std::string zahashowaneHaslo;
    Adres adres;

public:
    Uzytkownik();
    Uzytkownik(const std::string& nazwaUzytkownika, const std::string& haslo, const std::string& rola, 
               const std::string& imie, const std::string& nazwisko, const Adres& adres);
    bool sprawdzHaslo(const std::string& wprowadzoneHaslo);
    std::string getRola();
    std::string getNazwaUzytkownika() const;
    std::string getImie() const{return imie;};
    std::string getNazwisko() const{return nazwisko;};
    Adres getAdres() const{return adres;};
    std::string getHaslo() const;
    std::string getZahashowaneHaslo()const;
    std::string zahashujHaslo(const std::string& haslo);
    
};

#endif // UZYTKOWNIK_H
