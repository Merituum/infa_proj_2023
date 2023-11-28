#include <iostream>
#include "katalog.h"
using namespace std;

int main() {
    Katalog katalog;

    Ksiazka ksiazka1("Samobojstwo", "Wojciech Leszczynski", "0123456789", "2023");
    Ksiazka ksiazka2("Ydostwo", "Wojciech Leszczynski", "0123456780", "1939");
    katalog.dodaj_ksiazke(ksiazka1);
    katalog.dodaj_ksiazke(ksiazka2);

    // Szukanie ksiarzek
    string szukana_fraza;
    cin >> szukana_fraza;
    vector<Ksiazka> znalezione_ksiazki = katalog.szukaj_ksiazki(szukana_fraza);

    // Wyswietlanie znalezionej ksionzki
    for (const Ksiazka &ksiazka : znalezione_ksiazki) {
        cout << ksiazka.wez_tytul() << " autorstwa " << ksiazka.wez_autor() << " (" << ksiazka.wez_isbn() << ")" << endl;
    }

    return 0;
}
