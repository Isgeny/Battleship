#include "GraphicsItem.h"

GraphicsItem::GraphicsItem() : 
	rect(Rect()), r(1.0), g(1.0), b(1.0), a(0.0), visible(false), callbackClicked(NULL)
{

}

GraphicsItem::GraphicsItem(const Rect& _rect, double _r, double _g, double _b, double _a, bool _visible, CallbackClicked _callbackClicked) :
	rect(_rect), r(_r), g(_g), b(_b), a(_a), visible(_visible), callbackClicked(_callbackClicked)
{

}

GraphicsItem::~GraphicsItem()
{

}

void GraphicsItem::drawRect()
{
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glColor4d(r, g, b, a);
	glVertex2d(rect.x() + rect.width(), rect.y() + rect.height());
	glVertex2d(rect.x() + rect.width(), rect.y());
	glVertex2d(rect.x(), rect.y());
	glVertex2d(rect.x(), rect.y() + rect.height());
	glEnd();
}

void GraphicsItem::mousePressed(int button, int state, int mouseX, int mouseY)
{
	if(contains(mouseX, mouseY) && visible && callbackClicked)
	{
		callbackClicked(this, button, state, mouseX, mouseY);
	}
}

void GraphicsItem::setRect(const Rect& _rect)
{
	rect = _rect;
}

void GraphicsItem::setRect(int x, int y, int width, int height)
{
	rect.setX(x);
	rect.setY(y);
	rect.setWidth(width);
	rect.setHeight(height);
}

void GraphicsItem::setRGBA(double _r, double _g, double _b, double _a)
{
	r = _r; g = _g; b = _b; a = _a;
}

void GraphicsItem::setAlpha(double alpha)
{
	a = alpha;
}

void GraphicsItem::setVisible(bool _visible)
{
	visible = _visible;
}

void GraphicsItem::setCallbackClicked(CallbackClicked _callbackClicked)
{
	callbackClicked = _callbackClicked;
}

Rect& GraphicsItem::getRect()
{
	return rect;
}

double GraphicsItem::getR() const
{
	return r;
}

double GraphicsItem::getG() const
{
	return g;
}

double GraphicsItem::getB() const
{
	return b;
}

double GraphicsItem::getA() const
{
	return a;
}

bool GraphicsItem::isVisible() const
{
	return visible;
}

bool GraphicsItem::contains(int mouseX, int mouseY)
{
	return (mouseX > rect.x() && mouseX < rect.x() + rect.width() && mouseY > rect.y() && mouseY < rect.y() + rect.height());
}