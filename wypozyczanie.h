//
// Created by basiw on 26.11.2023.
//

#ifndef INFA_PROJ_2023_WYPOZYCZANIE_H
#define INFA_PROJ_2023_WYPOZYCZANIE_H

#include <iostream>
#include <string>

using namespace std;

class Wypozyczanie{
private:
    string username;
    string nazwa_ksiazki;
    string data_zwrotu;
    bool dostepnosc;

public:

    Wypozyczanie(string username, string data_zwrotu,bool dostepnosc, string nazwa_ksiazki);
    void wypozyczKsiazke();
    void zwrocKsiazke();

    bool czy_dostepna() const;


};


#endif //INFA_PROJ_2023_WYPOZYCZANIE_H
