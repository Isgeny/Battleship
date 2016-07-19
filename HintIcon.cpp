#include "HintIcon.h"

HintIcon::HintIcon(const Rect& rect, CallbackClicked callbackClicked, bool visible, double r, double g, double b, double a) :
	GraphicsItem(rect, callbackClicked, visible, r, g, b, a)
{
	pl = new Label("place", GLUT_BITMAP_HELVETICA_18, 15, Rect(rect.x() - 100, rect.y() + 20, 0, 0));
	rot = new Label("rotate", GLUT_BITMAP_HELVETICA_18, 15, Rect(rect.x() - 10, rect.y() - 30, 0, 0));
	del = new Label("delete", GLUT_BITMAP_HELVETICA_18, 15, Rect(rect.x() + 90, rect.y() + 20, 0, 0));
}

HintIcon::~HintIcon()
{

}

void HintIcon::draw()
{
	if(visible)
	{
		//Рисование мышки-подсказки
		this->drawRect();
		pl->draw();
		rot->draw();
		del->draw();
		glColor4d(r, g, b, a);
		glLineWidth(2);
		glBegin(GL_LINES);
		//Горизонтальная
		glVertex2d(rect.x(), rect.y() + CELL_SZ);
		glVertex2d(rect.x() + rect.width(), rect.y() + CELL_SZ);
		//Колесико верт левое
		glVertex2d(rect.x() + rect.width()/2 - 7, rect.y());
		glVertex2d(rect.x() + rect.width() / 2 - 7, rect.y() + CELL_SZ);
		//Колесико верт правое
		glVertex2d(rect.x() + rect.width() / 2 + 7, rect.y());
		glVertex2d(rect.x() + rect.width() / 2 + 7, rect.y() + CELL_SZ);
		//place
		glVertex2d(rect.x() - 25, rect.y() + CELL_SZ/2);
		glVertex2d(rect.x() + 10, rect.y() + CELL_SZ / 2);
		//delete
		glVertex2d(rect.x() + rect.width() - 10, rect.y() + CELL_SZ / 2);
		glVertex2d(rect.x() + rect.width() + 25, rect.y() + CELL_SZ / 2);
		//rotate
		glVertex2d(rect.x() + rect.width()/2, rect.y() + 10);
		glVertex2d(rect.x() + rect.width()/2, rect.y() - 25);

		glEnd();
	}
}

void HintIcon::setVisible(bool visible)
{
	GraphicsItem::setVisible(visible);
	pl->setVisible(true);
	rot->setVisible(true);
	del->setVisible(true);
}
