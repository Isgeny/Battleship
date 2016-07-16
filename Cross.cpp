#include "Cross.h"

Cross::Cross() : GraphicsItem()
{

}

Cross::Cross(const Rect& rect, double r, double g, double b, double a, bool visible) :
	GraphicsItem(rect, r, g, b, a, visible)
{

}

Cross::~Cross()
{

}

void Cross::draw()
{
	if(visible)
	{
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