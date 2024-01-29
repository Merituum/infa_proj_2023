#include <iostream>
#include <fstream>
#include "katalog.h"
#include "ksiazka.h"
#include "Adres.h"
#include "uzytkownik.h"
#include "bazadanychuzytkownika.h"
//kod wspolny
using namespace std;


int main() {
    setlocale(LC_CTYPE, "Polish");
    Katalog katalog;
    katalog.wczytajKsiazkiZPliku("ksiazki.txt");

    BazaUzytkownikow bazaDanychUzytkownika;
    bazaDanychUzytkownika.wczytajUzytkownikowZPliku("uzytkownicy.txt");

char opcja;
do{ 
    cout << "Wybierz opcję: r - rejestracja, l - logowanie, q - wyjście\n";
    cin >> opcja;
string nazwaUzytkownika;
string haslo;
string kodUwierzytelniajacy;
string rola;
if (opcja == 'r') {
    string imie;
    string nazwisko;
    string ulica;
    string numerDomu;
    string kodPocztowy;
    string miasto;
    cout << "Podaj imię: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj ulicę: ";
    cin >> ulica;
    cout << "Podaj numer domu: ";
    cin >> numerDomu;
    do{
        cout << "Podaj kod pocztowy: ";
        cin >> kodPocztowy;
        if(!Adres::czyPoprawnyFormatKoduPocztowego(kodPocztowy)){
            cout << "Niepoprawny format kodu pocztowego. Spróbuj ponownie.\n";
        }
    } while(!Adres::czyPoprawnyFormatKoduPocztowego(kodPocztowy));
    cout << "Podaj miasto: ";
    cin >> miasto;
    Adres adres(ulica, numerDomu, kodPocztowy, miasto);
    cout << "Podaj nazwę użytkownika: ";
    cin >> nazwaUzytkownika;
    cout << "Podaj hasło: ";
    cin >> haslo;
    do{
    cout << "Podaj rolę (czytelnik/bibliotekarz): ";
    cin >> rola;
    } while (rola != "czytelnik" && rola != "bibliotekarz");
    if (rola == "bibliotekarz") {
    cout << "Podaj kod uwierzytelniający dla bibliotekarza: ";
    cin >> kodUwierzytelniajacy;
    if (kodUwierzytelniajacy != "1111") { 
        cout << "Niepoprawny kod uwierzytelniający. Nie możesz się zarejestrować jako bibliotekarz.\n";   
        rola="czytelnik"; 
        }
}   
    bazaDanychUzytkownika.zarejestrujUzytkownika(nazwaUzytkownika, haslo, rola, imie, nazwisko, adres);
    cout << "Rejestracja zakończona pomyślnie. Teraz mozesz sie zalogowac.\n";
   
} else if (opcja == 'l') {
    // logowanie
    cout << "Podaj nazwę użytkownika: ";
    cin >> nazwaUzytkownika;
    cout << "Podaj hasło: ";
    cin >> haslo;

Uzytkownik* uzytkownik = bazaDanychUzytkownika.znajdzUzytkownika(nazwaUzytkownika);
    if (uzytkownik != nullptr) {
    string zahashowaneWprowadzoneHaslo = uzytkownik->zahashujHaslo(haslo);
    if (uzytkownik->sprawdzHaslo(zahashowaneWprowadzoneHaslo)) {
        cout << "Logowanie pomyślne.\n";
        
        if (uzytkownik->getRola() == "czytelnik") {
            //  menu dla czytelnika
            char wybor;
            do{
            cout << "1. Wyszukaj książkę\n"; //Kod Wojtka
            cout << "2. Wypozycz ksiazke \n"; //Kod Bartka
            cout << "3. Zwroc ksiazke \n"; //Kod Bartka
            cout<< "4. Zapis awaryjny\n"; //Kod Bartka
            cout << "5. Wyjdz\n";
            cin>>wybor;
            cin.ignore();
            switch(wybor){
                case '1':{
                    string szukana_fraza;
                    cout << "Podaj frazę do wyszukania: ";
                    getline(cin, szukana_fraza);

                    int liczbaZnalezionych;
                    Ksiazka** znalezioneKsiazki = katalog.wyszukajKsiazki(szukana_fraza, liczbaZnalezionych);

                    if (liczbaZnalezionych > 0) {
                    cout << "Znalezione książki:\n";
                    for (int i = 0; i < liczbaZnalezionych; ++i) {
                        cout << i + 1 << ". Tytuł: " << znalezioneKsiazki[i]->wez_tytul()
                        << ", Autor: " << znalezioneKsiazki[i]->wez_autor()
                        << ", ISBN: " << znalezioneKsiazki[i]->wez_isbn()
                        << ", Rok publikacji: " << znalezioneKsiazki[i]->wez_rok_publikacji()
                        << ", Ilość w bibliotece: " << znalezioneKsiazki[i]->wez_ilosc_w_bibliotece()
                        << "\n";
                        }
                    } else {
                        cout << "Brak pasujących książek.\n";
                    }
                    break;
                }
                case '2':{
                    cout << "Podaj isbn ksiazki do wypozyczenia: \n";
                    string isbn;
                    cin >> isbn;
                    Ksiazka* ksiazka;
                    ksiazka = katalog.znajdzKsiazkePoISBN(isbn);
                    if(ksiazka->wez_ilosc_w_bibliotece()>0)
                    {
                        ksiazka->wypozycz();
                        Uzytkownik* uzytkownik = bazaDanychUzytkownika.znajdzUzytkownika(nazwaUzytkownika);
                        for(int i=0; i<5; i++)
                            if(uzytkownik->wypozyczone_ksiazki[i] == "")
                                {
                                    uzytkownik->wypozyczone_ksiazki[i] = isbn;
                                    //wypozyczone.txt
                                    break;
                                }
                    }//bazaDanychUzytkownika.zapiszWypozyczoneKsiazki();
                    break;
                }
                case '3': {
                   cout << "Podaj isbn ksiazki do zwrocenia: " << endl;
                string isbn;
                cin >> isbn;

                 Uzytkownik* uzytkownik = bazaDanychUzytkownika.znajdzUzytkownika(nazwaUzytkownika);

                if (uzytkownik != nullptr) {
                for (int i = 0; i < 5; i++) {
                if (uzytkownik->wypozyczone_ksiazki[i] == isbn) {

                uzytkownik->wypozyczone_ksiazki[i] = "";


                std::ofstream plik("wypozyczone.txt");

                for (int j = 0; j < 5; j++) {
                    if (uzytkownik->wypozyczone_ksiazki[j] != "") {
                        plik << uzytkownik->getNazwaUzytkownika() << " " << uzytkownik->wypozyczone_ksiazki[j] << endl;
                    }
                }

                plik.close();
                //bazaDanychUzytkownika.zapiszWypozyczoneKsiazki();
                cout << "Ksiazka o numerze ISBN " << isbn << " zostala zwrocona." << endl;
                break; 
            }
        }
                }
                }
                case '4': {
                    //zapis
                    bazaDanychUzytkownika.zapiszWypozyczoneKsiazki();
                    cout << "Do widzenia!\n";
                    break;      
                }
                case '5':{
                    cout << "Do widzenia!\n";
                    break;
                }

                default:
                    cout << "Niepoprawny wybór.\n";
            }
              

            
            }while (wybor != '5');}
            
         else if (uzytkownik->getRola() == "bibliotekarz") {
            //  menu dla bibliotekarza
            char wybor;
            do{
            cout << "1. Wyszukaj książkę\n";
            cout << "2. Usun uzytkownika\n";
            cout << "3. Pokaz wszystkich uzytkownikow\n";
            cout << "4. Dane uzytkownika\n";
            cout << "5. Wyjdz\n";
            cin>>wybor;
            cin.ignore();
            switch(wybor){
                case '1':{
                    string szukana_fraza;
                    cout << "Podaj frazę do wyszukania: ";
                    getline(cin, szukana_fraza);

                    int liczbaZnalezionych;
                    Ksiazka** znalezioneKsiazki = katalog.wyszukajKsiazki(szukana_fraza, liczbaZnalezionych);

                    if (liczbaZnalezionych > 0) {
                    cout << "Znalezione książki:\n";
                    for (int i = 0; i < liczbaZnalezionych; ++i) {
                        cout << i + 1 << ". Tytuł: " << znalezioneKsiazki[i]->wez_tytul()
                        << ", Autor: " << znalezioneKsiazki[i]->wez_autor()
                        << ", ISBN: " << znalezioneKsiazki[i]->wez_isbn()
                        << ", Rok publikacji: " << znalezioneKsiazki[i]->wez_rok_publikacji()
                        << ", Ilość w bibliotece: " << znalezioneKsiazki[i]->wez_ilosc_w_bibliotece()
                        << "\n";
                        }
                    } else {
                        cout << "Brak pasujących książek.\n";
                    }
                    break;
                }
                case '2':{
                    string nazwaUzytkownika;
                    cout << "Podaj nazwę użytkownika do usunięcia: ";
                    cin >> nazwaUzytkownika;
                    bazaDanychUzytkownika.usunUzytkownika(nazwaUzytkownika);
                    break;
                }
                case '3':{
                    bazaDanychUzytkownika.wyswietlWszystkichUzytkownikow();
                    break;
                }
                case '4':{
                    cout<<"Podaj nazwe uzytkownika ktorego dane chcesz zobaczyc"<<endl;
                    cin>>nazwaUzytkownika;
                    bazaDanychUzytkownika.wyswietlSzczegolyUzytkownika(nazwaUzytkownika);
                }
                case '5':{
                    cout << "Do widzenia!\n";
                    break;
                }
                default:
                    cout << "Niepoprawny wybór.\n";
            
            }
            }while (wybor != '5');
        }    
            
    }else {
        cout << "Logowanie nieudane.\n";
    }
    } else {
    cout << "Nie znaleziono użytkownika.\n";
    }
   
    }}while (opcja == 'q');
  
 bazaDanychUzytkownika.zapiszUzytkownikowDoPliku("uzytkownicy.txt");
return 0;
 } 

   
   
   
   