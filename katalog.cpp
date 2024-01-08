#include "katalog.h"

int Katalog::getLiczbaKsiazek() const {
    return liczbaKsiazek;
}

void Katalog::dodaj_ksiazke(const Ksiazka &ksiazka) {
    Ksiazka* nowaKsiazka = new Ksiazka(ksiazka);
    Ksiazka** nowaTablica = new Ksiazka*[liczbaKsiazek + 1];

    // Skopiuj istniejące obiekty
    for (int i = 0; i < liczbaKsiazek; ++i) {
        nowaTablica[i] = ksiazki[i];
    }

    // Dodaj nowy obiekt
    nowaTablica[liczbaKsiazek] = nowaKsiazka;

    // Zwolnij starą pamięć i przypisz nową tablicę
    delete[] ksiazki;
    ksiazki = nowaTablica;

    ++liczbaKsiazek;
}

Ksiazka* const* Katalog::szukaj_ksiazki(const std::string &szukana_fraza) const {
    Ksiazka** znalezione_ksiazki = nullptr;
    int liczbaZnalezionych = 0;

    for (int i = 0; i < liczbaKsiazek; ++i) {
        if (ksiazki[i]->wez_tytul().find(szukana_fraza) != std::string::npos ||
            ksiazki[i]->wez_autor().find(szukana_fraza) != std::string::npos ||
            ksiazki[i]->wez_isbn().find(szukana_fraza) != std::string::npos ||
            ksiazki[i]->wez_rok_publikacji().find(szukana_fraza) != std::string::npos) {
            // Dodaj do tablicy znalezionych
            Ksiazka** nowaTablica = new Ksiazka*[liczbaZnalezionych + 1];
            for (int j = 0; j < liczbaZnalezionych; ++j) {
                nowaTablica[j] = znalezione_ksiazki[j];
            }
            nowaTablica[liczbaZnalezionych] = ksiazki[i];
            delete[] znalezione_ksiazki;
            znalezione_ksiazki = nowaTablica;

            ++liczbaZnalezionych;
        }
    }

    return znalezione_ksiazki;
}

