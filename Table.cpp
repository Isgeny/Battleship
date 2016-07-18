#include "Table.h"
Table::Table(int _rows, int _columns, const Rect& rect, double r, double g, double b, double a, bool visible, CallbackClicked callbackClicked) :
	rows(_rows), columns(_columns), GraphicsItem(rect, r, g, b, a, visible, callbackClicked)
{
	cellWidth = rect.width() / columns;
	cellHeight = rect.height() / rows;
}

Table::~Table()
{
	deleteData();
}

void Table::draw()
{
	if(visible)
	{
		glColor4d(r, g, b, a);
		glBegin(GL_LINES);
		//Отрисовка горизонтальных линий
		for(int i = 0; i < rows - 1; i++)
		{
			glVertex2d(rect.x(), rect.y() + cellHeight + i*cellHeight);
			glVertex2d(rect.x() + rect.width(), rect.y() + cellHeight + i*cellHeight);
		}
		//Отрисовка вертикальных линий
		for(int i = 0; i < columns - 1; i++)
		{
			glVertex2d(rect.x() + cellWidth + i*cellWidth, rect.y());
			glVertex2d(rect.x() + cellWidth + i*cellWidth, rect.y() + rect.height());
		}
		glEnd();
		for(auto it = cells.begin(); it != cells.end(); it++)
			(*it)->draw();
	}
}

void Table::addData(int row, int column, const std::string& text)
{
	Rect r;
	r.setX(rect.x() + column*cellWidth + cellWidth/2 - text.size()*16/2);
	r.setY(rect.y() + row*cellHeight + cellHeight/2 + 7);
	cells.push_back(new Label(text, GLUT_BITMAP_HELVETICA_18, 17, r, 0.0, 0.0, 1.0, 1.0, true));
}

void Table::deleteData()
{
	for(auto it = cells.begin(); it != cells.end(); it++)
		delete (*it);
	cells.erase(cells.begin(), cells.end());
}