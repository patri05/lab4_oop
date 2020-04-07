#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "DrugStore.h"
#include "Repository.h"
#include <string>
#include <vector>


class Controller
{
public:
	Repository Repo;

	Controller();
	void Show_Amount(int Amount);
	void Show_Sort_Price();
	void Search_String(string Name);
	void Search_String_Empty();
	void Print(std::vector<DrugStore> vect);
};
#endif
