#pragma once
#include <string>
#include "freeglut.h"
#include "Ship.h"
#include "enums.h"

class PlacingShip : public Ship
{
private:
	bool pressed;
	int shipPlaceCount;

public:
	PlacingShip(int x, int y, int weight, int height, int deckCount, const Orientation& orientation, bool visiable, bool alive, int areaX, int areaY, int areaWidth, int areaHeight, bool pressed, int shipPlaceCount);
	~PlacingShip();
	void draw();
	void setPressed(bool pressed);
	void setShipPlaceCount(int shipPlaceCount);
	bool isPressed() const;
	int getShipPlaceCount() const;
	void operator ++ (int);
	void operator -- (int);

};