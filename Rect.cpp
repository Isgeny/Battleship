#include "Rect.h"
Rect::Rect() : rX(0), rY(0), rWidth(0), rHeight(0)
{

}

Rect::Rect(int x, int y, int width, int height) :
	rX(x), rY(y), rWidth(width), rHeight(height)
{

}

Rect::~Rect()
{

}

void Rect::setX(int x)
{
	rX = x;
}

void Rect::setY(int y)
{
	rY = y;
}

void Rect::setWidth(int width)
{
	rWidth = width;
}

void Rect::setHeight(int height)
{
	rHeight = height;
}

int Rect::x() const
{
	return rX;
}

int Rect::y() const
{
	return rY;
}

int Rect::width() const
{
	return rWidth;
}

int Rect::height() const
{
	return rHeight;
}