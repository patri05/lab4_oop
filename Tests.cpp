#include "Tests.h"
#include "DrugStore.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

void Tests::Test()
{	
	/*
		functia de teste 
	*/

	//test add
	DrugsTest.Repo.Add_Drug("primul", 12.4, 45, 12);
	DrugsTest.Repo.Add_Drug("al doilea", 34.6, 10, 12.99);
	DrugsTest.Repo.Add_Drug("al treilea", 43.76, 100, 34.99);
	assert(DrugsTest.Repo.Smile.size() == 3);

	//test getters
	assert(DrugsTest.Repo.Smile[0].Get_Name() == "primul");
	assert(DrugsTest.Repo.Smile[0].Get_Concentration() == 12.4);
	assert(DrugsTest.Repo.Smile[0].Get_Amount() == 45);
	assert(DrugsTest.Repo.Smile[0].Get_Price() == 12);

	//test setters
	DrugsTest.Repo.Smile[0].Set_Name("second");
	DrugsTest.Repo.Smile[0].Set_Concentration(14.99);
	DrugsTest.Repo.Smile[0].Set_Amount(3);
	DrugsTest.Repo.Smile[0].Set_Price(99);
	assert(DrugsTest.Repo.Smile[0].Get_Name() == "second");
	assert(DrugsTest.Repo.Smile[0].Get_Concentration() == 14.99);
	assert(DrugsTest.Repo.Smile[0].Get_Amount() == 3);
	assert(DrugsTest.Repo.Smile[0].Get_Price() == 99);

	//test change amount
	DrugsTest.Repo.Change_Amount_Concentration(14.99, 60);
	assert(DrugsTest.Repo.Smile[0].Get_Amount() == 60);
	DrugsTest.Repo.Change_Amount_Name("al doilea", 50);
	assert(DrugsTest.Repo.Smile[1].Get_Amount() == 50);

	//change price
	DrugsTest.Repo.Change_Price_Concentration(14.99, 30);
	assert(DrugsTest.Repo.Smile[0].Get_Price() == 30);
	DrugsTest.Repo.Change_Price_Name("al doilea", 40);
	assert(DrugsTest.Repo.Smile[1].Get_Price() == 40);
	undo_redo.Add_Undo(DrugsTest.Repo.Smile);

	//test remove
	DrugsTest.Repo.Remove_Drug_Name("second");
	undo_redo.Add_Undo(DrugsTest.Repo.Smile);
	DrugsTest.Repo.Remove_Drug_Concentration(43.76);
	undo_redo.Add_Undo(DrugsTest.Repo.Smile);
	DrugsTest.Repo.Remove_Drug_Concentration(34.6);
	undo_redo.Add_Undo(DrugsTest.Repo.Smile);
	assert(DrugsTest.Repo.Smile.size() == 0);

	//test undo 
	DrugsTest.Repo.Smile = undo_redo.Undo();
	assert(DrugsTest.Repo.Smile.size() == 1);
	DrugsTest.Repo.Smile = undo_redo.Undo();
	assert(DrugsTest.Repo.Smile.size() == 2);
	DrugsTest.Repo.Smile = undo_redo.Undo();
	assert(DrugsTest.Repo.Smile.size() == 3);

	//test redo
	DrugsTest.Repo.Smile = undo_redo.Redo();
	undo_redo.redo_array.erase(undo_redo.redo_array.begin());
	assert(DrugsTest.Repo.Smile.size() == 0);
	DrugsTest.Repo.Smile = undo_redo.Redo();
	undo_redo.redo_array.erase(undo_redo.redo_array.begin());
	assert(DrugsTest.Repo.Smile.size() == 1);
	DrugsTest.Repo.Smile = undo_redo.Redo();
	undo_redo.redo_array.erase(undo_redo.redo_array.begin());
	assert(DrugsTest.Repo.Smile.size() == 2);
}
