#pragma once
#include <vector>
#include "GraphicsRectItem.h"
#include "enums.h"

class Ship : public GraphicsRectItem
{
protected:
	int deckCount;
	bool visiable;
	Orientation orientation;
	int areaX, areaY, areaWidth, areaHeight;
	bool alive;
	std::vector<GraphicsRectItem*> parts;

public:
	Ship();
	Ship(int x, int y, int width, int height, int countDeck, const Orientation& orientation, bool visiable, bool alive = true);
	Ship(Ship* obj);
	~Ship();
	void draw();
	void setDeckCount(int deckCount);
	void setOrientation(const Orientation& orientation);
	void setVisiable(bool visiable);
	void setArea(int areaX, int areaY);
	void setAlive(bool alive);
	int getDeckCount() const;
	const Orientation& getOrientation() const;
	bool isVisiable() const;
	int getAreaX() const;
	int getAreaY() const;
	int getAreaWidth() const;
	int getAreaHeight() const;
	bool getAlive() const;
	std::vector<GraphicsRectItem*>& getParts();
	bool mouseOnShipArea(int mX, int mY);
	
};