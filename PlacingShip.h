#pragma once
#include "Ship.h"
#include "freeglut.h"
#include <string>
#include "enums.h"

class PlacingShip : public Ship
{
private:
	bool pressed;
	int shipPlaceCount;

public:
	PlacingShip();
	PlacingShip(int x, int y, int weight, int height, int deck, int count);
	~PlacingShip();
	void draw();
	bool isPressed() const;
	void setPressed(bool state);
	int getAvailableShipPlaceCount() const;
	void setShipPlaceCount(int count);
	void incShipCount();
	void decShipCount();

};

