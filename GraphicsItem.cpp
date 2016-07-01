#include "GraphicsItem.h"

GraphicsItem::GraphicsItem() : 
	x(0), y(0), width(0), height(0)
{

}

GraphicsItem::GraphicsItem(int _x, int _y, int _width, int _height) :
	x(_x), y(_y), width(_width), height(_height)
{

}

GraphicsItem::~GraphicsItem()
{

}

void GraphicsItem::draw()
{
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glColor3d(0.0, 0.0, 1.0);
	glVertex2d(x + width, y + height);
	glVertex2d(x + width, y);
	glVertex2d(x, y);
	glVertex2d(x, y + height);
	glEnd();
}

int GraphicsItem::getX() const
{
	return x;
}

int GraphicsItem::getY() const
{
	return y;
}

int GraphicsItem::getWith() const
{
	return width;
}

int GraphicsItem::getHeight() const
{
	return height;
}

void GraphicsItem::setX(int _x)
{
	x = _x;
}

void GraphicsItem::setY(int _y)
{
	y = _y;
}

void GraphicsItem::setWidth(int _width)
{
	width = _width;
}

void GraphicsItem::setHeight(int _height)
{
	height = _height;
}