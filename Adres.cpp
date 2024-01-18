#include "Adres.h"
 Adres::Adres() {
    // Default constructor definition
    // Initialize your variables here    
    ulica = "";
    miasto = "";
    kodPocztowy = "";
    numerDomu = "";
}
bool Adres::czyPoprawnyFormatKoduPocztowego(const std::string& kodPocztowy) {
    return std::regex_match(kodPocztowy, std::regex("\\d{2}-\\d{3}"));
}
//Adres::Adres(const std::string& ulica, const std::string& numerDomu, const std::string& miasto, const std::string& kodPocztowy) {
    // implementacja konstruktora
