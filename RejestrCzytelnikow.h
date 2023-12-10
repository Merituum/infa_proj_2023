#pragma once
#include <vector>
#include <iostream>
#include "Czytelnik.h"



class RejestrCzytelnikow {
private:
    std::vector<Czytelnik> czytelnicy;
    static bool czytelnikMaTakieSameID(const Czytelnik& czytelnik, const std::string& ID);
public:
    bool czyCzytelnikZarejestrowany(const std::string& ID) const;
    void zarejestrujCzytelnika(const Czytelnik& czytelnik);
    void wyswietlSzczegolyCzytelnika(const std::string& ID) const;
    void wyswietlWszystkichCzytelnikow() const;
    void zapiszDoPliku(const std::string& nazwaPliku) const;
    void wczytajZPliku(const std::string& nazwaPliku);
    void usunCzytelnika(const std::string& ID);
    std::string generujID();
};



