#include "ShipPart.h"

ShipPart::ShipPart(int x, int y, int width, int height, bool aAlive) :
	GraphicsRectItem(x, y, width, height), alive(aAlive)
{

}

ShipPart::~ShipPart()
{

}

void ShipPart::draw()
{
	//Отрисовка красных крестиков
	if(!this->alive)
	{
		glColor3d(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2d(this->x, this->y);
		glVertex2d(this->x + this->width, this->y + this->height);
		glVertex2d(this->x + this->width, this->y);
		glVertex2d(this->x, this->y + this->height);
		glEnd();
	}
}

void ShipPart::setAlive(bool aAlive)
{
	alive = aAlive;
}

bool ShipPart::getAlive() const
{
	return alive;
}
