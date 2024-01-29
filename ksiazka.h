#pragma once
#include <iostream>
#include <string>
#include "uzytkownik.h"
using namespace std;
//Kod Wojtka
class Ksiazka {
public:
    Ksiazka(string tytul, string autor, string isbn, string rok_publikacji, int ilosc);
    int wez_ilosc_w_bibliotece() const;
    string wez_tytul() const;
    string wez_autor() const;
    string wez_isbn() const;
    string wez_rok_publikacji() const;
    bool czy_wypozyczona() const;
    //ponizej Kod Bartka
    void wypozycz();
    void zwroc();
    void zwrocInt();
private:
    string tytul;
    string autor;
    string isbn;
    string rok_publikacji;
    int ilosc_w_bibliotece;
   

};
