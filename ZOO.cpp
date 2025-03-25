#include <iostream>
#include <string>
using namespace std;

class animal {
protected:
	string nume;
	int varsta;
	string mancare;
	float kg;
	string culoare;
public:
	animal(string nume, int varsta, string mancare, float kg, string culoare) : nume(nume), varsta(varsta), mancare(mancare), kg(kg), culoare(culoare) {}
	void inf_animal() {
		cout << "Animal: " << nume << endl << "Varsta: " << varsta << endl << "Mancare: " << mancare << endl << "Kilograme: " << kg << endl << "Culoare: " << culoare << endl;
	}
};

class mamifer : public animal {
protected:
	string tip_alimentar;
public:
	mamifer(string nume, int varsta, string mancare, float kg, string culoare, string tip_alimentar) : animal(nume, varsta, mancare, kg, culoare), tip_alimentar(tip_alimentar) {}
	void inf_mamifer() {
		cout << "Animal: " << nume << endl << "Varsta: " << varsta << endl << "Mancare: " << mancare << endl << "Kilograme: " << kg << endl << "Tip alimentar: " << tip_alimentar << endl << "Culoare: " << culoare << endl << endl;
	}
};

class fauna_marina : public animal {
protected:
	string tip_animal;
public:
	fauna_marina(string nume, int varsta, string mancare, float kg, string culoare, string tip_animal) : animal(nume, varsta, mancare, kg, culoare), tip_animal(tip_animal) {}
	void inf_fauna_marina() {
		cout << "Animal: " << nume << endl << "Varsta: " << varsta << endl << "Mancare: " << mancare << endl << "Kilograme: " << kg << endl << "Tip de animal: " << tip_animal << endl << "Culoare: " << culoare << endl << endl;
	}
};

class pasare : public animal {
protected:
	float lungime_aripi;
public:
	pasare(string nume, int varsta, string mancare, float kg, string culoare, float lungime_aripi) : animal(nume, varsta, mancare, kg, culoare), lungime_aripi(lungime_aripi) {}
	void inf_pasare() {
		cout << "Animal: " << nume << endl << "Varsta: " << varsta << endl << "Mancare: " << mancare << endl << "Kilograme: " << kg << endl << "Lungime aripi: " << lungime_aripi << endl << "Culoare: " << culoare << endl << endl;
	}
};

void instructiuni() {
	cout << "Alege de la 1-3 tipul de animal pe care il ai la ZOO: \n";
	cout << "     (1) Mamifer\n";
	cout << "     (2) Fauna marina\n";
	cout << "     (3) Pasare\n";
}

int main() {
	mamifer elefant("Elefant", 10, "Iarba", 6000.0, "Gri", "Ierbivor");
	fauna_marina delfin("Delfin", 7, "Peste", 200.0, "Gri-Argintiu", "Mamifer marin");
	pasare papagal("Papagal", 5, "Fructe", 0.5, "Verde", 0.8);

	elefant.inf_mamifer();
	delfin.inf_fauna_marina();
	papagal.inf_pasare();

	int optiune;
	instructiuni();
	cin >> optiune;

	int n;
	cout << "Introduceti un numar de animale: ";
	cin >> n;

	if (optiune == 1) {
		mamifer** mamiferi = new mamifer * [n];
		for (int i = 0; i < n; i++) {
			string nume;
			int varsta;
			string mancare;
			float kg;
			string culoare;
			string tip_alimentar;

			cout << "Introduceti numele: " << i + 1 << endl;
			cin >> nume;
			cout << "Introduceti varsta: " << i + 1 << endl;
			cin >> varsta;
			cout << "Introduceti mancarea: " << i + 1 << endl;
			cin >> mancare;
			cout << "Introduceti kilogramele: " << i + 1 << endl;
			cin >> kg;
			cout << "Introduceti culoarea: " << i + 1 << endl;
			cin >> culoare;
			cout << "Introduceti tipul alimentar: " << i + 1 << endl;
			cin >> tip_alimentar;
			cout << endl;

			mamiferi[i] = new mamifer(nume, varsta, mancare, kg, culoare, tip_alimentar);
		}

		cout << "Animalele introduse sunt: ";
		for (int i = 0; i < n; i++) {
			mamiferi[i]->inf_mamifer();
		}
	}

	else if (optiune == 2) {
		fauna_marina** faune_marine = new fauna_marina * [n];
		for (int i = 0; i < n; i++) {
			string nume;
			int varsta;
			string mancare;
			float kg;
			string culoare;
			string tip_animal;

			cout << "Introduceti numele: " << i + 1 << endl;
			cin >> nume;
			cout << "Introduceti varsta: " << i + 1 << endl;
			cin >> varsta;
			cout << "Introduceti mancarea: " << i + 1 << endl;
			cin >> mancare;
			cout << "Introduceti kilogramele: " << i + 1 << endl;
			cin >> kg;
			cout << "Introduceti culoarea: " << i + 1 << endl;
			cin >> culoare;
			cout << "Introduceti tipul de animal: " << i + 1 << endl;
			cin >> tip_animal;
			cout << endl;

			faune_marine[i] = new fauna_marina(nume, varsta, mancare, kg, culoare, tip_animal);
		}

		cout << "Animalele introduse sunt: " << endl;
		for (int i = 0; i < n; i++) {
			faune_marine[i]->inf_fauna_marina();
		}
	}

	else if (optiune == 3) {
		pasare** pasari = new pasare * [n];
		for (int i = 0; i < n; i++) {
			string nume;
			int varsta;
			string mancare;
			float kg;
			string culoare;
			float lungime_aripi;

			cout << "Introduceti numele: " << i + 1 << endl;
			cin >> nume;
			cout << "Introduceti varsta: " << i + 1 << endl;
			cin >> varsta;
			cout << "Introduceti mancarea: " << i + 1 << endl;
			cin >> mancare;
			cout << "Introduceti kilogramele: " << i + 1 << endl;
			cin >> kg;
			cout << "Introduceti culoarea: " << i + 1 << endl;
			cin >> culoare;
			cout << "Introduceti lungimea aripilor: " << i + 1 << endl;
			cin >> lungime_aripi;
			cout << endl;

			pasari[i] = new pasare(nume, varsta, mancare, kg, culoare, lungime_aripi);
		}

		cout << "Animalele introduse sunt: " << endl;
		for (int i = 0; i < n; i++) {
			pasari[i]->inf_pasare();
		}
	}

	return 0;
}
