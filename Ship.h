#pragma once
#include "GraphicsItem.h"
#include "enums.h"

class Ship : public GraphicsItem
{
protected:
	int deck;
	MyPoint pos;
	bool visiable;

public:
	Ship();
	Ship(int x, int y, int width, int height, int countDeck, MyPoint pos = MyPoint(), bool vis = true);
	~Ship();
	void draw();
	int getDeckCount() const;
	void setDeckCount(int deckCount);
	MyPoint getPos() const;
	void setPos(MyPoint position);
	bool isVisiable() const;
	void setVisiable(bool state);
	

};