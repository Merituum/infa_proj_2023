// Wypozyczenie.h
#pragma once
#include <string>
#include <ctime>

class Wypozyczenie {
    // Wypozyczanie.h
#pragma once
#include <iostream>
#include <vector>
#include "ksiazka.h"

    class Wypozyczanie {
    private:
        std::vector<Ksiazka>& ksiazki;

    public:
        Wypozyczanie(std::vector<Ksiazka>& ksiazki);
        void wypozyczKsiazke(const std::string& tytul);
    };

//public:
//    Wypozyczenie(const std::string& idCzytelnika, const std::string& idKsiazki);
//
//    void ustawDaty(time_t dataWypozyczenia, time_t planowanyZwrot);
//    std::string pobierzIdCzytelnika() const;
//    std::string pobierzIdKsiazki() const;
//    time_t pobierzDateWypozyczenia() const;
//    time_t pobierzPlanowanyZwrot() const;
//    bool czyWypozyczenieAktualne() const;
//
//private:
//    std::string idCzytelnika;
//    std::string idKsiazki;
//    time_t dataWypozyczenia;
//    time_t planowanyZwrot;
};
