#include "Adres.h"
using namespace std;
 Adres::Adres() {
    ulica = "";
    miasto = "";
    kodPocztowy = "";
    numerDomu = "";
}
bool Adres::czyPoprawnyFormatKoduPocztowego(const string& kodPocztowy) {
    return regex_match(kodPocztowy, regex("\\d{2}-\\d{3}"));
}

