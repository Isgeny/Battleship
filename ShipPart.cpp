#include "ShipPart.h"

ShipPart::ShipPart(int x, int y, int width, int height, bool visiable, bool pressed, void(*callbackFunc)(), bool _alive) :
	GraphicsRectItem(x, y, width, height, visiable, pressed, callbackFunc), alive(_alive)
{

}

ShipPart::~ShipPart()
{

}

void ShipPart::draw()
{
	//Отрисовка красных крестиков
	if(!alive)
	{
		glColor3d(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2d(x, y);
		glVertex2d(x + width, y + height);
		glVertex2d(x + width, y);
		glVertex2d(x, y + height);
		glEnd();
	}
}

void ShipPart::setAlive(bool _alive)
{
	alive = _alive;
}

bool ShipPart::getAlive() const
{
	return alive;
}
