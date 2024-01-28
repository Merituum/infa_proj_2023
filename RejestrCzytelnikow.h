#pragma once
//#include <vector>
#include <iostream>
#include "Czytelnik.h"
using namespace std;

class RejestrCzytelnikow {
private:
    Czytelnik* czytelnicy; // Dynamiczna tablica obiektów Czytelnik
    int pojemnosc;         // Pojemność tablicy
    int rozmiar;           // Aktualna liczba elementów w tablicy

    // Prywatna metoda do zmiany rozmiaru tablicy w razie potrzeby
    void zmienRozmiar(int nowaPojemnosc);

    // Prywatna metoda do sprawdzenia, czy czytelnik ma takie same ID
    //bool czyCzytelnikMaTakieSameID(const string& ID) const;
     bool czytelnikMaTakieSameID(const Czytelnik& czytelnik, const string& ID);
public:
    RejestrCzytelnikow();   // Konstruktor
    ~RejestrCzytelnikow();  // Destruktor
    //bool czyCzytelnikMaTakieSameID(const string& ID) const;
    bool czyCzytelnikZarejestrowany(const string& ID) const;
    void zarejestrujCzytelnika(const Czytelnik& czytelnik);
    void wyswietlSzczegolyCzytelnika(const string& ID) const;
    void wyswietlWszystkichCzytelnikow() const;
    void zapiszDoPliku(const string& nazwaPliku) const;
    void wczytajZPliku(const string& nazwaPliku);
    void usunCzytelnika(const string& ID);
    string generujID();
};
    



