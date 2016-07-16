#pragma once
#include "freeglut.h"
#include "Ship.h"
#include "Label.h"
#include "enums.h"

class ShipButton : public Ship
{
private:
	int ships;
	bool focus;
	Label* textShipsCount;

public:
	ShipButton();
	ShipButton(int ships, int decks, const Rect& rect, double r = 1.0, double g = 1.0, double b = 1.0, double a = 1.0, bool visible = false, CallbackClicked callbackClicked = NULL, const Orientation& orientation = HORIZONTAL, bool alive = true, bool focus = false);
	~ShipButton();
	void draw();
	void mousePressed(int button, int state, int mouseX, int mouseY);
	void setShips(int ships);
	void setFocus(bool focus);
	int getShips() const;
	bool hasFocus() const;
	void operator ++ (int);
	void operator -- (int);

};