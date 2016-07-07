#pragma once
#include <vector>
#include <string>
#include "GraphicsRectItem.h"
#include "Ship.h"
#include "Dot.h"

class Field : public GraphicsRectItem
{
private:
	int placedShipsCount;
	std::vector<Ship*> ships;
	std::vector<Dot*> dots;

public:
	Field(int x, int y, int weight, int height, int placedShipsCount);
	~Field();
	void draw();
	void setPlacedShipsCount(int placedShipsCount);
	int getPlacedShipsCount() const;
	std::vector<Ship*>& getShips();
	std::vector<Dot*>& getDots();
	bool availableToPlaceShip(int x, int y, int deckCount, const Orientation& orientation);
	bool availableToMakeHit(int mX, int mY);
	void setShip(int x, int y, int width, int height, int deckCount, const Orientation& orientation, int areaX, int areaY, int areaWidth, int areaHeight);
	void cleanField();
	void operator++(int);
	void operator--(int);
	void setRandomShips();
	void hideShips();
	void makeHit(int mX, int mY);
	
};