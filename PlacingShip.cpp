#include "PlacingShip.h"

PlacingShip::PlacingShip(int x, int y, int width, int height, int deckCount, const Orientation& orientation, bool visiable, bool alive, int areaX, int areaY, int areaWidth, int areaHeight, bool aPressed, int aShipPlaceCount) :
	Ship(x, y, width, height, deckCount, orientation, visiable, alive, areaX, areaY, areaWidth, areaHeight), pressed(aPressed), shipPlaceCount(aShipPlaceCount)
{

}

PlacingShip::~PlacingShip()
{

}

void PlacingShip::draw()
{
	GraphicsRectItem::draw();
	int space = 15;
	glColor3d(0.0, 0.0, 1.0);
	glRasterPos2d(x - CELL_SZ, y + 22);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, std::to_string(shipPlaceCount)[0]);
	glRasterPos2d(x  - CELL_SZ + space, y + 22);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'x');
	if(pressed)
	{
		glLineWidth(2.0);
		glBegin(GL_LINE_LOOP);
		glColor3d(0.0, 1.0, 0.0);
		glVertex2d(x + width + 3.0, y + height + 3.0);
		glVertex2d(x + width + 3.0, y - 3.0);
		glVertex2d(x - 3.0, y - 3.0);
		glVertex2d(x - 3.0, y + height + 3.0);
		glEnd();
	}
}

void PlacingShip::setPressed(bool state)
{
	pressed = state;
}

void PlacingShip::setShipPlaceCount(int count)
{
	shipPlaceCount = count;
}

bool PlacingShip::isPressed() const
{
	return pressed;
}


int PlacingShip::getShipPlaceCount() const
{
	return shipPlaceCount;
}

void PlacingShip::operator++(int)
{
	shipPlaceCount++;
}

void PlacingShip::operator--(int)
{
	if(shipPlaceCount)
		shipPlaceCount--;
}