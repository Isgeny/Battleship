#include "Button.h"

Button::Button(int _x, int _y, int _width, int _height, const std::string & _text) : 
	x(_x), y(_y), width(_width), height(_height), text(_text)
{

}

int Button::getX() const
{
	return x;
}

int Button::getY() const
{
	return y;
}

int Button::getWith() const
{
	return width;
}

int Button::getHeight() const
{
	return height;
}

std::string Button::getText() const
{
	return std::string();
}

void Button::setX(int _x)
{
	x = _x;
}

void Button::setY(int _y)
{
	y = _y;
}

void Button::setWidth(int _width)
{
	width = _width;
}

void Button::setHeight(int _height)
{
	height = _height;
}

void Button::setText(std::string & _text)
{
	text = _text;
}

bool Button::mouseOnButton(int mX, int mY)
{
	if((mX > x) && (mX < x + width) && (mY < y) && (mY > y + height))
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
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glColor3d(0.0, 0.0, 1.0);
	glVertex2d(x + width, y + height);
	glVertex2d(x + width, y);
	glVertex2d(x, y);
	glVertex2d(x, y + height);
	glEnd();

	int space = 15;
	for(int i = 0; i < text.size(); i++)
	{
		glColor3d(0.0, 0.0, 1.0);
		glRasterPos2d(x + width/2 - text.size()*7 + i*space, y + height/2);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}
}