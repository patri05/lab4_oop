#include "Controller.h"
#include "DrugStore.h"
#include "Repository.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

Controller::Controller() {}

void Controller::Show_Amount(int x)
{

	/*
		x - valoarea cu care se compara cantitatea de medicamente
		ok - variabila cu ajutorul careia se verifica daca exista medicamente care au acntitatea mai mica de cat x
		vect - vector in care sunt memorate medicamentele cu cantitate mai mica de cat 
		functia verifica prima data sa existe medicamente; daca exista medicamente, 
		functia afiseaza medicamentele care sunt mai putine (cantitativ) de cat 
		o valoare primita ca si parametru
	*/

	bool ok = 0;
	vector <DrugStore> vect;
	
	if (Repo.Smile.size() == 0)
	{
		cout << "There are no drugs"; //in caz ca nu exista medicamente se afiseaza un mesaj si se iese din functie
		return;
	}
	
	for (unsigned int i = 0; i < Repo.Smile.size(); i++)
	{
		if (Repo.Smile[i].Get_Amount() < x) //se verifica daca exista medicamente cu cantitatea mai mica de cat x
		{
			ok = 1; 
		}
	}
	
	if (ok == true) // daca s-au gasit astfel de medicamente acestea sunt copiate in vect si sunt afisate
	{
		for (unsigned int i = 0; i < Repo.Smile.size(); i++)
		{
			if (Repo.Smile[i].Get_Amount() < x)
			{
				vect.push_back(Repo.Smile[i]);
			}
		}
		Print(vect);
	}
	else //cazul in care exista medicamente dar toate sunt intr-o cantitate mai mare de cat x se afiseaza un mesaj
	{
		cout << "There are no such drugs!" << endl; 
	}
}


void Controller::Show_Sort_Price()
{

	/*
		vect - vectorul in care sunt sortate elementele
		newDrug - variabila auxiliara pentru sortare
		swapped - variabila cu ajutorul careia se verifica daca mai trebuie sortate elementle
		functia sorteaza elementele din repo in functie de pret si le afiseaza, 
		daca exista elemente in repo
	*/

	vector<DrugStore> vect;
	DrugStore newDrug;
	bool swapped;
	
	vect.assign(Repo.Smile.begin(), Repo.Smile.end());
	
	if (vect.size() == 0) //daca nu exista elemente in repo se afiseaza mesaj si se iese din functie
	{
		cout << "There are no drugs";
		return;
	}
	
	do //bubble sort
	{
		swapped = false;
		for (unsigned int i = 0; i < vect.size() - 1; i++)
		{
			if (vect[i].Get_Price() > vect[i + 1].Get_Price())
			{
				newDrug = vect[i + 1];
				vect[i + 1] = vect[i];
				vect[i] = newDrug;
				swapped = true;
			}
		}
	} while (swapped == true);
	
	Print(vect); //se afiseaza medicamentele sortate
}


void Controller::Search_String(string Name)
{

	/*
		Name - string-ul dupa care se cauta elemente
		ok - variabila cu ajutorul careia se verifica daca s-au gasit astfel de elemente
		vect - vectorul in care se memoreaza elementele care au string-ul Name in nume
		functia cauta si afiseaza elementele care contin in nume string-ul Name
	*/

	bool ok = 0;
	vector<DrugStore> vect;

	if (Repo.Smile.size() == 0) //daca nu exista medicamente se afiseaza mesaj si se iese din functie
	{
		cout << "There are no drugs";
		return;
	}
	
	for (unsigned int i = 0; i < Repo.Smile.size(); i++)
	{
		if (Repo.Smile[i].Get_Name().find(Name) != string::npos) //se verifica daca exista elemente cu string-ul Name in nume
		{
			ok = 1;
		}
	}
	
	if (ok == true) //daca da se copiaza in vect elementele care contin string-ul Name si se afiseaza
	{
		for (unsigned int i = 0; i < Repo.Smile.size(); i++)
		{
			if (Repo.Smile[i].Get_Name().find(Name) != string::npos)
			{
				vect.push_back(Repo.Smile[i]);
			}
		}
		Print(vect);
	}
	else //daca nu se gasesc elemente cu string-ul Name in nume se afiseaza un mesaj
	{
		cout << "There are no such drugs!" << endl;
	}
}


void Controller::Search_String_Empty()
{

	/*
		vect - vectorul in care sunt sortate elementele
		newDrug - variabila auxiliara pentru sortare
		swapped - variabila cu ajutorul careia se verifica daca mai trebuie sortate elementle
		functia sorteaza elementele din repo in functie de nume si le afiseaza, 
		daca exista elemente in repo
	*/

	vector<DrugStore> vect;
	DrugStore newDrug;
	bool swapped;
	
	vect.assign(Repo.Smile.begin(), Repo.Smile.end());
	
	if (vect.size() == 0) //daca nu exista elemente in repo se afiseaza mesaj si se iese din functie
	{
		cout << "There are no drugs";
		return;
	}

	do //bubble sort
	{
		swapped = false;
		for (unsigned int i = 0; i < vect.size() - 1; i++)
		{
			if (vect[i].Get_Name() > vect[i + 1].Get_Name())
			{
				newDrug = vect[i + 1];
				vect[i + 1] = vect[i];
				vect[i] = newDrug;
				swapped = true;
			}
		}
	} while (swapped == true);
	
	Print(vect);
}


void Controller::Print(std::vector<DrugStore> vect)
{

	/*
		vect - vector cu elemente de tip DrugStore (medicamente) care trebuie afisat
		functia afiseaza toate elementele din vect 
	*/

	cout << fixed;
	cout << setprecision(8);
	cout << left << setw(15) << "Name";
	cout << right << setw(15) << "Amount";
	cout << right << setw(25) << "Concentration";
	cout << right << setw(15) << "Price";
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;
	
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		cout << fixed;
		cout << setprecision(2);
		cout << left << setw(15) << vect[i].Get_Name();
		cout << right << setw(15) << vect[i].Get_Amount();
		cout << right << setw(25) << vect[i].Get_Concentration();
		cout << right << setw(15) << vect[i].Get_Price();
		cout << "\n" << endl;
	}

}
