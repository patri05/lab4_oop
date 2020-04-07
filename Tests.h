#ifndef TESTS_H
#define TESTS_H
#include "Tests.h"
#include "DrugStore.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include "UndoRedo.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tests
{
public:
	Controller DrugsTest;
	UndoRedo undo_redo;
	void Test();
};
#endif 
