#pragma once
#include "GraphicsItem.h"
#include "Label.h"
#include "Ship.h"
#include "Dot.h"
#include "Cross.h"
#include "enums.h"

class Field : public GraphicsItem
{
private:
	int aliveShipsCount;
	int randoming;

public:
	Field();
	Field(int aliveShipsCount, const Rect& rect, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	~Field();
	void draw();
	void mousePressed(int button, int state, int mouseX, int mouseY);
	void setAliveShipsCount(int aliveShipsCount);
	int getAliveShipsCount() const;
	void operator++(int);
	void operator--(int);
	bool availableToPlaceShip(std::vector<Ship*>& ships, Ship* mouseShip);
	bool availableToPlaceDot(int mX, int mY, std::vector<Ship*>& ships, std::vector<Dot*>& dots);
	bool availableToPlaceCross(int mX, int mY, std::vector<Cross*>& crosses);
	void setRandomShips(std::vector<Ship*>& ships);
	void hideShips(std::vector<Ship*>& ships);
	void placeDotsAroundShip(Ship* killedShip, std::vector<Ship*>& ships, std::vector<Dot*>& dots);
	
};