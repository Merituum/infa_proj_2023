//
// Created by basiw on 26.11.2023.
//

#include "wypozyczanie.h"
Wypozyczanie::Wypozyczanie(std::string username, std::string data_zwrotu,bool dostepnosc, std::string nazwa_ksiazki) {}

bool Wypozyczanie::czy_dostepna() const {
    if(dostepnosc==true){
        return true;
    }
    else {
        return false;
    }
}

void Wypozyczanie::wypozyczKsiazke() {
    if(dostepnosc=true){
        //nie wiem jakie struktury wymysli kurwa wojtek
    }
}

void Wypozyczanie::zwrocKsiazke() {
    if(dostepnosc=true){
        return;
    }

}



