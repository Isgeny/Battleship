#pragma once
#include <string>
#include "freeglut.h"
#include "Ship.h"
#include "enums.h"

class ShipButton : public Ship
{
private:
	int shipPlaceCount;

public:
	ShipButton(int x, int y, int width, int height, bool visiable, bool pressed, void(*callbackFunc)(), int deckCount, const Orientation& orientation, bool alive, int areaX, int areaY, int areaWidth, int areaHeight, int shipPlaceCount);
	~ShipButton();
	void draw();
	void setShipPlaceCount(int shipPlaceCount);
	int getShipPlaceCount() const;
	void operator ++ (int);
	void operator -- (int);

};