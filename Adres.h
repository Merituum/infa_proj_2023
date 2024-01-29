#pragma once
#include <string>
#include <regex>
using namespace std;
class Adres {
    public:
    string ulica;
    string miasto;
    string kodPocztowy;
    string numerDomu;
    Adres();
    static bool czyPoprawnyFormatKoduPocztowego(const string& kodPocztowy);
    Adres(const string& ulica, const string& miasto, const string& kodPocztowy, const string& numerDomu)
    : ulica(ulica), miasto(miasto), kodPocztowy(kodPocztowy), numerDomu(numerDomu) {}

    string getUlica() const { return ulica; }
    string getMiasto() const { return miasto; }
    string getKodPocztowy() const { return kodPocztowy; }
    string getNumerDomu() const { return numerDomu; }

};

//kod Huberta
