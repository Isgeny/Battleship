#pragma once
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
	ShipButton(int ships, int decks, const Rect& areaRect, const Rect& rect, bool focus = false, const Orientation& orientation = HORIZONTAL, CallbackClicked callbackClicked = nullptr, bool visible = false, double r = 0.0, double g = 0.0, double b = 1.0, double a = 1.0);
	~ShipButton();
	void draw();
	void mousePressed(int button, int state, int x, int y);
	void setVisible(bool visible);
	void setShips(int ships);
	void setFocus(bool focus);
	int getShips() const;
	bool hasFocus() const;
	void operator ++ (int);
	void operator -- (int);

};