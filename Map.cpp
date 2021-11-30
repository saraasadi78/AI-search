#include "Map.h"

Map::Map() {}

Map::Map(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	std::vector<Base_Entity *> temp(rows * cols);
	game = temp;
}

void Map::Add(int i, int j, Base_Entity *entity)
{
	game[(i * cols) + j] = entity;
}

void Map::Print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << at(i, j)->name << " ";
		}
		cout << endl;
	}
}

Map Map::Copy()
{
	Map result(this->rows, this->cols);
	for (int i = 0; i < rows * cols; i++)
	{
		result.game[i] = this->game[i]->Copy();
	}
	return result;
}

Base_Entity* Map::at(int i, int j)
{
	return game[(i * cols) + j];
}