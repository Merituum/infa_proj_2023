
// Wypozyczanie.cpp
#include "Wypozyczanie.h"

Wypozyczanie::Wypozyczanie(std::vector<Ksiazka>& ksiazki) : ksiazki(ksiazki) {}

void Wypozyczanie::wypozyczKsiazke(const std::string& tytul) {
    for (Ksiazka& ksiazka : ksiazki) {
        if (ksiazka.wez_tytul() == tytul) {
            if (!ksiazka.czy_wypozyczona()) {
                ksiazka.wypozycz();
                std::cout << "Książka \"" << tytul << "\" została wypożyczona.\n";
            } else {
                std::cout << "Książka \"" << tytul << "\" jest już wypożyczona.\n";
            }
            return;
        }
    }
    std::cout << "Nie znaleziono książki o tytule \"" << tytul << "\".\n";
}







//Wypozyczenie::Wypozyczenie(const std::string& idCzytelnika, const std::string& idKsiazki)
//        : idCzytelnika(idCzytelnika), idKsiazki(idKsiazki), dataWypozyczenia(0), planowanyZwrot(0) {}
//
//void Wypozyczenie::ustawDaty(time_t dataWypozyczenia, time_t planowanyZwrot) {
//    this->dataWypozyczenia = dataWypozyczenia;
//    this->planowanyZwrot = planowanyZwrot;
//}
//
//std::string Wypozyczenie::pobierzIdCzytelnika() const {
//    return idCzytelnika;
//}
//
//std::string Wypozyczenie::pobierzIdKsiazki() const {
//    return idKsiazki;
//}
//
//time_t Wypozyczenie::pobierzDateWypozyczenia() const {
//    return dataWypozyczenia;
//}
//
//time_t Wypozyczenie::pobierzPlanowanyZwrot() const {
//    return planowanyZwrot;
//}
//
//bool Wypozyczenie::czyWypozyczenieAktualne() const {
//    time_t teraz = std::time(nullptr);
//    return teraz >= dataWypozyczenia && teraz <= planowanyZwrot;
//}
