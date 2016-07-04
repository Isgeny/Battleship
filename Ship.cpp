#include "Ship.h"

Ship::Ship() : GraphicsItem(), deck(0)
{
	x = -1000;
	y = -1000;
}

Ship::Ship(int x, int y, int width, int height, int countDeck, MyPoint pos) :
	GraphicsItem(x, y , width, height), deck(countDeck), pos(pos)
{

}

Ship::~Ship()
{

}

void Ship::draw()
{
	GraphicsItem::draw();
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
