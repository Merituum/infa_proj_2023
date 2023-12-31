#include "RejestrCzytelnikow.h"

RejestrCzytelnikow::RejestrCzytelnikow() : rozmiar(0), pojemnosc(1) {
    czytelnicy = new Czytelnik[pojemnosc];
}

RejestrCzytelnikow::~RejestrCzytelnikow() {
    delete[] czytelnicy;
}

void RejestrCzytelnikow::zmienRozmiar(int nowaPojemnosc) {
    Czytelnik* nowiCzytelnicy = new Czytelnik[nowaPojemnosc];
    for (int i = 0; i < rozmiar; ++i) {
        nowiCzytelnicy[i] = czytelnicy[i];
    }
    delete[] czytelnicy;
    czytelnicy = nowiCzytelnicy;
    pojemnosc = nowaPojemnosc;
}
        

bool RejestrCzytelnikow::czyCzytelnikZarejestrowany(const std::string& ID) const {
    for (int i = 0; i < rozmiar; ++i) {
        if (czytelnicy[i].pobierzID() == ID) {
            return true;
        }
    }
    return false;
}
bool RejestrCzytelnikow::czytelnikMaTakieSameID(const Czytelnik& czytelnik, const std::string& ID) {
    return czytelnik.pobierzID() == ID;
}

void RejestrCzytelnikow::zarejestrujCzytelnika(const Czytelnik& czytelnik) {
    if (czyCzytelnikZarejestrowany(czytelnik.pobierzID())) {
        std::cout << "Czytelnik o podanym ID już istnieje.\n";
        return;
    }
    if (rozmiar == pojemnosc) {
        zmienRozmiar(pojemnosc * 2);
    }
    czytelnicy[rozmiar] = czytelnik;
    rozmiar++;
    std::cout << "Czytelnik zarejestrowany pomyślnie.\n";
}

void RejestrCzytelnikow::wyswietlSzczegolyCzytelnika(const std::string& ID) const {
    for (int i = 0; i < rozmiar; ++i) {
        if (czytelnicy[i].pobierzID() == ID) {
            std::cout << "Szczegóły czytelnika:\n";
            std::cout << "ID: " << czytelnicy[i].pobierzID() << "\n";
            std::cout << "Imię i nazwisko: " << czytelnicy[i].pobierzImie() << " " << czytelnicy[i].pobierzNazwisko() << "\n";
            std::cout << "Adres: " << czytelnicy[i].pobierzAdres().ulica << " " << czytelnicy[i].pobierzAdres().numerDomu << ", "
                      << czytelnicy[i].pobierzAdres().kodPocztowy << " " << czytelnicy[i].pobierzAdres().miasto << "\n";
        }
    }
}

void RejestrCzytelnikow::wyswietlWszystkichCzytelnikow() const {
    if (rozmiar == 0) {
        std::cout << "Brak zarejestrowanych czytelników.\n";
    } else {
        std::cout << "Lista zarejestrowanych czytelników:\n";
        for (int i = 0; i < rozmiar; ++i) {
            std::cout << "ID: " << czytelnicy[i].pobierzID() << "\n";
            std::cout << "Imię i nazwisko: " << czytelnicy[i].pobierzImie() << " " << czytelnicy[i].pobierzNazwisko() << "\n";
            std::cout << "-------------------\n";
        }
    }
}

void RejestrCzytelnikow::zapiszDoPliku(const std::string& nazwaPliku) const {
    std::ofstream plikWyjsciowy(nazwaPliku);
    if (plikWyjsciowy.is_open()) {
        for (int i = 0; i < rozmiar; ++i) {
            if (Adres::czyPoprawnyFormatKoduPocztowego(czytelnicy[i].pobierzAdres().kodPocztowy)) {
                czytelnicy[i].zapisz(plikWyjsciowy);
            }
        }
        plikWyjsciowy.close();
    } else {
        std::cout << "Nie udało się otworzyć pliku.\n";
    }
}

void RejestrCzytelnikow::wczytajZPliku(const std::string& nazwaPliku) {
    std::ifstream plikWejsciowy(nazwaPliku);
    if (plikWejsciowy.is_open()) {
        delete[] czytelnicy; // usuń istniejącą tablicę
        czytelnicy = new Czytelnik[rozmiar]; // utwórz nową tablicę
        //czytelnicy.clear(); // Wyczyszczenie obecnych danych z wektora dlatego zakomentowane bo przerobione na tablice dynamiczna
        while (!plikWejsciowy.eof()) {
            std::string id, imie, nazwisko, ulica, numerDomu, miasto, kodPocztowy;
            plikWejsciowy >> id >> imie >> nazwisko >> ulica >> kodPocztowy >> miasto >> numerDomu;
            if (!id.empty() && !imie.empty() && !nazwisko.empty() && !ulica.empty() && !miasto.empty() &&
                !numerDomu.empty() && !kodPocztowy.empty()) {
                Adres adres{ulica, numerDomu, miasto, kodPocztowy};
                //czytelnicy.emplace_back(id, imie, nazwisko, adres);
                Czytelnik* nowaTablica = new Czytelnik[rozmiar+1]; // utwórz nową tablicę o rozmiarze o 1 większym
                std::copy(czytelnicy, czytelnicy + rozmiar, nowaTablica); // skopiuj elementy ze starej tablicy do nowej
                nowaTablica[rozmiar] = Czytelnik(id, imie, nazwisko, adres); // dodaj nowy element na końcu
                delete[] czytelnicy; // usuń starą tablicę
                czytelnicy = nowaTablica; // przypisz nową tablicę do czytelnicy
                rozmiar++; // zwiększ rozmiar
            }
        }
        plikWejsciowy.close();
    } else {
        std::cout << "Nie udało się otworzyć pliku.\n";
    }
}
void RejestrCzytelnikow::usunCzytelnika(const std::string& ID) {
    for (int i = 0; i < rozmiar; ++i) {
        if (czytelnicy[i].pobierzID() == ID) {
            for (int j = i; j < rozmiar - 1; ++j) {
                czytelnicy[j] = czytelnicy[j + 1];
            }
            rozmiar--;
            std::cout << "Czytelnik usunięty pomyślnie.\n";
            return;
        }
    }
    std::cout << "Czytelnik o podanym ID nie istnieje.\n";
}

std::string RejestrCzytelnikow::generujID() {
    return "ID" + std::to_string(Czytelnik::licznikID++); //do przedrostka ID dodajemy liczbe
}