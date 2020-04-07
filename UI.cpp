#include "DrugStore.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include "UndoRedo.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>


UI::UI() {}

double UI::Get_Concentration()
{

	//citeste concentratia de la tastatura si o returneaza

	double Concentration;
	
	while (!(cin >> Concentration))
	{
		cout << "Error, enter a number:";
		cin.clear();
		cin.ignore(123, '\n');
	}

	return Concentration;
}

int UI::Get_Amount()
{

	//citeste cantitatea de la tastatura si o returneaza

	int Amount;

	while (!(cin >> Amount))
	{
		cout << "Error, enter a number:";
		cin.clear();
		cin.ignore(123, '\n');
	}

	return Amount;
}

double UI::Get_Price()
{

	//citeste pretul de la tastatura si il returneaza

	double Price;
	
	while (!(cin >> Price))
	{
		cout << "Error, enter a number:";
		cin.clear();
		cin.ignore(123, '\n');
	}
	
	return Price;
}

void UI::Initialization()
{
	obj.Repo.Add_Drug("isofluran", 12.6, 456, 15.99);
	obj.Repo.Add_Drug("fentanil", 67.48, 123, 30.99);
	obj.Repo.Add_Drug("xenon", 45.86, 345, 99.99);
	obj.Repo.Add_Drug("articain", 23.45, 65, 23.99);
	obj.Repo.Add_Drug("diazepam", 45.43, 456, 56.99);

}

void UI::Interface()
{

	/*
		functie de meniu 
		se afiseaza pe ecran optiunile pe care utilizatorul le are si se citesc de la tastatura(unde se poate) valori
	*/

	UndoRedo undo_redo;
	undo_redo.Add_Undo(obj.Repo.Smile);
	bool ok=1;
	string Name,x;
	double n, Concentration, Price;
	int Amount;
	
	while (ok == 1)
	{
		system("cls");
		obj.Repo.Show_All();
		cout << endl;
		cout << "-------MENIU-------" << endl;
		cout << "1.Add drug" << endl;
		cout << "2.Deleate drug by name" << endl;
		cout << "3.Deleate drug by concentration" << endl;
		cout << "4.Change amount by name " << endl;
		cout << "5.Change amount by concentration" << endl;
		cout << "6.Change price by name" << endl;
		cout << "7.Change price by concentration" << endl;
		cout << "8.Display all drugs with a certain string" << endl;
		cout << "9.Display all drugs that their amount is lower them a certain number" << endl;
		cout << "10.Display all drugs price sorted" << endl;
		cout << "11.Undo the last change" << endl;
		cout << "12.Redo " << endl;
		cout << "Choose an option:";
		cin >> x;
		
		if (x == "1")
		{
			cout << "Name:";
			cin >> Name;
			cout << "Concentration:";
			Concentration = Get_Concentration();
			cout << "Amount:";
			Amount = Get_Amount();
			cout << "Price:";
			Price = Get_Price();
			obj.Repo.Add_Drug(Name, Concentration, Amount, Price);
		}
		else if (x == "2")
		{
			cout << "Type the name:";
			cin >> Name;
			if (obj.Repo.Remove_Drug_Name(Name) == 1)
			{
				obj.Repo.Remove_Drug_Name(Name);
			}
			else
			{
				cout << "That name does not exist" << endl;
			}
		}
		else if (x == "3")
		{
			cout << "Type the concentration:";
			n = Get_Concentration();
			if (obj.Repo.Remove_Drug_Concentration(n) == 1)
			{
				obj.Repo.Remove_Drug_Concentration(n);
			}
			else
			{
				cout << "That concentration is wrong" << endl;
			}
		}
		else if (x == "4")
		{
			cout << "Type the name:";
			cin >> Name;
			cout << "Amount:";
			Amount = Get_Amount();
			obj.Repo.Change_Amount_Name(Name,Amount);
		}
		else if (x == "5")
		{
			cout << "Type the concentration:";
			cin >> n;
			cout << "Amount:";
			Amount = Get_Amount();
			obj.Repo.Change_Amount_Concentration(n,Amount);
		}
		else if (x == "6")
		{
			cout << "Type the name:";
			cin >> Name;
			cout << "Price:";
			Price = Get_Price();
			obj.Repo.Change_Price_Name(Name,Price);
		}
		else if (x == "7")
		{
			cout << "Type the concentration:";
			cin >> n;
			cout << "Price:";
			Price = Get_Price();
			obj.Repo.Change_Price_Concentration(n,Price);
		}
		else if (x == "8")
		{
			cout << "Type the name or press enter to print all drug name-sorted:";
			cin.ignore();
			getline(cin, Name);
			transform(Name.begin(), Name.end(), Name.begin(), tolower);
			if (Name.size()==0)
				obj.Search_String_Empty();
			else
				obj.Search_String(Name);
		}
		else if (x == "9")
		{
			cout << "Amount:";
			Amount = Get_Amount();
			obj.Show_Amount(Amount);
		}
		else if (x == "10")
		{
			obj.Show_Sort_Price();
		}
		else if (x == "11")
		{
			if (undo_redo.undo_array.size() == 1)
				cout << "No undos possible" << endl;
			else
			{
				obj.Repo.Smile = undo_redo.Undo();
			}
		}
		else if (x == "12")
		{
			if(undo_redo.redo_array.size()==0)
				cout << "No redos possible" << endl;
			else
			{
				obj.Repo.Smile = undo_redo.Redo();
				undo_redo.redo_array.erase(undo_redo.redo_array.begin());
			}
		}
		else
		{
		cout << "Wrong option" << endl;
		}
		cout << "If you want to continue press 1 else 0 : " << endl;
		cin >> ok;
		//save the change in the undo array
		if ((int(x[0]) >= 49 && int(x[0]) <=55) || x=="12")
			undo_redo.Add_Undo(obj.Repo.Smile);
		//redo works only after a undo
		if (x != "11" && x != "12")
			undo_redo.redo_array.clear();
	}
}
