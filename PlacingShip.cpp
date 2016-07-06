#include "PlacingShip.h"

PlacingShip::PlacingShip() : Ship(), pressed(false), shipPlaceCount(0)
{

}

PlacingShip::PlacingShip(int x, int y, int weight, int height, int deck, int count) :
	Ship(x, y, weight, height, deck), pressed(false), shipPlaceCount(count)
{

}

PlacingShip::~PlacingShip()
{

}

void PlacingShip::draw()
{
	GraphicsItem::draw();
	int space = 15;
	glColor3d(0.0, 0.0, 1.0);
	glRasterPos2d(x - CELL_SIZE, y + 22);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, std::to_string(shipPlaceCount)[0]);
	glRasterPos2d(x  - CELL_SIZE + space, y + 22);
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

bool PlacingShip::isPressed() const
{
	return pressed;
}

void PlacingShip::setPressed(bool state)
{
	pressed = state;
}

int PlacingShip::getAvailableShipPlaceCount() const
{
	return shipPlaceCount;
}

void PlacingShip::setShipPlaceCount(int count)
{
	shipPlaceCount = count;
}

void PlacingShip::incShipCount()
{
	shipPlaceCount++;
}

void PlacingShip::decShipCount()
{
	if(shipPlaceCount)
		shipPlaceCount--;
}