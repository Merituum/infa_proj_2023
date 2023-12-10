//
// Created by basiw on 01.12.2023.
//
#include <gtkmm.h>
#ifndef INFA_PROJ_2023_GUI_H
#define INFA_PROJ_2023_GUI_H


class gui {
    class BibliotekaGUI : public Gtk::Window {
    public:
        BibliotekaGUI() {
            set_title("Aplikacja Biblioteczna");

            // Box do przechowywania elementów w pionie
            Gtk::Box* box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 10));
            add(*box);

            // Etykieta
            Gtk::Label* label = Gtk::manage(new Gtk::Label("Biblioteka"));
            box->pack_start(*label, Gtk::PACK_SHRINK, 0);

            // Przycisk do dodawania książki
            Gtk::Button* dodajPrzycisk = Gtk::manage(new Gtk::Button("Dodaj Książkę"));
            dodajPrzycisk->signal_clicked().connect(sigc::mem_fun(*this, &BibliotekaGUI::dodajKsiazke));
            box->pack_start(*dodajPrzycisk, Gtk::PACK_SHRINK, 0);

            // Lista przechowująca książki
            listaKsiazek = Gtk::manage(new Gtk::ListBox());
            box->pack_start(*listaKsiazek, Gtk::PACK_EXPAND_WIDGET, 0);
        }

        virtual ~BibliotekaGUI() {}

    protected:
        // Funkcja dodająca książkę do listy
        void dodajKsiazke() {
            DodajKsiazkeDialog dialog;

            // Blokada głównego okna do zamknięcia okna dialogowego
            dialog.run();

            // Po zamknięciu okna dialogowego, sprawdź czy użytkownik kliknął "Dodaj"
            if (dialog.dodaj) {
                std::string tytul = dialog.pobierzTytul();
                std::string autor = dialog.pobierzAutora();

                // Dodaj książkę do listy
                Ksiazka ksiazka(tytul, autor);
                dodajDoListy(ksiazka);
            }
        }

        // Dodaj książkę do listy
        void dodajDoListy(const Ksiazka& ksiazka) {
            Gtk::Label* label = Gtk::manage(new Gtk::Label("Tytuł: " + ksiazka.tytul + ", Autor: " + ksiazka.autor));
            listaKsiazek->append(*label);
        }

        Gtk::ListBox* listaKsiazek;
    };

    class DodajKsiazkeDialog : public Gtk::Dialog {
    public:
        DodajKsiazkeDialog() {
            set_title("Dodaj Książkę");

            // Pola tekstowe
            Gtk::Box* box = get_vbox();
            box->pack_start(tytulEntry, Gtk::PACK_SHRINK, 0);
            box->pack_start(autorEntry, Gtk::PACK_SHRINK, 0);

            // Etykiety i pola tekstowe
            box->pack_start(Gtk::Label("Tytuł:"), Gtk::PACK_SHRINK, 0);
            box->pack_start(tytulEntry, Gtk::PACK_SHRINK, 0);

            box->pack_start(Gtk::Label("Autor:"), Gtk::PACK_SHRINK, 0);
            box->pack_start(autorEntry, Gtk::PACK_SHRINK, 0);

            // Przyciski
            add_button("Anuluj", Gtk::RESPONSE_CANCEL);
            add_button("Dodaj", Gtk::RESPONSE_OK);
        }

        virtual ~DodajKsiazkeDialog() {}

        // Pobierz tytuł z pola tekstowego
        std::string pobierzTytul() const {
            return tytulEntry.get_text();
        }

        // Pobierz autora z pola tekstowego
        std::string pobierzAutora() const {
            return autorEntry.get_text();
        }

        // Sprawdź, czy użytkownik kliknął "Dodaj"
        bool dodaj = false;

    protected:
        Gtk::Entry tytulEntry;
        Gtk::Entry autorEntry;

        virtual void on_response(int response_id) {
            if (response_id == Gtk::RESPONSE_OK) {
                // Sprawdź czy oba pola są wypełnione
                if (tytulEntry.get_text().empty() || autorEntry.get_text().empty()) {
                    Gtk::MessageDialog dialog(*this, "Błąd", false, Gtk::MESSAGE_ERROR);
                    dialog.set_secondary_text("Wprowadź tytuł i autora");
                    dialog.run();
                } else {
                    // Ustaw zmienną dodaj na true
                    dodaj = true;
                }
            }

            hide();
        }
    };
};


#endif //INFA_PROJ_2023_GUI_H
