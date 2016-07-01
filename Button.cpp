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

bool Button::mouseOnButton(int mX, int mY)
{
	if((mX > x) && (mX < x + width) && (mY > y) && (mY < y + height))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Button::draw()
{
	GraphicsItem::draw();
	int space = 15;
	for(int i = 0; i < text.size(); i++)
	{
		glColor3d(0.0, 0.0, 1.0);
		glRasterPos2d(x + width/2 - text.size()*7 + i*space, y + height/2);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
}