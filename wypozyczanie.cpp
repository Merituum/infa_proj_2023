// #include "wypozyczanie.h"
// #include <iostream>

// void Wypozyczanie::wypozyczKsiazke(Katalog& katalog, const std::string& idKsiazki) {
//     Ksiazka* ksiazka = katalog.znajdzKsiazke(idKsiazki);

//     if (ksiazka == nullptr) {
//         std::cout << "Nie znaleziono książki o podanym ID.\n";
//         return;
//     }

//     if (!ksiazka->czy_wypozyczona()) {
//         ksiazka->wypozycz();
//         std::cout << "Książka " << ksiazka->wez_tytul() << " została wypożyczona.\n";
//     } else {
//         std::cout << "Książka " << ksiazka->wez_tytul() << " jest już wypożyczona.\n";
//     }
// }
