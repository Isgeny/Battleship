#pragma once
#include "Ship.h"
#include "freeglut.h"
#include <string>
#include "enums.h"

class PlacingShip : public Ship
{
private:
	bool pressed;

public:
	PlacingShip();
	PlacingShip(int x, int y, int weight, int height, int deck);
	~PlacingShip();
	void draw();
	bool mouseOnPlacingShip(int mX, int mY);
	bool isPressed() const;
	void setPressed(bool state);

};

