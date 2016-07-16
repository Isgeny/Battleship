#include "Dot.h"

Dot::Dot() : radius(0), GraphicsItem()
{

}

Dot::Dot(int _radius, const Rect& rect, double r, double g, double b, double a, bool visible) :
	radius(_radius), GraphicsItem(rect, r, g, b, a, visible)
{
	//radius = 40;
}

Dot::~Dot()
{

}

void Dot::draw()
{
	double tmpPoint;
	int newX = rect.x() + CELL_SZ/2, newY = rect.y() + CELL_SZ/2;
	glColor4d(r, g, b, a);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(newX, newY);
	for(int i = 0; i <= 10; i++)
	{
		tmpPoint = (float)i / 10 * 3.1415f * 2.0f;
		glVertex2f(newX + cos(tmpPoint) * (radius / 10),
			newY + sin(tmpPoint) * (radius / 10));
	}
	glEnd();
}