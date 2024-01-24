#include "Adres.h"
 Adres::Adres() {
    ulica = "";
    miasto = "";
    kodPocztowy = "";
    numerDomu = "";
}
bool Adres::czyPoprawnyFormatKoduPocztowego(const std::string& kodPocztowy) {
    return std::regex_match(kodPocztowy, std::regex("\\d{2}-\\d{3}"));
}

