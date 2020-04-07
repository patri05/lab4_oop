#ifndef UI_H
#define UI_H
#include "Controller.h"
#include "DrugStore.h"
#include "Repository.h"
#include <iostream>

using namespace std;

class UI
{
public:
	Controller obj;
	UI();
	double Get_Concentration();
	int Get_Amount();
	double Get_Price();
	void Initialization();
	void Interface();

};
#endif 
