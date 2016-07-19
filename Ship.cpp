#include "Ship.h"

Ship::Ship() : decks(0), healths(0), orientation(HORIZONTAL), areaRect(Rect()), GraphicsItem()
{

}

Ship::Ship(int _decks, const Rect& _areaRect, const Rect& rect, const Orientation& _orientation, CallbackClicked callbackClicked, bool visible, double r, double g, double b, double a) :
	decks(_decks), healths(_decks), orientation(_orientation), areaRect(_areaRect), GraphicsItem(rect, callbackClicked, visible, r, g, b, a)
{

}

Ship::~Ship()
{

}

void Ship::draw()
{
	if(visible)
		drawRect();
}

void Ship::mousePressed(int button, int state, int mouseX, int mouseY)
{
	if(mouseX % CELL_SZ != 0 && mouseY % CELL_SZ != 0)
		GraphicsItem::mousePressed(button, state, mouseX, mouseY);
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