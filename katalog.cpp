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
//Tworzy pusty wektor, kt�ry b�dzie przechowywa� znalezione ksi��ki.
//
//P�tla po ksi��kach w katalogu:
//
//
//
//for (const Ksiazka &ksiazka : ksiazki) {
//
//Iteruje przez ka�dy element w wektorze ksiazki (prawdopodobnie zdefiniowanym w klasie Katalog).
//
//Warunek wyszukiwania:
//
//
//if (ksiazka.wez_tytul().find(search_term) != string::npos ||
//    ksiazka.wez_autor().find(search_term) != string::npos ||
//    ksiazka.wez_isbn().find(search_term) != string::npos   ||
//    ksiazka.wez_rok_publikacji().find(search_term) != string::npos) {
//
//Sprawdza, czy podany search_term wyst�puje w tytule, autorze, ISBN lub roku publikacji danej ksi��ki. Je�li kt�rykolwiek z tych warunk�w jest spe�niony, ksi��ka jest uznawana za pasuj�c�.
//
//    ksiazka.wez_tytul(), ksiazka.wez_autor(), ksiazka.wez_isbn(), ksiazka.wez_rok_publikacji() s� prawdopodobnie metodami dost�powymi (getterami), kt�re zwracaj� odpowiednie informacje o danej ksi��ce.
//
//Dodawanie do wektora znalezionych ksi��ek:
//
//
//znalezione_ksiazki.push_back(ksiazka);
//
//Je�li ksi��ka spe�nia warunki wyszukiwania, dodaje j� do wektora znalezione_ksiazki.
//
//Zwracanie wyniku:
//
//
//return znalezione_ksiazki;
//
//Zwraca wektor zawieraj�cy wszystkie znalezione ksi��ki.
