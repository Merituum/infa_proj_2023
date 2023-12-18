#include "RejestrCzytelnikow.h"
bool RejestrCzytelnikow::czyCzytelnikZarejestrowany(const std::string& ID) const {
    for (const auto& czytelnik : czytelnicy) {
        if (czytelnik.pobierzID() == ID) {
            return true; // Czytelnik już zarejestrowany
        }
    }
    return false; // Czytelnik niezarejestrowany
}
bool RejestrCzytelnikow::czytelnikMaTakieSameID(const Czytelnik& czytelnik, const std::string& ID) {
    return czytelnik.pobierzID() == ID;
}

void RejestrCzytelnikow::zarejestrujCzytelnika(const Czytelnik& czytelnik) {
    if (!czyCzytelnikZarejestrowany(czytelnik.pobierzID())) {
        czytelnicy.push_back(czytelnik);
        std::cout << "Czytelnik zarejestrowany pomyślnie.\n";
    } else {
        std::cout << "Czytelnik o podanym ID już istnieje.\n";
    }
}

void RejestrCzytelnikow::wyswietlSzczegolyCzytelnika(const std::string& ID) const {
    for (const auto& czytelnik : czytelnicy) {
        if (czytelnik.pobierzID() == ID) {
            std::cout << "Szczegóły czytelnika:\n";
            std::cout << "ID: " << czytelnik.pobierzID() << "\n";
            std::cout << "Imię i nazwisko: " << czytelnik.pobierzImie() << " " << czytelnik.pobierzNazwisko() << "\n";
            std::cout << "Adres: " << czytelnik.pobierzAdres().ulica << " " << czytelnik.pobierzAdres().numerDomu << ", "
                      << czytelnik.pobierzAdres().kodPocztowy << " " << czytelnik.pobierzAdres().miasto << "\n";
            return;
        }
    }
    std::cout << "Czytelnik o podanym ID nie istnieje.\n";
}

void RejestrCzytelnikow::wyswietlWszystkichCzytelnikow() const {
    if (czytelnicy.empty()) {
        std::cout << "Brak zarejestrowanych czytelników.\n";
    } else {
        std::cout << "Lista zarejestrowanych czytelników:\n";
        for (const auto& czytelnik : czytelnicy) {
            std::cout << "ID: " << czytelnik.pobierzID() << "\n";
            std::cout << "Imię i nazwisko: " << czytelnik.pobierzImie() << " " << czytelnik.pobierzNazwisko() << "\n";
            std::cout << "-------------------\n";
        }
    }
}

void RejestrCzytelnikow::zapiszDoPliku(const std::string& nazwaPliku) const {
    std::ofstream plikWyjsciowy(nazwaPliku);
    if (plikWyjsciowy.is_open()) {
        for (const auto& czytelnik : czytelnicy) {
            if (Adres::czyPoprawnyFormatKoduPocztowego(czytelnik.pobierzAdres().kodPocztowy)) {
                czytelnik.zapisz(plikWyjsciowy);
            } else {
                std::cerr << "Błąd zapisu: Nieprawidłowy format kodu pocztowego.\n";
            }
        }
        plikWyjsciowy.close();
        std::cout << "Dane zapisane do pliku.\n";
    } else {
        std::cerr << "Błąd otwarcia pliku do zapisu.\n";
    }
}

void RejestrCzytelnikow::wczytajZPliku(const std::string& nazwaPliku) {
    std::ifstream plikWejsciowy(nazwaPliku);
    if (plikWejsciowy.is_open()) {
        czytelnicy.clear(); // Wyczyszczenie obecnych danych
        while (!plikWejsciowy.eof()) {
            std::string id, imie, nazwisko, ulica, numerDomu, miasto, kodPocztowy;
            plikWejsciowy >> id >> imie >> nazwisko >> ulica >> kodPocztowy >> miasto >> numerDomu;
            if (!id.empty() && !imie.empty() && !nazwisko.empty() && !ulica.empty() && !miasto.empty() &&
                !numerDomu.empty() && !kodPocztowy.empty()) {
                Adres adres{ulica, numerDomu, miasto, kodPocztowy};
                czytelnicy.emplace_back(id, imie, nazwisko, adres);
            }
        }
        plikWejsciowy.close();
        std::cout << "Dane wczytane z pliku.\n";
    } else {
        std::cerr << "Błąd otwarcia pliku do odczytu.\n";
    }
}
void RejestrCzytelnikow::usunCzytelnika(const std::string& ID) {
    for (auto it = czytelnicy.begin(); it != czytelnicy.end(); ++it) {      //petla po wszystkich
        if (czytelnikMaTakieSameID(*it, ID)) {  //jezeli to samo id to usuwamy
            czytelnicy.erase(it);
            std::cout << "Czytelnik usunięty pomyślnie.\n";
            return;
        }
    }
    std::cout << "Czytelnik o podanym ID nie istnieje.\n";
}

std::string RejestrCzytelnikow::generujID() {
    return "ID" + std::to_string(Czytelnik::licznikID++); //do przedrostka ID dodajemy liczbe
}