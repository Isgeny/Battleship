#include "Ship.h"

Ship::Ship() : GraphicsItem(), deck(0), orientation(HORIZONTAL)
{
	x = -1000;
	y = -1000;
}

Ship::Ship(int x, int y, int width, int height, int countDeck) :
	GraphicsItem(x, y , width, height), deck(countDeck), orientation(HORIZONTAL)
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

ShipOrientation Ship::getOrientation() const
{
	return orientation;
}

void Ship::setOrientation(ShipOrientation orient)
{
	orientation = orient;
}
