//Administrarea locurilor de parcare. Enache Darius si Ciobanu Vlad
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Masina {
public:
    string numar_inmatriculare;
    int ora_intrare;
    int minut_intrare;
    int ora_iesire;
    int minut_iesire;

    Masina(string numar_inmatriculare, int ora_intrare, int minut_intrare, int ora_iesire, int minut_iesire)
        : numar_inmatriculare(numar_inmatriculare), ora_intrare(ora_intrare), minut_intrare(minut_intrare),
        ora_iesire(ora_iesire), minut_iesire(minut_iesire) {
    }

    double calculeazaCost() const {
        int totalMinuteIntrare = ora_intrare * 60 + minut_intrare;
        int totalMinuteIesire = ora_iesire * 60 + minut_iesire;
        int timp_total_parcare = totalMinuteIesire - totalMinuteIntrare;

        if (timp_total_parcare < 0) {
            cout << "Eroare: Ora de iesire este inainte de ora de intrare!" << endl;
            return 0;
        }

        double ore = timp_total_parcare / 60.0;
        return ore * 5.0;
    }

    void afiseazaTarifFix() const {
        cout << "Tariful pe ora este de 5 lei." << endl;
    }
};

class Parcare {
private:
    int locuri_totale;
    int locuri_disponibile;
    vector<Masina> masini_parcate;

public:
    Parcare(int locuri_totale) : locuri_totale(locuri_totale), locuri_disponibile(locuri_totale) {}

    ~Parcare() {}

    void adaugaMasina(string numar_inmatriculare, int ora_intrare, int minut_intrare, int ora_iesire, int minut_iesire) {
        if (locuri_disponibile > 0) {
            masini_parcate.push_back(Masina(numar_inmatriculare, ora_intrare, minut_intrare, ora_iesire, minut_iesire));
            locuri_disponibile--;
            cout << "Masina cu numarul de inmatriculare " << numar_inmatriculare << " a fost parcata de la ora "
                << ora_intrare << ":" << minut_intrare << " pana la ora " << ora_iesire << ":" << minut_iesire << "." << endl;
        }
        else {
            cout << "Nu mai sunt locuri disponibile!" << endl;
        }
    }

    void afiseazaLocuriLibere() const {
        cout << "Locuri disponibile: " << locuri_disponibile << " din " << locuri_totale << endl;
    }

    void afiseazaMasiniParcate() const {
        if (masini_parcate.empty()) {
            cout << "Nu sunt masini in parcare." << endl;
        }
        else {
            cout << "Masini parcate:" << endl;
            for (const auto& masina : masini_parcate) {
                cout << masina.numar_inmatriculare << " - Ora intrare: " << masina.ora_intrare << ":" << masina.minut_intrare
                    << " | Ora iesire: " << masina.ora_iesire << ":" << masina.minut_iesire << " | ";
                double cost = masina.calculeazaCost();
                cout << "Cost parcare: " << (int)cost << "." << (int)((cost - (int)cost) * 100) << " Lei" << endl;
            }
        }
    }

    friend class AsistentParcare;
};

class AsistentParcare {
public:
    void afiseazaDetaliiParcare(const Parcare& parcare) {
        parcare.afiseazaLocuriLibere();
        parcare.afiseazaMasiniParcate();
    }
};

int main() {
    Parcare parcare(100);
    AsistentParcare asistent;

    string numar_inmatriculare;
    int ora_intrare, minut_intrare, ora_iesire, minut_iesire;
    char optiune;

    do {
        parcare.afiseazaLocuriLibere();
        cout << "Introduceti numarul de inmatriculare al masinii: ";
        cin >> numar_inmatriculare;

        Masina masina_temporara(numar_inmatriculare, 0, 0, 0, 0);
        masina_temporara.afiseazaTarifFix();

        cout << "Introduceti ora de intrare (0-23): ";
        cin >> ora_intrare;
        cout << "Introduceti minutul de intrare (0-59): ";
        cin >> minut_intrare;
        cout << "Introduceti ora de iesire (0-23): ";
        cin >> ora_iesire;
        cout << "Introduceti minutul de iesire (0-59): ";
        cin >> minut_iesire;

        parcare.adaugaMasina(numar_inmatriculare, ora_intrare, minut_intrare, ora_iesire, minut_iesire);

        cout << "Doriti sa adaugati alta masina? (y/n): ";
        cin >> optiune;
    } while (optiune == 'y' || optiune == 'Y');

    asistent.afiseazaDetaliiParcare(parcare);

    return 0;
}