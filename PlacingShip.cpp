#include "PlacingShip.h"

PlacingShip::PlacingShip() : Ship()
{

}

PlacingShip::PlacingShip(int x, int y, int weight, int height, int deck) :
	Ship(x, y, weight, height, deck), pressed(false)
{

}

PlacingShip::~PlacingShip()
{

}

void PlacingShip::draw()
{
	Ship::draw();
	int space = 15;
	glColor3d(0.0, 0.0, 1.0);
	glRasterPos2d(x - CELL_SIZE, y + 22);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, std::to_string(deck)[0]);
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

bool PlacingShip::mouseOnPlacingShip(int mX, int mY)
{
	return((mX > x) && (mX < x + width) && (mY > y) && (mY < y + height));
}

bool PlacingShip::isPressed() const
{
	return pressed;
}

void PlacingShip::setPressed(bool state)
{
	pressed = state;
}
