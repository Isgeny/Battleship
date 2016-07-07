#include "Ship.h"

Ship::Ship() : GraphicsRectItem(), deckCount(0), orientation(HORIZONTAL), visiable(true), areaX(0), areaY(0), areaWidth(0), areaHeight(0)
{
	x = -1000;
	y = -1000;
}

Ship::Ship(int aX, int aY, int aWidth, int aHeight, int aCountDeck, const Orientation& aOrientation, bool aVisiable, bool aAlive) :
	GraphicsRectItem(aX, aY, aWidth, aHeight), deckCount(aCountDeck), orientation(aOrientation), visiable(aVisiable), alive(aAlive)
{
	areaX = x - CELL_SZ;
	areaY = y - CELL_SZ;
	areaWidth = width + 2 * CELL_SZ;
	areaHeight = height + 2 * CELL_SZ;
	for(int i = 0; i < deckCount; i++)
	{

	}
}

Ship::Ship(Ship* obj)
{
	x = obj->x; y = obj->y; width = obj->width; height = obj->height;
	deckCount = obj->deckCount;
	visiable = obj->visiable;
	orientation = obj->orientation;
	areaX = obj->areaX; areaY = obj->areaY; areaWidth = obj->areaWidth; areaHeight = obj->areaHeight;
}

Ship::~Ship()
{

}

void Ship::draw()
{
	if(visiable)
	{
		GraphicsRectItem::draw();
	}
}

void Ship::setDeckCount(int aDeckCount)
{
	deckCount = aDeckCount;
}

void Ship::setOrientation(const Orientation & aOrientation)
{
	orientation = aOrientation;
}

void Ship::setVisiable(bool aVisiable)
{
	visiable = aVisiable;
}

void Ship::setArea(int aX, int aY)
{
	areaX = aX - CELL_SZ;
	areaY = aY - CELL_SZ;
	areaWidth = width + 2 * CELL_SZ;
	areaHeight = height + 2 * CELL_SZ;
}

void Ship::setAlive(bool aAlive)
{
	alive = aAlive;
}

int Ship::getDeckCount() const
{
	return deckCount;
}

const Orientation & Ship::getOrientation() const
{
	return orientation;
}

bool Ship::isVisiable() const
{
	return visiable;
}

int Ship::getAreaX() const
{
	return areaX;
}

int Ship::getAreaY() const
{
	return areaY;
}

int Ship::getAreaWidth() const
{
	return areaWidth;
}

int Ship::getAreaHeight() const
{
	return areaHeight;
}

bool Ship::getAlive() const
{
	return alive;
}

std::vector<GraphicsRectItem*>& Ship::getParts()
{
	return parts;
}

bool Ship::mouseOnShipArea(int mX, int mY)
{
	return (mX > areaX && mX < areaX + areaWidth && mY > areaY && mY < areaY + areaHeight);
}