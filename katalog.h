#pragma once
#include "ksiazka.h"
#include <fstream>
using namespace std;
class Katalog {
public:
    int getLiczbaKsiazek() const;
    void wczytajKsiazkiZPliku(const std::string &nazwaPliku);
    Ksiazka** wyszukajKsiazki(const std::string& fraza, int& liczbaZnalezionych) const;
private:
       Ksiazka **ksiazki;
        int liczbaKsiazek;

};
