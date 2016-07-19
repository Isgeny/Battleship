#include "Cross.h"

Cross::Cross() : GraphicsItem()
{

}

Cross::Cross(const Rect& rect, CallbackClicked callbackClicked, bool visible, double r, double g, double b, double a) :
	GraphicsItem(rect, callbackClicked, visible, r, g, b, a)
{

}

Cross::~Cross()
{

}

void Cross::draw()
{
	if(visible)
	{
		//Рисование креста
		glColor4d(r, g, b, a);
		glLineWidth(4);
		glBegin(GL_LINES);
		glVertex2d(rect.x(), rect.y());
		glVertex2d(rect.x() + rect.width(), rect.y() + rect.height());
		glVertex2d(rect.x() + rect.width(), rect.y());
		glVertex2d(rect.x(), rect.y() + rect.height());
		glEnd();
	}
}