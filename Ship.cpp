#include "Ship.h"

Ship::Ship(int x, int y, int width, int height, bool visiable, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state), int _deckCount, const Orientation& _orientation, bool _alive, int _areaX, int _areaY, int _areaWidth, int _areaHeight) :
	GraphicsRectItem(x, y, width, height, visiable, clicked, callbackClickedFunc), deckCount(_deckCount), orientation(_orientation), alive(_alive), areaX(_areaX), areaY(_areaY), areaWidth(_areaWidth), areaHeight(_areaHeight)
{
	//this->updateParts();
}

Ship::Ship(Ship* mouseShip)
{
	x = mouseShip->x;
	y = mouseShip->y;
	width = mouseShip->width;
	height = mouseShip->height;
	visiable = mouseShip->visiable;
	clicked = mouseShip->clicked;
	callbackClickedFunc = mouseShip->callbackClickedFunc;
	deckCount = mouseShip->deckCount;
	orientation = mouseShip->orientation;
	alive = mouseShip->alive;
	areaX = mouseShip->areaX;
	areaY = mouseShip->areaY;
	areaWidth = mouseShip->areaWidth;
	areaHeight = mouseShip->areaHeight;
	parts = mouseShip->parts;
}

Ship::~Ship()
{
	for(auto it = parts.begin(); it != parts.end(); it++)
		delete (*it);
	parts.erase(parts.begin(), parts.end());
}

void Ship::draw()
{
	if(visiable)
	{
		GraphicsRectItem::draw();
	}
	for(int i = 0; i < parts.size(); i++)
		parts[i]->draw();
}

void Ship::setDeckCount(int aDeckCount)
{
	deckCount = aDeckCount;
}

void Ship::setOrientation(const Orientation& aOrientation)
{
	orientation = aOrientation;
}

void Ship::setVisiable(bool aVisiable)
{
	visiable = aVisiable;
}

void Ship::setArea(int aAreaX, int aAreaY, int aAreaWidth, int aAreaHeight)
{
	areaX = aAreaX; areaY = aAreaY; areaWidth = aAreaWidth; areaHeight = aAreaHeight;
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

std::vector<ShipPart*>& Ship::getParts()
{
	return parts;
}

bool Ship::mouseOnShipArea(int mX, int mY)
{
	return (mX > areaX && mX < areaX + areaWidth && mY > areaY && mY < areaY + areaHeight);
}

void Ship::updateParts()
{
	for(int i = 0; i < deckCount; i++)
	{
		parts.push_back(new ShipPart(0, 0, 0, 0, true, false, NULL, true));
		if(orientation == HORIZONTAL)
		{
			parts[i]->setX(x + i*CELL_SZ);
			parts[i]->setY(y);
		} else
		{
			parts[i]->setX(x);
			parts[i]->setY(y + i*CELL_SZ);
		}
		parts[i]->setWidth(CELL_SZ);
		parts[i]->setHeight(CELL_SZ);
	}
}

bool Ship::allPartsKilled() const
{
	for(auto it = parts.begin(); it != parts.end(); it++)
	{
		if((*it)->getAlive())
			return false;
	}
	return true;
}