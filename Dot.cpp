#include "Dot.h"

Dot::Dot(int x, int y, int width, int height, bool visiable, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state)) :
	GraphicsRectItem(x, y, width, height, visiable, clicked, callbackClickedFunc)
{

}

Dot::~Dot()
{

}

void Dot::draw()
{
	double tmpPoint;
	int newX = x + CELL_SZ/2, newY = y + CELL_SZ/2, radius = 40;
	glColor3d(0.0, 0.0, 1.0);
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