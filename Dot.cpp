#include "Dot.h"

Dot::Dot() : GraphicsRectItem()
{

}

Dot::Dot(int aX, int aY, int aWidth, int aHeight) : GraphicsRectItem(aX, aY, aWidth, aHeight)
{

}

Dot::~Dot()
{

}

void Dot::draw()
{
	double tmpPoint;
	int newX = x + CELL_SZ/2, newY = y + CELL_SZ/2, radius = 40;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(newX, newY);
	for(int i = 0; i <= 50; i++)
	{
		tmpPoint = (float)i / 10 * 3.1415f * 2.0f;
		glVertex2f(newX + cos(tmpPoint) * (radius / 10),
			newY + sin(tmpPoint) * (radius / 10));
	}
	glEnd();
}