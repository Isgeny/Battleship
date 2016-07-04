#include "Button.h"

Button::Button() : GraphicsItem(), text("untitled")
{

}

Button::Button(int _x, int _y, int _width, int _height, const std::string & _text) :
	GraphicsItem(_x, _y, _width, _height), text(_text)
{

}

Button::~Button()
{

}

std::string Button::getText() const
{
	return std::string();
}

void Button::setText(std::string & _text)
{
	text = _text;
}

void Button::draw()
{
	GraphicsItem::draw();
	int space = 15;
	for(int i = 0; i < text.size(); i++)
	{
		glColor3d(0.0, 0.0, 1.0);
		glRasterPos2d(x + width / 2 - text.size()*space/2.15 + i*space, y+height/1.75);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
}