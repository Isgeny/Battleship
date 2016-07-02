#pragma once
#include "GraphicsItem.h"
#include "enums.h"
class Ship : public GraphicsItem
{
protected:
	int deck;

public:
	Ship();
	Ship(int x, int y, int width, int height, int countDeck);
	~Ship();
	void draw();
	int getDeckCount() const;
};