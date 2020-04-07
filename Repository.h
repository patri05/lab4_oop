#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <iostream>
#include "DrugStore.h"
#include <string>
#include <vector>

using namespace std;

class Repository
{
private:

public:
	vector<DrugStore> Smile;

	Repository();                                
	bool Add_Drug(string Name, double Concentration, int Amount, double Price); 
	bool Remove_Drug_Name(string Name);         
	bool Remove_Drug_Concentration(double x);    
	bool Change_Amount_Name(string Name,int Amount);        
	bool Change_Amount_Concentration(double x,int Amount);  
	bool Change_Price_Name(string Name, double Price);         
	bool Change_Price_Concentration(double x, double Price);   
	void Show_All();
};

#endif