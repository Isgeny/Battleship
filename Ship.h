#pragma once
#include "GraphicsRectItem.h"
#include "enums.h"

class Ship : public GraphicsRectItem
{
protected:
	int deckCount;
	bool visiable;
	Orientation orientation;
	int areaX, areaY, areaWidth, areaHeight;

public:
	Ship();
	Ship(int x, int y, int width, int height, int countDeck, const Orientation& orientation, bool visiable);
	Ship(Ship* obj);
	~Ship();
	void draw();
	void setDeckCount(int deckCount);
	void setOrientation(const Orientation& orientation);
	void setVisiable(bool state);
	void setArea(int aX, int aY);
	int getDeckCount() const;
	const Orientation& getOrientation() const;
	bool isVisiable() const;
	int getAreaX() const;
	int getAreaY() const;
	int getAreaWidth() const;
	int getAreaHeight() const;
	bool mouseOnShipArea(int mX, int mY);
	
};