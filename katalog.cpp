#include "katalog.h"
//Kod Wojtka
int Katalog::getLiczbaKsiazek() const {
    return liczbaKsiazek;
}

void Katalog::wczytajKsiazkiZPliku(const string &nazwaPliku) {
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cerr << "B��d otwarcia pliku " << nazwaPliku << endl;
        return;
    }

    
    liczbaKsiazek = 0;
    string tytul, autor, isbn, rokPublikacji;
    int ilosc;
     while (plik >> tytul >> autor >> isbn >> rokPublikacji >> ilosc) {
        liczbaKsiazek++;
    }
    ksiazki = new Ksiazka*[liczbaKsiazek];
    plik.clear();
    plik.seekg(0, ios::beg);

    
   for (int i = 0; i < liczbaKsiazek; ++i) {
        plik >> tytul >> autor >> isbn >> rokPublikacji >> ilosc;
        ksiazki[i] = new Ksiazka(tytul, autor, isbn, rokPublikacji, ilosc);
    }

    plik.close();
}

Ksiazka** Katalog::wyszukajKsiazki(const string& fraza, int& liczbaZnalezionych) const {
    Ksiazka** znalezioneKsiazki = new Ksiazka*[liczbaKsiazek];
    liczbaZnalezionych = 0;

    for (int i = 0; i < liczbaKsiazek; ++i) {
        Ksiazka* ksiazka = ksiazki[i];

       
        if (ksiazka->wez_tytul().find(fraza) != string::npos ||
            ksiazka->wez_autor().find(fraza) != string::npos ||
            ksiazka->wez_isbn().find(fraza) != string::npos ||
            ksiazka->wez_rok_publikacji().find(fraza) != string::npos) {
            znalezioneKsiazki[liczbaZnalezionych++] = ksiazka;
        }
    }

    return znalezioneKsiazki;
}

//Kod Bartka

Ksiazka* Katalog::znajdzKsiazkePoISBN(string ISBN)
{
    for(int i=0; i<liczbaKsiazek; i++)
        if( ksiazki[i][0].wez_isbn() == ISBN )
            return ksiazki[i];
    
    return nullptr;
}