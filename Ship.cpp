#include "Ship.h"

Ship::Ship() : GraphicsItem(), deck(0), visiable(true)
{
	x = -1000;
	y = -1000;
}

Ship::Ship(int x, int y, int width, int height, int countDeck, MyPoint pos, bool vis) :
	GraphicsItem(x, y , width, height), deck(countDeck), pos(pos), visiable(vis)
{

}

Ship::~Ship()
{

}

void Ship::draw()
{
	if(visiable)
	{
		GraphicsItem::draw();
	}
}

int Ship::getDeckCount() const
{
	return deck;
}

void Ship::setDeckCount(int deckCount)
{
	deck = deckCount;
}

MyPoint Ship::getPos() const
{
	return pos;
}

void Ship::setPos(MyPoint position)
{
	pos = position;
}

bool Ship::isVisiable() const
{
	return visiable;
}

void Ship::setVisiable(bool state)
{
	visiable = state;
}