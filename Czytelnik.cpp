#include "Czytelnik.h"
int Czytelnik::licznikID = 0;

Czytelnik::Czytelnik(const std::string& ID, const std::string& imie, const std::string& nazwisko, const Adres& adres)
        : ID(ID), imie(imie), nazwisko(nazwisko), adres(adres) {}

std::string Czytelnik::pobierzID() const {
    return ID;
}

std::string Czytelnik::pobierzImie() const {
    return imie;
}

std::string Czytelnik::pobierzNazwisko() const {
    return nazwisko;
}

Adres Czytelnik::pobierzAdres() const {
    return adres;
}

void Czytelnik::zapisz(std::ofstream& plikWyjsciowy) const {
    plikWyjsciowy << ID << " " << imie << " " << nazwisko << " "
                  << adres.ulica << " " << adres.numerDomu << " "
                  << adres.kodPocztowy << " " << adres.miasto << "\n";
}

int Czytelnik::pobierzLicznikID() {
    return licznikID;
}

void Czytelnik::ustawLicznikID(int licznik) {
    licznikID = licznik;
}

std::string Czytelnik::generujID() {
    return "ID" + std::to_string(++licznikID);
}

void Czytelnik::wczytajMaxIDZPliku(const std::string& nazwaPliku) {
    std::ifstream plikWejsciowy(nazwaPliku);
    if (plikWejsciowy.is_open()) {
        plikWejsciowy >> licznikID;
        plikWejsciowy.close();
    } else {
        std::cerr << "Błąd otwarcia pliku do odczytu.\n";
    }
}

void Czytelnik::zapiszMaxIDDoPliku(const std::string& nazwaPliku) {
    std::ofstream plikWyjsciowy(nazwaPliku);
    if (plikWyjsciowy.is_open()) {
        plikWyjsciowy << licznikID;
        plikWyjsciowy.close();
    } else {
        std::cerr << "Błąd otwarcia pliku do zapisu.\n";
    }
}