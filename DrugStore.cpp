#include "DrugStore.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

DrugStore::DrugStore()
{
	Amount = 0;
	Price = 0;
	Concentration = 0;
	Name = "";
}
void DrugStore::Set_Amount(int a)
{
	Amount = a;
}
void DrugStore::Set_Concentration(double c)
{
	Concentration = c;
}
void DrugStore::Set_Name(string n)
{
	Name = n;
}
void DrugStore::Set_Price(double p)
{
	Price = p;
}
int DrugStore::Get_Amount()
{
	return Amount;
}
double DrugStore::Get_Concentration()
{
	return Concentration;
}
string DrugStore::Get_Name()
{
	return Name;
}
double DrugStore::Get_Price()
{
	return Price;
}

