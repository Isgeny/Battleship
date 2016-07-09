#include "ShipButton.h"

ShipButton::ShipButton(int x, int y, int width, int height, bool visiable, bool clicked, void (*callbackClickedFunc)(GraphicsRectItem*, int button, int state), int deckCount, const Orientation& orientation, bool alive, int areaX, int areaY, int areaWidth, int areaHeight, int _shipPlaceCount, bool _pressed) :
	Ship(x, y, width, height, visiable, clicked, callbackClickedFunc, deckCount, orientation, alive, areaX, areaY, areaWidth, areaHeight), shipPlaceCount(_shipPlaceCount), pressed(_pressed)
{

}

ShipButton::~ShipButton()
{

}

void ShipButton::draw()
{
	if(visiable)
	{
		
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
		GraphicsRectItem::draw();
	}
}

void ShipButton::setShipPlaceCount(int _shipPlaceCount)
{
	shipPlaceCount = _shipPlaceCount;
}

void ShipButton::setPressed(bool _pressed)
{
	pressed = _pressed;
}

int ShipButton::getShipPlaceCount() const
{
	return shipPlaceCount;
}

bool ShipButton::isPressed() const
{
	return pressed;
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