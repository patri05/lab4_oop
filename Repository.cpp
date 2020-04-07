#include "Repository.h"
#include <iostream>
#include "DrugStore.h"
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

Repository::Repository() {}

bool Repository::Add_Drug(string Name, double Concentration, int Amount, double Price)
{

	/*
		n - valoarea noua pe care o ia Amount in caz ca elementul exista deja 
		i - iterator
		newDrug - medicamentul nou de adaugat
		functia adauga un element de tip DrugStore (medicament) in repository
		functia verifica daca exista elementul in lista, daca acesta exista,
		cantitatea este crescuta cu Amount(primit ca si parametru) si returneaza false, daca nu se creeaza un
		element de tip drugstore si se adauga la vectorul de elemente si returneaza true
	*/

	int n;
	unsigned int i;
	DrugStore newDrug;

	for (i = 0; i < Smile.size(); i++)
	{
		if (Smile[i].Get_Name() == Name) //se verifica daca exista medicamentul in vector
		{
			cout << "The drug is already in the list, the amount incresed with:" << Amount << endl;
			n = Smile[i].Get_Amount() + Amount;
			Smile[i].Set_Amount(n); //daca exista se creste cantitatea si functia returneaza false 
			return 0;
		}
	}
	
	newDrug.Set_Amount(Amount);
	newDrug.Set_Concentration(Concentration);
	newDrug.Set_Name(Name);
	newDrug.Set_Price(Price);
	Smile.push_back(newDrug); //daca nu exista medicamentul atunci acesta este creeat si adaugat la finalul vectorului si functia returneaza true
	
	return 1;
}


bool Repository::Remove_Drug_Name(string Name)
{

	/*
		Name - numele medicamentului care trebuie eliminat
		functia elimina un element din repo
		functia cauta in vector dupa parametrul Nume elementul
		daca il gaseste, atunci il elimina si returneaza true
		in orice alta situatie returneaza false
	*/

	for (unsigned int i = 0; i < Smile.size(); i++)
	{
		if (Smile[i].Get_Name() == Name)
		{
			Smile.erase(Smile.begin() + i);
			return 1;
		}
	}

	return 0;
}


bool Repository::Remove_Drug_Concentration(double x)
{

	/*
		x - concentratia medicamentului care trebuie eliminat
		i - iterator
		functia elimina un element din repo
		functia cauta in vector dupa parametrul x elementul
		daca il gaseste, atunci il elimina si returneaza true
		in orice alta situatie returneaza false
	*/

	unsigned int i;
	
	for (i = 0; i < Smile.size(); i++)
	{
		if (Smile[i].Get_Concentration() == x)
		{
			Smile.erase(Smile.begin() + i);
			return 1;
		}
	}

	return 0;
}


bool Repository::Change_Amount_Name(string Name,int Amount)
{

	/*
		Name - numele elementului caruia trebuie sa ii modificam cantitatea
		Amount - cantitatea noua
		functia cauta elementul in vector cu ajutorul parametrului Name si
		daca il gaseste ii modifica cantitatea cu valoarea parametrului 
		Amount si returneaza true
		in orice alta situatie functia returneaza false
	*/

	for (unsigned int i = 0; i < Smile.size(); i++)
	{
		if (Smile[i].Get_Name() == Name)
		{
			Smile[i].Set_Amount(Amount);
			return 1;
		}
	}

	return 0;
}


bool Repository::Change_Amount_Concentration(double x,int Amount)
{

	/*
		x - concentratia elementului caruia trebuie sa ii modificam cantitatea
		Amount - cantitatea noua
		functia cauta elementul in vector cu ajutorul parametrului x si
		daca il gaseste ii modifica cantitatea cu valoarea parametrului 
		Amount si returneaza true
		in orice alta situatie functia returneaza false
	*/

	for (unsigned int i = 0; i < Smile.size(); i++)
	{
		if (Smile[i].Get_Concentration() == x)
		{
			Smile[i].Set_Amount(Amount);
			return 1;
		}
	}

	return 0;
}


bool Repository::Change_Price_Name(string Name, double Price)
{

	/*
		Name - numele elementului caruia trebuie sa ii modificam pretul
		Price - pretul nou
		functia cauta elementul in vector cu ajutorul parametrului Name si
		daca il gaseste ii modifica pretul cu valoarea parametrului 
		Price si returneaza true
		in orice alta situatie functia returneaza false
	*/

	for (unsigned int i = 0; i < Smile.size(); i++)
	{
		if (Smile[i].Get_Name() == Name)
		{
			Smile[i].Set_Price(Price);
			return 1;
		}
	}

	return 0;
}


bool Repository::Change_Price_Concentration(double x, double Price)
{

	/*
		x - concentratia elementului caruia trebuie sa ii modificam pretul
		Price - pretul nou
		functia cauta elementul in vector cu ajutorul parametrului x si
		daca il gaseste ii modifica pretul cu valoarea parametrului 
		Price si returneaza true
		in orice alta situatie functia returneaza false
	*/

	for (unsigned int i = 0; i < Smile.size(); i++)
	{
		if (Smile[i].Get_Concentration() == x)
		{
			Smile[i].Set_Price(Price);
			return 1;
		}
	}

	return 0;
}


void Repository::Show_All()
{

	/*
		functia afiseaza toate elementele din repo
	*/

	unsigned int i;
	cout << fixed;
	cout << setprecision(8);
	cout << left << setw(15) << "Name";
	cout << right << setw(15) << "Amount";
	cout << right << setw(25) << "Concentration";
	cout << right << setw(15) << "Price";
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;

	for (i = 0; i < Smile.size(); i++)
	{
		cout << fixed;
		cout << setprecision(2);
		cout << left << setw(15) << Smile[i].Get_Name();
		cout << right << setw(15) << Smile[i].Get_Amount();
		cout << right << setw(25) << Smile[i].Get_Concentration();
		cout << right << setw(15) << Smile[i].Get_Price();
		cout << "\n" << endl;
	}
}