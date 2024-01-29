#include <iostream>
#include <fstream>
#include "uzytkownik.h"
#include "ksiazka.h"
using namespace std;
//Kod Huberta
Uzytkownik::Uzytkownik() {
 
    nazwaUzytkownika = "";
    haslo = "";
    rola = "";
    imie = "";
    nazwisko = "";
    adres = Adres(); 
}

Uzytkownik::Uzytkownik(const string& nazwaUzytkownika, const string& haslo, const string& rola, 
           const string& imie, const string& nazwisko, const Adres& adres)
    : nazwaUzytkownika(nazwaUzytkownika), zahashowaneHaslo(haslo), rola(rola), 
      imie(imie), nazwisko(nazwisko), adres(adres) {
       // cout << "Zahashowane hasło1: " << zahashowaneHaslo << endl; linijka sluzyla do testow

        for(int i=0; i<5; i++)
            wypozyczone_ksiazki[i] = "";
      }

bool Uzytkownik::sprawdzHaslo(const string& wprowadzoneHaslo) {
    return zahashowaneHaslo == wprowadzoneHaslo;
}

string Uzytkownik::getRola() {
    return rola;
}
void Uzytkownik::setHaslo(const string& haslo) {
    this->zahashowaneHaslo = haslo;
}

string Uzytkownik::zahashujHaslo(const string& haslo) {
    string zahashowaneHaslo;
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
   //cout << "Zahashowane hasło: " << zahashowaneHaslo << endl; linijka sluzyla do testow
    return zahashowaneHaslo;
}
string Uzytkownik::getNazwaUzytkownika() const {
    return nazwaUzytkownika;
}

string Uzytkownik::getZahashowaneHaslo() const {
   return zahashowaneHaslo;
}   
string Uzytkownik::getHaslo() const {
    return haslo;
}