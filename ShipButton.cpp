#include "ShipButton.h"
ShipButton::ShipButton() : ships(0), focus(false), Ship()
{

}

ShipButton::ShipButton(int _ships, int decks, const Rect& rect, double r, double g, double b, double a, bool visible, CallbackClicked callbackClicked, const Orientation & orientation, bool alive, bool _focus) :
	ships(_ships), focus(_focus), Ship(decks, Rect(), rect, r, g, b, a, visible, callbackClicked, orientation)
{
	textShipsCount = new Label(std::to_string(ships) + "x", GLUT_BITMAP_HELVETICA_18, 15, Rect(rect.x() - CELL_SZ, rect.y() + 22, 0, 0), r, g, b, a, true);
}

ShipButton::~ShipButton()
{

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

void ShipButton::mousePressed(int button, int state, int mouseX, int mouseY)
{
	if(contains(mouseX, mouseY) && visible)
	{
		GraphicsItem::mousePressed(button, state, mouseX, mouseY);
	}
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