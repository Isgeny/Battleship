#include "Ship.h"

Ship::Ship() : GraphicsItem(), deck(0)
{

}

Ship::Ship(int x, int y, int width, int height, int countDeck) :
	GraphicsItem(x, y , width, height), deck(countDeck)
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
