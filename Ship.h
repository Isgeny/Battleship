#pragma once
#include <vector>
#include "GraphicsRectItem.h"
#include "ShipPart.h"

class Ship : public GraphicsRectItem
{
protected:
	int deckCount;
	Orientation orientation;
	bool alive;

private:
	int areaX, areaY, areaWidth, areaHeight;
	std::vector<ShipPart*> parts;

public:
	Ship(int x, int y, int width, int height, bool visible, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state), int deckCount, const Orientation& orientation, bool alive, int areaX, int areaY, int areaWidth, int areaHeight);
	~Ship();
	void draw();
	void setDeckCount(int deckCount);
	void setOrientation(const Orientation& orientation);
	void setVisible(bool visible);
	void setArea(int areaX, int areaY, int areaWidth, int areaHeight);
	void setAlive(bool alive);
	int getDeckCount() const;
	const Orientation& getOrientation() const;
	bool isVisible() const;
	int getAreaX() const;
	int getAreaY() const;
	int getAreaWidth() const;
	int getAreaHeight() const;
	bool getAlive() const;
	std::vector<ShipPart*>& getParts();
	bool mouseOnShipArea(int mX, int mY);
	void updateParts();
	bool allPartsKilled() const;
	
};