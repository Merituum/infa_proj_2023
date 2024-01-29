#pragma once
#include "ksiazka.h"
#include <fstream>
using namespace std;
//Kod Wojtka
class Katalog {
public:
    int getLiczbaKsiazek() const;
    void wczytajKsiazkiZPliku(const string &nazwaPliku);
    Ksiazka** wyszukajKsiazki(const string& fraza, int& liczbaZnalezionych) const;
    Ksiazka* znajdzKsiazkePoISBN(string ISBN);//Kod Bartka
private:
       Ksiazka **ksiazki;
        int liczbaKsiazek;

};
