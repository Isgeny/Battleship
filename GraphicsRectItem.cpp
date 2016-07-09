#include "GraphicsRectItem.h"

GraphicsRectItem::GraphicsRectItem() : 
	x(0), y(0), width(0), height(0), visiable(false), pressed(false), callbackFunc(NULL)
{

}

GraphicsRectItem::GraphicsRectItem(int _x, int _y, int _width, int _height, bool _visiable, bool _pressed, void(*_callbackFunc)()) :
	x(_x), y(_y), width(_width), height(_height), visiable(_visiable), pressed(_pressed), callbackFunc(_callbackFunc)
{

}

GraphicsRectItem::~GraphicsRectItem()
{

}

void GraphicsRectItem::draw()
{
	if(visiable)
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

void GraphicsRectItem::setVisiable(bool _visiable)
{
	visiable = _visiable;
}

void GraphicsRectItem::setPressed(bool _pressed)
{
	pressed = _pressed;
	if(pressed)
		callbackFunc();
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

bool GraphicsRectItem::isVisiable() const
{
	return visiable;
}

bool GraphicsRectItem::isPressed() const
{
	return pressed;
}

bool GraphicsRectItem::mouseOnItem(int mX, int mY)
{
	return (mX > x && mX < x + width && mY > y && mY < y + height);
}