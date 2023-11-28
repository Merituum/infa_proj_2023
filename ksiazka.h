#pragma once
#include <iostream>
#include <string>
using namespace std;
class Ksiazka {
    private:
        string tytul;
        string autor;
        string isbn;
        string rok_publikacji;

    public:
        Ksiazka(string tytul, string autor, string isbn, string rok_publikacji);

        string wez_tytul() const;
        string wez_autor() const;
        string wez_isbn() const;
        string wez_rok_publikacji() const;
};
