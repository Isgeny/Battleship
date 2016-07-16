#pragma once
#include "GraphicsItem.h"
#include "enums.h"
class Ship : public GraphicsItem
{
protected:
	int decks, healths;
	Orientation orientation;

private:
	Rect areaRect;

public:
	Ship();
	Ship(int decks, const Rect& areaRect, const Rect& rect, double r = 1.0, double g = 1.0, double b = 1.0, double a = 1.0, bool visible = false, CallbackClicked callbackClicked = NULL, const Orientation& orientation = HORIZONTAL);
	~Ship();
	void draw();
	void mousePressed(int button, int state, int mouseX, int mouseY);
	void setDecks(int decks);
	void setHealths(int healths);
	void setOrientation(const Orientation& orientation);
	void setAreaRect(int areaX, int areaY, int areaWidth, int areaHeight);
	void setAreaRect(const Rect& rect);
	int getDecks() const;
	int getHealths() const;
	const Orientation& getOrientation() const;
	const Rect& getAreaRect() const;
	bool mouseOnShipArea(int mouseX, int mouseY);
	void operator -- (int);
	
};