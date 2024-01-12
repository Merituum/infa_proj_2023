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
    std::string zaszyfrowaneHaslo;
    std::string kodUwierzytelniajacy;
    Adres adres;

public:
    Uzytkownik(const Uzytkownik& other)
    : nazwaUzytkownika(other.nazwaUzytkownika),
      zahashowaneHaslo(other.zahashowaneHaslo), // kopiujemy już zahashowane hasło
      rola(other.rola),
      imie(other.imie),
      nazwisko(other.nazwisko),
      adres(other.adres)
{}
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
    void setHaslo(const std::string& haslo);
    std::string getsetHaslo(const std::string& haslo)  const;
    static std::string zahashujHaslo(const std::string& haslo);
    
};

#endif // UZYTKOWNIK_H
