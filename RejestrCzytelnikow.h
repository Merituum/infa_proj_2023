#pragma once
//#include <vector>
#include <iostream>
#include "Czytelnik.h"

class RejestrCzytelnikow {
private:
    Czytelnik* czytelnicy; // Dynamiczna tablica obiektów Czytelnik
    int pojemnosc;         // Pojemność tablicy
    int rozmiar;           // Aktualna liczba elementów w tablicy

    // Prywatna metoda do zmiany rozmiaru tablicy w razie potrzeby
    void zmienRozmiar(int nowaPojemnosc);

    // Prywatna metoda do sprawdzenia, czy czytelnik ma takie same ID
    //bool czyCzytelnikMaTakieSameID(const std::string& ID) const;
     bool czytelnikMaTakieSameID(const Czytelnik& czytelnik, const std::string& ID);
public:
    RejestrCzytelnikow();   // Konstruktor
    ~RejestrCzytelnikow();  // Destruktor
    //bool czyCzytelnikMaTakieSameID(const std::string& ID) const;
    bool czyCzytelnikZarejestrowany(const std::string& ID) const;
    void zarejestrujCzytelnika(const Czytelnik& czytelnik);
    void wyswietlSzczegolyCzytelnika(const std::string& ID) const;
    void wyswietlWszystkichCzytelnikow() const;
    void zapiszDoPliku(const std::string& nazwaPliku) const;
    void wczytajZPliku(const std::string& nazwaPliku);
    void usunCzytelnika(const std::string& ID);
    std::string generujID();
};
    



