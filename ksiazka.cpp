#include "ksiazka.h"
using namespace std;
Ksiazka::Ksiazka(string tytul, string autor, string isbn, string rok_publikacji)
    : tytul(tytul), autor(autor), isbn(isbn), rok_publikacji(rok_publikacji) {}

string Ksiazka::wez_tytul() const {
    return tytul;
}

string Ksiazka::wez_autor() const {
    return autor;
}

string Ksiazka::wez_isbn() const {
    return isbn;
}

string Ksiazka::wez_rok_publikacji() const {
    return rok_publikacji;
}
