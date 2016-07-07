#include "Button.h"

Button::Button(int x, int y, int width, int height, const std::string& aText) :
	GraphicsRectItem(x, y, width, height), text(aText)
{

}

Button::~Button()
{

}

void Button::draw()
{
	GraphicsRectItem::draw();
	int space = 15;
	for(int i = 0; i < text.size(); i++)
	{
		glColor3d(0.0, 0.0, 1.0);
		glRasterPos2d(x + width / 2 - text.size()*space / 2.15 + i*space, y + height / 1.75);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
}

void Button::setText(std::string& aText)
{
	text = aText;
}

const std::string& Button::getText() const
{
	return text;
}