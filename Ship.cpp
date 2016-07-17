#include "Ship.h"
Ship::Ship() : decks(0), orientation(HORIZONTAL), GraphicsItem()
{

}

Ship::Ship(int _decks, const Rect& _areaRect, const Rect& rect, double r, double g, double b, double a, bool visible, CallbackClicked callbackClicked, const Orientation& _orientation) :
	decks(_decks), orientation(_orientation), areaRect(_areaRect), GraphicsItem(rect, r, g, b, a, visible, callbackClicked)
{

}

Ship::~Ship()
{

}

void Ship::draw()
{
	if(visible)
	{
		drawRect();
	}
}

void Ship::mousePressed(int button, int state, int mouseX, int mouseY)
{
	if(mouseX % CELL_SZ != 0 && mouseY % CELL_SZ != 0)
	{
		GraphicsItem::mousePressed(button, state, mouseX, mouseY);
	}
}

void Ship::setDecks(int _decks)
{
	decks = _decks;
}

void Ship::setHealths(int _healths)
{
	healths = _healths;
}

void Ship::setOrientation(const Orientation& _orientation)
{
	orientation = _orientation;
}

void Ship::setAreaRect(int areaX, int areaY, int areaWidth, int areaHeight)
{
	areaRect.setX(areaX);
	areaRect.setY(areaY);
	areaRect.setWidth(areaWidth);
	areaRect.setHeight(areaHeight);
}

void Ship::setAreaRect(const Rect& _rect)
{
	rect = _rect;
}

int Ship::getDecks() const
{
	return decks;
}

int Ship::getHealths() const
{
	return healths;
}

const Orientation& Ship::getOrientation() const
{
	return orientation;
}

const Rect& Ship::getAreaRect() const
{
	return rect;
}

bool Ship::mouseOnShipArea(int mouseX, int mouseY)
{
	return (mouseX > areaRect.x() && mouseX < areaRect.x() + areaRect.width() && mouseY > areaRect.y() && mouseY < areaRect.y() + areaRect.height());
}

void Ship::operator -- (int)
{
	if(healths)
		healths--;
}




































/*bool Ship::allPartsKilled() const
{
	for(auto it = parts.begin(); it != parts.end(); it++)
	{
		if((*it)->getAlive())
			return false;
	}
	return true;
}

void Ship::updateParts()
{
for(int i = 0; i < decks; i++)
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
}*/