#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string nume;
	int varsta;
	float medie;

public:
	//constructor cu var aux
	Student(string nume_student, int varsta_student, float medie_student) {
		nume = nume_student;
		varsta = varsta_student;
		medie = medie_student;
		cout << "constructorul a fost apelat pentru: " << nume << endl;
	}

	//FOLOSITI UN SINGUR CONSTRUCTOR
	//constructor folosind THIS
	/*Student(string nume, int varsta, float medie) {
		this->nume = nume;
		this->varsta = varsta;
		this->medie = medie;

	cout<<"constructorul a fost apelat pentru: "<< nume << endl;
	}*/

	~Student()
	{
		cout << "constructorul a fost apelat pentru: " << nume << endl;
	}

	void afisare_informatii()
	{
		cout << "NUME: " << nume << ", Varsta: " << varsta << ", Medie: " << medie;
	}

	float returneaza_media() const {
		return medie;
	}
};

void sortare_dupa_medie(Student** studenti, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (studenti[j]->returneaza_media() > studenti[j + 1]->returneaza_media())
			{
				Student* aux = studenti[j];
				studenti[j] = studenti[j + 1];
				studenti[j + 1] = aux;
			}
		}
	}
}
int main() {
	int n, i;
	cout << "n="; cin >> n;
	Student** studenti = new Student * [n];

	//citirea datelor de la tastatura pt n studneti unde n este citit de la tastatura
	for (i = 0; i < n; i++)
	{
		//declaram variabilele
		string nume;
		int varsta;
		float medie;
		//citim de la tastatura datele despre studentul curent (i)
		cout << "introduceti numele studentului: " << i + 1 << ": "; cin >> nume;
		cout << "introduceti varsta studentului: " << i + 1 << ": "; cin >> varsta;
		cout << "introduceti media studentului: " << i + 1 << ": "; cin >> medie;
		//crearea unui nou obiect Student si stocarea lui intr un array
		studenti[i] = new Student(nume, varsta, medie);
	}

	//afisarea studentilor folosind metoda afisare_informatii()
	for (i = 0; i < n; i++)
	{
		studenti[i]->afisare_informatii();
	}

	//afisati studentul cu cea mai mare medie
	cout << "cea mai mare medie este: ";
	studenti[n]->afisare_informatii();


	//afisati media mediilor



	//sortarea studentiilor dupa medie, bubble sort



	//eliberam memoria alocata dinamic
	for (i = 0; i < n; i++)
	{
		delete studenti[i];
	}
	return 0;
}