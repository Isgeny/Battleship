#include "GraphicsRectItem.h"

GraphicsRectItem::GraphicsRectItem(int aX, int aY, int aWidth, int aHeight) :
	x(aX), y(aY), width(aWidth), height(aHeight)
{

}

GraphicsRectItem::~GraphicsRectItem()
{

}

void GraphicsRectItem::draw()
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

void GraphicsRectItem::setX(int aX)
{
	x = aX;
}

void GraphicsRectItem::setY(int aY)
{
	y = aY;
}

void GraphicsRectItem::setWidth(int aWidth)
{
	width = aWidth;
}

void GraphicsRectItem::setHeight(int aHeight)
{
	height = aHeight;
}

int GraphicsRectItem::getX() const
{
	return x;
}

int GraphicsRectItem::getY() const
{
	return y;
}

int GraphicsRectItem::getWidth() const
{
	return width;
}

int GraphicsRectItem::getHeight() const
{
	return height;
}

bool GraphicsRectItem::mouseOnItem(int mX, int mY)
{
	return (mX > x && mX < x + width && mY > y && mY < y + height);
}