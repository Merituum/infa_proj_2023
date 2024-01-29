#include "ksiazka.h"
using namespace std;
//Kod Wojtka
Ksiazka::Ksiazka(string tytul, string autor, string isbn, string rok_publikacji, int ilosc)
        : tytul(tytul), autor(autor), isbn(isbn), rok_publikacji(rok_publikacji), ilosc_w_bibliotece(ilosc) {}

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

void Ksiazka::wypozycz() {
    this->ilosc_w_bibliotece--;
}

void Ksiazka::zwroc() {
    this->ilosc_w_bibliotece++;
}

int Ksiazka::wez_ilosc_w_bibliotece() const {
    return ilosc_w_bibliotece;
}

