#include <iostream>
#include <fstream>
#include "uzytkownik.h"

Uzytkownik::Uzytkownik() {
 
    nazwaUzytkownika = "";
    haslo = "";
    rola = "";
    imie = "";
    nazwisko = "";
    adres = Adres(); // Wywołanie konstruktora domyślnego klasy Adres
}
// Uzytkownik.cpp
Uzytkownik::Uzytkownik(const std::string& nazwaUzytkownika, const std::string& haslo, const std::string& rola, 
           const std::string& imie, const std::string& nazwisko, const Adres& adres)
    : nazwaUzytkownika(nazwaUzytkownika), zahashowaneHaslo(zahashujHaslo(haslo)), rola(rola), 
      imie(imie), nazwisko(nazwisko), adres(adres) {}

bool Uzytkownik::sprawdzHaslo(const std::string& wprowadzoneHaslo) {
    return zahashowaneHaslo == zahashujHaslo(wprowadzoneHaslo);
}

std::string Uzytkownik::getRola() {
    return rola;
}
std::string Uzytkownik::zahashujHaslo(const std::string& haslo) {
    std::string zahashowaneHaslo;
    int przesuniecie = 3; // Przesunięcie dla szyfru Cezara
    for (char c : haslo) {
        if (c >= 'a' && c <= 'z') {
            zahashowaneHaslo += 'a' + (c - 'a' + przesuniecie) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            zahashowaneHaslo += 'A' + (c - 'A' + przesuniecie) % 26;
        } else {
            zahashowaneHaslo += c; // Nie przesuwaj znaków niebędących literami
        }
    }
    std::cout << "Zahashowane hasło: " << zahashowaneHaslo << std::endl;
    return zahashowaneHaslo;
}
std::string Uzytkownik::getNazwaUzytkownika() const {
    return nazwaUzytkownika;
}

std::string Uzytkownik::getZahashowaneHaslo() const {
   return zahashowaneHaslo;
}   
std::string Uzytkownik::getHaslo() const {
    return zahashowaneHaslo;
}