#pragma once
#include <vector>
#include <string>
#include "GraphicsItem.h"
#include "Ship.h"
#include "enums.h"

class Field : public GraphicsItem
{
private:
	std::vector<Ship* > ships;
	int sShips = 4, dShips = 3, tShips = 2, qShips = 1;

public:
	Field();
	Field(int x, int y, int weight, int height);
	~Field();
	void setShip(GameStatus status, int x, int y, int weight, int height, int deck, MyPoint pos);
	void makeHit(MyPoint pos, GameStatus status);
	std::vector<Ship* >& getAllShips();
	void draw();
};