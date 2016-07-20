#include "GraphicsItem.h"

GraphicsItem::GraphicsItem() : rect(Rect()), callbackClicked(nullptr), visible(false), r(0.0), g(0.0), b(1.0), a(1.0)
{

}

GraphicsItem::GraphicsItem(const Rect& _rect, CallbackClicked _callbackClicked, bool _visible, double _r, double _g, double _b, double _a) :
	rect(_rect), callbackClicked(_callbackClicked), visible(_visible), r(_r), g(_g), b(_b), a(_a)
{

}

GraphicsItem::~GraphicsItem()
{

}

void GraphicsItem::mousePressed(int button, int state, int mouseX, int mouseY)
{
	if(contains(mouseX, mouseY) && callbackClicked)
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

void GraphicsItem::setR(double _r)
{
	r = _r;
}

void GraphicsItem::setG(double _g)
{
	g = _g;
}

void GraphicsItem::setB(double _b)
{
	b = _b;
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

void GraphicsItem::drawRect()
{
	//Отрисовка прямоугольника
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glColor4d(r, g, b, a);
	glVertex2d(rect.x() + rect.width(), rect.y() + rect.height());
	glVertex2d(rect.x() + rect.width(), rect.y());
	glVertex2d(rect.x(), rect.y());
	glVertex2d(rect.x(), rect.y() + rect.height());
	glEnd();
}

bool GraphicsItem::contains(int mouseX, int mouseY)
{
	//Проверяет координаты нажатия мыши по элементу
	return (mouseX > rect.x() && mouseX < rect.x() + rect.width() && mouseY > rect.y() && mouseY < rect.y() + rect.height());
}