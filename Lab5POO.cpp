#include <iostream>
#include <string>
using namespace std;

class Persoana {
protected:
	string nume;
	int varsta;
public:
	//constructor
	Persoana(string nume, int varsta) {
		this->nume = nume;
		this->varsta = varsta;
	}

	//metoda de afisare
	void afisare_detalii() {
		cout << "Nume: " << nume << ", Varsta: " << varsta << endl;
	}
};

//cream o clasa derivata, mostenita din clasa Persoana
class Student : public Persoana {
private:
	float medie;

public:
	Student(string nume, int varsta, float medie) : Persoana(nume, varsta) {
		this->medie = medie;
	}
	//Suprascrierea metodei de afisare:
	void afiseaza_informatii() {
		cout << "Nume: " << nume << ", Varsta: " << varsta << ", Medie: " << medie << endl;
	}
};
int main()
{
	//cream obiect de tip student
	Student s("Ion", 21, 10);
	s.afiseaza_informatii();
}
int main()
{
	Student s("Ion", 21, 10);
	s.afiseaza_informatii();
	int n;
	cout << "Introduceti un numar de studenti: " << endl;
	cin >> n;

	Student** studenti = new Student * [n];
	for (int i = 0; i < n; i++) {
		string nume;
		int varsta;
		float medie;

		cout << "Introduceti numele: " << i + 1 << endl;
		cin >> nume;
		cout << "Introduceti varsta: " << i + 1 << endl;
		cin >> varsta;
		cout << "Introduceti media: " << i + 1 << endl;
		cin >> medie;

		studenti[i] = new Student(nume, varsta, medie);
	}

	cout << "Studentii introdusi sunt: " << endl;
	for (int i = 0; i < n; i++) {
		studenti[i]->afiseaza_informatii();
	}
}