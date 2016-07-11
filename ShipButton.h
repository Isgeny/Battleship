#pragma once
#include <string>
#include "freeglut.h"
#include "Ship.h"
#include "enums.h"

class ShipButton : public Ship
{
private:
	int shipPlaceCount;
	bool pressed;

public:
	ShipButton(int x, int y, int width, int height, bool visible, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state), int deckCount, const Orientation& orientation, bool alive, int areaX, int areaY, int areaWidth, int areaHeight, int shipPlaceCount, bool pressed = false);
	~ShipButton();
	void draw();
	void setShipPlaceCount(int shipPlaceCount);
	void setPressed(bool pressed);
	int getShipPlaceCount() const;
	bool isPressed() const;
	void operator ++ (int);
	void operator -- (int);

};