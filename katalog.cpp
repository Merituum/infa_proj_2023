#include "katalog.h"
using namespace std;
void Katalog::dodaj_ksiazke(const Ksiazka &ksiazka) {
    ksiazki.push_back(ksiazka);
}

vector<Ksiazka> Katalog::szukaj_ksiazki(const string &szukana_fraza) const {
    vector<Ksiazka> znalezione_ksiazki;

    for (const Ksiazka &ksiazka : ksiazki) {
        if (ksiazka.wez_tytul().find(szukana_fraza) != string::npos ||
            ksiazka.wez_autor().find(szukana_fraza) != string::npos ||
            ksiazka.wez_isbn().find(szukana_fraza) != string::npos   ||
            ksiazka.wez_rok_publikacji().find(szukana_fraza) != string::npos) {
            znalezione_ksiazki.push_back(ksiazka);
        }
    }

    return znalezione_ksiazki;
}


//Inicjalizacja wektora:
//
//
//vector<Ksiazka> znalezione_ksiazki;
//
//Tworzy pusty wektor, który będzie przechowywać znalezione książki.
//
//Pętla po książkach w katalogu:
//
//
//
//for (const Ksiazka &ksiazka : ksiazki) {
//
//Iteruje przez każdy element w wektorze ksiazki (prawdopodobnie zdefiniowanym w klasie Katalog).
//
//Warunek wyszukiwania:
//
//
//if (ksiazka.wez_tytul().find(search_term) != string::npos ||
//    ksiazka.wez_autor().find(search_term) != string::npos ||
//    ksiazka.wez_isbn().find(search_term) != string::npos   ||
//    ksiazka.wez_rok_publikacji().find(search_term) != string::npos) {
//
//Sprawdza, czy podany search_term występuje w tytule, autorze, ISBN lub roku publikacji danej książki. Jeśli którykolwiek z tych warunków jest spełniony, książka jest uznawana za pasującą.
//
//    ksiazka.wez_tytul(), ksiazka.wez_autor(), ksiazka.wez_isbn(), ksiazka.wez_rok_publikacji() są prawdopodobnie metodami dostępowymi (getterami), które zwracają odpowiednie informacje o danej książce.
//
//Dodawanie do wektora znalezionych książek:
//
//
//znalezione_ksiazki.push_back(ksiazka);
//
//Jeśli książka spełnia warunki wyszukiwania, dodaje ją do wektora znalezione_ksiazki.
//
//Zwracanie wyniku:
//
//
//return znalezione_ksiazki;
//
//Zwraca wektor zawierający wszystkie znalezione książki.
