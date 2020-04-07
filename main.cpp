#include "DrugStore.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	UI obj;
	Tests test;
	
	test.Test();
	obj.Initialization(); obj.Interface();
	
	return 0;
}