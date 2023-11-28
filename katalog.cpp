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
//Tworzy pusty wektor, który bêdzie przechowywaæ znalezione ksi¹¿ki.
//
//Pêtla po ksi¹¿kach w katalogu:
//
//
//
//for (const Ksiazka &ksiazka : ksiazki) {
//
//Iteruje przez ka¿dy element w wektorze ksiazki (prawdopodobnie zdefiniowanym w klasie Katalog).
//
//Warunek wyszukiwania:
//
//
//if (ksiazka.wez_tytul().find(search_term) != string::npos ||
//    ksiazka.wez_autor().find(search_term) != string::npos ||
//    ksiazka.wez_isbn().find(search_term) != string::npos   ||
//    ksiazka.wez_rok_publikacji().find(search_term) != string::npos) {
//
//Sprawdza, czy podany search_term wystêpuje w tytule, autorze, ISBN lub roku publikacji danej ksi¹¿ki. Jeœli którykolwiek z tych warunków jest spe³niony, ksi¹¿ka jest uznawana za pasuj¹c¹.
//
//    ksiazka.wez_tytul(), ksiazka.wez_autor(), ksiazka.wez_isbn(), ksiazka.wez_rok_publikacji() s¹ prawdopodobnie metodami dostêpowymi (getterami), które zwracaj¹ odpowiednie informacje o danej ksi¹¿ce.
//
//Dodawanie do wektora znalezionych ksi¹¿ek:
//
//
//znalezione_ksiazki.push_back(ksiazka);
//
//Jeœli ksi¹¿ka spe³nia warunki wyszukiwania, dodaje j¹ do wektora znalezione_ksiazki.
//
//Zwracanie wyniku:
//
//
//return znalezione_ksiazki;
//
//Zwraca wektor zawieraj¹cy wszystkie znalezione ksi¹¿ki.
