#pragma once
#include "GraphicsItem.h"
#include "enums.h"
class Ship : public GraphicsItem
{
protected:
	int deck;
	MyPoint pos;

public:
	Ship();
	Ship(int x, int y, int width, int height, int countDeck, MyPoint pos = MyPoint());
	~Ship();
	void draw();
	int getDeckCount() const;
	void setDeckCount(int deckCount);
	MyPoint getPos() const;
	void setPos(MyPoint position);

};