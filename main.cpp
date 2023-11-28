#include <iostream>
#include "katalog.h"
using namespace std;
#include <locale.h>
int main() {
    setlocale(LC_CTYPE, "Polish");
    Katalog katalog;

    Ksiazka ksiazka1("Samobojstwo", "Wojciech Leszczynski", "0123456789", "1997");
    Ksiazka ksiazka2("Ydostwo", "Wojciech Leszczynski", "0123456780", "1939");
    Ksiazka ksiazka3("Harry Potter", "J.K. Rowling", "9780545582889", "1997");
    Ksiazka ksiazka4("W³adca Pierœcieni", "J.R.R. Tolkien", "9788373191723", "1954");
    Ksiazka ksiazka5("1984", "George Orwell", "9780451524935", "1949");

    katalog.dodaj_ksiazke(ksiazka1);
    katalog.dodaj_ksiazke(ksiazka2);
    katalog.dodaj_ksiazke(ksiazka3);
    katalog.dodaj_ksiazke(ksiazka4);
    katalog.dodaj_ksiazke(ksiazka5);
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
