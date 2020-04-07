#ifndef DRUGSTORE_H
#define DRUGSTORE_H
#include <string>

using namespace std;

class DrugStore
{
private:
	string Name;
	double Concentration;
	int Amount;
	double Price;
public:
	DrugStore();
	void Set_Name(string n);
	void Set_Concentration(double c);
	void Set_Amount(int a);
	void Set_Price(double f);
	string Get_Name();
	double Get_Concentration();
	int Get_Amount();
	double Get_Price();
};
#endif 