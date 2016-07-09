#include "ShipButton.h"

ShipButton::ShipButton(int x, int y, int width, int height, bool visiable, bool pressed, void(*callbackFunc)(), int deckCount, const Orientation& orientation, bool alive, int areaX, int areaY, int areaWidth, int areaHeight, int _shipPlaceCount) :
	Ship(x, y, width, height, visiable, pressed, callbackFunc, deckCount, orientation, alive, areaX, areaY, areaWidth, areaHeight), shipPlaceCount(_shipPlaceCount)
{

}

ShipButton::~ShipButton()
{

}

void ShipButton::draw()
{
	if(visiable)
	{
		GraphicsRectItem::draw();
		int space = 15;
		glColor3d(0.0, 0.0, 1.0);
		glRasterPos2d(x - CELL_SZ, y + 22);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, std::to_string(shipPlaceCount)[0]);
		glRasterPos2d(x - CELL_SZ + space, y + 22);
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
}

void ShipButton::setShipPlaceCount(int _shipPlaceCount)
{
	shipPlaceCount = _shipPlaceCount;
}

int ShipButton::getShipPlaceCount() const
{
	return shipPlaceCount;
}

void ShipButton::operator++(int)
{
	shipPlaceCount++;
}

void ShipButton::operator--(int)
{
	if(shipPlaceCount)
		shipPlaceCount--;
}