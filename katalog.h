#pragma once
#include "ksiazka.h"
#include <vector>
using namespace std;
class Katalog {
private:
    vector<Ksiazka> ksiazki;

public:
    void dodaj_ksiazke(const Ksiazka &ksiazka);
    vector<Ksiazka> szukaj_ksiazki(const string &szukana_fraza) const;
};
