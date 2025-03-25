#include <iostream>
#include <string>

using namespace std;

class Persoana {
protected:
	string nume;
	int varsta;

public:
	Persoana(string nume, varsta)
	{
		this->nume = nume;
		this->varsta = varsta;

	}
	void afiseazaInformatii()
	{
		cout << "Nume: " << nume << ", Varsta" << varsta << endl;
	}
};

class Student : public Persoana {
private:
	Student(string nume, int varsta, float medie) : Persoana(nume, varsta)
	{
		this->medie = medie;
	}
	void afiseazaInformatii()
	{
		cout << "Nume: " << nume << ", Varsta" << varsta << "Medie: " << medie << endl;
	}
};

class Admin {
public:
	void modificMedie(Student& s, float nouaMedie)
	{
		cout << "Modific media pentru:" << s.nume << " de la " << s.medie << " la " << nouaMedie << endl;
		s.Medie = nouaMedie;
	}
	void afiseazaDetaliistudent(const Student& s) {
		cout << "ADMIN -> STUDENT: " << s.nume << ", Varsta: " << s.varsta << ", Medie " << s.medie << endl;
	}
};

int main()
{
	Student s1("Mihai", 20, 7.5);
	Student s2("Victor", 21, 10);
	s1.afiseazaInformatii();
	s2.afiseazaInformatii();
	Admin admin;
	admin.modificMedie(s2, 5);
	admin.afiseazaDetaliistudent(s2);



}