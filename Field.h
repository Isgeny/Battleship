#pragma once
#include <vector>
#include <string>
#include <time.h>
#include "GraphicsRectItem.h"
#include "Ship.h"
#include "enums.h"

class Field : public GraphicsRectItem
{
private:
	int placedShipsCount;
	std::vector<Ship* > ships;

public:
	Field();
	Field(int x, int y, int weight, int height, int placedShipsCount = 0);
	~Field();
	void draw();
	void setPlacedShipsCount(int placedShipsCount);
	int getPlacedShipsCount() const;
	std::vector<Ship* >& getShips();
	bool availableToPlaceShip(Ship* mouseShip);
	void setShip(Ship* mouseShip);
	void cleanField();
	void operator++(int);
	void operator--(int);
	void setRandomShips();
	void makeHit(int mX, int mY);
	
};