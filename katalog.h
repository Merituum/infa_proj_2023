#pragma once
#include "ksiazka.h"

using namespace std;
class Katalog {
public:
    int getLiczbaKsiazek() const;
    void dodaj_ksiazke(const Ksiazka &ksiazka);
    Ksiazka* const* szukaj_ksiazki(const string &szukana_fraza) const;
private:
       Ksiazka **ksiazki;
        int liczbaKsiazek;

};
