#pragma once
#include <string>
#include <regex>

class Adres {
    public:
    std::string ulica;
    std::string miasto;
    std::string kodPocztowy;
    std::string numerDomu;
    Adres();
    static bool czyPoprawnyFormatKoduPocztowego(const std::string& kodPocztowy);
    Adres(const std::string& ulica, const std::string& miasto, const std::string& kodPocztowy, const std::string& numerDomu)
    : ulica(ulica), miasto(miasto), kodPocztowy(kodPocztowy), numerDomu(numerDomu) {}

    
    std::string getUlica() const { return ulica; }
    std::string getMiasto() const { return miasto; }
    std::string getKodPocztowy() const { return kodPocztowy; }
    std::string getNumerDomu() const { return numerDomu; }

};


