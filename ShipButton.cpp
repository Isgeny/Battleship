#include "ShipButton.h"
ShipButton::ShipButton() : ships(0), focus(false), textShipsCount(nullptr), Ship()
{

}

ShipButton::ShipButton(int _ships, int decks, const Rect& areaRect, const Rect& rect, bool _focus, const Orientation& orientation, CallbackClicked callbackClicked, bool visible, double r, double g, double b, double a) :
	ships(_ships), focus(_focus), Ship(decks, areaRect, rect, orientation, callbackClicked, visible, r, g, b, a)
{
	textShipsCount = new Label(std::to_string(ships) + "x", GLUT_BITMAP_HELVETICA_18, 15, Rect(rect.x() - CELL_SZ, rect.y() + 22, 0, 0));
}

ShipButton::~ShipButton()
{
	delete textShipsCount;
}

void ShipButton::draw()
{
	if(visible)
	{
		textShipsCount->setText(std::to_string(ships) + "x");
		textShipsCount->draw();
		drawRect();
		if(focus)
		{
			//Обводим зеленым выбранный корабль
			glLineWidth(2.0);
			glBegin(GL_LINE_LOOP);
			glColor3d(0.0, 1.0, 0.0);
			glVertex2d(rect.x() + rect.width() + 3.0, rect.y() + rect.height() + 3.0);
			glVertex2d(rect.x() + rect.width() + 3.0, rect.y() - 3.0);
			glVertex2d(rect.x() - 3.0, rect.y() - 3.0);
			glVertex2d(rect.x() - 3.0, rect.y() + rect.height() + 3.0);
			glEnd();
		}
	}
}

void ShipButton::setVisible(bool visible)
{
	GraphicsItem::setVisible(visible);
	textShipsCount->setVisible(true);
}

void ShipButton::setShips(int _ships)
{
	ships = _ships;
}

void ShipButton::setFocus(bool _focus)
{
	focus = _focus;
}

int ShipButton::getShips() const
{
	return ships;
}

bool ShipButton::hasFocus() const
{
	return focus;
}

void ShipButton::operator++(int)
{
	ships++;
}

void ShipButton::operator--(int)
{
	if(ships)
		ships--;
}