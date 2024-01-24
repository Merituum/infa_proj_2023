#include <iostream>
#include <fstream>
#include "uzytkownik.h"

Uzytkownik::Uzytkownik() {
 
    nazwaUzytkownika = "";
    haslo = "";
    rola = "";
    imie = "";
    nazwisko = "";
    adres = Adres(); // Wywolanie konstruktora domyslnego klasy Adres
}

Uzytkownik::Uzytkownik(const std::string& nazwaUzytkownika, const std::string& haslo, const std::string& rola, 
           const std::string& imie, const std::string& nazwisko, const Adres& adres)
    : nazwaUzytkownika(nazwaUzytkownika), zahashowaneHaslo(haslo), rola(rola), 
      imie(imie), nazwisko(nazwisko), adres(adres) {
       // std::cout << "Zahashowane hasło1: " << zahashowaneHaslo << std::endl;
      }

bool Uzytkownik::sprawdzHaslo(const std::string& wprowadzoneHaslo) {
    return zahashowaneHaslo == wprowadzoneHaslo;//zahashujHaslo(wprowadzoneHaslo);
}

std::string Uzytkownik::getRola() {
    return rola;
}
void Uzytkownik::setHaslo(const std::string& haslo) {
    this->zahashowaneHaslo = haslo;
}

std::string Uzytkownik::zahashujHaslo(const std::string& haslo) {
    std::string zahashowaneHaslo;
    int przesuniecie = 3; // Przesunięcie dla szyfru Cezara
    for (char c : haslo) {
        if (c >= 'a' && c <= 'z') {
            zahashowaneHaslo += 'a' + (c - 'a' + przesuniecie) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            zahashowaneHaslo += 'A' + (c - 'A' + przesuniecie) % 26;
        } else if (c >= '0' && c <= '9') {
            zahashowaneHaslo += '0' + (c - '0' + przesuniecie) % 10;  
        } else {
            zahashowaneHaslo += c; 
        }
    }
   //std::cout << "Zahashowane hasło: " << zahashowaneHaslo << std::endl;
    return zahashowaneHaslo;
}
std::string Uzytkownik::getNazwaUzytkownika() const {
    return nazwaUzytkownika;
}

std::string Uzytkownik::getZahashowaneHaslo() const {
   return zahashowaneHaslo;
}   
std::string Uzytkownik::getHaslo() const {
    return haslo;
}