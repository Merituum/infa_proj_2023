#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Adres.h"

class Czytelnik {
    private:
    std::string ID;
    std::string imie;
    std::string nazwisko;
    Adres adres;

    public:
    Czytelnik(){
    
    };
    static int licznikID;

    Czytelnik(const std::string& ID, const std::string& imie, const std::string& nazwisko, const Adres& adres);

    std::string pobierzID() const;
    std::string pobierzImie() const;
    std::string pobierzNazwisko() const;
    Adres pobierzAdres() const;

    void zapisz(std::ofstream& plikWyjsciowy) const;

    static int pobierzLicznikID();
    static void ustawLicznikID(int licznik);
    std::string generujID();

    static void wczytajMaxIDZPliku(const std::string& nazwaPliku);
    static void zapiszMaxIDDoPliku(const std::string& nazwaPliku);
};


