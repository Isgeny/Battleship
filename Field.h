#pragma once
#include <vector>
#include "GraphicsItem.h"
#include "enums.h"

class Field : public GraphicsItem
{
private:
	std::vector<std::vector<Cell>> field;
public:
	Field();
	Field(int x, int y, int weight, int height);
	~Field();
	std::vector<std::vector<Cell>>& getField();
	void setShip(MyPoint pos, GameStatus status);
	void makeHit(MyPoint pos, GameStatus status);
	void draw();
};