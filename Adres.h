#pragma once
#include <string>
#include <regex>

class Adres {
    public:
    std::string ulica;
    std::string miasto;
    std::string kodPocztowy;
    std::string numerDomu;

    static bool czyPoprawnyFormatKoduPocztowego(const std::string& kodPocztowy);
};


