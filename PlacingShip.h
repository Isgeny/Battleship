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
	PlacingShip();
	PlacingShip(int x, int y, int weight, int height, int deckCount, const Orientation& orientation, bool visiable, int shipPlaceCount);
	~PlacingShip();
	void draw();
	void setPressed(bool state);
	void setShipPlaceCount(int count);
	bool isPressed() const;
	int getShipPlaceCount() const;
	void operator ++ (int);
	void operator -- (int);

};

