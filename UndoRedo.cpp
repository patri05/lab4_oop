#include "UndoRedo.h"

void UndoRedo::Add_Undo(std::vector<DrugStore> v)
{
	undo_array.push_back(v);
}

void UndoRedo::Add_Redo(std::vector<DrugStore> v)
{
	redo_array.push_back(v);
}

std::vector<DrugStore> UndoRedo::Undo()
{
	Add_Redo(undo_array[undo_array.size() - 1]);
	undo_array.erase(undo_array.begin() + undo_array.size() - 1);
	return undo_array[undo_array.size() - 1];
}

std::vector<DrugStore> UndoRedo::Redo()
{
	return redo_array[0];
}
