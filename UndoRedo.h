#ifndef UNDOREDO_H
#define UNDOREDO_H
#include "DrugStore.h"
#include "Repository.h"
#include <vector>

class UndoRedo
{
public:
	std::vector<std::vector<DrugStore>> undo_array;
	std::vector<std::vector<DrugStore>> redo_array;
	void Add_Undo(std::vector<DrugStore> v);
	void Add_Redo(std::vector<DrugStore> v);
	std::vector<DrugStore> Undo();
	std::vector<DrugStore> Redo();
};
#endif
