#include "katalog.h"

int Katalog::getLiczbaKsiazek() const {
    return liczbaKsiazek;
}

void Katalog::wczytajKsiazkiZPliku(const std::string &nazwaPliku) {
    std::ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        std::cerr << "B��d otwarcia pliku " << nazwaPliku << std::endl;
        return;
    }

    // Determine the actual number of books in the file
    liczbaKsiazek = 0;
    std::string tytul, autor, isbn, rokPublikacji;
    int ilosc;
     while (plik >> tytul >> autor >> isbn >> rokPublikacji >> ilosc) {
        liczbaKsiazek++;
    }

    // Allocate memory for dynamic array
    ksiazki = new Ksiazka*[liczbaKsiazek];

    // Rewind the file to read data again
    plik.clear();
    plik.seekg(0, std::ios::beg);

    // Read book data and allocate objects
   for (int i = 0; i < liczbaKsiazek; ++i) {
        plik >> tytul >> autor >> isbn >> rokPublikacji >> ilosc;
        ksiazki[i] = new Ksiazka(tytul, autor, isbn, rokPublikacji, ilosc);
    }

    plik.close();
}

Ksiazka** Katalog::wyszukajKsiazki(const std::string& fraza, int& liczbaZnalezionych) const {
    Ksiazka** znalezioneKsiazki = new Ksiazka*[liczbaKsiazek];
    liczbaZnalezionych = 0;

    for (int i = 0; i < liczbaKsiazek; ++i) {
        Ksiazka* ksiazka = ksiazki[i];

        // Sprawd� czy fraza pasuje do tytu�u, autora, isbn lub roku publikacji
        if (ksiazka->wez_tytul().find(fraza) != std::string::npos ||
            ksiazka->wez_autor().find(fraza) != std::string::npos ||
            ksiazka->wez_isbn().find(fraza) != std::string::npos ||
            ksiazka->wez_rok_publikacji().find(fraza) != std::string::npos) {
            znalezioneKsiazki[liczbaZnalezionych++] = ksiazka;
        }
    }

    return znalezioneKsiazki;
}


Ksiazka* Katalog::znajdzKsiazkePoISBN(std::string ISBN)
{
    for(int i=0; i<liczbaKsiazek; i++)
        if( ksiazki[i][0].wez_isbn() == ISBN )
            return ksiazki[i];
    
    return nullptr;
}