#include <iostream>
#include <string>
#include "Adres.h"
using namespace std;
#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
//kod Huberta
class Uzytkownik  {
public:
    string wypozyczone_ksiazki[5];
    Uzytkownik(const Uzytkownik& other)
    : nazwaUzytkownika(other.nazwaUzytkownika),
      zahashowaneHaslo(other.zahashowaneHaslo), // kopiujemy już zahashowane hasło
      rola(other.rola),
      imie(other.imie),
      nazwisko(other.nazwisko),
      adres(other.adres){}
    Uzytkownik();
    Uzytkownik(const string& nazwaUzytkownika, const string& haslo, const string& rola, 
               const string& imie, const string& nazwisko, const Adres& adres);
    bool sprawdzHaslo(const string& wprowadzoneHaslo);
    string getRola();
    string getNazwaUzytkownika() const;
    string getImie() const{return imie;};
    string getNazwisko() const{return nazwisko;};
    Adres getAdres() const{return adres;};
    string getHaslo() const;
    string getZahashowaneHaslo()const;
    void setHaslo(const string& haslo);
    static string zahashujHaslo(const string& haslo);
private:
    string nazwaUzytkownika;
    string haslo;
    string rola; // "czytelnik" lub "bibliotekarz"
    string imie;
    string nazwisko;
    string zahashowaneHaslo;
    string zaszyfrowaneHaslo;
    string kodUwierzytelniajacy;
    Adres adres;

    
};


#endif // UZYTKOWNIK_H
