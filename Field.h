#pragma once
#include <vector>
#include <string>
#include <time.h>
#include "GraphicsItem.h"
#include "Ship.h"
#include "enums.h"

class Field : public GraphicsItem
{
private:
	int countOfPlacedShips;
	std::vector<Ship* > ships;

public:
	Field();
	Field(int x, int y, int weight, int height, int countPl = 0);
	~Field();
	void setShip(GameStatus status, int x, int y, int weight, int height, int deck, MyPoint pos);
	void setRandomShips();
	void makeHit(MyPoint pos, GameStatus status);
	std::vector<Ship* >& getAllShips();
	void draw();
	bool availableToPlaceShip(int mX, int mY, int mW, int mH, int mDeck);
	void cleanField();
	int getCountOfPlacedShips() const;
	void setCountOfPlacedShips(int count);
	void incCountOfPlacedShips();
	void decCountOfPlacedShips();
	MyPoint coordTransform(int mX, int mY);
};